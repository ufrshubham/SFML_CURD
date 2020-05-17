/**
 * @file main.cpp
 * @author Shubham Kamble (ufrshubham@gmail.com)
 * @brief The entry point to this app.
 * @version 0.1
 * @date 2020-05-16
 * 
 * Copyright (c) 2020 Shubham Kamble
 * 
 */

#include <iostream>
#include "DatabaseManager.hpp"
#include "SFML/Graphics.hpp"

int main()
{
    // Sqlite test.
    try
    {
        DatabaseManager dMan;
        dMan.OpenDatabase("sqlite-is-working.db");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    // SFML test.
    sf::RenderWindow window({200,200}, "SFML is working!!!");
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::Blue);
        window.display();
    }
}