#pragma once
#include <map>
#include <iostream>
#include "energy.h"

class Energy_container
{
public:
  // Shall return extra energy, that has not been added;
  double add(const std::string &state, const double &value);
  double pass(Energy_container &target_container,
              const double &value,
              const std::string &state);
  void add_state(const std::string &new_state);

  //void set_capacity(const std::string &new_state);

protected:
  double capacity;
  std::set<std::string> allowed_states;
  std::map<std::string, double> energies;
};