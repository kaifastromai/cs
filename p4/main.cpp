#include <iostream>
#include <ctime>
#include <curses.h>
#include <thread>
#include <chrono>
#include "drop.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    Storm storm;

    srand((unsigned int)time(nullptr));
    initscr();
    curs_set(0);
    while (true)
    {
        erase();
        storm.Birth();
        storm.Draw();
        storm.Cull();
        box(stdscr, 0, 0);
        mvaddstr(0, 0, " Retro Rain ");
        //mvaddstr(11, 20, (to_string(LINES)+",").c_str());
        //mvaddstr(LINES / 2, COLS / 2, (to_string(COLS / 2) + "," + to_string(LINES / 2)).c_str());
        refresh();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    endwin();
    return 0;
}