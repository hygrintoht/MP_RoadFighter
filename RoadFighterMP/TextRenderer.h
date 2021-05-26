#pragma once
#include "Renderer.h"

using namespace sf;

class TextRenderer : public Renderer
{
public:
	TextRenderer(Text* textDrawable, string fontName, Color fillColor, Color outlineColor, float outlineThickness,
				float size, string defaultText);

	static TextRenderer* createText(Text* textDrawable, string fontName, Color fillColor, Color outlineColor, float outlineThickness,
									float size, string defaultText);
};

