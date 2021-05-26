#include "ProgressBarInputController.h"

PGInputController::PGInputController(string name) : GenericInputController(name) {}

PGInputController::~PGInputController()
{
	GenericInputController::~GenericInputController();
}

void PGInputController::perform() {

	bool keyFlag = false;
	if (event.type == sf::Event::KeyPressed) {
		keyFlag = true;
	}
	else if (event.type == sf::Event::KeyReleased) {
		keyFlag = false;
	}

	switch (event.key.code) {
	case sf::Keyboard::Space:
		this->moveSpace = keyFlag;
		break;
	}
}

bool PGInputController::isSpace() {
	return this->moveSpace;
}