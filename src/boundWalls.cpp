#include "boundWalls.h"

boundWalls::boundWalls()
{
	
}

boundWalls::boundWalls(sf::Vector2i windowSize, int wallThickness)
{
	topWall.changeWallSettings(sf::Vector2f(windowSize.x, wallThickness), sf::Vector2f(windowSize.x / 2.0f, wallThickness / 2.0f), 0.0f, sf::Color(0, 100, 0, 255)); //Size, position, rotation, fillcolor
	bottomWall.changeWallSettings(sf::Vector2f(windowSize.x, wallThickness), sf::Vector2f(windowSize.x / 2.0f, windowSize.y - (wallThickness / 2.0f)), 0.0f, sf::Color(0, 100, 0, 255));
	leftWall.changeWallSettings(sf::Vector2f(wallThickness, windowSize.y), sf::Vector2f(wallThickness / 2.0f, windowSize.y / 2.0f), 0.0f, sf::Color(0, 100, 0, 255));
	rightWall.changeWallSettings(sf::Vector2f(wallThickness, windowSize.y), sf::Vector2f(windowSize.x - (wallThickness / 2.0f), windowSize.y / 2.0f), 0.0f, sf::Color(0, 100, 0, 255));
}

wall boundWalls::getTopWall()
{
	return topWall;
}

wall boundWalls::getBottomWall()
{
	return bottomWall;
}


wall boundWalls::getLeftWall()
{
	return leftWall;
}

wall boundWalls::getRightWall()
{
	return rightWall;
}

sf::FloatRect boundWalls::getTopWallBb()
{
	return topWall.wallBb;
}

sf::FloatRect boundWalls::getBottomWallBb()
{
	return bottomWall.wallBb;
}

sf::FloatRect boundWalls::getLeftWallBb()
{
	return leftWall.wallBb;
}

sf::FloatRect boundWalls::getRightWallBb()
{
	return rightWall.wallBb;
}