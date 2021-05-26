#include "Fuel.h"
#include "TextureManager.h"
#include "Game.h"
#include "FuelBehavior.h"
#include <iostream>
#include "Renderer.h"
#include "Collider.h"
#include "PhysicsManager.h"

Fuel::Fuel(string name) : APoolable(name)
{

}

void Fuel::initialize()
{
	//assign texture
	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture("fuel"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

	this->setPosition(Game::WINDOW_WIDTH / 2, -30);
	//randomize
	this->getTransformable()->move(rand() % 175 - rand() % 175, -rand() % 400);
	this->getTransformable()->setRotation(180); //must face towards player


	Renderer* renderer = new Renderer("FuelSprite");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	FuelBehavior* behavior = new FuelBehavior("FuelBehavior");
	this->attachComponent(behavior);
	behavior->configure(1.0f);

	Collider* collider = new Collider("FuelCollider", sprite);
	this->attachComponent(collider);

	PhysicsManager::getInstance()->trackFuel(collider);
}

void Fuel::onRelease()
{
	FuelBehavior* behavior = (FuelBehavior*)this->findComponentByName("FuelBehavior");
	behavior->reset();
	this->setPosition(Game::WINDOW_WIDTH / 2, -30);
	this->getTransformable()->move(rand() % 175 - rand() % 175, -rand() % 400);
}

void Fuel::onActivate()
{
	//reset state
	FuelBehavior* behavior = (FuelBehavior*)this->findComponentByName("FuelBehavior");
	behavior->reset();
	this->setPosition(Game::WINDOW_WIDTH / 2, -30);
	//randomize
	this->getTransformable()->move(rand() % 175 - rand() % 175, -rand() % 400);
}

APoolable* Fuel::clone()
{
	APoolable* copyObj = new Fuel(this->name);
	return copyObj;
}