#include "BGInputController.h"

BGInputController::BGInputController(string name) : GenericInputController(name) {}

BGInputController::~BGInputController()
{
	GenericInputController::~GenericInputController();
}

void BGInputController::perform() {

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

bool BGInputController::isSpace() {
	return this->moveSpace;
}