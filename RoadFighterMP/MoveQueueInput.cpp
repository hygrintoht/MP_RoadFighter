#include "MoveQueueInput.h"
#include "AirplanePlayer.h"
#include <conio.h>
MoveQueueInput::MoveQueueInput(string name) : GenericInputController(name)
{

}

MoveQueueInput::~MoveQueueInput()
{
	GenericInputController::~GenericInputController();
}

void MoveQueueInput::perform()
{
	AirplanePlayer* player = (AirplanePlayer*)this->owner;
	bool keyFlag = false;
	if (event.type == sf::Event::KeyPressed) {
		keyFlag = true;
	}
	else if (event.type == sf::Event::KeyReleased) {
		keyFlag = false;
	}
	switch (event.key.code) {
	case sf::Keyboard::W:
		player->moveUp = keyFlag;
		break;
	case sf::Keyboard::A:
		player->moveLeft = keyFlag;
		break;
	case sf::Keyboard::S:
		player->moveDown = keyFlag;
		break;
	case sf::Keyboard::D:
		player->moveRight = keyFlag;
		break;
	case sf::Keyboard::Space:
		player->moveStop = keyFlag;
		break;
	case sf::Keyboard::Enter:
		player->isEntered = true;
		break;
	}
}
