#include "energy_container.h"

enum Node_states
{
	water,
	earth
};

class Node : Energy_container
{
public:

private:
	Node_states state;
	double permeability = 0.0;
	double capacity = 0.0;
};
