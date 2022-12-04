#pragma once
#include <SFML/Graphics.hpp>

class wall : public sf::RectangleShape
{
public:
	sf::FloatRect wallBb;
	wall();
	wall(sf::Vector2f size, sf::Vector2f position, float rotation, sf::Color fillColor);
	void changeWallSettings(sf::Vector2f size, sf::Vector2f position, float rotation, sf::Color fillColor);
};