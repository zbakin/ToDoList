#ifndef TODOLIST_TODOLIST_H
#define TODOLIST_TODOLIST_H

#include <queue>
#include "Task.h"

class ToDoList {
public:
    ToDoList() {}
    // create list from a file
    ToDoList(const std::string& pathToFile);

    size_t getSize();
    void addTask(size_t id, std::unique_ptr<Task> theTask);

    void extractToFile(const std::string& filename);
private:
    std::vector<std::unique_ptr<Task>> m_tasks{};
    std::queue<Task> queueOfTasks{};
    size_t m_size {};
};


#endif //TODOLIST_TODOLIST_H
