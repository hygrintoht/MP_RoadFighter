#include "GameScreen.h"
#include "Game.h"
#include "GameObjectManager.h"
#include "BGObject.h"
#include "AirplanePlayer.h"
#include "AirplaneSupport.h"
#include "EmptyGameObject.h"
#include "EnemySwarmHandler.h"
#include "HUDScreen.h"



GameScreen::GameScreen(string name) : AGameObject(name), ButtonListener()
{
}

GameScreen::~GameScreen()
{
	AGameObject::~AGameObject();
}

void GameScreen::initialize()
{
	BGObject* bgObject = new BGObject("BGObject");
	GameObjectManager::getInstance()->addObject(bgObject);

	AirplanePlayer* planeObject = new AirplanePlayer("PlaneObject");
	GameObjectManager::getInstance()->addObject(planeObject);

	AirplaneSupport* support1 = new AirplaneSupport("AirSupport_1");
	planeObject->attachChild(support1);
	support1->setPosition(50, 100);

	AirplaneSupport* support2 = new AirplaneSupport("AirSupport_2");
	planeObject->attachChild(support2);
	support2->setPosition(-50, 100);

	HUDScreen* hudScreen = new HUDScreen("HUDScreen");
	GameObjectManager::getInstance()->addObject(hudScreen);

	//create N enemies via object pooling
	srand(time(NULL));
	EmptyGameObject* enemiesManager = new EmptyGameObject("EnemiesManager");
	EnemySwarmHandler* swarmHandler = new EnemySwarmHandler(200, "SwarmHandler");
	enemiesManager->attachComponent(swarmHandler);
	GameObjectManager::getInstance()->addObject(enemiesManager);
}

void GameScreen::onButtonClick(UIButton* button)
{
}

void GameScreen::onButtonReleased(UIButton* button)
{
}