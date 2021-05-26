#pragma once
#include "AGameObject.h"
#include "UIButton.h"

class PopupWindow : public AGameObject, public ButtonListener
{
public:
	PopupWindow(string name);
	~PopupWindow();

	void initialize();

	void onButtonClick(UIButton* button);
	void onButtonReleased(UIButton* button);

};