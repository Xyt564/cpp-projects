#include <ncurses.h>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <string>

// ===== UTILS =====
std::string randomHex(int len) {
    std::stringstream ss;
    for (int i = 0; i < len; i++)
        ss << std::hex << (rand() % 16);
    return ss.str();
}

// ===== HEX POPUP =====
void showHexPopup() {
    int h = 14, w = 60;
    int y = (LINES - h) / 2;
    int x = (COLS - w) / 2;

    WINDOW* win = newwin(h, w, y, x);
    box(win, 0, 0);
    keypad(win, true);

    const char spinner[] = "|/-\\";
    int spin = 0;

    for (int progress = 0; progress <= 100; progress++) {
        werase(win);
        box(win, 0, 0);

        mvwprintw(win, 1, 2, "SECURE EXECUTION ENVIRONMENT");
        mvwprintw(win, 2, 2, "Attempting to decrypt carrier modules %c", spinner[spin++ % 4]);

        // hex stream
        for (int i = 0; i < 6; i++) {
            mvwprintw(
                win,
                4 + i,
                2,
                "0x%s  0x%s  0x%s",
                randomHex(8).c_str(),
                randomHex(8).c_str(),
                randomHex(8).c_str()
            );
        }

        // progress bar
        mvwprintw(win, 11, 2, "[");
        int filled = progress * 40 / 100;
        for (int i = 0; i < 40; i++)
            waddch(win, i < filled ? '#' : '-');
        waddch(win, ']');

        mvwprintw(win, 12, 2, "Execution progress: %d%%", progress);

        wrefresh(win);

        // pacing
        if (progress < 70)
            std::this_thread::sleep_for(std::chrono::milliseconds(120));
        else if (progress < 90)
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
        else if (progress < 98)
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
        else
            std::this_thread::sleep_for(std::chrono::milliseconds(900));
    }

    mvwprintw(win, 12, 2, "Execution complete. Closing environment...");
    wrefresh(win);
    std::this_thread::sleep_for(std::chrono::seconds(2));

    delwin(win);
    clear();
    refresh();
}

// ===== MAIN =====
int main() {
    srand(time(nullptr));

    initscr();
    noecho();
    curs_set(0);
    cbreak();

    char target[64];
    mvprintw(2, 2, "Enter SIM / MSISDN target: ");
    getstr(target);

    clear();

    const char spinner[] = "|/-\\";
    int spin = 0;

    // main processing phase
    for (int i = 0; i < 20; i++) {
        clear();
        mvprintw(2, 2, "=== SIM SIGNAL LOCATOR ===");
        mvprintw(4, 2, "Target: %s", target);
        mvprintw(6, 2, "Scanning carrier spectrum %c", spinner[spin++ % 4]);
        mvprintw(8, 2, "RSSI: %d dBm", -110 + rand() % 30);
        mvprintw(9, 2, "Tower sync drift: %d ms", rand() % 42);
        refresh();

        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    // popup execution
    showHexPopup();

    // post-popup processing
    for (int i = 0; i < 12; i++) {
        clear();
        mvprintw(2, 2, "=== SIM SIGNAL LOCATOR ===");
        mvprintw(4, 2, "Target: %s", target);
        mvprintw(6, 2, "Estimating signal location %c", spinner[spin++ % 4]);
        mvprintw(8, 2, "Estimated lock confidence: %d%%", 88 + rand() % 5);
        refresh();

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    // final failure
    clear();
    mvprintw(2, 2, "=== SIM SIGNAL LOCATOR ===");
    mvprintw(5, 2, "ERROR: Ping not sent.");
    mvprintw(6, 2, "ERROR: Number unavailable");
    mvprintw(8, 2, "Process terminated.");
    refresh();

    std::this_thread::sleep_for(std::chrono::seconds(4));
    endwin();
    return 0;
}
