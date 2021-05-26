#include <stddef.h>
#include <iostream>
#include "TextureManager.h"

TextureManager* TextureManager::sharedInstance = NULL;

TextureManager* TextureManager::getInstance() {
		//initialize only when we need it
		if (sharedInstance == NULL) {
			sharedInstance = new TextureManager();
		}
		return sharedInstance;
}

void TextureManager::loadAll() {

	loadTexture("road", "Media/Textures/Road.png");
	sf::Texture* bgTex;
	bgTex = getTexture("road");
	bgTex->setRepeated(true);

	loadTexture("tree", "Media/Textures/Tree.png");
	loadTexture("car", "Media/Textures/Car.png");
	loadTexture("car2", "Media/Textures/Car2.png");
	loadTexture("fuel", "Media/Textures/GasCan.png");
	loadTexture("pg_bg", "Media/Textures/ProgressBar.png");
	loadTexture("minicar", "Media/Textures/MiniCar.png");

	loadTexture("btn_normal", "Media/Textures/Button.png");
	loadTexture("btn_pressed", "Media/Textures/ButtonPressed.png");

	loadTexture("ui_bg", "Media/Textures/f.png");
	loadTexture("title_bg", "Media/Textures/TitleScreenBG.png");
}

void TextureManager::loadTexture(std::string key, std::string path) {
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(path);
	textureMap[key] = texture;
}

sf::Texture* TextureManager::getTexture(std::string key) {
	if (textureMap[key] != NULL) {
		return textureMap[key];
	}
	else {
		std::cout << "No texture found for " << key;
		return NULL;
	}
}

void TextureManager::testFunction() {
	std::cout << "Hi, I'm single-ton ;D";
}