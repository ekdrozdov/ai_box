#include "energy_container.h"

double Energy_container::add(const std::string &state, const double &value)
{
    if (allowed_states.find(state) != allowed_states.end())
    {
        energies[state] += value;
        if (energies[state] < 0.0)
        {
            double extra_energy = energies[state] * (-1);
            energies[state] = 0.0;
            return extra_energy;
        }
        return 0.0;
    }
    //std::cout << "warning: Energy_container::add: "
    //          << "unallowed type of energy: "
    //          << state << std::endl;
    return value;
}

double Energy_container::pass(Energy_container &target_container,
                              const double &value,
                              const std::string &state)
{
    return target_container.add(state, value);
}

void Energy_container::add_state(const std::string &new_state)
{
    allowed_states.insert(new_state);
}