/**
 * @file state.hpp
 * @brief Header file defining the base State class.
 * 
 * @author Michele Di Lecce
 * @year 2025
 * @contact michele.dilecce@hotmail.com
 */

#pragma once

#ifndef STATE_HPP
#define STATE_HPP

#include <string>
#include <memory>
#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>

#include "key_config.hpp"

/**
 * @class State
 * @brief Interface Class to manage states in the hyrarchical state machine
 */
class State {
    public:
        State() = default;
        virtual ~State() = default; // Add virtual destructor

        /**
         * @brief Initialize the state.
         */
        virtual void init();

        /**
         * @brief Exit the state.
         */
        virtual void exit();

        /**
         * @brief Handle an event and transition to the next state.
         * @param Events The event to handle.
         * @return The next state.
         */
        virtual const std::shared_ptr<State> handleEvent(Events) = 0;

        /**
         * @brief Run the actions within the state.
         */
        virtual void stateRun() = 0;

    protected:
        std::string msg_ = "";       ///< Message to display for the state.
        std::string commands_ = ""; ///< Command options for the state.
};

#endif
