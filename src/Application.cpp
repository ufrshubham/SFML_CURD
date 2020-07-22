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

Application::Application(unsigned int width, unsigned int height, const std::string& title)
{
    m_window.create(sf::VideoMode(width, height), title);
}

Application::~Application()
{
}

void Application::Run()
{
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_window.close();
            }
        }

        m_window.clear(sf::Color::Red);
        m_window.display();
    }
}