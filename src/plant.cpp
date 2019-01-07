// // TODO
// // wrap coordinates in class "Node"
// // some methods of Node:
// // 	node.left(int count);
// // 	node.leftUp(int count);

// #include "organism.h"

// Organism::Organism(double pep, int x, int y, Space *space)
// {
// 	this->space = space;
// 	this->pep = pep - pep * cBornAep;
// 	aep = pep * cBornAep;
// 	wepq = this->pep * cWepq;
// 	state = 0;
// 	repq = 0.0;
// 	lifetime = 0;
// 	this->x = x;
// 	this->y = y;
// }

// Organism::~Organism()
// {
// 	space = NULL;
// }

// void Organism::eat(double availableEnergy)
// {
// 	double energyToEat = pep * cEating;
// 	if (availableEnergy > energyToEat)
// 	{
// 		space->add_energy_to_node(x, y, -energyToEat);
// 		repq = energyToEat;
// 	}
// 	else
// 	{
// 		space->set_energy_in_node(x, y, 0.0);
// 		repq = availableEnergy;
// 	}
// }

// void Organism::disintegration()
// {
// 	double energyToPass = pep * cDesintegration;
// 	if (pep < energyToPass)
// 	{
// 		pep = 0.0;
// 		space->add_energy_to_node(x, y, pep);
// 		// !DELETE ORGANISM.
// 	}
// 	else
// 	{
// 		pep -= energyToPass;
// 		space->add_energy_to_node(x, y, energyToPass);
// 	}
// }

// void Organism::die()
// {
// 	state = -1;
// 	wepq = 0.0;
// 	repq = 0.0;
// }

// void Organism::grow()
// {
// 	double growthEnergy = cGrowth * aep;
// 	pep += growthEnergy;
// 	aep -= growthEnergy;
// 	state++;
// }

// Organism Organism::reproduct()
// {
// 	// Define child coordinates.
// 	int shiftDirection = rand() % 4;
// 	int shiftX = 0;
// 	int shiftY = 0;
// 	if (shiftDirection = 0)
// 	{
// 		shiftX = rand() % reproductionMaxShift;
// 	}
// 	else if (shiftDirection = 1)
// 	{
// 		shiftX = -(rand() % reproductionMaxShift);
// 	}
// 	else if (shiftDirection = 2)
// 	{
// 		shiftY = (rand() % reproductionMaxShift);
// 	}
// 	else if (shiftDirection = 3)
// 	{
// 		shiftY = -(rand() % reproductionMaxShift);
// 	}
// 	int *childCoordinates;
// 	childCoordinates = new int[2];
// 	childCoordinates = space->get_node_by_shift(x, y, shiftX, shiftY);

// 	// Define child pep.
// 	double childPep = pep * cReproductionPep;
// 	pep -= childPep;

// 	return Organism(childPep,
// 					childCoordinates[0], childCoordinates[1], space);
// }

// void Organism::step()
// {
// 	// Desintegration.
// 	if (state == -1)
// 	{
// 		disintegration();
// 		return;
// 	}

// 	wepq = pep * cWepq;
// 	repq = 0.0;
// 	double availableEnergy = space->get_node_energy(x, y);
// 	prevAvailEnergy = availableEnergy;

// 	// Death.
// 	if (aep <= 0.0)
// 	{
// 		printf("\n");
// 		printf("MESSAGE: plant is dead\n");
// 		printf("\n");
// 		die();
// 		return;
// 	}
// 	// Eating.
// 	else if ((repq < wepq) && (availableEnergy > 0.0) &&
// 			 (aep < (pep * cAep)))
// 	{
// 		eat(availableEnergy);
// 	}
// 	// Growth or reproduction.
// 	else if (aep >= (pep * cAep))
// 	{
// 		printf("\n");
// 		printf("MESSAGE: plant is grown up\n");
// 		printf("[");
// 		printf("aep = %lf   ", aep);
// 		printf("cap = %lf", pep * cAep);
// 		printf("]\n");
// 		printf("\n");
// 		grow();
// 		/*
// 		double growthChance = (rand() % 100) + 1;
// 		if (growthChance > cReproduction) {
// 			grow();
// 		}
// 		else {
// 			reproduct();
// 		}
// 		*/
// 	}

// 	aep -= wepq;
// 	aep += repq;
// 	lifetime++;
// }

// void Organism::printInfo()
// {
// 	printf("coordinates: (%d, %d)\n", x, y);
// 	printf("pep: %lf\n", pep);
// 	printf("aep: %lf\n", aep);
// 	printf("wepq: %lf\n", wepq);
// 	printf("state: %d\n", state);
// 	printf("repq: %lf\n", repq);
// 	printf("life time: %d\n", lifetime);
// 	printf("<max aep>: %lf\n", pep * cAep);
// 	printf("<max repq>: %lf\n", pep * cEating);
// 	printf("<energy available>: %lf\n", prevAvailEnergy);
// }
