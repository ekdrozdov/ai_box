#include "resource.h"

Resource::Resource()
{
    // capacity = 0.;
    capacity = 500.;
    // permeability = 0.;
    permeability = 5.;
    energy = Energy();
}

// double Resource::add(const std::string &state, const double &value)
// {
//     if (allowed_states.find(state) != allowed_states.end())
//     {
//         energies[state] += value;
//         if (energies[state] < 0.0)
//         {
//             double extra_energy = energies[state] * (-1);
//             energies[state] = 0.0;
//             return extra_energy;
//         }
//         return 0.0;
//     }
//     //std::cout << "warning: Resource::add: "
//     //          << "unallowed type of energy: "
//     //          << state << std::endl;
//     return value;
// }

Energy_state Resource::get_state() const
{
    return energy.get_state();
}

Energy Resource::add(const Energy &energy)
{
    if (this->energy.get_state() == energy.get_state())
    {
        this->energy.inc(energy.get_count());
        if (this->energy.get_count() > capacity)
        {
            Energy extra = this->energy.get_count() - capacity;
            this->energy.dec(extra.get_count());
            return extra;
        }
        return Energy(0.);
    }
    return energy;
}

double Resource::get_overflow(const double &addition) const
{
    double new_count = energy.get_count() + addition;
    if (new_count > capacity)
    {
        return new_count - capacity;
    }
    return 0.;
}

Energy Resource::extract(const double &count)
{
    double extra = energy.dec(count);
    return Energy(count - extra);
}

bool operator<(const Resource &lhs, const Resource &rhs)
{
    return lhs.get_state() < rhs.get_state();
}