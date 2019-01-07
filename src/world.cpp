// #include "world.h"
// #include <iostream>

// World::World(Time *wTime, Space *space)
// {
// 	this->wTime = wTime;
// 	this->space = space;
// };

// World::~World()
// {
// 	wTime = NULL;
// 	space = NULL;
// };

// void World::live(int nSteps)
// {
// 	if (isPrintOn)
// 	{
// 		printf("Initialization:\n");
// 		printf("\t--- Mesh (energy total: %lf) ---\n",
// 			   space->get_total_energy_value());
// 		space->print_mesh();
// 		printf("\n");
// 		printf("\t--- Plant ---\n");
// 		plant->printInfo();
// 	}

// 	for (int i = 0; i < nSteps; ++i)
// 	{

// 		space->step();
// 		plant->step();

// 		if (isPrintOn)
// 		{
// 			printf("\n");
// 			printf("\t###### Step %d/%d ######\n", i + 1, nSteps);
// 			printf("\t--- Mesh (energy total: %lf) ---\n",
// 				   space->get_total_energy_value());
// 			space->print_mesh();
// 			printf("\n");
// 			printf("\t--- Plant ---\n");
// 			plant->printInfo();
// 		}
// 	}
// }

// void World::printOn()
// {
// 	isPrintOn = 1;
// }

// void World::printOff()
// {
// 	isPrintOn = 0;
// }
