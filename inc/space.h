#pragma once
#include <iostream>
#include <algorithm>
#include "energy.h"

class Space
{
  public:
	Space();
	Space(int xSize, int ySize);
	~Space();

	void setMeshSize(int xSize, int ySize);
	void printMesh();
	double **getMesh();
	double **step();
	double getMaxEnergyInMesh();
	double getMinEnergyInMesh();
	double getTotalEnergyValue();

	void addEnergyToNode(int x, int y, double energyVal);
	void setEnergyInNode(int x, int y, double energyVal);
	double getNodeEnergy(int x, int y);

	double *getRight(int x, int y);
	double *getLeft(int x, int y);
	double *getTop(int x, int y);
	double *getBottom(int x, int y);

	int *getNodeByShift(int x, int y, int shiftX, int shiftY);

  private:
	double **mesh;
	int xSize;
	int ySize;

	const int defaultSize = 10;
};

class Spacex
{
  public:
	Spacex();
};