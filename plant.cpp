#include "organism.h"

Organism::Organism(double pep, int x, int y) {
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
}

Organism::eat(double availableEnergy) {
	double energyToEat = pep * cEating;
	if (availableEnergy > energyToEat) {
		addEnergyToNode(x, y, -energyToEat);
		repq = energyToEat;
	}
	else {
		setEnergyInNode(x, y, 0.0);
		repq = availableEnergy;
	}
}

void Organism::disintegration() {
	energyToPass = pep * cDesintegration;
	if (pep < energyToPass) {
		pep = 0.0;
		addEnergyToNode(x, y, pep);
		// !DELETE ORGANISM.
	}
	else {
		pep -= energyToPass;
		addEnergyToNode(x, y, energyToPass);
	}
}

void Organism::die() {
	state = -1;
	wepq = 0.0;
	repq = 0.0;
}

void Organism::grow() {
	growthEnergy = cGrowth * aep;
	pep += growthEnergy;
	aep -= growthEnergy;
	state++;
}

void Organism::reproduct() {

}

Organism::step() {
	// Desintegration.
	if (state == -1) {
		desintegration();
		return;
	}

	wepq = pep * cWepq;
	availableEnergy = space.getNodeEnergy(x, y);

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
		growthChance = (rand() % 100) + 1;
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

