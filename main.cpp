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

        Task exampleTask{name, description};
        exampleTask.setDueDate("14 January 2024");
        exampleTask.showTask();
        myList.addTask(0, exampleTask);
        std::cout << "Task " << exampleTask.getTaskName() << " was added to the list" << std::endl;
        sleep(2);
    }

    return EXIT_SUCCESS;
}
