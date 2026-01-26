#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <vector>

// ===== TERMINAL CONTROL =====
void clearScreen() {
    std::cout << "\033[2J\033[H";
}

// ===== UTILS =====
int randRange(int min, int max) {
    return min + rand() % (max - min + 1);
}

// ===== MAIN =====
int main() {
    // Fix buffering so output appears immediately
    std::ios::sync_with_stdio(false);
    std::cout.setf(std::ios::unitbuf);

    srand(time(nullptr));

    const std::string YELLOW = "\033[33m";
    const std::string RED    = "\033[31m";
    const std::string RESET  = "\033[0m";

    std::vector<std::string> statusMsgs = {
        "sending probe packets",
        "awaiting network response",
        "retrying ping",
        "re-establishing session",
        "verifying route stability",
        "monitoring signal integrity"
    };

    clearScreen();

    std::string number;
    std::cout << "Enter target phone number: ";
    std::cin >> number;

    const int barWidth = 40;
    int statusIndex = randRange(0, statusMsgs.size() - 1);

    for (int percent = 0; percent <= 100; percent++) {
        clearScreen();

        // header
        std::cout << YELLOW
                  << "Passive network ping in progress\n"
                  << "Target: " << number << "\n\n"
                  << RESET;

        // status text ABOVE the bar
        std::cout << "[STATUS] " << statusMsgs[statusIndex] << "\n\n";

        // progress bar
        int filled = percent * barWidth / 100;
        std::cout << "[";
        for (int i = 0; i < barWidth; i++) {
            if (i < filled) std::cout << "#";
            else std::cout << "-";
        }
        std::cout << "] " << percent << "%\n";

        // rotate status text occasionally
        if (percent % 10 == 0 && percent != 0) {
            statusIndex = randRange(0, statusMsgs.size() - 1);
        }

        // ===== pacing (slow + realistic) =====
        if (percent < 70) {
            std::this_thread::sleep_for(
                std::chrono::milliseconds(randRange(600, 1000))
            );
        }
        else if (percent < 90) {
            std::this_thread::sleep_for(
                std::chrono::milliseconds(randRange(1000, 1300))
            );
        }
        else if (percent < 98) {
            std::this_thread::sleep_for(
                std::chrono::milliseconds(randRange(1500, 1600))
            );
        }
        else if (percent == 98) {
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
        else {
            std::this_thread::sleep_for(std::chrono::milliseconds(1800));
        }
    }

    // final failure
    clearScreen();
    std::cout << RED
              << "Ping failed\n\n"
              << "[ERROR] Session timed out due to sim inactivity. Ping not delivered. sim offline.\n"
              << RESET;

    return 0;
}
