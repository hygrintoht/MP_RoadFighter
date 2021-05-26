#pragma once
#include "GenericInputController.h"

class BGInputController : public GenericInputController
{
public:
	BGInputController(string name);
	~BGInputController();

	void perform();
	bool isSpace();

private:
	const float SPEED_MULTIPLIER = 300.0f;
	bool moveSpace = false;
};
