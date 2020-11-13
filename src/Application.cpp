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

Application::Application(int argc, char *argv[], float width, float height, const std::string &title, const std::string &databasePath)
    : m_app(1, nullptr, title, "com.ufrshubham.todo-plus-plus"),
      m_width(width),
      m_height(height),
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
}

auto getVTileElements(DatabaseManager &dman)
{
    cycfi::elements::vtile_composite list;

    for (int i = 0; i < 10; ++i)
    {
        auto task = Task(i);
        task.SetTitle("Task" + std::to_string(i));
        dman.AddTask(task);
    }

    for (const auto &task : dman.GetAllTasks())
    {
        list.push_back(cycfi::elements::share(cycfi::elements::top_bottom_margin(cycfi::elements::vmargin_rect(5, 5), cycfi::elements::button(task.GetTitle()))));
    }
    return list;
}

auto getTasks(DatabaseManager &dman)
{
    return cycfi::elements::vscroller(
        getVTileElements(dman));
}

auto makeTableHeaders()
{
    return cycfi::elements::vsize(50,
                                  cycfi::elements::align_center_middle(cycfi::elements::label("Todo Plus Plus").font_size(30)));
}

void Application::InitUI()
{
    using namespace cycfi::elements;

    cycfi::elements::window window(m_app.name(), cycfi::elements::window::style::standard, cycfi::elements::rect{0, 0, m_width, m_height});
    window.on_close = [this]() { this->m_app.stop(); };

    cycfi::elements::view view(window);

    auto constexpr bkd_color = cycfi::elements::rgba(35, 35, 37, 255);
    auto background = cycfi::elements::box(bkd_color);

    view.content(
        cycfi::elements::vtile(makeTableHeaders(), cycfi::elements::vsize(720, getTasks(m_dman))),
        background);

    m_app.run();
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
