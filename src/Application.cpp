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
#include <elements.hpp>

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
    using namespace cycfi::elements;

    app _app(0, nullptr, "Todo Plus Plus", "com.ufrshubham.todo-plus-plus");
    window _win(_app.name());
    _win.on_close = [&_app]() { _app.stop(); };

    view view_(_win);

    view_.content(
       scroller(image{ "space.jpg" })
    );

    _app.run();
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
