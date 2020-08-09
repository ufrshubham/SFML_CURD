/**
 * @file Task.cpp
 * @author Shubham Kamble (ufrshubham@gmail.com)
 * @brief Method definitions for Task class.
 * @version 0.1
 * @date 2020-05-23
 * 
 * Copyright (c) 2020 Shubham Kamble
 * 
 */

#include "Task.hpp"

Task::Task(int taskID) : m_taskID(taskID), m_title(), m_status(TaskStatus::Pending) {}

Task::~Task() {}

TaskStatus Task::GetStatus() const
{
    return m_status;
}

void Task::SetStatus(const TaskStatus &status)
{
    m_status = status;
}

const std::string &Task::GetTitle() const
{
    return m_title;
}

void Task::SetTitle(const std::string &title)
{
    m_title = title;
}

int Task::GetID() const
{
    return m_taskID;
}