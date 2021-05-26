#include "TextRenderer.h"
#include "FontManager.h"

TextRenderer::TextRenderer(Text* textDrawable, string fontName, Color fillColor, Color outlineColor, float outlineThickness,
						float size, string defaultText) : Renderer(name)
{
    Font* font = FontManager::getInstance()->getFont(fontName);

    textDrawable->setFont(*font);
    textDrawable->setFillColor(fillColor);
    textDrawable->setOutlineColor(outlineColor);
    textDrawable->setOutlineThickness(outlineThickness);
    textDrawable->setCharacterSize(size);
    textDrawable->setString(defaultText);
    this->assignDrawable(textDrawable);
}

TextRenderer* TextRenderer::createText(Text* textDrawable, string fontName, Color fillColor, Color outlineColor, float outlineThickness,
                        float size, string defaultText)
{
    return new TextRenderer(textDrawable, fontName, fillColor, outlineColor, outlineThickness, size, defaultText);
}