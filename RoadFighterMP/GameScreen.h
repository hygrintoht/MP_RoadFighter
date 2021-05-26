#pragma once
#include "AGameObject.h"
#include "UIButton.h"
#include "UIText.h"

class GameScreen : public AGameObject, public ButtonListener
{
public:
	GameScreen(string name);
	~GameScreen();

	void initialize();

	void onButtonClick(UIButton* button);
	void onButtonReleased(UIButton* button);
private:
	UIText* displayText;
};