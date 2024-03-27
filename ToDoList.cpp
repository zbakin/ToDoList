#include "ToDoList.h"

size_t ToDoList::getSize() {
    m_size = m_tasks.size();
    return m_size;
}

void ToDoList::addTask(std::unique_ptr<Task> theTask) {
    std::cout << "Adding '" << theTask->getTaskName() << "' to the ToDo list" << std::endl;
    theTask->setTaskId(m_size++);
    m_tasks.emplace_back(std::move(theTask));
}

void ToDoList::extractToCSV(const std::string& filename) const {
    if (!m_tasks.empty()) {
        std::ofstream myFile(filename);
        if (myFile.is_open()) {
            // Add header
            myFile << "ID,Task Name,Description,Status\n";
            // Add Tasks
            for(const auto& task : m_tasks) {
                myFile << task->getTaskId() << "," << task->getTaskName() << "," <<
                task->getDesc() << "," << task->getStatus() << "\n";
            }
            myFile.close();
        } else {
            std::cerr << "Unable to open file for writing" << std::endl;
        }
    }
}

void ToDoList::showAllTasks() {
    for(auto& task : m_tasks) {
        task->showTask();
    }
}