#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "energy.h"
#include "node.h"

class Mesh_2d_configuration
{
public:
  //Mesh_2d_configuration();
  explicit Mesh_2d_configuration(std::string file_name);

  int x_size;
  int y_size;

private:
  const int default_x_size = 0;
  const int default_y_size = 0;
};

struct Point
{
  int x;
  int y;
};

class Mesh_2d
{
public:
  Mesh_2d(Mesh_2d_configuration configuration);
  Mesh_2d(Point size);
  ~Mesh_2d(){};
  inline Point get_size() { return size; };

private:
  Point size;
  Node **mesh;
  std::vector<std::vector<Node>> mesh2;
};
