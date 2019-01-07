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
	void print_mesh();
	double **getMesh();
	double **step();
	double getMaxEnergyInMesh();
	double getMinEnergyInMesh();
	double get_total_energy_value();

	void add_energy_to_node(int x, int y, double energyVal);
	void set_energy_in_node(int x, int y, double energyVal);
	double get_node_energy(int x, int y);

	double *get_right(int x, int y);
	double *get_left(int x, int y);
	double *get_top(int x, int y);
	double *get_bottom(int x, int y);

	int *get_node_by_shift(int x, int y, int shiftX, int shiftY);

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