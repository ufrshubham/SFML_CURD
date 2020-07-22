/**
 * @file DatabaseManager.hpp
 * @author Shubham Kamble (ufrshubham@gmail.com)
 * @brief This file contains class to manage sqlite database in an object oriented way.
 * @version 0.1
 * @date 2020-05-16
 * 
 * Copyright (c) 2020 Shubham Kamble
 * 
 */

#pragma once

#include <string>
#include <vector>
#include <sqlite3.h>

#include "Task.hpp"

class DatabaseManager
{
    /**
     * @brief Holds a reference to currently open database.
     * 
     */
    sqlite3 *m_dbRef;

public:
    /**
     * @brief Construct a new Database Manager object
     * 
     */
    DatabaseManager();

    /**
     * @brief Destroy the Database Manager object
     *        Will close any open database connections.
     */
    ~DatabaseManager();

    /**
     * @brief Opens a databaes connection for the given database name.
     *        Creates a new database if it does not already exist.
     *        Note that this method will throw an runtime exception if
     *        open operation fails.
     * 
     * @param databaseName Name of database file.
     */
    void OpenDatabase(const std::string &databaseName);

    /**
     * @brief Creates the todo table if it is not already present.
     *        Will throw a runtime exception if called before OpenDatabase(const std::string& databaseName).
     *        Will throw a runtime exception if any database failure occurs.
     */
    void CreateTable();

    /**
     * @brief Adds the given task to Todo table of currently opened database.
     *        Will throw a runtime exception if not database connection exists.
     *        Will throw a runtime exception if any database failure occurs.
     * 
     * @param task Task to be added.
     */
    void AddTask(const Task &task);

    /**
     * @brief Get the All Tasks from Todo table.
     *        Will return an empty array if called before table is initialized.
     * 
     * @return std::vector<Task> 
     */
    std::vector<Task> GetAllTasks() const;

    /**
     * @brief Collects task details and fill ptrToTaskVec with it.
     * 
     * @param ptrToTaskVec - void pointer to std::vector<Task>.
     * @param nEntries - number of entries returned by select all sql query.
     * @param entries - array of entries.
     * @param columns - array of column names.
     * @return int 
     */
    static int CollectTasksCallBack(void *ptrToTaskVec, int nEntries, char **entries, char **columns);
};