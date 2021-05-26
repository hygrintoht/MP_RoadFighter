#pragma once
#include "APoolable.h"
class Projectile : public APoolable
{
public:
	Projectile(string name);
	void initialize();
	void onRelease();
	void onActivate();
	APoolable* clone();

private:
	int counter = 0;
};