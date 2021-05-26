#include "FuelSwarmHandler.h"
#include "GameObjectPool.h"
#include "ObjectPoolHolder.h"
#include "Fuel.h"

FuelSwarmHandler::FuelSwarmHandler(int numFuel, string name) : AComponent(name, Script)
{
	GameObjectPool* fuelPool = new GameObjectPool(ObjectPoolHolder::FUEL_POOL_TAG, new Fuel("fuel"), numFuel, NULL);
	fuelPool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(fuelPool);
}

FuelSwarmHandler::~FuelSwarmHandler()
{

}

void FuelSwarmHandler::perform()
{
	GameObjectPool* fuelPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::FUEL_POOL_TAG);
	this->ticks += this->deltaTime.asSeconds();

	if (this->ticks > SPAWN_INTERVAL) {
		this->ticks = 0.0f;
		fuelPool->requestPoolable();
	}
}