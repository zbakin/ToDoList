#include "ToDoList.h"

ToDoList::ToDoList(const std::string& pathToFile) {
    std::ifstream csvFile(pathToFile);
    if (csvFile.is_open()) {
        std::string line;
        while(getline(csvFile, line)) {
            std::cout << line << std::endl;
        }
        csvFile.close();
    } else {
        std::cerr << "Unable to open file for writing" << std::endl;
    }
    m_tasks.emplace_back();
}

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
        std::ofstream csvFile(filename);
        if (csvFile.is_open()) {
            // Add header
            csvFile << "ID,Task Name,Description,Status\n";
            // Add Tasks
            for(const auto& task : m_tasks) {
                csvFile << task->getTaskId() << "," << task->getTaskName() << "," <<
                task->getDesc() << "," << task->getStatus() << "\n";
            }
            csvFile.close();
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