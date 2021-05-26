#include "Projectile.h"
#include "TextureManager.h"
#include "Game.h"
#include "ProjectileBehavior.h"
#include <iostream>
#include "Renderer.h"
#include "GameObjectManager.h"
#include "PlayerInputController.h"
#include "Collider.h"
#include "PhysicsManager.h"

Projectile::Projectile(string name) : APoolable(name)
{

}

void Projectile::initialize()
{
	//assign texture
	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture("bullet"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

	Renderer* renderer = new Renderer("BulletSprite");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	ProjectileBehavior* behavior = new ProjectileBehavior("ProjectileBehavior");
	this->attachComponent(behavior);
	behavior->configure(1.0f);

	Collider* collider = new Collider("ProjectileCollider", sprite);
	this->attachComponent(collider);

	PhysicsManager::getInstance()->trackObject(collider, 3);
}

void Projectile::onRelease()
{
	ProjectileBehavior* behavior = (ProjectileBehavior*)this->findComponentByName("ProjectileBehavior");
	behavior->reset();
	sf::Vector2f playerPos = GameObjectManager::getInstance()->findObjectByName("PlaneObject")->getTransformable()->getPosition();
	this->setPosition(playerPos.x, playerPos.y - 35);
}

void Projectile::onActivate()
{
	//reset state
	ProjectileBehavior* behavior = (ProjectileBehavior*)this->findComponentByName("ProjectileBehavior");
	behavior->reset();
	sf::Vector2f playerPos = GameObjectManager::getInstance()->findObjectByName("PlaneObject")->getTransformable()->getPosition();
	this->setPosition(playerPos.x, playerPos.y - 35);
}

APoolable* Projectile::clone()
{
	APoolable* copyObj = new Projectile(this->name);
	return copyObj;
}