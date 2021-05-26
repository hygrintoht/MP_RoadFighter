#include "BGMovement.h"
#include "Game.h"
#include "AGameObject.h"
#include "BGInputController.h"
BGMovement::BGMovement(string name) : AComponent(name, Script)
{

}

BGMovement::~BGMovement()
{
	AComponent::~AComponent();
}

void BGMovement::perform()
{
	BGInputController* inputController = (BGInputController*)this->getOwner()->getComponentsOfType(ComponentType::Input)[0];
	//make BG scroll slowly
	sf::Vector2f offset(0.0f, 0.0f);
	//offset.y += SPEED_MULTIPLIER;
	//this->getOwner()->getTransformable()->move(offset * deltaTime.asSeconds());
	sf::Transformable* BGTransformable = this->getOwner()->getTransformable();

	if (inputController->isSpace() && velocity < SPEED_MULTIPLIER) {
		velocity += 100 * deltaTime.asSeconds();
		offset.y += velocity;
		BGTransformable->move(offset * deltaTime.asSeconds());
	}
	else if (inputController->isSpace()) {
		//velocity += 100 * deltaTime.asSeconds();
		offset.y += velocity;
		BGTransformable->move(offset * deltaTime.asSeconds());
	}
	else if (!(inputController->isSpace()) && velocity > 0) {
		velocity -= 100 * deltaTime.asSeconds();
		offset.y += velocity;
		BGTransformable->move(offset * deltaTime.asSeconds());
	}

	sf::Vector2f localPos = this->getOwner()->getTransformable()->getPosition();
	if (localPos.y * deltaTime.asSeconds() > 0) {
		//reset position
		this->getOwner()->getTransformable()->setPosition(0, -Game::WINDOW_HEIGHT * 7);
	}

}