/**
 * @file CommonStrings.cpp
 * @author Shubham Kamble (ufrshubham@gmail.com)
 * @brief Define all your string IDs and strings to be showing in UI.
 * @version 0.1
 * @date 2020-08-11
 * 
 * Copyright (c) 2020 Shubham Kamble
 * 
 */

#include "CommonStrings.hpp"
#include <map>

static const std::map<StrID, std::string> stringIdMap = {
    {StrID::APP_TITLE, "To-Do Manager"},
    {StrID::ERROR_WINDOW_TITLE, "Error"},
    {StrID::OKAY_BUTTON_TITLE, "Okay"},
    {StrID::TASK_NAME_COLUMN_TITLE, "Task Name"},
    {StrID::TASK_STATUS_COLUMN_TITLE, "Status"},
    {StrID::TASK_PENDING, "Pending"},
    {StrID::TASK_COMPLETED, "Completed"},
    {StrID::ADD_TASK_WINDOW_TITLE, "Add New Task"},
    {StrID::ADD_TASK_HINT_STR, "Enter task title here"},
    {StrID::ADD_TASK_COMPLETED_TOGGLE_TITLE, "Completed?"},
};

const std::string GetString(StrID id)
{
    return stringIdMap.at(id);
}