/**
 * @file power_state.hpp
 * @brief Header file defining the PowerOn and PowerOff states.
 * 
 * @author Michele Di Lecce
 * @year 2025
 * @contact michele.dilecce@hotmail.com
 */

#ifndef POWER_STATE_HPP
#define POWER_STATE_HPP

#include <memory>
#include "state.hpp"

// Add a forward declaration for MediaPlayer
class MediaPlayer;

/**
 * @class PowerOn
 * @brief Represents the "Power On" state.
 */
class PowerOn : public State {
    public:
        PowerOn();

        /**
         * @brief Get the singleton instance of the PowerOn state.
         * @return The singleton instance.
         */
        const static std::shared_ptr<State> getIstance();

        const std::shared_ptr<State> handleEvent(Events event) override; // Fix return type
        void stateRun() override;
};

/**
 * @class PowerOff
 * @brief Represents the "Power Off" state.
 */
class PowerOff : public State {
    public:
        PowerOff();

        /**
         * @brief Get the singleton instance of the PowerOff state.
         * @return The singleton instance.
         */
        const static std::shared_ptr<State> getIstance();

        const std::shared_ptr<State> handleEvent(Events event) override; // Fix return type
        void stateRun() override;
};

#endif // POWER_STATE_HPP