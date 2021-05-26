#include "EnemyBehavior.h"
#include "AGameObject.h"
#include <iostream>
#include "Game.h";
#include "ObjectPoolHolder.h"

EnemyBehavior::EnemyBehavior(string name) : AComponent(name, Script)
{
	this->reset();
}

void EnemyBehavior::perform()
{
	this->ticks += this->deltaTime.asSeconds();
	sf::Transformable* transformable = this->getOwner()->getTransformable();

	if (this->movementType == Forward) {
		transformable->move(0, this->deltaTime.asSeconds() * SPEED_MULTIPLIER);
	}
	if (transformable->getPosition().y > Game::WINDOW_HEIGHT + 30) {
		ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG)->releasePoolable((APoolable*)this->getOwner());
	}
}

void EnemyBehavior::configure(float delay)
{
	this->delay += delay;
}

void EnemyBehavior::reset()
{
	//this->delay = (rand() % 3);
	this->movementType = Forward;
	this->forwardDuration = (rand() % 3) + 1.0f;
	//this->forwardDuration = 1.0f;
	this->ticks = 0.0f;
}