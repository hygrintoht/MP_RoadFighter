#include "ProgressBarBG.h"
#include "TextureManager.h"
#include "Game.h"
#include "ProgressBarInputController.h"
#include "ProgressBarMovement.h"
#include "Renderer.h"

ProgressBarBG::ProgressBarBG(std::string name) : AGameObject(name) {}

void ProgressBarBG::initialize() {

	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture("pg_bg"));

	getTransformable()->setPosition(0, 0);

	Renderer* renderer = new Renderer("PGBG");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

}