#include "MainMenuScreen.h"
#include "TextureManager.h"
#include "Game.h"
#include "Renderer.h"
#include "UIButton.h"
#include "UIText.h"
#include "SamplePopupScreen.h"
#include "GameObjectManager.h"
#include <iostream>
#include "SceneManager.h"
#include "QuitScreen.h"
#include "SFXManager.h"
#include "SFML/Audio.hpp"

MainMenuScreen::MainMenuScreen(string name) : AGameObject(name), ButtonListener()
{
}

MainMenuScreen::~MainMenuScreen()
{
	AGameObject::~AGameObject();
}

void MainMenuScreen::initialize()
{
	//sf::Sprite* sprite = new sf::Sprite();
	//sprite->setTexture(*TextureManager::getInstance()->getTexture("title_bg"));
	//sf::Vector2u textureSize = sprite->getTexture()->getSize();
	//sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

	//Renderer* renderer = new Renderer("MainMenuScreen");
	//renderer->assignDrawable(sprite);
	//this->attachComponent(renderer);

	UIText* GameTitle = new UIText("gameTitle");
	this->attachChild(GameTitle);
	GameTitle->setPosition(0, -200);
	GameTitle->setSize(75);
	GameTitle->setText("ROAD FIGHTER");

	float posX = Game::WINDOW_WIDTH / 2;
	float posY = Game::WINDOW_HEIGHT / 2;
	this->setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2);

	sf::Texture* btnNormal = TextureManager::getInstance()->getTexture("btn_normal");
	sf::Texture* btnPressed = TextureManager::getInstance()->getTexture("btn_pressed");

	UIButton* button1 = new UIButton("button_1", btnNormal, btnPressed);
	this->attachChild(button1);
	button1->setPosition(-150, 150);
	button1->getTransformable()->setScale(0.3f, 0.3f); 
	button1->setButtonListener(this);
	
	UIText* button_1Text = new UIText("text_1");
	button1->attachChild(button_1Text);
	button_1Text->setPosition(0, -20);
	button_1Text->setSize(100);
	button_1Text->setText("START");


	UIButton* button2 = new UIButton("button_2", btnNormal, btnPressed);
	this->attachChild(button2);
	button2->setPosition(150, 150);
	button2->getTransformable()->setScale(0.3f, 0.3f);
	button2->setButtonListener(this);
	UIText* button_2Text = new UIText("text_1");
	button2->attachChild(button_2Text);
	button_2Text->setPosition(0, -20);
	button_2Text->setSize(100);
	button_2Text->setText("EXIT");

	SFXManager::getInstance()->getSFX("bgm")->setLoop(true);
	SFXManager::getInstance()->getSFX("bgm")->play();
}

void MainMenuScreen::onButtonClick(UIButton* button)
{
}

void MainMenuScreen::onButtonReleased(UIButton* button)
{
	if (button->getName() == "button_1") {
		SceneManager::getInstance()->loadScene(SceneManager::GAME_SCENE_NAME);
	}
	else if (button->getName() == "button_2") {
		QuitScreen* quitScreen = new QuitScreen("QuitScreen");
		quitScreen->markMainMenuQuit();
		GameObjectManager::getInstance()->addObject(quitScreen);
	}
}


