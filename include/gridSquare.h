#pragma once
#include <SFML/Graphics.hpp>

class gridSquare : public sf::RectangleShape
{
public:
	float gridSquareHeight = 50.0;
	float gridSquareWidth = 50.0;
	sf::Color fillColor = sf::Color::Green;
	int getGridSquareWidth();
	int getGridSquareHeight();
	gridSquare();
};
