/**
 * @file DatabaseManager.hpp
 * @author Shubham Kamble (ufrshubham@gmail.com)
 * @brief This file contains class to manager sqlite database in object oriented way.
 * @version 0.1
 * @date 2020-05-16
 * 
 * Copyright (c) 2020 Shubham Kamble
 * 
 */

#pragma once

#include <string>
#include <sqlite3.h>

class DatabaseManager
{
    /**
     * @brief Holds a reference to currently open database.
     * 
     */
    sqlite3* m_dbRef;

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
    void OpenDatabase(const std::string& databaseName);
};