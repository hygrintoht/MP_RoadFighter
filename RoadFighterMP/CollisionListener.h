#pragma once
#include "AGameObject.h"

class Collider;
class CollisionListener {

public:
	//add pure virtual functions here
	virtual ~CollisionListener() {}

	virtual void onCollission(Collider* collide) = 0;

protected:
	CollisionListener() {}
};