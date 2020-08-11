/**
 * @file CommonStrings.hpp
 * @author Shubham Kamble (ufrshubham@gmail.com)
 * @brief A commong place to store all the string used in this application.
 * @version 0.1
 * @date 2020-08-11
 * 
 * Copyright (c) 2020 Shubham Kamble
 * 
 */

#pragma once

#include <string>

/**
 * @brief Elements of this enum are used to get the string corresponding to that element.
 *        For this use GetString().
 * 
 */
enum class StrID
{
    APP_TITLE,
    ERROR_WINDOW_TITLE,
    OKAY_BUTTON_TITLE,
    TASK_NAME_COLUMN_TITLE,
    TASK_STATUS_COLUMN_TITLE,
    TASK_PENDING,
    TASK_COMPLETED,
    ADD_TASK_WINDOW_TITLE,
    ADD_TASK_HINT_STR,
    ADD_TASK_COMPLETED_TOGGLE_TITLE,
};

/**
 * @brief Get the corresponding string for given StrID.
 * 
 * @param id StrID to get corresponding string.
 * @return const std::string 
 */
const std::string GetString(StrID id);