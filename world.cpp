#include "world.h"
#include <iostream>

World::World(Time* wTime, Space* space) {
	this->wTime = wTime;
	this->space = space;
};

World::~World() {
	wTime = NULL;
	space = NULL;
};

void World::live(int nSteps) {
	for (int i = 0; i < nSteps; ++i) {
		space->step();
		if (isPrintOn) {
			printf("Step %d/%d:\n", i + 1, nSteps);
			space->printMesh();
			plant->step();
			plant->printInfo();
		}
	}
}

void World::printOn() {
	isPrintOn = 1;
}

void World::printOff() {
	isPrintOn = 0;
}

