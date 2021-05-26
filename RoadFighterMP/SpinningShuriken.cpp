#include "SpinningShuriken.h"
#include "TextureManager.h"
#include "SpinningShurikenMovement.h"
#include "Renderer.h"

SpinningShuriken::SpinningShuriken(std::string name) :AGameObject(name)
{
}

void SpinningShuriken::initialize()
{
	//assign texture
	sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture("spike"));
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	sprite->setPosition(0, 0);
	sprite->setScale(0.15f, 0.15f);

	//assign components
	SpinningShurikenMovement* logicComponent = new SpinningShurikenMovement("SpinningShurikenMovement_1");
	this->attachComponent(logicComponent);

	Renderer* renderer = new Renderer("SupportSprite");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

}
