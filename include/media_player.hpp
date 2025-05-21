/**
 * @file media_player.hpp
 * @brief Header file defining the MediaPlayer, Play, Pause, and Stop states.
 * 
 * @author Michele Di Lecce
 * @year 2025
 * @contact michele.dilecce@hotmail.com
 */

#ifndef MEDIA_PLAYER_HPP
#define MEDIA_PLAYER_HPP

#include <vector>
#include <random> 
#include "power_state.hpp"

/**
 * @class MediaPlayer
 * @brief Abstract base class for media player states.
 */
class MediaPlayer : public PowerOn { 
    public:
        MediaPlayer();

        /**
         * @brief Handle an event and transition to the next state.
         * @param event The event to handle.
         * @return The next state.
         */
        virtual const std::shared_ptr<State> handleEvent(Events event) = 0; // Fixed signature and return type

    protected:
        std::string speaker; ///< String representing the speaker output.
};

/**
 * @class Play
 * @brief Represents the "Play" state.
 */
class Play : public MediaPlayer {
    public:
        Play();

        /**
         * @brief Get the singleton instance of the Play state.
         * @return The singleton instance.
         */
        const static std::shared_ptr<State> getIstance();

        const std::shared_ptr<State> handleEvent(Events event) override; // Fixed signature and return type
        void stateRun();;
};

/**
 * @class Pause
 * @brief Represents the "Pause" state.
 */
class Pause : public MediaPlayer {
    public:
        Pause();

        void init();

        const static std::shared_ptr<State> getIstance();

        const std::shared_ptr<State> handleEvent(Events event) override; // Fixed signature and return type
        void stateRun();; // Added implementation declaration
};

/**
 * @class Stop
 * @brief Represents the "Stop" state.
 */
class Stop : public MediaPlayer {
    public:
        Stop();
        
        const static std::shared_ptr<State> getIstance();

        const std::shared_ptr<State> handleEvent(Events event) override; // Fixed signature and return type
        void stateRun();; // Added implementation declaration
};

#endif // MEDIA_PLAYER_HPP