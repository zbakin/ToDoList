#ifndef TODOLIST_TASK_H
#define TODOLIST_TASK_H

#include <iostream>

class Task {
public:
    Task() = default;
    explicit Task(size_t id, std::string name, std::string desc, bool status) :
                  m_id(id), m_name(std::move(name)), m_description(std::move(desc)), m_status(status) {}
    ~Task() { std::cout << "Calling destructor" << std::endl; }

    // copy
    Task(const Task& other);
    // copy assignment
    Task& operator=(const Task& other);

    void showTask() const;

    void setTaskId(size_t id)               { m_id = id; }
    void setTaskName(std::string name)      { m_name = std::move(name); }
    void setDesc(std::string desc)          { m_description = std::move(desc); }
    void setDueDate(std::string date)       { m_dueDate = std::move(date); }
    void setStatus(bool complete)           { m_status = complete; }

    inline size_t getTaskId() const         { return m_id; }
    inline std::string getTaskName() const  { return m_name; }
    inline std::string getDesc() const      { return m_description; }
    inline std::string getDueDate() const   { return m_dueDate; }
    inline std::string getStatus() const    { return m_status ? "COMPLETED" : "NOT COMPLETED"; }
private:
    std::string m_description{"EMPTY TASK"};
    std::string m_name{"noName"};
    std::string m_dueDate{"noDueDate"};
    size_t m_id{};
    bool m_status {false};
};


#endif //TODOLIST_TASK_H
