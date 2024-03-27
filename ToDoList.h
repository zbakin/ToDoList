#ifndef TODOLIST_TODOLIST_H
#define TODOLIST_TODOLIST_H

#include <fstream>
#include "Task.h"

class ToDoList {
public:
    ToDoList() = default;
    // create list from a file
    explicit ToDoList(const std::string& pathToFile);

    size_t getSize();

//    std::unique_ptr<Task> getTask(int id) const { return m_tasks[id]; }

//    std::vector<std::unique_ptr<Task>> getTasks() const { return m_tasks; }

    void addTask(std::unique_ptr<Task> theTask);

    void extractToCSV(const std::string& filename) const;

    void showAllTasks();
private:
    std::vector<std::unique_ptr<Task>> m_tasks{};
    size_t m_size {};
};


#endif //TODOLIST_TODOLIST_H
