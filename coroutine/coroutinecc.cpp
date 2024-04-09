
#include <functional>
#include <vector>
#include <memory>
#include <cstddef>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include<iostream>
#include<typeinfo>

#if __APPLE__ && __MACH__
	#include <sys/ucontext.h>
#else 
	#include <ucontext.h>
#endif 


namespace Coroutinecc{ // 定义了一个命名空间

class Scheduler;// 先声明了两个类
class Coroutine;

typedef std::function<void (Scheduler*, void*)> CoroutineFunc; // 对应的是一个返回值为void，参数为Scheduler,void*的函数
using std::vector;
using std::shared_ptr;

class Coroutine: public std::enable_shared_from_this<Coroutine> {
// 此处继承自enable_shared_from_this类，主要是为了能够在类的对象中创建一个指向自身的shared_ptr,目的是为了
// 在对象内部的某个成员函数中，需要异步地调用自己，而在调用时需要保证对象的生命周期不会提前结束
public:
    typedef enum status{// 对应四种状态 协程的初始状态就是READY 协程还存在一个死亡的状态
        COROUTINE_DEAD,
        COROUTINE_READY,
        COROUTINE_RUNNING,
        COROUTINE_SUSPEND
    } status;
private:
    CoroutineFunc func_;// 协程执行的函数
    void* ud_;// 函数的参数
    ucontext_t ctx_;
    Scheduler* sch_;// 指向调度器的指针
    ptrdiff_t cap_;// ptrdiff_t表示指针之间的差值
    ptrdiff_t size_;
    Coroutine::status status_;// 协程状态
    char* stack_;// 栈空间，以字节为单位 指针保存在栈空间，指针所指向的堆空间
public:
    Coroutine(Scheduler* s, CoroutineFunc func, void* ud);
    ~Coroutine();
    Coroutine::status getStatus() const { return this->status_; }
    void setStatus(Coroutine::status stat) { this->status_ = stat; }
    ucontext_t& getContext() { return ctx_; }// 此处是返回协程的上下文
    void saveStack(char *top);
    void inline runFunc(Scheduler* s);
    inline ptrdiff_t size() { return size_; }
    inline char* stack() { return stack_; }
    inline bool dead() { return status_ == status::COROUTINE_DEAD; }
};

class Scheduler {
public:

    static const int STACK_SIZE = (1024*1024);
    static const int DEFAULT_COROUTINE = 16;// 默认的协程数量

    Scheduler();
    virtual ~Scheduler();
    Scheduler& open();
    void close();
    ptrdiff_t add(CoroutineFunc func, void* ud);
    void resume(int id);
    inline Coroutine::status status(int id) const;
    int running();
    void yield();
    inline shared_ptr<Coroutine>& operator[](size_t key) { return co_[key]; };// 此处是重载[]运算符的
    char* getStack(){ return stack_;};

private:
    static void mainfunc(uint32_t low32, uint32_t hi32);// 定义了静态函数

    //私有变量
    char stack_[STACK_SIZE]; // 1M的栈空间 并且这个内存空间将会被保存在进程的栈空间中
    ucontext_t main_; // 主协程的上下文
    int coroutine_num_;// 协程数
    int cap_;// 协程的最大容量
    int running_;
    vector<shared_ptr<Coroutine>> co_; // 此处保存的是已经创建的协程的共享指针
};

}

namespace Coroutinecc{

Scheduler::Scheduler(): 
    coroutine_num_(0), cap_(DEFAULT_COROUTINE), running_(-1), co_(vector<shared_ptr<Coroutine>>(0)) { }

Scheduler& Scheduler::open() {
    return *this;
}

void 
Scheduler::close() {
    co_.erase(co_.begin(), co_.end());// 清空协程队列
    running_ = -1;
    coroutine_num_ = 0;
}

Scheduler::~Scheduler() {
    this->close();
}

/**
 * 向Schedular尾部插入Coroutine实例
 */
ptrdiff_t
Scheduler::add(CoroutineFunc func, void* ud) {// 创建一个新的协程
    Coroutine *co = new Coroutine(this, func, ud);// 在进程的对内存中分配空间
    this->co_.push_back(std::shared_ptr<Coroutine>(co));// 创建了一个指向该堆内存的智能指针，保存在对象自身中，对象在堆内存，所以也是在堆内存
    return this->co_.size() - 1;// 返回的是协程的个数
}


/**
 * 恢复id指向的Coroutine实例
 */
void
Scheduler::resume(int id) {// 使用调度器让某一个协程运行
    //std::assert(this->running_ == -1);
    //std::assert(id >= 0 && id < cap_);

    auto C = co_[id];// 得到的是一个指针
    uintptr_t ptr;
    if(!C) {
        return ;
    }

    Coroutine::status nowStatus = C->getStatus();
    ucontext_t& nowContext = C->getContext();
    switch(nowStatus) {
        case Coroutine::status::COROUTINE_READY:    // READY状态的协程，没有上下问
            getcontext(&nowContext);                //初始化该协程的上下文
            nowContext.uc_stack.ss_sp = stack_;     //设置协程的uc_stack
            nowContext.uc_stack.ss_size = STACK_SIZE; // 栈大小是1024K
            nowContext.uc_link = &main_;            //设置该协程的后继上下文
            running_ = id;                          
            C->setStatus(Coroutine::status::COROUTINE_RUNNING);
            ptr = (uintptr_t)this;// 指向当前调度器对象的独占指针
            makecontext(&nowContext, (void(*)(void))mainfunc, 2, (uint32_t)ptr, (uint32_t)(ptr >> 32));    //为协程设置入口函数
            swapcontext(&main_, &nowContext);       //保存当前上下文到main_，激活nowContext指向的目标上下文
            break;
        case Coroutine::status::COROUTINE_SUSPEND:
            ::memcpy(stack_ + STACK_SIZE - C->size(), C->stack(), C->size());  // 从低地址向高地址复制
            running_ = id;
            swapcontext(&main_, &nowContext);
            break;
        default:
            assert(0);
    }
}

/**
 * 协程主动让出控制权，保存栈空间，恢复main_中保存的上下文（即恢复到Schduler::resume函数的上下文）
 */
void
Scheduler::yield() {
    assert(running_ >= 0);
    Coroutine& C = *co_[running_];     //获取正在运行的协程实例
    //assert((char*)(&C) > stack_);
    C.saveStack(stack_ + STACK_SIZE);   //保存当前栈空间
    C.setStatus(Coroutine::status::COROUTINE_SUSPEND);
    running_ = -1;
    swapcontext(&C.getContext(), &main_);// 切换到主协程，也就是调度器执行
}

/**
 * 获取 id 指向协程实例的状态
 */
inline Coroutine::status
Scheduler::status(int id) const {
    assert(id >= 0 && id < cap_);
    if(!co_[id]) {
        return Coroutine::status::COROUTINE_DEAD;
    }

    return co_[id]->getStatus();
}

/**
 * 获取该调度器正在运行的协程实例ID
 */
int
Scheduler::running() {
    return running_;
}

/**
 * @param low32 调度表指针的低32位
 * @param hi32  调度表指针的高32位
 * 执行在Coroutine实例中注册的协程实体函数，函数执行完毕后清理此协程
 */
void
Scheduler::mainfunc(uint32_t low32, uint32_t hi32) {// 32位的无符号数就对应于内存的地址
    uintptr_t sptr = (uintptr_t)low32 | ((uintptr_t)hi32 << 32);
    Scheduler& S = *(Scheduler*)(sptr);// 调度器的引用
    int id = S.running();
    S[id]->runFunc(&S);// 执行函数
    S[id] = nullptr;// 在完成执行之后标记协程为死亡
}

/**
 * @param s 管理协程实例的调度表
 * @param func 协程执行的实例
 * @param ud    协程运行时的参数
 * 初始化协程实例，初始运行状态为READY
 */
Coroutine::Coroutine(Scheduler* s, CoroutineFunc func, void* ud):
    func_(func),  ud_(ud), sch_(s), cap_(0), size_(0), status_(status::COROUTINE_READY), stack_(nullptr) {
        ::memset(&ctx_, 0, sizeof(ctx_));
}

/**
 * 协程实例的析构函数
 */
Coroutine::~Coroutine() {
    if(this->stack_)
        delete this->stack_;
}

/**
 * 保存当前栈空间到Coroutine实例的stack_空间中
 * @param top 当前栈的栈底
 * 由于栈空间是向低地址增长，因此栈底-当前函数栈的栈顶是需要保存的所有栈空间
 */
void    
Coroutine::saveStack(char* top) {// 此处的top是调度器的栈底指针
    char dummy = 0;// 创建的这个变量就位于当前协程的栈空间
    assert(top - &dummy <= Scheduler::STACK_SIZE);
    if(cap_ < top - &dummy) {
        delete stack_;// 清空的是协程的栈空间
        cap_ = top - &dummy;
        stack_ = new char[cap_];// 重新分配了栈空间
    }
    size_ = top - &dummy;
    memcpy(stack_, &dummy, size_);// 将栈空间的内容写入到堆中
}

/**
 * @param s 管理协程的调度表实例
 * 运行协程实例
 */
void inline
Coroutine::runFunc(Scheduler* s) {
    func_(s, ud_);
}
}

using namespace Coroutinecc;
using namespace std;

struct args {
    int n;
};

static void
foo(Scheduler* s, void* ud) {
    args* arg = reinterpret_cast<args*>(ud);// 类型转换
    int start = arg->n;
    for(int i = 0; i < 5; i++) {
        ::printf("coroutine %d : %d\n", s->running(), start + i);
        s->yield();
    }
}

static void
test(Scheduler* s) {
    args arg1 = { 0 };
    args arg2 = { 200 };

    ptrdiff_t co1 = s->add(foo, &arg1);// 添加l两个个协程
    ptrdiff_t co2 = s->add(foo, &arg2);
    printf("main start\n");
    while((*s)[co1] && (*s)[co2]) {// 获取的是共享指针
            if((*s)[co1])
                s->resume(co1);
            if((*s)[co2])
                s->resume(co2);
    }
    printf("main end\n");
}

int
main() {
    Scheduler* s = new Scheduler(); // s保存在进程的堆空间中
    cout<<static_cast<void*>(s)<<" "<<typeid(s).name()<<endl;
    cout<<static_cast<void*>(&s)<<" "<<typeid(&s).name()<<endl;
    cout<<static_cast<void*>(s->getStack())<<" "<<typeid(s->getStack()).name()<<endl;
    test(s);

    return 0;
}