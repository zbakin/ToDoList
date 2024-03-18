#ifndef TODOLIST_TODOLIST_H
#define TODOLIST_TODOLIST_H

#include <fstream>
#include "Task.h"

class ToDoList {
public:
    ToDoList() {}
    // create list from a file
    ToDoList(const std::string& pathToFile);

    size_t getSize();
    void addTask(std::unique_ptr<Task> theTask);

    void extractToFile(const std::string& filename);

    void showAllTasks();
private:
    std::vector<std::unique_ptr<Task>> m_tasks{};
    size_t m_size {};
};


#endif //TODOLIST_TODOLIST_H
