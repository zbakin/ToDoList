#include <iostream>
#include <string>

class CommandLine {
public:
    // Method to start the command line interface
    void start() {
        while (true) {
            displayOptions();
            int option = getUserInput();
            processOption(option);
        }
    }

private:
    // Method to display available options
    void displayOptions() {
        std::cout << "Options:\n";
        std::cout << "1. Add task\n";
        std::cout << "2. Remove task\n";
        std::cout << "3. Show all tasks\n";
        std::cout << "4. Set task as complete\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter option number: ";
    }

    // Method to get user input as an integer
    int getUserInput() {
        int option;
        std::cin >> option;
        // Clear input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return option;
    }

    // Method to process user-selected option
    void processOption(int option) {
        switch (option) {
            case 1:
                // Add task command
                std::cout << "Adding a new task...\n";
                // Call a method to handle adding a task
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
};