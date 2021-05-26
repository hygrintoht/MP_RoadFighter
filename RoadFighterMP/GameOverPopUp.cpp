#include "GameOverPopUp.h"
#include "UIText.h"
#include "TextureManager.h"
#include "Game.h"
#include "UIButton.h"
#include "ApplicationManager.h"
#include "GameObjectManager.h"
#include "Renderer.h"
#include "SceneManager.h"

GameOverPopUp::GameOverPopUp(string name) : AGameObject(name), ButtonListener()
{
}

GameOverPopUp::~GameOverPopUp()
{
	AGameObject::~AGameObject();
}

void GameOverPopUp::initialize()
{
	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture("ui_bg"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2);

	Renderer* renderer = new Renderer("QuitScreen");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	sf::Texture* btnNormal = TextureManager::getInstance()->getTexture("btn_normal");
	sf::Texture* btnPressed = TextureManager::getInstance()->getTexture("btn_pressed");

	UIButton* button = new UIButton("button_1", btnNormal, btnPressed);
	this->attachChild(button);
	button->setPosition(0, 150);
	button->getTransformable()->setScale(0.3f, 0.3f);
	button->setButtonListener(this);

	UIText* button_1Text = new UIText("text_1");
	button->attachChild(button_1Text);
	button_1Text->setPosition(0, -50);
	button_1Text->setSize(100);
	button_1Text->setText("RETURN");

	UIText* displayText = new UIText("displayText");
	this->attachChild(displayText);
	displayText->setPosition(0, -100);
	displayText->setSize(40);
	displayText->setText("Game Over!");

	ApplicationManager::getInstance()->pauseApplication();
}

void GameOverPopUp::onButtonClick(UIButton* button)
{

}

void GameOverPopUp::onButtonReleased(UIButton* button)
{
	SceneManager::getInstance()->loadScene(SceneManager::MAIN_MENU_SCENE_NAME);
	ApplicationManager::getInstance()->resumeApplication();
}