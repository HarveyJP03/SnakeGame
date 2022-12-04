#include "GridSquare.h"

gridSquare::gridSquare()
{
	setSize(sf::Vector2f(gridSquareWidth, gridSquareHeight));
	setPosition(25, 25);
	setFillColor(fillColor);
	setOrigin(getSize().x / 2.0f, getSize().y / 2.0f);
}

int gridSquare::getGridSquareWidth()
{
	return gridSquareWidth;
}

int gridSquare::getGridSquareHeight()
{
	return gridSquareHeight;
}

