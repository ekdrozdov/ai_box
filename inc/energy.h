#pragma once
#include <stdexcept>
#include <string>
#include <set>

class Base_energy_states
{
public:
  inline std::set<std::string> get_states() const
  {
    return states;
  };

private:
  static std::set<std::string> states;
};

class Energy_state
{
public:
  inline Energy_state() { state = "water"; };
  inline Energy_state(const std::string &state) { this->state = state; };
  std::string state;
};

bool operator<(const Energy_state &lhs, const Energy_state &rhs);
bool operator==(const Energy_state &lhs, const Energy_state &rhs);

class Energy
{
public:
  Energy();
  Energy(const double &count);
  Energy(const double &count, const Energy_state &state);

  // bool add(const Energy &energy);
  // double sub(const double &count);

  void inc(const double &count);
  double dec(const double &count);
  double get_count() const;
  //double set_count(const double &count);
  inline Energy_state get_state() const { return state; };

private:
  double count;
  Energy_state state;
};

Energy operator+=(const Energy &lhs, const Energy &rhs);
