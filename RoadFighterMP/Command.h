#pragma once
#include <queue>
#include <string>
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class Command
{
public:
	virtual ~Command() {}
	virtual void execute(Transformable*, Time, const float, queue<string>&) = 0;
};

class MoveUpCommand : public Command
{
public:
	virtual void execute(Transformable*, Time, const float, queue<string>&); //{ moveUp(); }
};

class MoveDownCommand : public Command
{
public:
	virtual void execute(Transformable*, Time, const float, queue<string>&); //{ moveDown(); }
};

class MoveLeftCommand : public Command
{
public:
	virtual void execute(Transformable*, Time, const float, queue<string>&); //{ moveLeft(); }
};

class MoveRightCommand : public Command
{
public:
	virtual void execute(Transformable*, Time, const float, queue<string>&); //{ moveRight(); }
};

class StopCommand : public Command
{
public:
	virtual void execute(Transformable*, Time, const float, queue<string>&); //{ moveRight(); }
};
