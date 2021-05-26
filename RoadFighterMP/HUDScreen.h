#pragma once
#include "AGameObject.h"
#include "UIButtonInputController.h"
#include "UIText.h"

class HUDScreen : public AGameObject, public ButtonListener
{
public:
	HUDScreen(string name);
	~HUDScreen();

	void initialize();
	void onButtonClick(UIButton* button);
	void onButtonReleased(UIButton* button);

	UIText* fuelText;
	string fuelString;
	int playerFuel = 100;
private:
	sf::Sprite* sprite;
};

