#include "wall.h"

wall::wall()
{
	setSize(sf::Vector2f(1000.0f, 20.0f));
	setPosition(sf::Vector2f(500.0f, 10.0f));
	setFillColor(sf::Color(0, 100, 0, 255));
	setOrigin(500.0f, 10.0f);
	wallBb = getGlobalBounds();
}

wall::wall(sf::Vector2f size, sf::Vector2f position, float rotation, sf::Color fillColor)
{
	setSize(size);
	setPosition(position);
	setOrigin(size.x / 2.0f, size.y / 2.0f);
	setFillColor(fillColor);
	setRotation(rotation);
	wallBb = getGlobalBounds();
}

void wall::changeWallSettings(sf::Vector2f size, sf::Vector2f position, float rotation, sf::Color fillColor)
{
	setSize(size);
	setPosition(position);
	setOrigin(size.x / 2.0f, size.y / 2.0f);
	setFillColor(fillColor);
	setRotation(rotation);
	wallBb = getGlobalBounds();
}

