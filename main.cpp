#include <iostream>
#include "Task.h"


int main() {
    std::string name, description;

    std::cout << "Type a name of the task" << std::endl;
    std::getline(std::cin, name);
    std::cout << "Type a description of the task" << std::endl;
    std::getline(std::cin, description);

    Task exampleEmptyTask;
    Task exampleTask{name, description};
    exampleTask.showTask();
    return 0;
}
