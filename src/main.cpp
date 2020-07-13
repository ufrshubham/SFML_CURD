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
        dMan.CreateTable();

        Task task;
        task.SetTitle("Complete this project!!!");
        dMan.AddTask(task);
        auto tasks = dMan.GetAllTasks();

        for (const auto &t : tasks)
        {
            std::cout << t.GetTitle() << std::endl;
            std::cout << (int)t.GetStatus() << "\n";
            std::cout << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

#ifdef SFML_TEST
    // SFML test.
    sf::RenderWindow window({200, 200}, "SFML is working!!!");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::Blue);
        window.display();
    }
#endif
}
