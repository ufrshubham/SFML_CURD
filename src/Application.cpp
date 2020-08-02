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
#include "TGUI/TGUI.hpp"

#include <iostream>

Application::Application(unsigned int width, unsigned int height, const std::string &title, const std::string &databasePath) : m_window(sf::VideoMode(width, height), title),
                                                                                                                               m_gui(m_window),
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
    else // Might have to move all this into a private method.
    {
        auto childWindow = tgui::ChildWindow::create("Error");
        childWindow->setTitleTextSize(20);
        childWindow->setSize({400, 200});

        auto errorLabel = tgui::Label::create("Error : Failed to open database.");
        errorLabel->setTextSize(20);
        errorLabel->setPosition({((childWindow->getSize().x / 2) - (errorLabel->getSize().x / 2)), ((childWindow->getSize().y / 2) - (70))});
        childWindow->add(errorLabel);

        auto okButton = tgui::Button::create("Okay");
        okButton->setTextSize(20);
        okButton->setPosition({((childWindow->getSize().x / 2) - (okButton->getSize().x / 2)), ((childWindow->getSize().y / 2) - (10))});
        okButton->onClick([this]() {
            this->m_window.close();
        });
        childWindow->add(okButton);

        childWindow->setPosition({((m_gui.getView().getWidth() / 2) - (childWindow->getSize().x / 2)), ((m_gui.getView().getHeight() / 2) - (childWindow->getSize().y / 2))});
        m_gui.add(childWindow);
    }

    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_window.close();
            }
            m_gui.handleEvent(event);
        }

        m_window.clear(sf::Color::Red);
        m_gui.draw();
        m_window.display();
    }
}

void Application::InitUI()
{
    auto listView = tgui::ListView::create();
    listView->addColumn("Todo", 400);
    listView->addColumn("Status", 200);

    const auto &tasks = m_dman.GetAllTasks();
    for (const auto &task : tasks)
    {
        std::vector<tgui::String> taskData(2);
        taskData[0] = task.GetTitle();

        if (task.GetStatus() == TaskStatus::Pending)
        {
            taskData[1] = "Pending";
        }
        else
        {
            taskData[1] = "Completed";
        }

        listView->addItem(taskData);
        listView->setItemHeight(40);
        listView->setTextSize(20);
        listView->setSize({"100 %", "100 %"});
    }

    m_gui.add(listView);
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
