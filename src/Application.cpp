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

Application::Application(unsigned int width, unsigned int height, const std::string& title)
{
    m_window.create(sf::VideoMode(width, height), title);
}

Application::~Application()
{
}

void Application::Run()
{
    // Some test code to see if TGUI works!
    tgui::Gui gui{m_window};
    auto myButton = tgui::Button::create("Hey! Don't press this!!!");

    myButton->setPosition("30%", "30%");
    myButton->onClick([&myButton](){
        myButton->setText("I told you don't press this.\nYou are an idiot.");
    });

    gui.add(myButton);

    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_window.close();
            }
            gui.handleEvent(event);
        }

        m_window.clear(sf::Color::Red);
        gui.draw();
        m_window.display();
    }
}