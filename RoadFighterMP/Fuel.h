#pragma once
#include "APoolable.h"
class Fuel : public APoolable
{
public:
	Fuel(string name);
	void initialize();
	void onRelease();
	void onActivate();
	APoolable* clone();

private:
	int counter = 0;
};