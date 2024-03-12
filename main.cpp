#include <iostream>
#include <unistd.h>

#include "Task.h"
#include "ToDoList.h"

void signal_exit_handler(int signum) {
    std::cout << "Caught signal " << signum << std::endl;
    // Terminate program
    exit(signum);
}

int main() {

    signal(SIGINT, signal_exit_handler);
    ToDoList myList;
    while(true) {
        std::string name, description;
        std::cout << "Type a name of the task" << std::endl;
        std::getline(std::cin, name);
        std::cout << "Type a description of the task" << std::endl;
        std::getline(std::cin, description);

        std::unique_ptr<Task> exampleTask = std::make_unique<Task>(0, name, description);
        exampleTask->setDueDate("14 January 2024");
        exampleTask->setComplete();
        exampleTask->setComplete();
        myList.addTask(0, std::move(exampleTask));
        myList.extractToFile("tasks.txt");
        sleep(2);
    }

    return EXIT_SUCCESS;
}
