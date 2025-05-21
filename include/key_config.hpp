/**
 * @file key_config.hpp
 * @brief Configuration file for key bindings and event mappings.
 * 
 * @author Michele Di Lecce
 * @year 2025
 * @contact michele.dilecce@hotmail.com
 */

#pragma once

#if __has_include("key_binding.h")
    #include "key_binding.h"
#endif

#include <map>

#ifndef POWER_KEY
#define POWER_KEY 's'
#endif

#ifndef PLAY_BUTTON
#define PLAY_BUTTON 'd'
#endif

#ifndef STOP_BUTTON
#define STOP_BUTTON 'f'
#endif

enum Events {
    POWER_TOGGLE,
    PLAY_PAUSE,
    STOP
};

static const std::map<char, Events> mapEvents{
    {POWER_KEY, POWER_TOGGLE},
    {PLAY_BUTTON, PLAY_PAUSE},
    {STOP_BUTTON, STOP},
};