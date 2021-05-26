#pragma once
#include "AGameObject.h"
#include "UIButtonInputController.h"
class SamplePopupScreen : public AGameObject, public ButtonListener
{
public:
	SamplePopupScreen(string name);
	~SamplePopupScreen();

	void initialize();
	void onButtonClick(UIButton* button);
	void onButtonReleased(UIButton* button);
};

