#pragma once
#include "AComponent.h"
//class handling N enemy airplanes. communicates with object pool
class FuelSwarmHandler : public AComponent
{
public:
	FuelSwarmHandler(int numFuel, string name);
	~FuelSwarmHandler();
	void perform();

private:
	const float SPAWN_INTERVAL = 15.00f;
	float ticks = 0.0f;
};