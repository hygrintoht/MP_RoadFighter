#include "FuelBehavior.h"
#include "AGameObject.h"
#include <iostream>
#include "Game.h";
#include "ObjectPoolHolder.h"

FuelBehavior::FuelBehavior(string name) : AComponent(name, Script)
{
	this->reset();
}

void FuelBehavior::perform()
{
	this->ticks += this->deltaTime.asSeconds();
	sf::Transformable* transformable = this->getOwner()->getTransformable();

	if (this->movementType == Forward) {
		transformable->move(0, this->deltaTime.asSeconds() * SPEED_MULTIPLIER);
	}
	if (transformable->getPosition().y > Game::WINDOW_HEIGHT + 30) {
		ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::FUEL_POOL_TAG)->releasePoolable((APoolable*)this->getOwner());
	}
}

void FuelBehavior::configure(float delay)
{
	this->delay += delay;
}

void FuelBehavior::reset()
{
	//this->delay = (rand() % 3);
	this->movementType = Forward;
	this->forwardDuration = (rand() % 3) + 1.0f;
	//this->forwardDuration = 1.0f;
	this->ticks = 0.0f;
}