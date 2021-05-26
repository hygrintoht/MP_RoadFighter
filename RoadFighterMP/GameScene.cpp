#include "GameScene.h"
#include "BGObject.h"
#include "AirplanePlayer.h"
#include "EnemyAirplane.h"
#include "GameObjectPool.h"
#include "ObjectPoolHolder.h"
#include "EmptyGameObject.h"
#include "EnemySwarmHandler.h"
#include "HUDScreen.h"
#include "PhysicsManager.h"
#include "Fuel.h"
#include "FuelSwarmHandler.h"
#include "ProgressBar.h"
#include "ProgressBarBG.h"

GameScene::GameScene() :AScene("GameScene")
{

}

GameScene::~GameScene()
{
}

void GameScene::onLoadResources()
{
}

void GameScene::onLoadObjects()
{
    BGObject* bgObject = new BGObject("BGObject");
    this->registerObject(bgObject);

    AirplanePlayer* planeObject = new AirplanePlayer("PlaneObject");
    this->registerObject(planeObject);

    HUDScreen* hudScreen = new HUDScreen("HUDScreen");
    this->registerObject(hudScreen);

    ProgressBarBG* pbBG = new ProgressBarBG("pb_bg");
    this->registerObject(pbBG);

    ProgressBar* progressBar = new ProgressBar("progressBar");
    this->registerObject(progressBar);

    //create N enemies via object pooling
    srand(time(NULL));
    EmptyGameObject* enemiesManager = new EmptyGameObject("EnemiesManager");
    EnemySwarmHandler* swarmHandler = new EnemySwarmHandler(5, "EnemySwarm");
    enemiesManager->attachComponent(swarmHandler);
    this->registerObject(enemiesManager);

    //create N fuel via object pooling
    EmptyGameObject* fuelManager = new EmptyGameObject("FuelManager");
    FuelSwarmHandler* fuelSwarm = new FuelSwarmHandler(5, "FuelSwarm");
    fuelManager->attachComponent(fuelSwarm);
    this->registerObject(fuelManager);

    PhysicsManager::initialize("psixManager", planeObject);
}

void GameScene::onUnloadObjects()
{
	GameObjectPool* enemyPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG);
	ObjectPoolHolder::getInstance()->unregisterObjectPool(enemyPool);
	AScene::onUnloadObjects();

    GameObjectPool* fuelPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::FUEL_POOL_TAG);
    ObjectPoolHolder::getInstance()->unregisterObjectPool(fuelPool);
    AScene::onUnloadObjects();

    PhysicsManager::getInstance()->cleanUpObjects();//clears trackedobjects
    AScene::onUnloadObjects();
}


void GameScene::onUnloadResources()
{
}