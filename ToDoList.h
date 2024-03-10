#ifndef TODOLIST_TODOLIST_H
#define TODOLIST_TODOLIST_H

#include <queue>
#include "Task.h"

class ToDoList {
public:
    size_t getSize();
    void addTask(size_t id, Task theTask);
private:
    std::vector<Task> m_tasks{};
    std::queue<Task> queueOfTasks{};
    size_t m_size {};
};


#endif //TODOLIST_TODOLIST_H
