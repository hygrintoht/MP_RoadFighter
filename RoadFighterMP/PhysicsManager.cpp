#include "PhysicsManager.h"
#include <iostream>
#include "ObjectPoolHolder.h"
#include "GameOverPopUp.h"
#include "GameObjectManager.h"
#include "HUDScreen.h"

PhysicsManager* PhysicsManager::sharedInstance = NULL;

void PhysicsManager::initialize(string name, AGameObject* parent)
{
    PhysicsManager* physicsManager = new PhysicsManager(name);
    parent->attachComponent(physicsManager);
}

void PhysicsManager::destroy()
{
    sharedInstance = NULL;
}

PhysicsManager* PhysicsManager::getInstance()
{
	if (sharedInstance == NULL) {
		sharedInstance = new PhysicsManager("placeholder");
	}

	return sharedInstance;
}

PhysicsManager::~PhysicsManager()
{
}

void PhysicsManager::trackObject(Collider* object)
{
	trackedObjects.push_back(object);
}

void PhysicsManager::trackFuel(Collider* object)
{
    trackedFuel.push_back(object);
}

void PhysicsManager::untrackObject(Collider* object)
{
	//forCleaningObjects.push_back(object);
	//delete object;
	//trackedObjects.erase(std::remove(trackedObjects.begin(), trackedObjects.end(), object), trackedObjects.end());
	//trackedObjects.shrink_to_fit();
}

void PhysicsManager::perform()
{
    HUDScreen* hud = (HUDScreen*)GameObjectManager::getInstance()->findObjectByName("HUDScreen");

    for (int i = 1; i < sharedInstance->trackedObjects.size(); i++)
    {
        if (sharedInstance->trackedObjects[0]->willCollide(sharedInstance->trackedObjects[i]))
        {/////PlayerCar and EnemyCar collision
            sharedInstance->trackedObjects[0]->setAlreadyCollided(true);
            this->ticks = 0;
            //GameOverPopUp* gameOverPopUp = new GameOverPopUp("gameOverPopUp");
            //GameObjectManager::getInstance()->addObject(gameOverPopUp);
        }
    }

    if (sharedInstance->trackedObjects[0]->alreadyCollided())
    {/////PlayerCar spins for a fixed time
        this->ticks += this->deltaTime.asSeconds();
        if (this->ticks < 3)
        {
            sharedInstance->trackedObjects[0]->getOwner()->getTransformable()->rotate(15);
        }
        else
        {
            sharedInstance->trackedObjects[0]->getOwner()->getTransformable()->setRotation(0);
            sharedInstance->trackedObjects[0]->setAlreadyCollided(false);
            this->ticks = 0;
        }
    }

    for (int i = 1; i < sharedInstance->trackedObjects.size(); i++)
    {
        for (int j = i+1; j < sharedInstance->trackedObjects.size(); j++)
        {
            if (sharedInstance->trackedObjects[i]->willCollide(sharedInstance->trackedObjects[j]))
            {//////EnemyCar and EnemyCar spawn collision
                ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG)->releasePoolable((APoolable*)sharedInstance->trackedObjects[j]->getOwner());
            }
        }
        for (int y = 0; y < sharedInstance->trackedFuel.size(); y++)
        {
            if (sharedInstance->trackedFuel[y]->willCollide(sharedInstance->trackedObjects[i]))
            {//////EnemyCar and fuel spawn collision
                ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::FUEL_POOL_TAG)->releasePoolable((APoolable*)sharedInstance->trackedFuel[y]->getOwner());
            }

            if (sharedInstance->trackedObjects[0]->willCollide(sharedInstance->trackedFuel[y]))
            {//////PlayerCar and fuel refill collision
                ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::FUEL_POOL_TAG)->releasePoolable((APoolable*)sharedInstance->trackedFuel[y]->getOwner());
                hud->playerFuel += 5;
            }
        }
    }
}

void PhysicsManager::cleanUpObjects()
{
    sharedInstance->trackedObjects.clear();
    sharedInstance->trackedFuel.clear();
}

bool PhysicsManager::getFuel()
{
    bool refillPlayer = this->refill;
    this->refill = false;
    return refillPlayer;
}
