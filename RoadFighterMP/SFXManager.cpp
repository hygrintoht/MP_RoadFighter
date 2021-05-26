#include <stddef.h>
#include <iostream>
#include "SFXManager.h"

SFXManager* SFXManager::sharedInstance = NULL;

SFXManager* SFXManager::getInstance() {
	//initialize only when we need it
	if (sharedInstance == NULL) {
		sharedInstance = new SFXManager();
	}
	return sharedInstance;
}

void SFXManager::loadAll() {
	loadSFX("bgm", "Media/SFX/RoadFighterBGM.wav");
}

void SFXManager::loadSFX(std::string key, std::string path) {
	sf::SoundBuffer* buffer = new sf::SoundBuffer();
	buffer->loadFromFile(path);
	sf::Sound* sfx = new sf::Sound();
	sfx->setBuffer(*buffer);
	sfxMap[key] = sfx;
}

sf::Sound* SFXManager::getSFX(std::string key) {
	if (sfxMap[key] != NULL) {
		return sfxMap[key];
	}
	else {
		std::cout << "No buffer found for " << key;
		return NULL;
	}
}

void SFXManager::testFunction() {
	std::cout << "Hi, I'm single-ton ;D";
}