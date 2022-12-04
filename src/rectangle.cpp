#include "rectangle.h"

rectangle::rectangle()
{
	setSize(sf::Vector2f(200.0f, 180.0f));
	setPosition(200, 180);
	setFillColor(sf::Color::Cyan);
	rectBb = getGlobalBounds();
}