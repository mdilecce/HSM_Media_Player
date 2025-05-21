#include "power_state.hpp"
#include "media_player.hpp"

PowerOn::PowerOn() {
    this->msg_ = "System Power On"; // Ensure msg_ is defined in the base class
    this->commands_ = "<Power Off: " + std::string(1, POWER_KEY) + ">"; // Ensure commands_ is defined in the base class
}

const std::shared_ptr<State> PowerOn::getIstance() {
    const static std::shared_ptr<State> poweron = std::make_shared<PowerOn>();
    return poweron;
}

const std::shared_ptr<State> PowerOn::handleEvent(Events event) { // Fix return type
    if (event == POWER_TOGGLE)
        return PowerOff::getIstance();
    else
        return PowerOn::getIstance();
}

void PowerOn::stateRun() {
    // Specific implementation for PowerOn state
}

PowerOff::PowerOff() {
    this->msg_ = "System Power Off"; // Ensure msg_ is defined in the base class
    this->commands_ = "<Power On: " + std::string(1, POWER_KEY) + ">"; // Ensure commands_ is defined in the base class
}

const std::shared_ptr<State> PowerOff::getIstance() {
    const static std::shared_ptr<State> poweroff = std::make_shared<PowerOff>();
    return poweroff;
}

const std::shared_ptr<State> PowerOff::handleEvent(Events event) { // Fix return type
    if (event == POWER_TOGGLE)
        return Stop::getIstance();
    else
        return PowerOff::getIstance();
}

void PowerOff::stateRun() {
    // Specific implementation for PowerOff state
}