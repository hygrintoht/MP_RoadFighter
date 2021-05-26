#include "AGameObject.h"
#include "ProgressBarMovement.h"
#include "ProgressBarInputController.h"
#include "GameOverPopUp.h"
#include "GameObjectManager.h"
#include "HUDScreen.h"
#include "PhysicsManager.h"

ProgressBarMovement::ProgressBarMovement(string name) : AComponent(name, Script) {}

ProgressBarMovement::~ProgressBarMovement() {
	AComponent::~AComponent();
}

void ProgressBarMovement::perform() 
{
	HUDScreen* hud = (HUDScreen*)GameObjectManager::getInstance()->findObjectByName("HUDScreen");
	hud->fuelString = "FUEL: " + to_string(hud->playerFuel);
	hud->fuelText->setText(hud->fuelString);

	//if (PhysicsManager::getInstance()->getFuel())
	//
	//	hud->playerFuel += 5;
	//}

	PGInputController* inputController = (PGInputController*)this->getOwner()->getComponentsOfType(ComponentType::Input)[0];
	sf::Transformable* PGTransformable = this->getOwner()->getTransformable();

	sf::Vector2f offset(0.0f, 0.0f);

	if (inputController->isSpace()) {
		offset.y -= this->SPEED_MULTIPLIER;
		PGTransformable->move(offset * deltaTime.asSeconds());
		this->ticks += deltaTime.asSeconds() * 2;
		if (this->ticks > 1)
		{
			hud->playerFuel--;
			this->ticks = 0;
		}
	}
	if (PGTransformable->getPosition().y < 60) {
		GameOverPopUp* gameOverPopUp = new GameOverPopUp("gameOverPopUp");
		GameObjectManager::getInstance()->addObject(gameOverPopUp);
	}
	if (hud->playerFuel <= 0)
	{
		GameOverPopUp* gameOverPopUp = new GameOverPopUp("gameOverPopUp");
		GameObjectManager::getInstance()->addObject(gameOverPopUp);
	}
}