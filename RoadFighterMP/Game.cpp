#include "Game.h"
#include "TextureManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameObjectManager.h"
#include "BGObject.h"
#include "AirplanePlayer.h"
#include "AirplaneSupport.h"
#include "MainMenuScreen.h"
#include "FontManager.h"
#include "ApplicationManager.h"
#include "HUDScreen.h"
#include "EnemyAirplane.h"
#include "GameObjectPool.h"
#include "EmptyGameObject.h"
#include "EnemySwarmHandler.h"
#include "MainMenuScene.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "SFXManager.h"

Game::Game() : 
mWindow(sf::VideoMode(Game::WINDOW_WIDTH, Game::WINDOW_HEIGHT), "SFML Application") {
    TextureManager::getInstance()->loadAll();
    FontManager::getInstance()->loadAll();
    SFXManager::getInstance()->loadAll();
    ApplicationManager::getInstance()->initialize(&this->mWindow);
     
    //reigster scemes
    SceneManager::getInstance()->registerScene(new MainMenuScene());
    SceneManager::getInstance()->registerScene(new GameScene());

    //load first scene
    SceneManager::getInstance()->loadScene(SceneManager::MAIN_MENU_SCENE_NAME);
};


void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen()) {

        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
        SceneManager::getInstance()->checkLoadScene();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            mWindow.close();
            break;
        default:
            GameObjectManager::getInstance()->processInput(event);
            break;
        }
    }
}

void Game::update(sf::Time deltaTime) {
    if (!ApplicationManager::getInstance()->isPaused()) {
        GameObjectManager::getInstance()->update(deltaTime);
        SceneManager::getInstance()->checkLoadScene();
    }
}

void Game::render() {
  mWindow.clear();
  GameObjectManager::getInstance()->draw(&mWindow);
  mWindow.display();
}

