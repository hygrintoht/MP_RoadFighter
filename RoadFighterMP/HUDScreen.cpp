#include "HUDScreen.h"
#include "TextureManager.h"
#include "Game.h"
#include "UIButton.h"
#include "UIText.h"
#include "QuitScreen.h"
#include "GameObjectManager.h"
#include "Renderer.h"
#include <iostream>

HUDScreen::HUDScreen(string name) : AGameObject(name), ButtonListener()
{

}

HUDScreen::~HUDScreen()
{
	AGameObject::~AGameObject();
}

void HUDScreen::initialize()
{
	this->setPosition(100, 50);
	sf::Texture* btnNormal = TextureManager::getInstance()->getTexture("btn_normal");
	sf::Texture* btnPressed = TextureManager::getInstance()->getTexture("btn_pressed");
	UIButton* quitBtn = new UIButton("quitBtn", btnNormal, btnPressed);
	this->attachChild(quitBtn);
	quitBtn->setPosition(0, 0);
	quitBtn->getTransformable()->setScale(0.15f, 0.15f);
	quitBtn->setButtonListener(this);

	UIText* button_1Text = new UIText("text_1");
	//do not make as a button child. difficult to position
	quitBtn->attachChild(button_1Text);
	button_1Text->setPosition(0, -50);
	button_1Text->setSize(150);
	button_1Text->setText("QUIT");


	this->fuelString = "FUEL: " + to_string(this->playerFuel);

	this->fuelText = new UIText("fuel_text1");
	this->attachChild(this->fuelText);
	this->fuelText->setPosition(0, Game::WINDOW_HEIGHT - 150);
	this->fuelText->setSize(20);
	this->fuelText->setText(this->fuelString);
}

void HUDScreen::onButtonClick(UIButton* button)
{
}

void HUDScreen::onButtonReleased(UIButton* button)
{
	if (button->getName() == "quitBtn") {
		QuitScreen* quitScreen = new QuitScreen("quitScreen");
		quitScreen->markGameQuit();
		GameObjectManager::getInstance()->addObject(quitScreen);
	}
}
