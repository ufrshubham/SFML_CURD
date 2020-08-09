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
#include "Application.hpp"

int main()
{
    auto app = Application(800, 400, "SFML-Sqlite Curd", "sqlite-is-working.db");
    app.Run();
}
