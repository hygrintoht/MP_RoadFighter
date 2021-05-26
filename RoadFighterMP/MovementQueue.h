#pragma once
#include "AComponent.h"
#include <queue>
#include <ctime>
#include "Command.h"

class MovementQueue : public AComponent
{
public:
	MovementQueue(string name);
	~MovementQueue();

	void perform();

private:
	const float SPEED_MULTIPLIER = 300.0f;
	queue<string> moveQueue;
	Command* upCommand;
	Command* downCommand;
	Command* rightCommand;
	Command* leftCommand;
	Command* stopCommand;

	clock_t start = clock();
	bool isFirstExecute = true;
};
