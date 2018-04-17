#include "space.h"

Space::Space() {
	xSize = defaultSize;
	ySize = defaultSize;
}

Space::Space(int xSize, int ySize) {
	mesh = new double*[ySize];
	for (int i = 0; i < ySize; ++i) {
		mesh[i] = new double[xSize];
	}
	this->xSize = xSize;
	this->ySize = ySize;	

	for (int i = 0; i < ySize; ++i) {
		for (int j = 0; j < xSize; ++j) {
			mesh[i][j] = 0.0;
		}
	}
}

Space::~Space() {
	if (mesh != NULL) {
		for (int i = 0; i < ySize; ++i) {
			delete[] mesh[i];
		}
		delete[] mesh;
	}
	xSize = 0;
	ySize = 0;
}

void Space::setMeshSize(int xSize, int ySize) {
	// Create buffer.
	double** oldMesh;
	int oldXSize = this->xSize;
	int oldYSize = this->ySize;
	oldMesh = new double*[oldYSize];
	for (int i = 0; i < oldYSize; ++i) {
		oldMesh[i] = new double[oldXSize];
	}

	// Copy mesh to a buffer considering resizing direction.
	int xMin = std::min(oldXSize, xSize);
	int yMin = std::min(oldYSize, ySize);
	for (int i = 0; i < yMin; ++i) {
		for (int j = 0; j < xMin; ++j) {
			oldMesh[i][j] = mesh[i][j];
		}
	}

	// Delete old mesh.
	if (mesh != NULL) {
		for (int i = 0; i < oldYSize; ++i) {
			delete[] mesh[i];
		}
		delete[] mesh;
	}

	// Create new mesh.
	mesh = new double*[ySize];
	for (int i = 0; i < ySize; ++i) {
		mesh[i] = new double[xSize];
	}
	this->xSize = xSize;
	this->ySize = ySize;	

	for (int i = 0; i < ySize; ++i) {
		for (int j = 0; j < xSize; ++j) {
			mesh[i][j] = 0.0;
		}
	}

	// Copy old mesh to new mesh.
	for (int i = 0; i < yMin; ++i) {
		for (int j = 0; j < xMin; ++j) {
			mesh[i][j] = oldMesh[i][j];
		}
	}
}

void Space::printMesh() {
	printf("Mesh:\n");
	for (int i = 0; i < ySize; ++i) {
		for (int j = 0; j < xSize; ++j) {
			printf("%3.3f ", mesh[i][j]);
		}
		printf("\n");
	}
}

double** Space::getMesh() {
	return mesh;
}

double** Space::step() {
	// Extended mesh is mesh with shadow strings.
	int extMeshXSize = xSize + 2;
	int extMeshYSize = ySize + 2;

	double** extMesh;
	extMesh = new double*[extMeshYSize];
	for (int i = 0; i < extMeshYSize; ++i) {
		extMesh[i] = new double[extMeshXSize];
	}

	// Copy base mesh in extended mesh.
	for (int i = 0, extI = 1; i < ySize; ++i, ++extI) {
		for (int j = 0, extJ = 1; j < xSize; ++j, ++extJ) {
			extMesh[extI][extJ] = mesh[i][j];
		}
	}

	// Fill the shadow strings, except corners.
	for (int i = 0, extI = 1; i < ySize; ++i, ++extI) {
		// Left border:
		extMesh[extI][0] = mesh[i][xSize - 1];
		// Right border:
		extMesh[extI][extMeshXSize - 1] = mesh[i][0];
	}

	for (int j = 0, extJ = 1; j < xSize; ++j, ++extJ) {
		// Top border:
		extMesh[0][extJ] = mesh[ySize - 1][j];
		// Bottom border:
		extMesh[extMeshYSize - 1][extJ] = mesh[0][j];
	}

	// Fill shadow border corners.
	// Top left corner:
	extMesh[0][0] = mesh[ySize - 1][xSize - 1];
	// Top right corner:
	extMesh[0][extMeshXSize - 1] = mesh[ySize - 1][0];
	// Bottom left corner:
	extMesh[extMeshYSize - 1][0] = mesh[0][xSize - 1];
	// Bottom right corner:
	extMesh[extMeshYSize - 1][extMeshXSize - 1] = mesh[0][0];

	// Additions mesh is the mesh that describes how many
	// energy must get or lost each node in the next step.
	double** additionsMesh;
	additionsMesh = new double*[extMeshYSize];
	for (int i = 0; i < extMeshYSize; ++i) {
		additionsMesh[i] = new double[extMeshXSize];
	}

	// Initialize additions mesh with zeros.
	for (int i = 0; i < ySize; ++i) {
		for (int j = 0; j < xSize; ++j) {
			additionsMesh[i][j] = 0.0;
		}
	}

	for (int i = 0, iExt = 1; i < ySize; ++i, ++iExt) {
		for (int j = 0, jExt = 1; j < xSize; ++j, ++jExt) {
			// For each node count lack of energy neighbours.
			int lackNeighboursNumber = 0;
			double currentEnergy = mesh[i][j];
			if (extMesh[iExt - 1][jExt- 1] < mesh[i][j]) {
				++lackNeighboursNumber;
			}
			if (extMesh[iExt][jExt - 1] < mesh[i][j]) {
				++lackNeighboursNumber;
			}
			if (extMesh[iExt + 1][jExt - 1] < mesh[i][j]) {
				++lackNeighboursNumber;
			}
			if (extMesh[iExt - 1][jExt] < mesh[i][j]) {
				++lackNeighboursNumber;
			}
			if (extMesh[iExt + 1][jExt] < mesh[i][j]) {
				++lackNeighboursNumber;
			}
			if (extMesh[iExt + 1][jExt + 1] < mesh[i][j]) {
				++lackNeighboursNumber;
			}
			if (extMesh[iExt][jExt + 1] < mesh[i][j]) {
				++lackNeighboursNumber;
			}
			if (extMesh[iExt - 1][jExt + 1] < mesh[i][j]) {
				++lackNeighboursNumber;
			}

			// And fill additions mesh.
			double k = 0.5;
			double energyToPass = currentEnergy * k *
				(1.0 / lackNeighboursNumber);
			if (extMesh[iExt - 1][jExt - 1] < mesh[i][j]) {
				additionsMesh[iExt - 1][jExt - 1] += energyToPass;
			}
			if (extMesh[iExt - 1][jExt] < mesh[i][j]) {
				additionsMesh[iExt - 1][jExt] += energyToPass;
			}
			if (extMesh[iExt - 1][jExt + 1] < mesh[i][j]) {
				additionsMesh[iExt - 1][jExt + 1] += energyToPass;
			}
			if (extMesh[iExt][jExt - 1] < mesh[i][j]) {
				additionsMesh[iExt][jExt - 1] += energyToPass;
			}
			if (extMesh[iExt][jExt + 1] < mesh[i][j]) {
				additionsMesh[iExt][jExt + 1] += energyToPass;
			}
			if (extMesh[iExt + 1][jExt - 1] < mesh[i][j]) {
				additionsMesh[iExt + 1][jExt - 1] += energyToPass;
			}
			if (extMesh[iExt + 1][jExt] < mesh[i][j]) {
				additionsMesh[iExt + 1][jExt] += energyToPass;
			}
			if (extMesh[iExt + 1][jExt + 1] < mesh[i][j]) {
				additionsMesh[iExt + 1][jExt + 1] += energyToPass;
			}

			if (lackNeighboursNumber > 0) {
				additionsMesh[iExt][jExt] -= 
					(extMesh[iExt][jExt] - currentEnergy * k);
			}
		}
	}

	// Apply additions to mesh.
	for (int i = 0, extI = 1; i < ySize; ++i, ++extI) {
		for (int j = 0, extJ = 1; j < xSize; ++j, ++extJ) {
			mesh[i][j] += additionsMesh[extI][extJ];
		}
	}

	for (int i = 0, extI = 1; i < ySize; ++i, ++extI) {
		// Consider left shadow border.
		mesh[i][xSize - 1] += additionsMesh[extI][0];
		// Consider rigth shadow border.
		mesh[i][0] += additionsMesh[extI][extMeshXSize - 1];
	}
	for (int j = 0, extJ = 1; j < xSize; ++j, ++extJ) {
		// Consider top shadow border.
		mesh[ySize - 1][j] += additionsMesh[0][extJ];
		// Consider bottom shadow border.
		mesh[0][j] += additionsMesh[extMeshYSize - 1][extJ];
	}

	// Top left shadow corner:
	mesh[ySize - 1][xSize - 1] += additionsMesh[0][0];
	// Top right corner:
	mesh[ySize - 1][0] += additionsMesh[0][extMeshXSize - 1];
	// Bottom left corner:
	mesh[0][xSize - 1] += additionsMesh[extMeshYSize - 1][0];
	// Bottom right corner:
	mesh[0][0] += additionsMesh[extMeshYSize - 1][extMeshXSize - 1];

	for (int i = 0; i < ySize; ++i) {
		delete[] extMesh[i];
		delete[] additionsMesh[i];
	}
	delete[] extMesh;
	delete[] additionsMesh;

	return mesh;
}

double Space::getMaxEnergyInMesh() {
	double maxEnergy = mesh[0][0];
	for (int i = 0; i < ySize; ++i) {
		for (int j = 0; j < xSize; ++j) {
			if (mesh[i][j] > maxEnergy) {
				maxEnergy = mesh[i][j];
			}
		}
	}
	return maxEnergy;
}

double Space::getMinEnergyInMesh() {
	double minEnergy = mesh[0][0];
	for (int i = 0; i < ySize; ++i) {
		for (int j = 0; j < xSize; ++j) {
			if (mesh[i][j] < minEnergy) {
				minEnergy = mesh[i][j];
			}
		}
	}
	return minEnergy;
}

double Space::getTotalEnergyValue() {
	double total = 0.0;
	for (int i = 0; i < ySize; ++i) {
		for (int j = 0; j < xSize; ++j) {
			total =+ mesh[i][j];
		}
	}
	return total;
}

void Space::addEnergyToNode(int x, int y, double energyVal) {
	mesh[y][x] += energyVal;
}

void Space::setEnergyInNode(int x, int y, double energyVal) {
	mesh[y][x] = energyVal;
}

double Space::getNodeEnergy(int x, int y) {
	return mesh[y][x];
}
