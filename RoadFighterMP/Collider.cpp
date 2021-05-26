#include "Collider.h"

void Collider::setCollisionListener(CollisionListener* listener)
{
	this->listener = listener;
	//
	//
}

void Collider::setChecked(bool flag)
{
	this->checked = flag;
}

bool Collider::isChecked()
{
	return this->checked;
}

bool Collider::willCollide(Collider* another)
{
    if (this->getGlobalBounds().intersects(another->getGlobalBounds()))
        return true;

    return false;
}

bool Collider::alreadyCollided()
{
	return this->collided;
}

void Collider::setAlreadyCollided(bool flag)
{
	this->collided = flag;
}

sf::FloatRect Collider::getGlobalBounds()
{
	//cout << "Entered collider getGlobalBounds" << endl;
	sf::FloatRect bounds = this->objectSprite->getGlobalBounds();
	bounds = this->owner->getGlobalTransform().transformRect(bounds);

	return bounds;
}

void Collider::setLocalBounds(sf::FloatRect localBounds)
{
	this->localBounds = localBounds;
}

void Collider::collisionEnter(AGameObject* gameObjects)
{

}

void Collider::collisionExit(AGameObject* gameObjects)
{
}

void Collider::perform()
{
}
