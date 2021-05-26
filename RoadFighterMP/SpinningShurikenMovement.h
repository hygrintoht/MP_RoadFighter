#pragma once
#include "AComponent.h"
class SpinningShurikenMovement : public AComponent
{

public:
	SpinningShurikenMovement(string name);
	void perform();
	bool moveLeft = false;
	bool moveRight = false;

private:
	const float SPEED = 50.0f;

};

