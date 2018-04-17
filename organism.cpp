#include "organism.h"

Organism(double pep, int x, int y) {
	this->pep = pep;
	aep = 0.0;
	wepq = 0.0;
	state = 1;
	repq = 0.0;
	liveTime = 0;
	this->x = x;
	this->y = y;
}

~Organism() {
}

void Organism::step() {
	int decision = 0;
	// if (state != dead)
	switch(decision) {
		case 0 : eat();
				 break;
		case 1 : reproduct();
				 break;
		case 3 : die();
				 break;
		default : disintegration();
	}
}

