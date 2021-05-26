#pragma once
#include "AComponent.h"
class ProjectileBehavior : public AComponent
{
public:
	enum ProjectileMovementType { Delay = 0, Forward = 1, SlowForward = 2, Side = 3 };

	ProjectileBehavior(string name);
	void perform();
	void configure(float delay);
	void reset();

private:
	const float SPEED_MULTIPLIER = 100.0f;
	ProjectileMovementType movementType = Forward;
	float ticks = 0.0f;
	float delay = 0.0f;
	float forwardDuration = 0.0f;
};
