#ifndef TODOLIST_TASK_H
#define TODOLIST_TASK_H

#include <iostream>

class Task {
public:
    Task() = default;
    explicit Task(std::string name, std::string desc) : m_name(std::move(name)), m_description(std::move(desc)) {}
    void showTask();

    void setDueDate(std::string date) { m_dueDate = std::move(date); }

    std::string getDueDate() { return m_dueDate; }
    bool isCompleted() { return completed; }
private:
    std::string m_description{"EMPTY TASK"};
    std::string m_name{"noName"};
    std::string m_dueDate{"noDueDate"};
    bool completed {false};
};


#endif //TODOLIST_TASK_H
