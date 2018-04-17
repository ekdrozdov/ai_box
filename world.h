#pragma once
#include <iostream>
#include <stdio.h>
#include "space.h"
#include "time.h"

class World {
public:
	World(Time time, Space space);
	~World();
	void tick();

	Time time;
	Space space;
};
