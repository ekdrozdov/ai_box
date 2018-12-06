#include "energy.h"

std::set<std::string> Base_energy_states::states = {
    "wasted",
    "warm",
    "earth",
    "air",
    "water"};

Energy::Energy()
{
    this->count = 0;
}

Energy::Energy(const double &count)
{
    this->count = count < 0.0 ? 0.0 : count;
}

Energy::Energy(const double &count, const Energy_state &state)
{
    this->count = count < 0.0 ? 0.0 : count;
    this->state = state;
}

double Energy::inc(const double &count)
{
    // to do: what to return?
    this->count += count;
    if (this->count < 0.0)
    {
        double buf = this->count * (-1);
        this->count = 0.0;
        return buf;
    }
    return count;
}

double Energy::dec(const double &count)
{
    this->count -= count;
    if (this->count < 0.0)
        this->count = 0.0;
    return this->count;
}

double Energy::get_count() const
{
    return this->count;
}

double Energy::set_count(const double &count)
{
    this->count = count < 0.0 ? 0.0 : count;
    return this->count;
}
