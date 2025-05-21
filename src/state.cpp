/**
 * @file state.cpp
 * @brief Implementation of the base State class.
 * 
 * @author Michele Di Lecce
 * @year 2025
 * @contact michele.dilecce@hotmail.com
 */

#include "state.hpp"

void State::init() {
    // Clear the alternate screen
    std::cout << "\033[2J";

    // Retrieve terminal dimensions
    winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);

    // Find Center Console
    int mid_row = size.ws_row / 2;
    int mid_col = size.ws_col / 2;

    // Print Info Message
    std::cout << "\033[" << mid_row - 1 << ";" << mid_col - this->msg_.size() / 2 << "H" << this->msg_;

    // Print Commands Options
    std::cout << "\033[" << mid_row + 1 << ";" << mid_col - this->commands_.size() / 2 << "H" << this->commands_;

    // Move Cursor to the End
    std::cout << "\033[" << size.ws_row - 1 << ";1H";

    // Flush the output
    std::cout.flush();
}

void State::exit() {
    // Clear the alternate screen
    std::cout << "\033[2J";
}
