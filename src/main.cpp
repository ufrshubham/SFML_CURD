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
#include "CommonStrings.hpp"

int main(int argc, char* argv[])
{
    auto app = Application(argc, argv, 800, 400, GetString(StrID::APP_TITLE), "sqlite-is-working.db");
    app.Run();
}
