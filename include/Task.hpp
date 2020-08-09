/**
 * @file Task.hpp
 * @author Shubham Kamble (ufrshubham@gmail.com)
 * @brief This file contains the Task class, which represents an
 *        item in the todo list. 
 * @version 0.1
 * @date 2020-05-23
 * 
 * Copyright (c) 2020 Shubham Kamble
 * 
 */

#pragma once

#include <string>

/**
 * @brief Represents status of tasks.
 * 
 */
enum class TaskStatus
{
    Pending = 0,
    Completed = 1
};

class Task
{
    int m_taskID;
    std::string m_title;
    TaskStatus m_status;

public:
    
    /**
     * @brief Construct a new Task object
     * 
     * @param taskID 
     */
    Task(int taskID);

    /**
     * @brief Destroy the Task object
     * 
     */
    ~Task();

    /**
     * @brief Get the Status of this task.
     * 
     * @return TaskStatus 
     */
    TaskStatus GetStatus() const;

    /**
     * @brief Set the Status of this task.
     * 
     * @param status to set.
     */
    void SetStatus(const TaskStatus &status);

    /**
     * @brief Get the Title of this task.
     * 
     * @return const std::string& 
     */
    const std::string &GetTitle() const;

    /**
     * @brief Set the Title of this task.
     * 
     * @param title to set.
     */
    void SetTitle(const std::string &title);

    /**
     * @brief Returns the unique identifier for this task.
     * 
     * @return int 
     */
    int GetID() const;
};
