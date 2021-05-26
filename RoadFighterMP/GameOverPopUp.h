#pragma once
#include "UIButtonInputController.h"
class GameOverPopUp : public AGameObject, public ButtonListener
{
public:
	GameOverPopUp(string name);
	~GameOverPopUp();

	void initialize();
	void onButtonClick(UIButton* button);
	void onButtonReleased(UIButton* button);
};
