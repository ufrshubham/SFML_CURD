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

Application::Application(int argc, char* argv[], unsigned int width, unsigned int height, const std::string &title, const std::string &databasePath) 
    :   app(1, nullptr, title, "com.ufrshubham.todo-plus-plus"),
        m_dman(),
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

    cycfi::elements::window _win(app.name());
    _win.on_close = [this]() { this->app.stop(); };

    cycfi::elements::view view_(_win);

    auto constexpr bkd_color = cycfi::elements::rgba(35, 35, 37, 255);
    auto background = cycfi::elements::box(bkd_color);

    view_.content(
        background
    );

    app.run();
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
