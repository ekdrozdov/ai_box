#pragma once
#include <stdlib.h>
#include <time.h>
#include "space.h"

class Organism {
public:
	Organism(double pep, int x, int y, Space* space);
	~Organism();
	void step();

	void printInfo();

protected:
	Space* space;

	Organism reproduct();
	void grow();
	void eat(double availableEnergy);
	void die();
	void disintegration();

	double aep; // Active energy.
	double pep; // Passive energy.
	double wepq; // Energy waste per quantum.
	int state; // Live cicle state.
	double repq; // Energy recieve per quantum.
	int liveTime; // Quantums lived.

	int x, y; // Coordinates.

	static constexpr double cWepq = 0.05;
	static constexpr double cEating = 0.10;
	static constexpr double cAep = 0.20;
	static constexpr double cReproduction = 0.0;//20.0;
	static constexpr double maxSize = 100.0;
	static constexpr double cDesintegration = 0.10;
	static constexpr double cGrowth = 0.50;
	static constexpr int reproductionMaxShift = 3;
	static constexpr double cReproductionPep = 0.05;
};
