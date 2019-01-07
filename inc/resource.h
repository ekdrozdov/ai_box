#pragma once
#include <map>
#include <set>
#include <iostream>
#include "energy.h"

// QUESTIONS
// Maybe make control function virtual?
// Energy container could contain only 1 type of energy.
class Resource
{
public:
  Resource();
  // Shall return extra energy, that has not been added.
  Energy add(const Energy &energy);
  // Shall return as much energy, as possible to fulfill count.
  Energy extract(const double &count);
  // Shall return same value as add(), but don't change anything within an object.
  double get_overflow(const double &addition) const;

  // Shall return state of the storing energy.
  Energy_state get_state() const;
  double get_energy_count() const { return energy.get_count(); }

  // double get_capacity();
  // // Shall return extra energy, that can't be stored anymore.
  // Energy set_capacity(const double &new_capacity);
  // Energy inc_capacity(const double &capacity);
  // Energy dec_capacity(const double &capacity);

  // double get_limit();
  // bool set_limit(const double &new_single_acception_limit);
  // bool inc_limit(const double &new_single_acception_limit);
  // bool dec_limit(const double &new_single_acception_limit);

protected:
  double capacity = 0.;
  double permeability = 0.;

private:
  Energy energy;
};

bool operator<(const Resource &lhs, const Resource &rhs);

// todo on next iteration
// class Energy_multicontainer
// {
// public:
//   // Insert container to set, and if it already exist, add container to existing.
//   // Return extra-energy.
//   double add_container();
//   // Remove container and return extra energy.
//   double remove_container();
//   bool is_allowed(std::string state);
//   bool allow_state();

// protected:
//   std::set<Resource> containers;

//   std::set<std::string> allowed_states;
//   std::map<std::string, double> energies;
// };