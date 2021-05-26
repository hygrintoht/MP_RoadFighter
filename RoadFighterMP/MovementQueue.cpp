#include "MovementQueue.h"
#include "AGameObject.h"
#include "MoveQueueInput.h"
#include <iostream>
#include "AirplanePlayer.h"
#include <string>
MovementQueue::MovementQueue(string name) : AComponent(name, Script)
{

}

MovementQueue::~MovementQueue()
{
	AComponent::~AComponent();
}

void MovementQueue::perform()
{
	AirplanePlayer* player = (AirplanePlayer*)this->getOwner();
	sf::Transformable* playerTransformable = this->getOwner()->getTransformable();
	if (playerTransformable == NULL || player == NULL) {
		cout << "One or more of the needed dependencies are missing!\n";
		return;
	}

	if (player->moveUp) {
		upCommand = new MoveUpCommand();
		this->moveQueue.push("Up");
		cout << "Queueing: Up" << '\n';
		player->moveUp = false;
	}
	else if (player->moveDown) {
		downCommand = new MoveDownCommand();
		this->moveQueue.push("Down");
		cout << "Queueing: Down" << '\n';
		player->moveDown = false;
	}
	else if (player->moveRight) {
		rightCommand = new MoveRightCommand();
		this->moveQueue.push("Right");
		cout << "Queueing: Right" << '\n';
		player->moveRight = false;
	}
	else if (player->moveLeft) {
		leftCommand = new MoveLeftCommand();
		this->moveQueue.push("Left");
		cout << "Queueing: Left" << '\n';
		player->moveLeft = false;
	}
	else if (player->moveStop) {
		stopCommand = new StopCommand();
		this->moveQueue.push("Stop");
		cout << "Queueing: Stop" << '\n';
		player->moveStop = false;
	}

	if (!this->moveQueue.empty() && player->isEntered) {
		
		if (this->moveQueue.front().compare("Up") == 0) {
			upCommand->execute(playerTransformable, deltaTime, this->SPEED_MULTIPLIER, this->moveQueue);
		}
		else if (this->moveQueue.front().compare("Down") == 0) {
			downCommand->execute(playerTransformable, deltaTime, this->SPEED_MULTIPLIER, this->moveQueue);
		}
		else if (this->moveQueue.front().compare("Right") == 0) {
			rightCommand->execute(playerTransformable, deltaTime, this->SPEED_MULTIPLIER, this->moveQueue);
		}
		else if (this->moveQueue.front().compare("Left") == 0) {
			leftCommand->execute(playerTransformable, deltaTime, this->SPEED_MULTIPLIER, this->moveQueue);
		}
		else if (this->moveQueue.front().compare("Stop") == 0) {
			stopCommand->execute(playerTransformable, deltaTime, this->SPEED_MULTIPLIER, this->moveQueue);
		}
		//////////////////////////TIMER
		if (this->isFirstExecute)
		{
			cout << "------------------" << endl << "Starting Execution" << endl;
			this->start = clock();
			this->isFirstExecute = false;
		}
		float timer = (clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
		//std::cout << "Time: " << timer << " ms" << std::endl;
		if (timer >= 500) {
			if (this->moveQueue.front().compare("Stop") == 0)
				cout << "Stopping " << endl;
			else
				cout << "MOVING " << this->moveQueue.front() << endl;
			//cout << "popped" << endl;
			this->moveQueue.pop();
			this->start = clock();
			timer = 0;
		}
		if (this->moveQueue.empty())
			cout << "End Execution" << endl << "------------------" << endl;
		//////////////////////////TIMER
	}
	else {
		player->isEntered = false;
		this->isFirstExecute = true;

	}
	
}