#ifndef TODOLIST_TODOLIST_H
#define TODOLIST_TODOLIST_H

#include <queue>
class ToDoList {
private:
    std::vector<Task> m_tasks;
    std::queue<Task> queueOfTasks;
};


#endif //TODOLIST_TODOLIST_H
