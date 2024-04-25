#include "Database.h"

Database::Database(std::string dbName, std::string ip, std::string port) :
        m_dbName(std::move(dbName)), m_hostIp(std::move(ip)), m_hostPort(std::move(port)) {
    try {
        std::string conn_parameters = "dbname=" + m_dbName + " hostaddr=" + m_hostIp + " port="
                                      + m_hostPort;
        pqxx::connection conn(conn_parameters);
        pqxx::work txn(conn);
        pqxx::result result = txn.exec("SELECT * FROM zhanitodolist");
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

        // Close the connection when done
        conn.close();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void Database::addTask(std::string tableName, Task newTask) {

}