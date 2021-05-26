#include "ProjectileSwarmHandler.h"
#include "GameObjectPool.h"
#include "ObjectPoolHolder.h"
#include "Projectile.h"
#include "AirplanePlayer.h"
#include "PlayerInputController.h"

ProjectileSwarmHandler::ProjectileSwarmHandler(int numProjectiles, string name) : AComponent(name, Script)
{
	GameObjectPool* projectilePool = new GameObjectPool(ObjectPoolHolder::PROJECTILE_POOL_TAG, new Projectile("bullet"), numProjectiles, NULL);
	projectilePool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(projectilePool);
}

ProjectileSwarmHandler::~ProjectileSwarmHandler()
{

}

void ProjectileSwarmHandler::perform()
{
	GameObjectPool* projectilePool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::PROJECTILE_POOL_TAG);
	this->ticks += this->deltaTime.asSeconds();

	AirplanePlayer* player = (AirplanePlayer*)this->owner;
	PlayerInputController* playerInputs = (PlayerInputController*)player->findComponentByName("MyPlayerInput");
	
	if (this->ticks > SPAWN_INTERVAL && playerInputs->isShooting()) {
		this->ticks = 0.0f;
		projectilePool->requestPoolable();
	}
}