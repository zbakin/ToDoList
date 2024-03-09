//
// Created by Zhanibek's Mac on 09/03/2024.
//

#ifndef TODOLIST_TASK_H
#define TODOLIST_TASK_H

#include <iostream>

class Task {
public:
    Task() = default;
    explicit Task(std::string name, std::string desc) : m_name(std::move(name)), m_description(std::move(desc)) {}
    void showTask();
private:
    std::string m_description{"EMPTY TASK"};
    std::string m_name{"noName"};
};


#endif //TODOLIST_TASK_H
