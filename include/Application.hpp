/**
 * @file Application.hpp
 * @author Shubham Kamble (ufrshubham@gmail.com)
 * @brief This file contains the Application class, which can create a window and handle inputs.
 * @version 0.1
 * @date 2020-07-22
 * 
 * Copyright (c) 2020 Shubham Kamble
 * 
 */

#pragma once

#include "SFML/Graphics.hpp"

class Application
{
    sf::RenderWindow m_window;
public:
    Application(unsigned int width, unsigned int height, const std::string& title);
    ~Application();

    void Run();
};
