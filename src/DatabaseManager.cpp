/**
 * @file DatabaseManager.cpp
 * @author Shubham Kamble (ufrshubham@gmail.com)
 * @brief Method definitions for DatabaseManager class.
 * @version 0.1
 * @date 2020-05-16
 * 
 * Copyright (c) 2020 Shubham Kamble
 * 
 */

#include "DatabaseManager.hpp"
#include <stdexcept>

DatabaseManager::DatabaseManager() : m_dbRef(nullptr) {}

DatabaseManager::~DatabaseManager()
{
    sqlite3_close(m_dbRef);
}

void DatabaseManager::OpenDatabase(const std::string &databaseName)
{
    sqlite3 *ptr = nullptr;
    sqlite3_open(databaseName.c_str(), &ptr);

    if (!ptr)
    {
        throw std::runtime_error("Failed to open " + databaseName);
    }
}
