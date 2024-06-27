#include "Database.h"

Database::Database(std::string dbName, std::string ip, std::string port) :
        m_dbName(std::move(dbName)), m_hostIp(std::move(ip)), m_hostPort(std::move(port)) {
    try {
        std::string conn_parameters = "dbname=" + m_dbName + " hostaddr=" + m_hostIp + " port="
                                      + m_hostPort;
        m_connection = std::make_unique<pqxx::connection>(conn_parameters);
        pqxx::work txn(*m_connection);
        pqxx::result result = txn.exec("SELECT * FROM tasks");
        txn.commit();

        // Print column names
        for (int i = 0; i < result.columns(); ++i) {
            std::cout << result.column_name(i) << "\t";
        }
        std::cout << std::endl;

        // Print each row
        for (const auto& row : result) {
            for (const auto &field : row) {
                std::cout << field.c_str() << "\t";
            }
            std::cout << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void Database::insertTask(std::string tableName, Task newTask) {
    pqxx::work txn(*m_connection);
    pqxx::result result = txn.exec("INSERT INTO tasks (task_name, description, deadline, is_complete) VALUES ('task3', 'Dummy task 3', '2024-07-15', false);");
    txn.commit();
}

void Database::deleteTask(std::string tableName, size_t id) {
    pqxx::work txn(*m_connection);
    pqxx::result result = txn.exec(std::format("DELETE FROM tasks WHERE task_id = {};", id));
    txn.commit();
}


