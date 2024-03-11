#include "Task.h"

void Task::showTask() {
    std::cout << "\n\n";
    std::cout << "Task " << m_id << ":" << std::endl;
    std::cout << m_name << std::endl;
    std::cout << m_description << std::endl;
    std::cout << "Finish by: " << m_dueDate << std::endl;
    std::string status = m_completed ? "Done." : "Not done yet.";
    std::cout << "Status: " << status << std::endl;
}