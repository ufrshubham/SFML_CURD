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

Application::Application(unsigned int width, unsigned int height, const std::string &title, const std::string &databasePath) : m_window(sf::VideoMode(width, height), title, sf::Style::Close),
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
        listView->setSize("100%, 100%");
    }

    auto button = tgui::Button::create();
    button->setText("+");
    button->setSize(40, 40);
    button->setPosition("&.width - 70", "&.height - 70");
    button->onClick([this]() {
        this->AddTaskGui();
    });
    m_gui.add(listView);
    m_gui.add(button);
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
    // Major refactoring needed !!!!!
    auto addTaskWindow = tgui::ChildWindow::create("Add new task");
    addTaskWindow->setTextSize(20);
    addTaskWindow->setSize(600, 200);
    addTaskWindow->setPosition(100,100);
    m_gui.add(addTaskWindow);

    auto vLayout = tgui::VerticalLayout::create();
    vLayout->setSize("100%", "100%");

    auto hLayout = tgui::HorizontalLayout::create();
    hLayout->setSize("100%", "80%");

    auto taskTitle = tgui::TextBox::create();
    taskTitle->setDefaultText("Enter task title here");
    auto taskStatus = tgui::CheckBox::create("Completed?");

    hLayout->addSpace(0.2f);
    hLayout->add(taskTitle);
    hLayout->addSpace(0.2f);
    hLayout->add(taskStatus);
    hLayout->addSpace(0.2f);

    taskTitle->setSize("80%", "100%");
    taskStatus->setSize("20%", "100%");

    auto hLayout2 = tgui::HorizontalLayout::create();
    hLayout2->setSize("100%", "20%");

    auto submitButton = tgui::Button::create("Done");
    submitButton->setSize("80%", "20%");

    submitButton->onClick([this, taskStatus, taskTitle, addTaskWindow]() {
        auto task = Task();
        auto tStatus = TaskStatus::Pending;
        if (taskStatus->isChecked())
        {
            tStatus = TaskStatus::Completed;
        }
        if(taskTitle->getText().toUtf8()!=""){
            //i don
            task.SetStatus(tStatus);
            task.SetTitle(taskTitle->getText().toUtf8());

            this->m_dman.AddTask(task);
        }
        
        addTaskWindow->close();
        this->InitUI();
    });

    hLayout2->addSpace(0.5f);
    hLayout2->add(submitButton);
    hLayout2->addSpace(0.5f);

    vLayout->addSpace(0.2f);
    vLayout->add(hLayout);
    vLayout->addSpace(0.5f);
    vLayout->add(hLayout2);
    vLayout->addSpace(0.5f);

    addTaskWindow->add(vLayout);
}