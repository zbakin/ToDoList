#ifndef TODOLIST_TASK_H
#define TODOLIST_TASK_H

#include <iostream>

class Task {
public:
    Task() = default;
    explicit Task(size_t id, std::string name, std::string desc) :
                  m_id(id), m_name(std::move(name)), m_description(std::move(desc)) {}
    void showTask();

    void setTaskId(size_t id)                  { m_id = id; }
    void setTaskName(std::string name)         { m_name = std::move(name); }
    void setDesc(std::string desc)             { m_description = desc; }
    void setDueDate(std::string date)          { m_dueDate = std::move(date); }

    size_t getTaskId()            { return m_id; }
    std::string getTaskName()     { return m_name; }
    std::string getDesc()         { return m_description; }
    std::string getDueDate()      { return m_dueDate; }
    bool isComplete()             { return completed; }
private:
    std::string m_description{"EMPTY TASK"};
    std::string m_name{"noName"};
    std::string m_dueDate{"noDueDate"};
    size_t m_id{};
    bool completed {false};
};


#endif //TODOLIST_TASK_H
