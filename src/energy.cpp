#include "energy.h"

std::set<std::string> Base_energy_states::states = {
    "wasted",
    "warm",
    "earth",
    "air",
    "water"};

bool operator==(const Energy_state &lhs, const Energy_state &rhs)
{
    return lhs.state == rhs.state;
}

bool operator<(const Energy_state &lhs, const Energy_state &rhs)
{
    return lhs.state < rhs.state;
}

Energy::Energy()
{
    this->count = 0.;
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

void Energy::inc(const double &count)
{
    if (count < 0.)
    {
        throw std::invalid_argument("Energy::inc(count) count should be non-negative");
    }

    this->count += count;
    // if (this->count < 0.0)
    // {
    //     double buf = this->count * (-1);
    //     this->count = 0.0;
    // }
}

double Energy::dec(const double &count)
{
    this->count -= count;
    if (this->count < 0.0)
    {
        double extra = -this->count;
        this->count = 0.0;
        return extra;
    }
    return 0.;
}

double Energy::get_count() const
{
    return this->count;
}

// bool Energy::add(const Energy &energy)
// {
//     if (this->state == energy.get_state())
//     {
//         this->count += energy.get_count();
//         return true;
//     }
//     return false;
// }

// double Energy::sub(const double &count)
// {
//     this->count -= count;
//     if (this->count < 0.0)
//     {
//         double extra = -this->count;
//         this->count = 0.0;
//         return extra;
//     }
//     return 0.;
// }

// double Energy::set_count(const double &count)
// {
//     this->count = count < 0.0 ? 0.0 : count;
//     return this->count;
// }

Energy operator+=(const Energy &lhs, const Energy &rhs)
{
    return Energy(lhs.get_count() + rhs.get_count());
}
