#pragma once
#include "AComponent.h"
class FuelBehavior : public AComponent
{
public:
	enum FuelMovementType { Delay = 0, Forward = 1, SlowForward = 2, Side = 3 };

	FuelBehavior(string name);
	void perform();
	void configure(float delay);
	void reset();

private:
	const float SPEED_MULTIPLIER = 200.0f;
	FuelMovementType movementType = Forward;
	float ticks = 0.0f;
	float delay = 0.0f;
	float forwardDuration = 0.0f;
};
