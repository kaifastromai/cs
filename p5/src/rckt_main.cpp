#include <thread>
#include <chrono>
#include <ctime>
#include "../include/rocket.h"
#include "../include/streamer.h"
#include "../include/palm_tree.h"
#include "../include/fleet.h"
#include "../include/sparkler.h"

using namespace std;

/*	frand() - this function returns a floating point value chosen
	at random in the range of -0.5 to 0.5. It can be used to perturb
	constant values.

	For example, if you want values near 4 you can do this:
	4 + frand()

	This will return in values from 3.5 to 4.5.
*/

float frand()
{
	return float(rand()) / float(RAND_MAX) - 0.5f;
}

/*	main()

	The program currently offers no means of termination other than CNTRL-c.
*/

int main(int argc, char *argv[])
{
	initscr();
	float initial_up_force = 4.0;
	srand((unsigned int)time(nullptr));
	Fleet fleet;

	/*	If argv[1] is given, it is taken to be a value for the initial
		up force given to a rocket. The default up force is 4 in this
		program. If your terminal window is short, use a smaller number.
		If your terminal window is very tall, try a larger number.
	*/
	if (argc > 1)
	{
		initial_up_force = stof(argv[1]);
	}

	Rocket r;
	Sparkler s;
	Streamer strm;
	//Setup ofstream for output logging:
	ofstream log;
	log.open("log.txt");
	Rocket::SetLog(&log);

	curs_set(0);
	/*	Gravity is the pervasive down force and is constant for all
		rockets. Because it is the same for all rockets, it is declared
		as a static. Rocket::SetGravity() is likewise a static method
		within Rocket.
	*/
	Rocket::SetGravity(-0.1);

	/*	A Fleet object manages (and hides the details of) the collection
		of Rockets. The flow here is:
		- Possibly make new rockets
		- Advance the simulation for each currently defined rocket. Note
		  that if the given rocket is one which explodes creating subrockets,
		  it is done within the Step() function.
		- Draw each rocket.
		- Eliminate rockets that have aged out.
	*/
	int frame = 0;
	while (true)
	{
		//erase();
		/* fleet.Birth(initial_up_force);
		fleet.Step();
		fleet.Draw();
		fleet.Cull(); */
		box(stdscr, 0, 0);
		mvaddstr(0, 1, " RETRO FIREWORKS ");
		//r.Draw();
		//r.Step();
		//s.Draw();
		//s.Step();
		strm.Draw();
		r.SetFrame(frame);
		refresh();
		frame++;
		stringstream ss;
		ss << 23.676768f << endl;
		*Rocket::log<<ss.str()<<endl;
		this_thread::sleep_for(chrono::milliseconds(100));
	}
	curs_set(1);
	endwin();

	return 0;
}