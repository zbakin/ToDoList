#include "ToDoList.h"

ToDoList::ToDoList(const std::string& pathToFile) {
    std::ifstream csvFile(pathToFile);
    if (csvFile.is_open()) {
        std::string line;
        while(getline(csvFile, line)) {
            if(line.starts_with("ID")) continue;
            addTask(line);
        }
        csvFile.close();
    } else {
        std::cerr << "Unable to open file for writing" << std::endl;
    }
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

void ToDoList::addTask(const std::string& task) {
    static const std::unordered_map<std::string, bool> statusMap = {
            { "COMPLETED",     true  },
            { "NOT COMPLETED", false }
    };
    std::string data;
    std::vector<std::string> task_details{};
    std::stringstream ss(task);
    while(getline(ss, data, ',')) {
        task_details.emplace_back(data);
    }
    std::unique_ptr<Task> newTask =
            std::make_unique<Task>(m_size, task_details[1], task_details[2], statusMap.at(task_details[3]));
    m_tasks.emplace_back(std::move(newTask));
    ++m_size;
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