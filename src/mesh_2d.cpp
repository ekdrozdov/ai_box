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

// Mesh_2d_configuration::Mesh_2d_configuration(std::string file_name)
// {
//     // TODO: read config from config.json
//     // this code its stub
//     x_size = 101;
//     y_size = 102;
// }

// Mesh_2d::Mesh_2d(Mesh_2d_configuration configuration)
// {
//     this->size.x = configuration.x_size;
//     this->size.y = configuration.y_size;
// }

// Mesh_2d::Mesh_2d(Point size)
// {
//     mesh = new Node *[size.x];
//     for (const auto &row : mesh)
//     {
//     }

//     mesh2 = ;
//     alloc memoty to mesh

//     	double **oldMesh;
//     int oldXSize = this->size.x;
//     int oldYSize = this->size.y;
//     oldMesh = new double *[oldYSize];
//     for (int i = 0; i < oldYSize; ++i)
//     {
//     	oldMesh[i] = new double[oldXSize];
//     }
// }

Mesh_2d::Mesh_2d(const Point &size = Mesh_2d_configuration::get_default_size(),
                 const Node &init_node = Node())
{
    mesh = new Node *[size.y];
    for (int i = 0; i < size.y; ++i)
    {
        mesh[i] = new Node[size.x];
    }

    for (int i = 0; i < size.y; ++i)
    {
        for (int j = 0; j < size.x; j++)
        {
            mesh[i][j] = init_node;
        }
    }
    this->size = size;
}

Mesh_2d::~Mesh_2d()
{
    if (mesh != NULL)
    {
        for (int i = 0; i < size.y; ++i)
        {
            delete[] mesh[i];
        }
        delete[] mesh;
    }
    size.x = 0;
    size.y = 0;
}

// void Mesh_2d::setMeshSize(const Point &new_size)
// {
//     // // Create buffer.
//     // Node **old_mesh;
//     // Point old_size = this->size;
//     // old_mesh = new Node *[old_size.y];
//     // for (int i = 0; i < old_size.y; ++i)
//     // {
//     //     old_mesh[i] = new Node[old_size.x];
//     // }

//     // // Copy mesh to a buffer considering resizing direction.
//     // int xMin = old_size.x < new_size.x ? old_size.x : new_size.x;
//     // int yMin = old_size.y < new_size.y ? old_size.y : new_size.y;
//     // for (int i = 0; i < yMin; ++i)
//     // {
//     //     for (int j = 0; j < xMin; ++j)
//     //     {
//     //         old_mesh[i][j] = mesh[i][j];
//     //     }
//     // }

//     // // Create new mesh.
//     // mesh = new Node *[new_size.y];
//     // for (int i = 0; i < new_size.y; ++i)
//     // {
//     //     mesh[i] = new Node[new_size.x];
//     // }
//     // this->size.x = new_size.x;
//     // this->size.y = new_size.y;

//     // for (int i = 0; i < size.y; ++i)
//     // {
//     //     for (int j = 0; j < size.x; ++j)
//     //     {
//     //         mesh[i][j] = Node();
//     //     }
//     // }

//     // // Copy old mesh to new mesh.
//     // for (int i = 0; i < yMin; ++i)
//     // {
//     //     for (int j = 0; j < xMin; ++j)
//     //     {
//     //         mesh[i][j] = old_mesh[i][j];
//     //     }
//     // }

//     // // Delete old mesh.
//     // if (mesh != NULL)
//     // {
//     //     for (int i = 0; i < old_size.y; ++i)
//     //     {
//     //         delete[] mesh[i];
//     //     }
//     //     delete[] mesh;
//     // }
// }

void Mesh_2d::print_mesh() const
{
    for (int i = 0; i < size.y; ++i)
    {
        for (int j = 0; j < size.x; ++j)
        {
            std::cout << std::setfill(' ')
                      << std::setw(15)
                      << std::setprecision(5)
                      << mesh[i][j].resource.get_energy_count();
        }
        std::cout << std::endl;
    }
}

// double **Mesh_2d::getMesh()
// {
//     return mesh;
// }

const Node *const *Mesh_2d::step()
{
    // Extended mesh is mesh with shadow strings.
    Point ext_mesh_size = {size.x + 2, size.y + 2};

    Node **ext_mesh;
    ext_mesh = new Node *[ext_mesh_size.y];
    for (int i = 0; i < ext_mesh_size.y; ++i)
    {
        ext_mesh[i] = new Node[ext_mesh_size.x];
    }

    // Copy base mesh in extended mesh.
    for (int i = 0, extI = 1; i < size.y; ++i, ++extI)
    {
        for (int j = 0, extJ = 1; j < size.x; ++j, ++extJ)
        {
            ext_mesh[extI][extJ] = mesh[i][j];
        }
    }

    // Fill the shadow strings, except corners.
    for (int i = 0, extI = 1; i < size.y; ++i, ++extI)
    {
        // Left border:
        ext_mesh[extI][0] = mesh[i][size.x - 1];
        // Right border:
        ext_mesh[extI][ext_mesh_size.x - 1] = mesh[i][0];
    }

    for (int j = 0, extJ = 1; j < size.x; ++j, ++extJ)
    {
        // Top border:
        ext_mesh[0][extJ] = mesh[size.y - 1][j];
        // Bottom border:
        ext_mesh[ext_mesh_size.y - 1][extJ] = mesh[0][j];
    }

    // Fill shadow border corners.
    // Top left corner:
    ext_mesh[0][0] = mesh[size.y - 1][size.x - 1];
    // Top right corner:
    ext_mesh[0][ext_mesh_size.x - 1] = mesh[size.y - 1][0];
    // Bottom left corner:
    ext_mesh[ext_mesh_size.y - 1][0] = mesh[0][size.x - 1];
    // Bottom right corner:
    ext_mesh[ext_mesh_size.y - 1][ext_mesh_size.x - 1] = mesh[0][0];

    // Additions mesh is the mesh that describes how many
    // energy must get or lost each node in the next step.
    double **additions_mesh;
    additions_mesh = new double *[ext_mesh_size.y];
    for (int i = 0; i < ext_mesh_size.y; ++i)
    {
        additions_mesh[i] = new double[ext_mesh_size.x];
    }

    // Prepare additions mesh.
    for (int i = 0; i < ext_mesh_size.y; ++i)
    {
        for (int j = 0; j < ext_mesh_size.x; ++j)
        {
            additions_mesh[i][j] = 0.;
        }
    }

    for (int i = 0, i_ext = 1; i < size.y; ++i, ++i_ext)
    {
        for (int j = 0, j_ext = 1; j < size.x; ++j, ++j_ext)
        {
            // For each node count lack of energy neighbours.
            int n_lack_neighbours = 0;
            if (ext_mesh[i_ext - 1][j_ext - 1] < mesh[i][j])
            {
                ++n_lack_neighbours;
            }
            if (ext_mesh[i_ext][j_ext - 1] < mesh[i][j])
            {
                ++n_lack_neighbours;
            }
            if (ext_mesh[i_ext + 1][j_ext - 1] < mesh[i][j])
            {
                ++n_lack_neighbours;
            }
            if (ext_mesh[i_ext - 1][j_ext] < mesh[i][j])
            {
                ++n_lack_neighbours;
            }
            if (ext_mesh[i_ext + 1][j_ext] < mesh[i][j])
            {
                ++n_lack_neighbours;
            }
            if (ext_mesh[i_ext + 1][j_ext + 1] < mesh[i][j])
            {
                ++n_lack_neighbours;
            }
            if (ext_mesh[i_ext][j_ext + 1] < mesh[i][j])
            {
                ++n_lack_neighbours;
            }
            if (ext_mesh[i_ext - 1][j_ext + 1] < mesh[i][j])
            {
                ++n_lack_neighbours;
            }

            // And fill additions mesh.
            if (n_lack_neighbours > 0)
            {
                double k = 0.5;
                double current_energy_count = mesh[i][j].resource.get_energy_count();
                double total_energy_to_get = current_energy_count * k;
                double recieved_energy = mesh[i][j].resource.extract(total_energy_to_get).get_count();
                double energy_to_pass = recieved_energy / n_lack_neighbours;
                double extra_energy = 0.;

                if (ext_mesh[i_ext - 1][j_ext - 1].resource.get_energy_count() < current_energy_count)
                {
                    additions_mesh[i_ext - 1][j_ext - 1] += energy_to_pass;
                    extra_energy += ext_mesh[i_ext - 1][j_ext - 1].resource.get_overflow(energy_to_pass);
                }
                if (ext_mesh[i_ext - 1][j_ext].resource.get_energy_count() < current_energy_count)
                {
                    additions_mesh[i_ext - 1][j_ext] += energy_to_pass;
                    extra_energy += ext_mesh[i_ext - 1][j_ext].resource.get_overflow(energy_to_pass);
                }
                if (ext_mesh[i_ext - 1][j_ext + 1].resource.get_energy_count() < current_energy_count)
                {
                    additions_mesh[i_ext - 1][j_ext + 1] += energy_to_pass;
                    extra_energy += ext_mesh[i_ext - 1][j_ext + 1].resource.get_overflow(energy_to_pass);
                }
                if (ext_mesh[i_ext][j_ext - 1].resource.get_energy_count() < current_energy_count)
                {
                    additions_mesh[i_ext][j_ext - 1] += energy_to_pass;
                    extra_energy += ext_mesh[i_ext][j_ext - 1].resource.get_overflow(energy_to_pass);
                }
                if (ext_mesh[i_ext][j_ext + 1].resource.get_energy_count() < current_energy_count)
                {
                    additions_mesh[i_ext][j_ext + 1] += energy_to_pass;
                    extra_energy += ext_mesh[i_ext][j_ext + 1].resource.get_overflow(energy_to_pass);
                }
                if (ext_mesh[i_ext + 1][j_ext - 1].resource.get_energy_count() < current_energy_count)
                {
                    additions_mesh[i_ext + 1][j_ext - 1] += energy_to_pass;
                    extra_energy += ext_mesh[i_ext + 1][j_ext - 1].resource.get_overflow(energy_to_pass);
                }
                if (ext_mesh[i_ext + 1][j_ext].resource.get_energy_count() < current_energy_count)
                {
                    additions_mesh[i_ext + 1][j_ext] += energy_to_pass;
                    extra_energy += ext_mesh[i_ext + 1][j_ext].resource.get_overflow(energy_to_pass);
                }
                if (ext_mesh[i_ext + 1][j_ext + 1].resource.get_energy_count() < current_energy_count)
                {
                    additions_mesh[i_ext + 1][j_ext + 1] += energy_to_pass;
                    extra_energy += ext_mesh[i_ext + 1][j_ext + 1].resource.get_overflow(energy_to_pass);
                }

                additions_mesh[i_ext][j_ext] += extra_energy;
                //additions_mesh[i_ext][j_ext] -= (recieved_energy - extra_energy);
            }
        }
    }

    // Apply additions to mesh.
    for (int i = 0, extI = 1; i < size.y; ++i, ++extI)
    {
        for (int j = 0, extJ = 1; j < size.x; ++j, ++extJ)
        {
            mesh[i][j].resource.add(additions_mesh[extI][extJ]);
        }
    }

    for (int i = 0, extI = 1; i < size.y; ++i, ++extI)
    {
        // Consider left shadow border.
        mesh[i][size.x - 1].resource.add(additions_mesh[extI][0]);
        // Consider rigth shadow border.
        mesh[i][0].resource.add(additions_mesh[extI][ext_mesh_size.x - 1]);
    }
    for (int j = 0, extJ = 1; j < size.x; ++j, ++extJ)
    {
        // Consider top shadow border.
        mesh[size.y - 1][j].resource.add(additions_mesh[0][extJ]);
        // Consider bottom shadow border.
        mesh[0][j].resource.add(additions_mesh[ext_mesh_size.y - 1][extJ]);
    }

    // Top left shadow corner:
    mesh[size.y - 1][size.x - 1].resource.add(additions_mesh[0][0]);
    // Top right corner:
    mesh[size.y - 1][0].resource.add(additions_mesh[0][ext_mesh_size.x - 1]);
    // Bottom left corner:
    mesh[0][size.x - 1].resource.add(additions_mesh[ext_mesh_size.y - 1][0]);
    // Bottom right corner:
    mesh[0][0].resource.add(additions_mesh[ext_mesh_size.y - 1][ext_mesh_size.x - 1]);

    for (int i = 0; i < ext_mesh_size.y; ++i)
    {
        delete[] ext_mesh[i];
    }
    delete[] ext_mesh;

    for (int i = 0; i < ext_mesh_size.y; ++i)
    {
        delete[] additions_mesh[i];
    }
    delete[] additions_mesh;

    const Node *const *ptr = &mesh[0];
    return ptr;
}

// double Mesh_2d::getMaxEnergyInMesh()
// {
//     double maxEnergy = mesh[0][0];
//     for (int i = 0; i < ySize; ++i)
//     {
//         for (int j = 0; j < xSize; ++j)
//         {
//             if (mesh[i][j] > maxEnergy)
//             {
//                 maxEnergy = mesh[i][j];
//             }
//         }
//     }
//     return maxEnergy;
// }

// double Mesh_2d::getMinEnergyInMesh()
// {
//     double minEnergy = mesh[0][0];
//     for (int i = 0; i < ySize; ++i)
//     {
//         for (int j = 0; j < xSize; ++j)
//         {
//             if (mesh[i][j] < minEnergy)
//             {
//                 minEnergy = mesh[i][j];
//             }
//         }
//     }
//     return minEnergy;
// }

double Mesh_2d::get_total_energy_value() const
{
    double total = 0.0;
    for (int i = 0; i < size.y; ++i)
    {
        for (int j = 0; j < size.x; ++j)
        {
            total += mesh[i][j].resource.get_energy_count();
        }
    }
    return total;
}

void Mesh_2d::add_energy_to_node(const Point &point, const Energy &energy)
{
    mesh[point.y][point.x].resource.add(energy);
}

// void Mesh_2d::set_energy_in_node(const Point &point, const Energy &energy)
// {
//     mesh[y][x] = energyVal;
// }

double Mesh_2d::get_node_energy(const Point &point) const
{
    return mesh[point.y][point.x].resource.get_energy_count();
}

int *Mesh_2d::get_node_by_shift(const Point &point, const Point &shift) const
{
    int *newCoords = new int[2];
    newCoords[0] = (point.x + shift.x) % size.x;
    newCoords[1] = (point.y + shift.y) % size.y;
    return newCoords;
}