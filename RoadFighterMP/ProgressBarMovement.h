#pragma once
#include "AComponent.h"
class ProgressBarMovement : public AComponent {
public:
	ProgressBarMovement(string name);
	~ProgressBarMovement();
	
	void perform();

private:
	const float SPEED_MULTIPLIER = 15.0f;
	float distance = 0;
	float ticks = 0;
};