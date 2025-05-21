/**
 * @file system.hpp
 * @brief Header file defining the System class.
 * 
 * @author Michele Di Lecce
 * @year 2025
 * @contact michele.dilecce@hotmail.com
 */

#pragma once

#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <memory>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <thread>

#include "state.hpp"
#include "power_state.hpp"


/**
 * @class System
 * @brief System to manage transition between state.
 */
class System {
    public:
        System();
        ~System();

        /**
         * @brief Handle system events.
         */
        void systemEvent();

        /**
         * @brief Run the routine assoicated with the active state.
         */
        void systemStatus();

        /**
         * @brief Start the jobs
         * 
         */
        void runJobs();

        /**
         * @brief Set the current state of the system.
         * @param newState The new state to set.
         */
        void setCurrentState(const std::shared_ptr<State>& newState) {
            currentState_ = newState;
        }

    private:
        std::shared_ptr<State> currentState_; ///< The current state of the system.
        std::thread eventListernerJob;
        std::thread systemRunJob;
        
};

#endif
