#include "node.h"

bool operator<(const Node &lhs, const Node &rhs)
{
    if (lhs.resource.get_energy_count() < rhs.resource.get_energy_count())
    {
        return true;
    }
    return false;
}