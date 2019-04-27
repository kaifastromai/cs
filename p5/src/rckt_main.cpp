#include <thread>
#include <chrono>
#include <ctime>
#include "../include/rocket.h"
#include "../include/streamer.h"
#include "../include/palm_tree.h"
#include "../include/fleet.h"
#include "../include/sparkler.h"
#include "../include/util.storm.h"
#include <getopt.h>
#include "../include/grid.h"
#include "../include/finale.h"

#include <cmath>

using namespace std;

/*	frand() - this function returns a floating point value chosen
	at random in the range of -0.5 to 0.5. It can be used to perturb
	constant values.

	For example, if you want values near 4 you can do this:
	4 + frand()

	This will return in values from 3.5 to 4.5.
*/

/*	main()

	The program currently offers no Pmeans of termination other than CNTRL-c.
*/
int main(int argc, char *argv[])
{
	bool is_finale = false;
	//Open our log file before anything else--Or else segmantation fault!
	Rocket r;
	ofstream log;
	log.open("log1.txt");
	Rocket::SetLog(&log);
	int opt;
	while ((opt = getopt(argc, argv, "df")) != -1)
	{
		switch (opt)
		{
		case 'd':
		{
			Rocket::IS_DEBUG_MODE = true;
			Rocket::Log("Debug mode is active");
			break;
		}
		case 'f':
		{
			is_finale = true;
			Rocket::Log("Finale has been activated!");
			break;
		}
		default: /* '?' */
			fprintf(stderr, "Usage: %s [-d for debug mode]\n",
					argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	/* for (; optind < argc; optind++)
	{
		*Rocket::log << argv[optind] << endl;
	} */

	initscr();
	//Colors! Must be predefined
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	float initial_up_force = 3.0;
	srand((unsigned int)time(nullptr));
	//Fleet fleet;
	/*	If argv[1] is given, it is taken to be a value for the initial
		up force given to a rocket. The default up force is 4 in this
		program. If your terminal window is short, use a smaller number.
		If your terminal window is very tall, try a larger number.

	*/
	if (argc > 1) //Checking argc and consuming arguments
	{
		if (optind <= 3 && optind >= 1)
		{
			if (argv[optind] != nullptr)
			{
				string str(argv[optind]);

				try
				{
					if (!csl::utils::safe_string_to_float(str, initial_up_force))
					{
						throw runtime_error("Did not manage to convert to float");
					}
					else
					{

						Rocket::Log("23 and me is the best: ", 5, " in the world!");
					}
				}
				catch (runtime_error &e)
				{
					Rocket::Log(e.what());
				}
			}
		}
		else
		{
			*Rocket::log << "Wrong command line arguments!:" << optind << endl;
		}
	}

	curs_set(0);
	/*	Gravity is the pervasive down force and is constant for all
		rockets. Because it is the same for all rockets, it is declared
		as a static. Rocket::SetGravity() is likewise a static method
		within Rocket.
	*/
	Rocket::SetGravity(-0.2);

	/*	A Fleet object manages (and hides the details of) the collection
		of Rockets. The flow here is:
		- Possibly make new rockets
		- Advance the simulation for each currently defined rocket. Note
		  that if the given rocket is one which explodes creating subrockets,
		  it is done within the Step() function.
		- Draw each rocket.
		- Eliminate rockets that have aged out.
	*/

	/* Fleet flt;
	Finale f; */
	std::deque<Rocket *> t_dq;

	int frame = 0;
	for (int k = 0; k < 12; k++)
	{
		int offsetx = csl::utils::Jiggle<int>(COLS / 2, 100);
		int offsety = csl::utils::Jiggle<int>(LINES / 2, 100);
		MagnetRocket *mr = new MagnetRocket(Vector(offsetx, offsety), Vector(0.0, 0.0));
		mr->mass = 1;
		t_dq.push_back(mr);
	}

	while (true)
	{
		erase();
		/* if (!is_finale)
		{
			flt.Run(12, initial_up_force);
		} */
		//f.Run();
		attron(COLOR_PAIR(4));
		box(stdscr, 0, 0);
		mvaddstr(0, 1, " RETRO FIREWORKS ");
		/* for (auto mr : t_dq)
		{
			mr->Draw();
			mr->Step(t_dq);
			csl::physics::attract_to_location(Vector(COLS / 2, LINES / 2), (MagnetRocket *)mr);

		} */
		Vector a(0.02, 0.02);
		Vector b(0.04, 0.04);
		if (a == b)
		{
			Rocket::Log("They are equal!");
		}

		//Rocket::Log("Position: ", (string)mr.position, " Force: ", (string)mr.force);
		//Increment frame as simulation increases. Mostly for debugging purposes.
		Rocket::SetFrame(frame);
		frame++;
		this_thread::sleep_for(chrono::milliseconds(40));

		refresh();
	}
	curs_set(1);
	endwin();

	return 0;
}