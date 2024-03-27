#include "Task.h"

void Task::showTask() const {
    std::cout << "\n";
    std::cout << "Task " << m_id << ":" << std::endl;
    std::cout << m_name << std::endl;
    std::cout << m_description << std::endl;
    std::cout << "Finish by: " << m_dueDate << std::endl;
    std::string status = m_status ? "Done." : "Not done yet.";
    std::cout << "Status: " << status << std::endl;
}

Task::Task(const Task &other) {
    std::cout << "Calling copy constructor" << std::endl;
    m_description = other.m_description;
    m_name = other.m_name;
    m_id = other.m_id;
    m_dueDate = other.m_dueDate;
    m_status = other.m_status;
}

Task &Task::operator=(const Task &other) {
    if(this != &other) {
        std::cout << "Calling copy assignment operator" << std::endl;
        m_description = other.m_description;
        m_name = other.m_name;
        m_id = other.m_id;
        m_dueDate = other.m_dueDate;
        m_status = other.m_status;
    }
    return *this;
}
