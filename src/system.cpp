/**
 * @file system.cpp
 * @brief Implementation of the System class to manage state transitions.
 * 
 * @author Michele Di Lecce
 * @year 2025
 * @contact michele.dilecce@hotmail.com
 */

#include "system.hpp"


System::System() {
    // Switch to alternate screen
    std::cout << "\033[?1049h";

    this->currentState_ = PowerOff::getIstance();
    this->currentState_->init();

    this->eventListernerJob = std::thread(&System::systemEvent, this);
    this->systemRunJob = std::thread(&System::systemStatus, this);
}

System::~System() {
    // Switch back to the normal screen
    std::cout << "\033[?1049l";
}

void System::systemEvent() {
    while (true) {
        char input = static_cast<char>(getchar()); // Explicit cast to fix warning

        winsize size;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);

        try {
            // Update the state
            Events event = mapEvents.at(input);
            this->currentState_->exit();
            this->currentState_ = this->currentState_->handleEvent(event);
            this->currentState_->init();
        } catch (const std::out_of_range& e) {
            // Print error message on the last terminal line
            std::cout << "\033[" << size.ws_row - 1 << ";1HError: Invalid input!";
            std::cout.flush();

            sleep(2);

            // Clean the last line by overwriting with spaces
            std::cout << "\033[" << size.ws_row - 1 << ";1H" << std::string(size.ws_col, ' ');
            std::cout.flush();
        }
    }
}

void System::systemStatus() {
    while(true){
        this->currentState_->stateRun();
        sleep(1);
    }
        
}

void System::runJobs(){
    this->eventListernerJob.join();
    this->systemRunJob.join();
}
