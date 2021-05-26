#include "ProjectileBehavior.h"
#include "AGameObject.h"
#include <iostream>
#include "Game.h";
#include "ObjectPoolHolder.h"

ProjectileBehavior::ProjectileBehavior(string name) : AComponent(name, Script)
{
	this->reset();
}

void ProjectileBehavior::perform()
{
	this->ticks += this->deltaTime.asSeconds();
	sf::Transformable* transformable = this->getOwner()->getTransformable();

	if (this->movementType == Forward) {
		transformable->move(0, this->deltaTime.asSeconds() * -SPEED_MULTIPLIER);
	}
	//check if position is out of bounds, we can delete/return to pool
	if (transformable->getPosition().y < 0) {
		ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::PROJECTILE_POOL_TAG)->releasePoolable((APoolable*)this->getOwner());
	}
}

void ProjectileBehavior::configure(float delay)
{
	this->delay += delay;
}

void ProjectileBehavior::reset()
{
	//this->delay = (rand() % 3);
	this->movementType = Forward;
	this->forwardDuration = 350.0f;
	//this->forwardDuration = 1.0f;
	this->ticks = 0.0f;
}