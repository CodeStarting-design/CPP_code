  #include <stdio.h>
  #include <pthread.h>
  #include <stdlib.h>
  #include <unistd.h>
  
  // 链表作为容器
  struct Node{
      int val;
      struct Node* next;
      Node(int v,Node* n):val(v),next(n){}
      Node()=default;
  };
  
  // 头结点
  struct Node* head = new Node(0,NULL);// 带有头节点
  int buffer_len=10;// 读写缓冲区的大小

  // 互斥量
  pthread_mutex_t mutex;
  
  // 写入元素
  void* producter(void* arg) {
      while (1) {
          pthread_mutex_lock(&mutex);
          if(head->val>=buffer_len){
            pthread_mutex_unlock(&mutex);
            usleep(100);
            continue;
          }
          struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
          newNode->val = rand() % 1000;
          newNode->next= NULL;
          struct Node* tail=head;
          while(tail->next) tail=tail->next;
          tail->next = newNode;
          head->val++;
          printf("add node, num : %d, tid : %ld\n", newNode->val, pthread_self());
          pthread_mutex_unlock(&mutex);
          usleep(100);
      }
      return NULL;
  }
  
  // 删除链表元素
  void* consumer(void* arg) {
      while (1) {
          pthread_mutex_lock(&mutex);
          struct Node* tmp = NULL;
          // 当链表不为空时，才能删除
          if (head->val > 0) {
              tmp = head->next;
              if(!tmp){
                printf("Logic error\n");
              }
              head->next=tmp->next;
              printf("del node, num : %d, tid : %ld\n", tmp->val, pthread_self());
              free(tmp);
              head->val--;
              pthread_mutex_unlock(&mutex);
              usleep(100);
          } else {
              pthread_mutex_unlock(&mutex);
          }
      }
      return NULL;
  }
  
  int main()
  {
      // 初始化互斥锁
      pthread_mutex_init(&mutex, NULL);
      // 创建5个生产者线程，和5个消费者线程
      pthread_t products[5], consumes[5];
      for (int i = 0; i < 5; i++) {
          pthread_create(&products[i], NULL, producter, NULL);
          pthread_create(&consumes[i], NULL, consumer, NULL);
      }
  
      // 分离，回收线程资源
      for (int i = 0; i < 5; i++) {
          pthread_detach(products[i]);
          pthread_detach(consumes[i]);
      }
  
      // 回收互斥锁
      pthread_mutex_destroy(&mutex);
      pthread_exit(NULL);     // 回收主线程
      return 0;
  }
