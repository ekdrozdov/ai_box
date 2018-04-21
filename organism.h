#pragma once
#include <stdlib.h>
#include <time.h>

extern Space space;

class Organism {
public:
	Organism(double pep, int x, int y);
	~Organism();
	void step();

protected:
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

	static const double cWepq = 0.05;
	static const double cEating = 0.10;
	static const double cAep = 0.20;
	static const double cReproduction = 20.0;
	static const double maxSize = 100.0;
	static const double cDesintegration = 0.10;
	static const double cGrowth = 0.50;
};
