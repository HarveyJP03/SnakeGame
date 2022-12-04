#pragma once
#include <SFML/Graphics.hpp>
#include "enums.h"

class snakeBodySegment : public sf::RectangleShape
{
public:
	snakeBodySegment();
	sf::Vector2f lastPos;
	movementStatus currentMovementStatus = movementStatus::stationary;
	movementStatus previousMovementStatus = movementStatus::stationary;
	bool hasReachedNextSquare = true;

	void moveBodyLeft(float snakeSpeed, sf::Time deltaTime);
	void moveBodyRight(float snakeSpeed, sf::Time deltaTime);
	void moveBodyUp(float snakeSpeed, sf::Time deltaTime);
	void moveBodyDown(float snakeSpeed, sf::Time deltaTime);
};
