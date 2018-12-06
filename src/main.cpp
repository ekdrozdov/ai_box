#include <iostream>
//#include "world.h"
#include "tester.h"
#include "energy_container.h"
//#include "mesh_2d.h"

int main(int argc, char **argv)
{
	if (!Tester::run_all_tests())
	{
		std::cout << "Some unit tests wasn't passed, exit with failure" << std::endl;
		return EXIT_FAILURE;
	}

	Energy_container ec;
	//Mesh_2d_configuration config = Mesh_2d_configuration("mesh_config.txt");
	//Mesh_2d mesh = Mesh_2d(config);

	// Space space = Space(7, 7);
	// Time wTime = Time(1.0);
	// World world = World(&wTime, &space);

	// world.space->addEnergyToNode(3, 3, 1000.0);

	// Organism plant = Organism(50.0, 5, 5, &space);
	// world.plant = &plant;

	// int nStepsToLive;
	// std::cout << "Enter number of steps to live" << std::endl;
	// std::cin >> nStepsToLive;
	// world.live(nStepsToLive);

	return 0;
}
