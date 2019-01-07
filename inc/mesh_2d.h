#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "energy.h"
#include "node.h"

struct Point
{
  Point(int new_x = 0, int new_y = 0)
  {
    x = new_x;
    y = new_y;
  }
  int x;
  int y;
};

struct Mesh_2d_configuration
{
  static Point get_default_size() { return {0, 0}; };
  static Node get_default_node() { return Node(); };
};

class Mesh_2d
{
public:
  Mesh_2d(const Point &size, const Node &init_node);
  ~Mesh_2d();

  //void setMeshSize(const Point &new_size);
  void print_mesh() const;
  //double **getMesh() const;
  const Node *const *step();
  //double getMaxEnergyInMesh() const;
  //double getMinEnergyInMesh() const;
  double get_total_energy_value() const;

  void add_energy_to_node(const Point &point, const Energy &energy);
  //void set_energy_in_node(const Point &point, const Energy &energy);
  double get_node_energy(const Point &point) const;

  double *get_right(const Point &point) const;
  double *get_left(const Point &point) const;
  double *get_top(const Point &point) const;
  double *get_bottom(const Point &point) const;

  int *get_node_by_shift(const Point &point, const Point &shift) const;

private:
  Node **mesh;
  Point size;
};