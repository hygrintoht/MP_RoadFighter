#pragma once
#include "GenericInputController.h"

class PGInputController : public GenericInputController
{//probably not needed since there is allredy a controler for spacbar in bg input controler
public:
	PGInputController(string name);
	~PGInputController();

	void perform();
	bool isSpace();

private:
	const float SPEED_MULTIPLIER = 10.0f;
	bool moveSpace = false;
};
