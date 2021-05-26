#pragma once
#include "AGameObject.h"
class ProgressBar : public AGameObject
{
public:
	ProgressBar(std::string name);
	void initialize();
private:
	const float SPEED_MULTIPLIER = -10.0f;
	bool moveSpace = false;
};

