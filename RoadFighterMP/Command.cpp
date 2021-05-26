#include "Command.h"
#include <iostream>

void MoveUpCommand::execute(Transformable* playerTransformable, Time deltaTime, const float SPEED_MULTIPLIER, queue<string>& moveQueue) {
	sf::Vector2f offset(0.0f, 0.0f);
	if (!moveQueue.empty()) {
		if (moveQueue.front().compare("Up") == 0) {
			offset.y -= SPEED_MULTIPLIER;
			playerTransformable->move(offset * deltaTime.asSeconds());
		}
	}
}

void MoveDownCommand::execute(Transformable* playerTransformable, Time deltaTime, const float SPEED_MULTIPLIER, queue<string>& moveQueue) {
	sf::Vector2f offset(0.0f, 0.0f);
	if (!moveQueue.empty()) {
		if (moveQueue.front().compare("Down") == 0) {
			offset.y += SPEED_MULTIPLIER;
			playerTransformable->move(offset * deltaTime.asSeconds());
		}
	}
}

void MoveLeftCommand::execute(Transformable* playerTransformable, Time deltaTime, const float SPEED_MULTIPLIER, queue<string>& moveQueue) {
	sf::Vector2f offset(0.0f, 0.0f);
	if (!moveQueue.empty()) {
		if (moveQueue.front().compare("Left") == 0) {
			offset.x -= SPEED_MULTIPLIER;
			playerTransformable->move(offset * deltaTime.asSeconds());
		}
	}
}

void MoveRightCommand::execute(Transformable* playerTransformable, Time deltaTime, const float SPEED_MULTIPLIER, queue<string>& moveQueue) {
	sf::Vector2f offset(0.0f, 0.0f);
	if (!moveQueue.empty()) {
		if (moveQueue.front().compare("Right") == 0) {
			offset.x += SPEED_MULTIPLIER;
			playerTransformable->move(offset * deltaTime.asSeconds());
		}
	}
}

void StopCommand::execute(Transformable* playerTransformable, Time deltaTime, const float SPEED_MULTIPLIER, queue<string>& moveQueue) {
}