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

	double aep; // Active energy points.
	double pep; // Passive energy points.
	double wepq; // Energy points waste per quantum.
	int state; // Live cicle state.
	double repq; // Energy points recieve per quantum.
	int lifetime; // Quantums lived.

	int x, y; // Coordinates.

	// Determines percent of the pep that will be transform into
	// the aep while born.
	static constexpr double cBornAep = 0.20;
	static constexpr double cWepq = 0.05;
	// Determines the repq limit.
	static constexpr double cEating = 0.10;
	// Determines the aep limit.
	static constexpr double cAep = 0.40; 
	// Determines a chances of the reproduction vs growth.
	static constexpr double cReproduction = 0.0;//20.0;
	// Determines the pep limit.
	static constexpr double maxSize = 100.0;
	static constexpr double cDesintegration = 0.10;
	// Determines the percent of the aep that will be
	// transform into the pep while growth.
	static constexpr double cGrowth = 0.50;
	static constexpr int reproductionMaxShift = 3;
	static constexpr double cReproductionPep = 0.05;

	// Technical variable to save available energy
	// value before eating for correct printing.
	double prevAvailEnergy;
};
