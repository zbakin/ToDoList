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

void ToDoList::extractToFile(const std::string& filename) {
    if (!m_tasks.empty()) {
        std::ofstream myFile(filename);
        if (myFile.is_open())
        {
            for(const auto& task : m_tasks) {
                myFile << "Task " << task->getTaskId() << ": Name: " << task->getTaskName() << " Description: " << task->getDesc() << "\n";
            }
            myFile.close();
        }
    }
}

void ToDoList::showAllTasks() {
    for(auto& task : m_tasks) {
        task->showTask();
    }
}