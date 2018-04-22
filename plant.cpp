// TODO
// wrap coordinates in class "Node"
// some methods of Node:
// 	node.left(int count);
// 	node.leftUp(int count);

#include "organism.h"

Organism::Organism(double pep, int x, int y, Space* space) {
	this->space = space;
	this->pep = pep - pep * cAep;
	aep = pep * cAep;
	wepq = 0.0;
	state = 0;
	repq = 0.0;
	liveTime = 0;
	this->x = x;
	this->y = y;
}

Organism::~Organism() {
	space = NULL;
}

void Organism::eat(double availableEnergy) {
	double energyToEat = pep * cEating;
	if (availableEnergy > energyToEat) {
		space->addEnergyToNode(x, y, -energyToEat);
		repq = energyToEat;
	}
	else {
		space->setEnergyInNode(x, y, 0.0);
		repq = availableEnergy;
	}
}

void Organism::disintegration() {
	double energyToPass = pep * cDesintegration;
	if (pep < energyToPass) {
		pep = 0.0;
		space->addEnergyToNode(x, y, pep);
		// !DELETE ORGANISM.
	}
	else {
		pep -= energyToPass;
		space->addEnergyToNode(x, y, energyToPass);
	}
}

void Organism::die() {
	state = -1;
	wepq = 0.0;
	repq = 0.0;
}

void Organism::grow() {
	double growthEnergy = cGrowth * aep;
	pep += growthEnergy;
	aep -= growthEnergy;
	state++;
}

Organism Organism::reproduct() {
	// Define child coordinates.
	int shiftDirection = rand() % 4;
	int shiftX = 0;
	int shiftY = 0;
	if (shiftDirection = 0) {
		shiftX = rand() % reproductionMaxShift;
	}
	else if (shiftDirection = 1) {
		shiftX = -(rand() % reproductionMaxShift);
	}
	else if (shiftDirection = 2) {
		shiftY = (rand() % reproductionMaxShift);
	}
	else if (shiftDirection = 3) {
		shiftY = -(rand() % reproductionMaxShift);
	}
	int* childCoordinates;
	childCoordinates = new int[2];
	childCoordinates = space->getNodeByShift(x, y, shiftX, shiftY);

	// Define child pep.
	double childPep = pep * cReproductionPep;
	pep -= childPep;

	return Organism(childPep, 
			childCoordinates[0], childCoordinates[1], space);
}

void Organism::step() {
	// Desintegration.
	if (state == -1) {
		disintegration();
		return;
	}

	wepq = pep * cWepq;
	double availableEnergy = space->getNodeEnergy(x, y);

	// Death.
	if (aep <= 0.0) {
		die();
		return;
	}
	// Eating.
	else if ((repq < wepq) && (availableEnergy > 0.0) && 
			(aep < (pep * cAep))) {
		eat(availableEnergy);
	}
	// Growth or reproduction.
	else {
		double growthChance = (rand() % 100) + 1;
		if (growthChance > cReproduction) {
			grow();
		}
		else {
			reproduct();
		}
	}

	aep -= wepq;
	aep += repq;
}

void Organism::printInfo() {
	printf("Plant:\n");
	printf("coordinates: %d %d\n", x, y);
	printf("pep: %lf\n", pep);
	printf("aep: %lf\n", aep);
	printf("wepq: %lf\n", wepq);
	printf("state: %d\n", state);
	printf("repq: %lf\n", repq);
	printf("life time: %d\n", liveTime);
}

