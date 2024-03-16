#include <iostream>
#include <string>
#include "ToDoList.h"

class CommandLine {
public:
    // Start the command line interface
    void start();

private:

    ToDoList m_list;
    std::unique_ptr<Task> exampleTask = std::make_unique<Task>(0, "Some task", "do that and this");

    // Display available options
    void displayOptions();

    // Get user input as an integer
    int getUserInput();

    // Process user-selected option
    void processOption(int option);
};
