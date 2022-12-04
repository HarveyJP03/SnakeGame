#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "snakeHead.h"
#include "enums.h"
#include "snakeBodySegment.h"
#include <vector>

using namespace std;

class snake
{
private:
	snakeHead head;
	sf::Vector2f previousPos = head.getPosition();
	movementStatus previousSnakeStatus;
	movementStatus currentSnakeStatus;
	movementStatus queuedSnakeStatus;
	float snakeSpeed = 400.0f;
	bool hasReachedNextSquare = true;
	bool isGrowQueued = false;
	vector<snakeBodySegment> snakeBody;
	int score = 0;
	int scoreToWin = 30;
	bool hasDied;

public:
	snake();
	sf::Vector2f getSnakeHeadPosition();
	sf::Sprite getSnakeHead();
	void moveUp(sf::Time deltaTime);
	void moveDown(sf::Time deltaTime);
	void moveLeft(sf::Time deltaTime);
	void moveRight(sf::Time deltaTime);

	bool getHasReachedNextSquare();
	sf::Vector2f getPreviousPos();
	void setSnakeStatus(movementStatus movementDirection);
	void setQueuedSnakeStatus(movementStatus movementDirection);
	void setPreviousSnakeStatus(movementStatus movementDirection);
	
	void handleBodyMovement(sf::Time deltaTime);
	int getSnakeBodySize();
	snakeBodySegment getSnakeBodySegment(int index);
	void grow();
	bool checkIsInBounds(sf::RectangleShape topWall, sf::RectangleShape bottomWall, sf::RectangleShape leftWall, sf::RectangleShape rightWall, float wallThickness);
	bool checkSelfCollision(); //Not sure about this green line, there is a function definition
	void reset();

	movementStatus getCurrentStatus();
	movementStatus getQueuedStatus();

	bool getIsGrowQueued();
	void queueGrow();
	void dequeGrow();

	void incrementScore();
	int getScore();
	void resetScore();

	int getScoreToWin();
	void setScoreToWin(int scoreCount);
	
	bool getHasDied();
	void setHasDied(bool isDead);

};
