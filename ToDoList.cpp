#include "ToDoList.h"

size_t ToDoList::getSize() {
    m_size = m_tasks.size();
    return m_size;
}

void ToDoList::addTask(size_t id, Task theTask) {
    theTask.setTaskId(id);
    m_tasks.emplace_back(theTask);
}
