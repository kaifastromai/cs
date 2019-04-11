#include <chrono>
#include <thread>
#include "curses.h"
#include "../include/rocket.h"
using namespace std;
int main(int argc, char **argv)
{
	Rocket r;
	ofstream log_file;
	log_file.open("./output/log.txt");
	r.SetLogFile(&log_file);
	log_file << "First output" << endl;
	log_file.close();

	srand((unsigned int)time(nullptr));
	initscr();
	curs_set(0);
	while (true)
	{
		erase();
		box(stdscr, 0, 0);
		mvaddstr(0, 0, "Rockets!");
		refresh();
		this_thread::sleep_for(chrono::milliseconds(100));
	}
	endwin();
	return 0;
}