#ifndef TODOLIST_DATABASE_H
#define TODOLIST_DATABASE_H

#include "ToDoList.h"
#include <pqxx/pqxx>
#include <utility>

class Database {
public:
    Database(std::string  dbName, std::string ip, std::string port);

    void insertTask(std::string tableName, Task newTask);
    void updateTask(std::string tableName, std::string field);
    void deleteTask(std::string tableName, size_t id);
    Task getTask(std::string tableName, std::string field);
    void deleteTasks(std::string tableName);

private:
    std::string m_dbName;
    std::string m_hostIp;
    std::string m_hostPort;
    std::unique_ptr<pqxx::connection> m_connection;
};

#endif //TODOLIST_DATABASE_H
