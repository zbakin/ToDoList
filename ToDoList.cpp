#include "ToDoList.h"

size_t ToDoList::getSize() {
    m_size = m_tasks.size();
    return m_size;
}

void ToDoList::addTask(size_t id, Task theTask) {
    ++m_size;
    theTask.setTaskId(id);
    m_tasks.emplace_back(std::move(theTask));
}

void ToDoList::extractToFile(const std::string& filename) {
    if (!m_tasks.empty()) {
        // TODO: implement
    }
}
