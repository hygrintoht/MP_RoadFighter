#pragma once
#include "GenericInputController.h"

class MoveQueueInput : public GenericInputController
{
public:
	MoveQueueInput(string name);
	~MoveQueueInput();

	void perform();

private:
	const float SPEED_MULTIPLIER = 300.0f;
};
