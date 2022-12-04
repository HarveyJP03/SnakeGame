#include "snakeBodySegment.h"

snakeBodySegment::snakeBodySegment()
{
	setSize(sf::Vector2f(50.0f, 50.0f)); //Set up body segment
	setOrigin(25.0f, 25.0f);
	setFillColor(sf::Color::Red);
	lastPos = getPosition();
}

void snakeBodySegment::moveBodyRight(float snakeSpeed, sf::Time deltaTime)
{
	move((1 * snakeSpeed * deltaTime.asSeconds()), 0); //Move body
	hasReachedNextSquare = false;
	if (getPosition().x >= lastPos.x + 50)
	{
		setPosition(lastPos.x + 50, getPosition().y); //Snap to grid square
		lastPos = getPosition();
		hasReachedNextSquare = true;
		previousMovementStatus = movementStatus::movingRight; //Update previous position
	}
}

void snakeBodySegment::moveBodyLeft(float snakeSpeed, sf::Time deltaTime)
{
	move((-1 * snakeSpeed * deltaTime.asSeconds()), 0);
	hasReachedNextSquare = false;
	if (getPosition().x <= lastPos.x - 50)
	{
		setPosition(lastPos.x - 50, getPosition().y);
		lastPos = getPosition();
		hasReachedNextSquare = true;
		previousMovementStatus = movementStatus::movingLeft;
	}
}

void snakeBodySegment::moveBodyUp(float snakeSpeed, sf::Time deltaTime)
{
	move(0, (-1 * snakeSpeed * deltaTime.asSeconds()));
	hasReachedNextSquare = false;
	if (getPosition().y <= lastPos.y - 50)
	{
		setPosition(getPosition().x, lastPos.y - 50);
		lastPos = getPosition();
		hasReachedNextSquare = true;
		previousMovementStatus = movementStatus::movingUp;
	}
}

void snakeBodySegment::moveBodyDown(float snakeSpeed, sf::Time deltaTime)
{
	move(0, (1 * snakeSpeed * deltaTime.asSeconds()));
	hasReachedNextSquare = false;
	if (getPosition().y >= lastPos.y + 50)
	{
		setPosition(getPosition().x, lastPos.y + 50);
		lastPos = getPosition();
		hasReachedNextSquare = true;
		previousMovementStatus = movementStatus::movingDown;
	}
}