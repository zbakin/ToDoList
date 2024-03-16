
#include "CommandLine.h"

// Start the command line interface
void CommandLine::start() {
    while (true) {
        displayOptions();
        int option = getUserInput();
        processOption(option);
    }
}

// Display available options
void CommandLine::displayOptions() {
    std::cout << "Options:\n";
    std::cout << "1. Add task\n";
    std::cout << "2. Remove task\n";
    std::cout << "3. Show all tasks\n";
    std::cout << "4. Set task as complete\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter option number: ";
}

// Get user input as an integer
int CommandLine::getUserInput() {
    int option;
    while (!(std::cin >> option)) {
        std::cin.clear(); // Clear error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Invalid input. Please enter a number: ";
    }
    // Clear input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return option;
}

// Process user-selected option
void CommandLine::processOption(int option) {
    switch (option) {
        case 1:
            // Add task command
            exampleTask->showTask();
            m_list.addTask(0, std::move(exampleTask));
            break;
        case 2:
            // Remove task command
            std::cout << "Removing a task...\n";
            // Call a method to handle removing a task
            break;
        case 3:
            // Show all tasks command
            std::cout << "Showing all tasks...\n";
            // Call a method to handle showing all tasks
            break;
        case 4:
            // Set task complete command
            std::cout << "Setting task as complete...\n";
            // Call a method to handle setting a task as complete
            break;
        case 5:
            // Exit command
            std::cout << "Exiting...\n";
            // Call a method to exit the program
            exit(0);
        default:
            // Invalid option
            std::cout << "Invalid option. Please try again.\n";
    }
}