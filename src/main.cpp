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

int main()
{
    try
    {
        DatabaseManager dMan;
        dMan.OpenDatabase("test");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}