#pragma once
#include <iostream>
#include "node.h"
#include <stdio.h>

const int WORLD_SIZE = 3;

class World {
public:
	World();
	~World();
	void addEnergyToNode(int x, int y, float energy);
	void printMesh();
	void tick();

	Node mesh[WORLD_SIZE][WORLD_SIZE];
	int timeQuantum;

private:
	void computeEnergy();
};
