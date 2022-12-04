#include "text.h"

text::text()
{
	font.loadFromFile(".\\assets\\VECTRO-Bold.otf");
	setFont(font);
	setString("Use WASD keys to move");
	setCharacterSize(60);
	setPosition(50, 50);
	setFillColor(sf::Color::Black);
}

text::text(string textString, int textSize, sf::Vector2f position)
{
	font.loadFromFile(".\\assets\\VECTRO-Bold.otf");
	setFont(font);
	setString(textString);
	setCharacterSize(textSize);
	setPosition(position);
	setFillColor(sf::Color::Black);
}

void text::update(string textString)
{
	setString(textString);
}


