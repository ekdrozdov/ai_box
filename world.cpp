#include "world.h"
#include <iostream>

World::World() {
	for (int i = 0; i < WORLD_SIZE; ++i) {
		for (int j = 0; j < WORLD_SIZE; ++j) {
			mesh[i][j].energy = 0.0;
		}
	}
};

World::~World() {
	for (int i = 0; i < WORLD_SIZE; ++i) {
		for (int j = 0; j < WORLD_SIZE; ++j) {
			mesh[i][j].energy = 0.0;
		}
	}
};

void World::addEnergyToNode(int x, int y, float energy) {
	mesh[x][y].energy = energy;
};

void World::computeEnergy() {
	// Extended mesh is mesh with shadow strings.
	int extMeshSize = WORLD_SIZE + 2;

	// Copy base mesh.
	float extMesh[extMeshSize][extMeshSize];
	float additionsMesh[extMeshSize][extMeshSize];
	for (int i = 0, extI = 1; i < WORLD_SIZE; ++i, ++extI) {
		for (int j = 0, extJ = 1; j < WORLD_SIZE; ++j, ++extJ) {
			extMesh[extI][extJ] = mesh[i][j].energy;
		}
	}

	for (int i = 0; i < extMeshSize; ++i) {
		for (int j = 0; j < extMeshSize; ++j) {
			additionsMesh[i][j] = 0.0;
		}
	}

	// Fill the shadow strings, except corners.
	// Top border:
	for (int j = 0, extJ = 1; j < WORLD_SIZE; ++j, ++extJ) {
		extMesh[0][extJ] = mesh[WORLD_SIZE - 1][j].energy;
	}
	// Left border:
	for (int i = 0, extI = 1; i < WORLD_SIZE; ++i, ++extI) {
		extMesh[extI][0] = mesh[i][WORLD_SIZE - 1].energy;
	}
	// Right border:
	for (int i = 0, extI = 1; i < WORLD_SIZE; ++i, ++extI) {
		extMesh[extI][extMeshSize - 1] = mesh[i][0].energy;
	}
	// Bottom border:
	for (int j = 0, extJ = 1; j < WORLD_SIZE; ++j, ++extJ) {
		extMesh[extMeshSize - 1][extJ] = mesh[0][j].energy;
	}

	// Fill shadow border corners.
	// Top left corner:
	extMesh[0][0] = mesh[WORLD_SIZE - 1][WORLD_SIZE - 1].energy;
	// Top right corner:
	extMesh[0][extMeshSize - 1] = mesh[WORLD_SIZE - 1][0].energy;
	// Bottom left corner:
	extMesh[extMeshSize - 1][0] = mesh[0][WORLD_SIZE - 1].energy;
	// Bottom right corner:
	extMesh[extMeshSize - 1][extMeshSize - 1] = mesh[0][0].energy;

	// 8 is number of neighbours of every node.
	for (int i = 0, iExt = 1; i < WORLD_SIZE; ++i, ++iExt) {
		for (int j = 0, jExt = 1; j < WORLD_SIZE; ++j, ++jExt) {
			// Count lack of energy neighbours.
			int lackNeighboursNumber = 0;
			float currentEnergy = mesh[i][j].energy;
			if (extMesh[iExt - 1][jExt- 1] < mesh[i][j].energy) {
				++lackNeighboursNumber;
			}
			if (extMesh[iExt][jExt - 1] < mesh[i][j].energy) {
				++lackNeighboursNumber;
			}
			if (extMesh[iExt + 1][jExt - 1] < mesh[i][j].energy) {
				++lackNeighboursNumber;
			}
			if (extMesh[iExt - 1][jExt] < mesh[i][j].energy) {
				++lackNeighboursNumber;
			}
			if (extMesh[iExt + 1][jExt] < mesh[i][j].energy) {
				++lackNeighboursNumber;
			}
			if (extMesh[iExt + 1][jExt + 1] < mesh[i][j].energy) {
				++lackNeighboursNumber;
			}
			if (extMesh[iExt][jExt + 1] < mesh[i][j].energy) {
				++lackNeighboursNumber;
			}
			if (extMesh[iExt - 1][jExt + 1] < mesh[i][j].energy) {
				++lackNeighboursNumber;
			}

			//printf("Lack n-s: %d\n", lackNeighboursNumber);
			// Pass an energy.
			// "k" is percentage of energy to pass.
			float k = 0.5;
			float energyToPass = currentEnergy * k *
				(1.0 / lackNeighboursNumber);
			if (extMesh[iExt - 1][jExt - 1] < mesh[i][j].energy) {
				additionsMesh[iExt - 1][jExt - 1] += energyToPass;
			}
			if (extMesh[iExt - 1][jExt] < mesh[i][j].energy) {
				additionsMesh[iExt - 1][jExt] += energyToPass;
			}
			if (extMesh[iExt - 1][jExt + 1] < mesh[i][j].energy) {
				additionsMesh[iExt - 1][jExt + 1] += energyToPass;
			}
			if (extMesh[iExt][jExt - 1] < mesh[i][j].energy) {
				additionsMesh[iExt][jExt - 1] += energyToPass;
			}
			if (extMesh[iExt][jExt + 1] < mesh[i][j].energy) {
				additionsMesh[iExt][jExt + 1] += energyToPass;
			}
			if (extMesh[iExt + 1][jExt - 1] < mesh[i][j].energy) {
				additionsMesh[iExt + 1][jExt - 1] += energyToPass;
			}
			if (extMesh[iExt + 1][jExt] < mesh[i][j].energy) {
				additionsMesh[iExt + 1][jExt] += energyToPass;
			}
			if (extMesh[iExt + 1][jExt + 1] < mesh[i][j].energy) {
				additionsMesh[iExt + 1][jExt + 1] += energyToPass;
			}

			if (lackNeighboursNumber > 0) {
				additionsMesh[iExt][jExt] -= 
					(extMesh[iExt][jExt] - currentEnergy * k);
			}
		}
	}

	/*
	std::cout << "Shadow mesh: \n";
	for (int i = 0; i < extMeshSize; ++i) {
		for (int j = 0; j < extMeshSize; ++j) {
			std::cout << additionsMesh[i][j] << " ";
		}
		std::cout << std::endl;
	}
	*/

	for (int i = 0, extI = 1; i < WORLD_SIZE; ++i, ++extI) {
		for (int j = 0, extJ = 1; j < WORLD_SIZE; ++j, ++extJ) {
			mesh[i][j].energy += additionsMesh[extI][extJ];
		}
	}

	// Consider top shadow border.
	for (int j = 0, extJ = 1; j < WORLD_SIZE; ++j, ++extJ) {
		mesh[WORLD_SIZE - 1][j].energy += additionsMesh[0][extJ];
	}
	// Consider left shadow border.
	for (int i = 0, extI = 1; i < WORLD_SIZE; ++i, ++extI) {
		mesh[i][WORLD_SIZE - 1].energy += additionsMesh[extI][0];
	}
	// Consider rigth shadow border.
	for (int i = 0, extI = 1; i < WORLD_SIZE; ++i, ++extI) {
		mesh[i][0].energy += additionsMesh[extI][extMeshSize - 1];
	}
	// Consider bottom shadow border.
	for (int j = 0, extJ = 1; j < WORLD_SIZE; ++j, ++extJ) {
		mesh[0][j].energy += additionsMesh[extMeshSize - 1][extJ];
	}
	// Top left shadow corner:
	mesh[WORLD_SIZE - 1][WORLD_SIZE - 1].energy += additionsMesh[0][0];
	// Top right corner:
	mesh[WORLD_SIZE - 1][0].energy += additionsMesh[0][extMeshSize - 1];
	// Bottom left corner:
	mesh[0][WORLD_SIZE - 1].energy += additionsMesh[extMeshSize - 1][0];
	// Bottom right corner:
	mesh[0][0].energy += additionsMesh[extMeshSize - 1][extMeshSize - 1];

};

void World::printMesh() {
	printf("Mesh:\n");
	for (int i = 0; i < WORLD_SIZE; ++i) {
		for (int j = 0; j < WORLD_SIZE; ++j) {
			printf("%3.3f ", mesh[i][j].energy);
		}
		printf("\n");
	}
};

void World::tick() {
	computeEnergy();
	printMesh();
};
