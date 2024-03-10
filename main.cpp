#include <iostream>
#include "Task.h"
#include "ToDoList.h"

int main() {
    std::string name, description;

    std::cout << "Type a name of the task" << std::endl;
    std::getline(std::cin, name);
    std::cout << "Type a description of the task" << std::endl;
    std::getline(std::cin, description);

    Task exampleEmptyTask;
    Task exampleTask{name, description};
    exampleTask.setDueDate("14 January 2024");
    exampleTask.showTask();


    ToDoList mylist;
    return 0;
}
