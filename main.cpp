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

int main(int argc, char* argv[]) {
    if (argc != 2) { // Check if exactly one argument (file path) is provided
        std::cerr << "Usage: " << argv[0] << " <file_path>" << std::endl;
        return EXIT_FAILURE;
    }
    signal(SIGINT, signal_exit_handler);
    ToDoList myList(argv[1]);

    myList.showAllTasks();

    return EXIT_SUCCESS;
}
