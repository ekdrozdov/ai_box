#pragma once
#include <iostream>
#include <stdio.h>
#include "space.h"
#include "time.h"
#include "organism.h"

class World {
public:
	World(Time* wTime, Space* space);
	~World();

	void live(int nSteps);

	void printOn();
	void printOff();

	Time* wTime;
	Space* space;
	Organism* plant;

private:	
	bool isPrintOn;
};
