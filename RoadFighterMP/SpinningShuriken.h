#pragma once
#include "AGameObject.h"
class SpinningShuriken :
	public AGameObject
{
public:
	SpinningShuriken(std::string name);
	void initialize();
};
