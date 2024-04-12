#include <iostream>
#include "ToDoList.h"
#include <pqxx/pqxx>

void signal_exit_handler(int signum) {
    std::cout << "Caught signal " << signum << std::endl;
    // Terminate program
    exit(signum);
}
static void usage()
{
    std::cerr << "syntax: " << "ToDoList" << " [global options] <command> [command options]" << std::endl;
    std::cerr << std::endl;
    std::cerr << "Global options are:" << std::endl;
    std::cerr << "  --help (-h)      Display this help" << std::endl;
    std::cerr << "  --verbose (-v)   Enable verbose mode" << std::endl;
    std::cerr << "  --quiet (-q)     Disable verbose mode" << std::endl;
    std::cerr << "  -f <file>        Specify ToDoList filename" << std::endl;
    std::cerr << std::endl;
    std::cerr << "Commands are:" << std::endl;
    std::cerr << "  add              Add a Task to the list" << std::endl;
    std::cerr << "  show             Display the tasks in the ToDoList" << std::endl;
    std::cerr << "  mark-complete    Update the status of specified Task" << std::endl;
    std::cerr << std::endl;
    std::cerr << "Type 'ToDoList command --help' to see the syntax of 'command'." << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) { // Check if exactly one argument (file path) is provided
        std::cerr << "Usage: " << argv[0] << " <file_path>" << std::endl;
        return EXIT_FAILURE;
    }
    signal(SIGINT, signal_exit_handler);
    ToDoList myList(argv[1]);

//    myList.showAllTasks();
    try {
        pqxx::connection conn("dbname=todolist hostaddr=127.0.0.1 port=5432");
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
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
