#pragma once
#include <stdlib.h>
#include <time.h>

class Organism {
public:
	Organism(double pep, int x, int y);
	~Organism();
	void step();

protected:
	Organism reproduct();
	void eat();
	void die();
	void disintegration();

	double aep; // Active energy.
	double pep; // Passive energy.
	double wepq; // Energy waste per quantum.
	int state; // Live cicle state.
	double repq; // Energy recieve per quantum.
	int liveTime; // Quantums lived.
	int x, y; // Coordinates.
};
