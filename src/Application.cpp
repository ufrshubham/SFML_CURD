/**
 * @file Application.cpp
 * @author Shubham Kamble (ufrshubham@gmail.com)
 * @brief This file contains the method definitions for Application class.
 * @version 0.1
 * @date 2020-07-22
 * 
 * Copyright (c) 2020 Shubham Kamble
 * 
 */

#include "Application.hpp"
#include "CommonStrings.hpp"

#include <iostream>

Application::Application(unsigned int width, unsigned int height, const std::string &title, const std::string &databasePath) : m_dman(),
                                                                                                                               m_databasePath(databasePath)
{
}

Application::~Application()
{
}

void Application::Run()
{
    if (InitDB() == DatabaseStatus::OPEN)
    {
        InitUI();
    }
    else // Might have to move all this into a private method.
    {
    }
}

void Application::InitUI()
{
}

DatabaseStatus Application::InitDB()
{
    DatabaseStatus status = DatabaseStatus::CLOSE;

    try
    {
        m_dman.OpenDatabase(m_databasePath);
        m_dman.CreateTable();
        status = DatabaseStatus::OPEN;
    }
    catch (const std::exception &e)
    {
        status = DatabaseStatus::CLOSE;
        std::cerr << e.what() << '\n';
    }

    return status;
}

void Application::AddTaskGui()
{
}

void Application::DeleteSelected()
{
}
