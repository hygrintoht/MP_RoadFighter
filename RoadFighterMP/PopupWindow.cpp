#include "PopupWindow.h"
#include "TextureManager.h"
#include "Game.h"
#include "Renderer.h"
#include "UIButton.h"
#include "UIText.h"
#include <iostream>

PopupWindow::PopupWindow(string name) : AGameObject(name), ButtonListener()
{
}

PopupWindow::~PopupWindow()
{
	AGameObject::~AGameObject();
}

void PopupWindow::initialize()
{
	float posX = Game::WINDOW_WIDTH / 2;
	float posY = Game::WINDOW_HEIGHT / 2;
	this->setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2);
	
	sf::Texture* btnNormal = TextureManager::getInstance()->getTexture("btn_normal");
	sf::Texture* btnPressed = TextureManager::getInstance()->getTexture("btn_pressed");

	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture("ui_bg"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

	Renderer* renderer = new Renderer("PopupWindow");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	UIButton* button1 = new UIButton("button_1", btnNormal, btnPressed);
	this->attachChild(button1);
	button1->setPosition(-150, 150);
	button1->getTransformable()->setScale(0.3f, 0.3f);
	button1->setButtonListener(this);

	UIText* button_1Text = new UIText("text_1");
	button1->attachChild(button_1Text);
	button_1Text->setPosition(0, -20);
	button_1Text->setSize(100);
	button_1Text->setText("YES");

	UIButton* button2 = new UIButton("button_2", btnNormal, btnPressed);
	this->attachChild(button2);
	button2->setPosition(150, 150);
	button2->getTransformable()->setScale(0.3f, 0.3f);
	button2->setButtonListener(this);

	UIText* button_2Text = new UIText("text_2");
	button2->attachChild(button_2Text);
	button_2Text->setPosition(0, -20);
	button_2Text->setSize(100);
	button_2Text->setText("NO");

	UIButton* button3 = new UIButton("button_3", btnNormal, btnPressed);
	this->attachChild(button3);
	button3->setPosition(400, 300);
	button3->getTransformable()->setScale(0.3f, 0.3f);
	button3->setButtonListener(this);

	UIText* button_3Text = new UIText("text_3");
	button3->attachChild(button_3Text);
	button_3Text->setPosition(0, -20);
	button_3Text->setSize(100);
	button_3Text->setText("QUIT");

	UIText* confirmation_text = new UIText("confirmation_text_1");
	button2->attachChild(confirmation_text);
	confirmation_text->setPosition(-510, -750);
	confirmation_text->setSize(120);
	confirmation_text->setText("ARE YOU SURE YOU WANT TO QUIT?");
}

void PopupWindow::onButtonClick(UIButton* button)
{
	std::cout << button->getName();
}

void PopupWindow::onButtonReleased(UIButton* button)
{
	std::cout << button->getName();
	if (button->getName() == "button_3")
		system("pause");
	if (button->getName() == "button_1")
		exit(0);
}


