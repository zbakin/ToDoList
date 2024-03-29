#include <iostream>
#include <unistd.h>

#include "ToDoList.h"
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

int main() {

    signal(SIGINT, signal_exit_handler);
    ToDoList myList;
    int countInput = 2;

    usage();
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
