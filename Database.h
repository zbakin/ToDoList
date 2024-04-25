#ifndef TODOLIST_DATABASE_H
#define TODOLIST_DATABASE_H

#include "ToDoList.h"
#include <pqxx/pqxx>
#include <utility>

class Database {
public:
    Database(std::string  dbName, std::string ip, std::string port);

    void addTask(std::string tableName, Task newTask);
    void updateTask(std::string tableName, std::string field);

    ~Database() {

    }
private:
    std::string m_dbName;
    std::string m_hostIp;
    std::string m_hostPort;

};

#endif //TODOLIST_DATABASE_H
