#include "Task.h"

void Task::showTask() {
    std::cout << "Task " << m_name << "." << std::endl;
    std::cout << m_description << std::endl;
}