#include "mesh_2d.h"

// Mesh_2d()
// {
//     std::ifstream ifs;
//     ifs.open("test.txt", std::ifstream::in);
//     ifs.open()
// }

// Mesh_2d_configuration::Mesh_2d_configuration()
// {
// }

Mesh_2d_configuration::Mesh_2d_configuration(std::string file_name)
{
    // TODO: read config from config.json
    // this code its stub
    x_size = 101;
    y_size = 102;
}

Mesh_2d::Mesh_2d(Mesh_2d_configuration configuration)
{
    this->size.x = configuration.x_size;
    this->size.y = configuration.y_size;
}

Mesh_2d::Mesh_2d(Point size)
{
    // mesh = new Node *[size.x];
    // for (const auto &row : mesh)
    // {
    // }

    // mesh2 = ;
    // alloc memoty to mesh

    // 	double **oldMesh;
    // int oldXSize = this->xSize;
    // int oldYSize = this->ySize;
    // oldMesh = new double *[oldYSize];
    // for (int i = 0; i < oldYSize; ++i)
    // {
    // 	oldMesh[i] = new double[oldXSize];
    // }
}