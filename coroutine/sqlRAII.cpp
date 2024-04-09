#include <iostream>
#include <vector>
#include <mutex>
#include <mysql/mysql.h>

class DBConnection {
private:
    MYSQL* connection;
public:
    DBConnection(const char* host, const char* user, const char* password, const char* dbname) {
        connection = mysql_init(nullptr);
        if (!mysql_real_connect(connection, host, user, password, dbname, 0, nullptr, 0)) {
            std::cerr << "Failed to connect to database: " << mysql_error(connection) << std::endl;
            throw std::runtime_error("Failed to connect to database.");
        }
    }

    ~DBConnection() {
        mysql_close(connection);
    }

    MYSQL* getConnection() const {
        return connection;
    }
};

class ConnectionPool {
private:
    std::vector<DBConnection*> connections;
    std::mutex mtx;
public:
    ConnectionPool(int size, const char* host, const char* user, const char* password, const char* dbname) {
        for (int i = 0; i < size; ++i) {
            try {
                DBConnection* conn = new DBConnection(host, user, password, dbname);
                connections.push_back(conn);
            } catch (const std::exception& e) {
                std::cerr << "Failed to create database connection: " << e.what() << std::endl;
            }
        }
    }

    ~ConnectionPool() {
        for (DBConnection* conn : connections) {
            delete conn;
        }
    }

    DBConnection* getConnection() {
        std::lock_guard<std::mutex> lock(mtx);
        if (connections.empty()) {
            return nullptr; // No available connections
        }
        DBConnection* conn = connections.back();
        connections.pop_back();
        return conn;
    }

    void releaseConnection(DBConnection* conn) {
        std::lock_guard<std::mutex> lock(mtx);
        connections.push_back(conn);
    }
};

int main() {
    const char* host = "localhost";
    const char* user = "username";
    const char* password = "password";
    const char* dbname = "database";
    int poolSize = 5;

    ConnectionPool pool(poolSize, host, user, password, dbname);

    // 使用连接池获取数据库连接
    DBConnection* conn1 = pool.getConnection();
    if (conn1) {
        std::cout << "Successfully obtained database connection 1." << std::endl;
        // 使用 conn1 执行数据库操作
        // ...

        // 释放连接回连接池
        pool.releaseConnection(conn1);
        std::cout << "Database connection 1 released." << std::endl;
    } else {
        std::cerr << "Failed to obtain database connection 1." << std::endl;
    }

    // 获取更多数据库连接，执行类似的操作
    // ...

    return 0;
}
