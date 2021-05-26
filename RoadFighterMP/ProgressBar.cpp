#include "ProgressBar.h"
#include "TextureManager.h"
#include "Game.h"
#include "ProgressBarInputController.h"
#include "ProgressBarMovement.h"
#include "Renderer.h"

ProgressBar::ProgressBar(std::string name) : AGameObject(name) {}

void ProgressBar::initialize() {

	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture("minicar"));

	getTransformable()->setPosition(20, Game::WINDOW_WIDTH - 70);

	PGInputController* inputController = new PGInputController("MyPlayerInput");
	this->attachComponent(inputController);

	ProgressBarMovement* movement = new ProgressBarMovement("PG_Movement");
	this->attachComponent(movement);

	Renderer* renderer = new Renderer("PG");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);
}