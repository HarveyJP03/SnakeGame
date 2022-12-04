#pragma once
#include <SFML/Graphics.hpp>
#include "wall.h"

class boundWalls
{
private:
	wall topWall;
	wall bottomWall;
	wall leftWall;
	wall rightWall;
public:
	boundWalls();
	boundWalls(sf::Vector2i windowSize, int wallThickness);
	wall getTopWall();
	wall getBottomWall();
	wall getLeftWall();
	wall getRightWall();
	sf::FloatRect getTopWallBb();
	sf::FloatRect getBottomWallBb();
	sf::FloatRect getLeftWallBb();
	sf::FloatRect getRightWallBb();

};