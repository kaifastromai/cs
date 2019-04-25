#pragma once
#include "../include/rocket.h"
#include "../include/streamer.h"
#include "../include/palm_tree.h"
#include "../include/finale.h"
#include <deque>

class Fleet
{

public:
	/*This runs the birth(),Step(),Draw(),Cull() loop, with the probability of birth a new Rocket
	represented by chanceAtBirth, (float from 0-100). It also takes in initial_up_force to pass
	into the birth function
	*/
	void Run(float chance_at_birth, float initial_up_force);
	inline static float g = -0.2f;
	//An enum for the possible types of rockets

	/*	Cull() is responsible for removing Rockets whose age has risen to
		the age limit specified in the Factory method.
	*/
	void Cull();

	/*	Birth() is responsible for spawning new Rockets. The implementation
		details are all hidden within Birth(). Birth() calls the Factory 
		method which does the actual birthing.

		Rockets are dynamically allocated. Therefore must be freed when culled.
	*/
	void Birth(float initial_up_force);

	/*	Step() advances the simulation for the entire Fleet. Each Rocket's own
		Step() function is called in turn. It is in the Rocket's Step() function that the physics are progressed, age increased and perhaps the Rocket will Trigger() causing an explosion of subrockets to be made.
	*/
	void Step();

	/*	Draw() causes each Rocket Draw() method to be called.
	*/
	void Draw();

public:
	/*	This may be your first Design Pattern. It implements the Factory pattern.
		https://www.geeksforgeeks.org/design-patterns-set-2-factory-method/

		A Factory method is a good choice here because one of a number of Rocket
		subclasses are to be made. The Factory hides how the choice of subclass is
		made and also how the newly made instances are initialized.
	*/
	Rocket *RocketFactory(float initial_up_force);

	/*	This is the collection of Rockets belonging to the Fleet. These are pointers
		to Rockets which can actually be one of several subclasses. Because they are
		all subclasses of Rocket, they can live on the same vector and be called / used
		in the same way.
	*/
	std::deque<Rocket *> rockets;
};