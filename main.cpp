#include "world.h"
#include <iostream>

int main() {
	World world;
	world.addEnergyToNode(1, 1, 9.0);
	int count = 0;
	std::cin >> count;
	world.printMesh();
	for (int i = 0; i < count; ++i) {
		world.tick();
	}

	return 0;
}
