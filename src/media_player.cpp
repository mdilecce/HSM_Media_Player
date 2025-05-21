#include "media_player.hpp"

MediaPlayer::MediaPlayer() : PowerOn() {
    this->commands_ += " <Play/Pause: " + std::string(1, PLAY_BUTTON) + ">";
    this->commands_ += " <Stop: " + std::string(1, STOP_BUTTON) + ">";

    std::vector<std::string> pool = {" ", u8"\u2669", u8"\u266A", u8"\u266B", u8"\u266C", u8"\u266D", u8"\u266E"};
    std::string result;
    result.reserve(25);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, pool.size() - 1);
    for (int i = 0; i < 25; ++i) {
        result += pool[dis(gen)];
    }

    this->speaker = result;
}

Play::Play() {
    this->msg_ = "Music Playing";
}

const std::shared_ptr<State> Play::getIstance() {
    const std::shared_ptr<State> play = std::make_shared<Play>();
    return play;
}

const std::shared_ptr<State> Play::handleEvent(Events event) {
    switch (event) {
        case POWER_TOGGLE:
            return PowerOn::getIstance()->handleEvent(event);
        case PLAY_PAUSE:
            return Pause::getIstance();
        case STOP:
            return Stop::getIstance();
        default:
            return Play::getIstance();
    }
}

void Play::stateRun() {
    if (!this->speaker.empty()) {
        // Perform a circular shift: remove the first character and append it to the end.
        char first = this->speaker.front();
        this->speaker.erase(0, 1);
        this->speaker.push_back(first);
        // Retrieve terminal dimensions
        winsize size;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);

        //Find Center Consol
        int mid_row = size.ws_row / 2;
        int mid_col = size.ws_col / 2;

        std::cout << "\033[" << mid_row + 3 << ";1H" << std::string(size.ws_col, ' ');
        //Play music
        std::cout << "\033[" << mid_row + 3 << ";" << mid_col - this->speaker.size() / 2 << "H" << this->speaker;
    }
}

Pause::Pause() {
    this->msg_ = "Music Paused";
}

const std::shared_ptr<State> Pause::getIstance() {
    const std::shared_ptr<State> pause = std::make_shared<Pause>();
    return pause;
}

const std::shared_ptr<State> Pause::handleEvent(Events event) {
    switch (event) {
        case POWER_TOGGLE:
            return PowerOn::getIstance()->handleEvent(event);
        case PLAY_PAUSE:
            return Play::getIstance();
        case STOP:
            return Stop::getIstance();
        default:
            return Pause::getIstance();
    }
}

void Pause::init() {
    this->State::init();

    // Retrieve terminal dimensions
    winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);

    //Find Center Consol
    int mid_row = size.ws_row / 2;
    int mid_col = size.ws_col / 2;

    //Print Info Message
    std::cout << "\033[" << mid_row + 3 << ";" << mid_col - this->speaker.size() / 2 << "H" << this->speaker;
}

void Pause::stateRun() {
    // Specific implementation for Pause state
}

Stop::Stop() {
    this->msg_ = "Music Stopped";
}

const std::shared_ptr<State> Stop::getIstance() {
    const std::shared_ptr<State> stop = std::make_shared<Stop>();
    return stop;
}

const std::shared_ptr<State> Stop::handleEvent(Events event) {
    switch (event) {
        case POWER_TOGGLE:
            return PowerOn::getIstance()->handleEvent(event);
        case PLAY_PAUSE:
            return Play::getIstance();
        default:
            return Stop::getIstance();
    }
}

void Stop::stateRun() {
    // Specific implementation for Stop state
}
