#include <iostream>
#include <unistd.h>

#include "ToDoList.h"
void signal_exit_handler(int signum) {
    std::cout << "Caught signal " << signum << std::endl;
    // Terminate program
    exit(signum);
}

int main() {

    signal(SIGINT, signal_exit_handler);
    ToDoList myList;
    int countInput = 2;
    // Enter tasks step
    while(countInput) {
        --countInput;
        std::string name, description;
        std::cout << "Type a name of the task" << std::endl;
        std::getline(std::cin, name);
        std::cout << "Type a description of the task" << std::endl;
        std::getline(std::cin, description);

        std::unique_ptr<Task> exampleTask = std::make_unique<Task>(0, name, description);
        exampleTask->setDueDate("14 January 2024");
        myList.addTask(std::move(exampleTask));
        myList.showAllTasks();
        myList.extractToCSV("tasks.csv");
        sleep(1);
    }

//    std::unique_ptr<Task> task1 = myList.getTask(0);
//    task1->setStatus(true); // means complete
//
//    myList.extractToCSV("tasks.csv");

    return EXIT_SUCCESS;
}
