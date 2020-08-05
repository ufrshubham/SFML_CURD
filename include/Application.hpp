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
#include "TGUI/TGUI.hpp"
#include "DatabaseManager.hpp"

class Application
{
    /**
     * @brief This is the main render window of this application.
     * 
     */
    sf::RenderWindow m_window;

    /**
     * @brief The UI object to handle all TGUI widgets and their events.
     * 
     */
    tgui::Gui m_gui;

    /**
     * @brief The database manager.
     * 
     */
    DatabaseManager m_dman;

    /**
     * @brief Path to currently opened database. Not sure if this is really needed.
     * 
     */
    std::string m_databasePath;

    /**
     * @brief Initilizes the UI and TGUI widgets.
     * 
     */
    void InitUI();

    /**
     * @brief Opens the database file using m_databasePath. Make sure to check for the returned status.
     *        If any error occues during opening the database, DatabaseStatus::FAILED will be returned.
     * 
     * @return DatabaseStatus 
     */
    DatabaseStatus InitDB();

    void AddTaskGui();

public:

    /**
     * @brief Construct a new Application object
     * 
     * @param width Initial window width for this application.
     * @param height Initial window height for this application.
     * @param title Title for this application.
     * @param databasePath Full path to the database file to be opened. Will be created if not already present.
     */
    Application(unsigned int width, unsigned int height, const std::string &title, const std::string &databasePath);

    /**
     * @brief Destroy the Application object
     * 
     */
    ~Application();

    /**
     * @brief Starts the application by displaying the application window and listening for events.
     * 
     */
    void Run();
};
