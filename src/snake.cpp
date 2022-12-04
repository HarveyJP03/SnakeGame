#include "snake.h"

snake::snake()
{
	previousSnakeStatus = movementStatus::stationary; //Snake starts stationary
	currentSnakeStatus = movementStatus::stationary;
	queuedSnakeStatus = movementStatus::stationary;
	snakeBody.resize(5); //Starting snake size = 5
	snakeBody[0].setPosition(head.getPosition().x- 50, head.getPosition().y); //Set pos of first segment behind the snake head
	for (int i = 1; i < snakeBody.size();  i++)
	{
		snakeBody[i].setPosition(snakeBody[i - 1].getPosition().x - 50, snakeBody[i - 1].getPosition().y); //Set position of body segments 
	}

	for (int j = 0; j < snakeBody.size(); j++)
	{
		snakeBody[j].lastPos = snakeBody[j].getPosition(); //Set lastPositions of snakeBody segments
	}
}

sf::Vector2f snake::getSnakeHeadPosition()
{
	return head.getPosition();
}

sf::Sprite snake::getSnakeHead()
{
	return head;
}

void snake::moveUp(sf::Time deltaTime)
{
	head.setRotation(0); //So snake is head is facing right way when moving
	head.move(0, (-1 * snakeSpeed * deltaTime.asSeconds())); //Move snake
	hasReachedNextSquare = false; 
	if (head.getPosition().y <= previousPos.y - 50) //If snakeHead has reached the square above its previous square
	{
		head.setPosition(head.getPosition().x, previousPos.y - 50); //Snap to grid
		previousPos = head.getPosition(); //Update previous psition of the snakeHead
		hasReachedNextSquare = true;
	}
}

void snake::moveDown(sf::Time deltaTime)
{
	head.setRotation(180);
	head.move(0, (1 * snakeSpeed * deltaTime.asSeconds()));
	hasReachedNextSquare = false;
	if (head.getPosition().y >= previousPos.y + 50)
	{
		head.setPosition(head.getPosition().x, previousPos.y + 50);
		previousPos = head.getPosition();
		hasReachedNextSquare = true;
	}
}

void snake::moveLeft(sf::Time deltaTime)
{
	head.setRotation(270);
	head.move((-1 * snakeSpeed * deltaTime.asSeconds()), 0);
	hasReachedNextSquare = false;
	if (head.getPosition().x <= previousPos.x - 50)
	{
		head.setPosition(previousPos.x - 50, head.getPosition().y);
		previousPos = head.getPosition();
		hasReachedNextSquare = true;
	}
}


void snake::moveRight(sf::Time deltaTime)
{
	head.setRotation(90);
	head.move((1 * snakeSpeed * deltaTime.asSeconds()), 0);
	hasReachedNextSquare = false;
	if (head.getPosition().x >= previousPos.x + 50)
	{
		head.setPosition(previousPos.x + 50, head.getPosition().y);
		previousPos = head.getPosition();
		hasReachedNextSquare = true;
	}
}

bool snake::getHasReachedNextSquare()
{
	return hasReachedNextSquare;
}

void snake::handleBodyMovement(sf::Time deltaTime)
{
	if(!(getCurrentStatus() == movementStatus::stationary)) //If snake is moving
	for (int i = 0; i < snakeBody.size(); i++)
	{
		if (i == 0)
		{
			if (previousSnakeStatus == movementStatus::stationary) //If the snake has started moving
			{
				snakeBody[i].currentMovementStatus = movementStatus::movingRight; //Set body segment to moving right
			}
			else
			{
				snakeBody[i].currentMovementStatus = previousSnakeStatus; //First body segment needs to follow the snakehead's previous status
			}
		}
		else
		{
			if (snakeBody[i - 1].previousMovementStatus == movementStatus::stationary) //If the segment infront was stationary
			{
				snakeBody[i].currentMovementStatus = snakeBody[i - 1].currentMovementStatus; //Body segment status = one in fronts status
			}
			else
			{
				if(snakeBody[i].hasReachedNextSquare) //If snake body has reached next square
				snakeBody[i].currentMovementStatus = snakeBody[i - 1].previousMovementStatus; //Body segment status = one in fronts previous status
			}
		}

		if (snakeBody[i].currentMovementStatus == movementStatus::movingRight) //Check body status and move it based on current status
		{
			snakeBody[i].moveBodyRight(snakeSpeed, deltaTime);
		}

		if (snakeBody[i].currentMovementStatus == movementStatus::movingLeft)
		{
			snakeBody[i].moveBodyLeft(snakeSpeed, deltaTime);
		}

		if (snakeBody[i].currentMovementStatus == movementStatus::movingDown)
		{
			snakeBody[i].moveBodyDown(snakeSpeed, deltaTime);
		}

		if (snakeBody[i].currentMovementStatus == movementStatus::movingUp)
		{
			snakeBody[i].moveBodyUp(snakeSpeed, deltaTime);
		}

	}
}

int snake::getSnakeBodySize()
{
	return snakeBody.size();
}

snakeBodySegment snake::getSnakeBodySegment(int index)
{
	return snakeBody[index];
}

void snake::grow()
{
	int lastBodyIndex = (snakeBody.size() - 1); //Vector element of snake last snakeBody 
	sf::Vector2f newBodyPosition = snakeBody[lastBodyIndex].getPosition(); //New position for new body piece
	snakeBodySegment sbs; //New body piece
	
	
	if (snakeBody[lastBodyIndex].currentMovementStatus == movementStatus::movingUp) 
	{
		newBodyPosition.y = newBodyPosition.y + 50; //Change new pos variable to be one grid sqaure behind the last bodySegment
		sbs.currentMovementStatus = movementStatus::movingUp; //Set status of new body piece
	}

	if (snakeBody[lastBodyIndex].currentMovementStatus == movementStatus::movingDown)
	{
		newBodyPosition.y = newBodyPosition.y - 50;
		sbs.currentMovementStatus = movementStatus::movingDown;
	}

	if (snakeBody[lastBodyIndex].currentMovementStatus == movementStatus::movingLeft)
	{
		newBodyPosition.x = newBodyPosition.x + 50;
		sbs.currentMovementStatus = movementStatus::movingLeft;
	}

	if (snakeBody[lastBodyIndex].currentMovementStatus == movementStatus::movingRight)
	{
		newBodyPosition.x = newBodyPosition.x - 50;
		sbs.currentMovementStatus = movementStatus::movingRight;
	}
	
	
	sbs.setPosition(newBodyPosition); //Set position of new body segment
	sbs.lastPos = newBodyPosition; //Set last pos
	snakeBody.push_back(sbs); //Add new body piece to the snakeBody vector

}

void snake::reset()
{
	previousSnakeStatus = movementStatus::stationary; //Set snake status to stationary
	currentSnakeStatus = movementStatus::stationary;
	queuedSnakeStatus = movementStatus::stationary;
	head.setPosition(sf::Vector2f(400, 150)); //Reset snakeHead position
	head.setRotation(90);
	previousPos = head.getPosition(); //Reinitialize snakeHead position
	snakeBody.resize(5); //Reset snakeBody size
	snakeBody[0].setPosition(head.getPosition().x - 50, head.getPosition().y); //Reset first snakeBody position
	
	for (int i = 1; i < snakeBody.size(); i++)
	{
		snakeBody[i].setPosition(snakeBody[i - 1].getPosition().x - 50, snakeBody[i - 1].getPosition().y); //set snakeBody posiiotns
	}

	for (int j = 0; j < snakeBody.size(); j++)
	{
		snakeBody[j].lastPos = snakeBody[j].getPosition(); //Update lastPos of snakeBodys
		snakeBody[j].hasReachedNextSquare = true;
		snakeBody[j].previousMovementStatus = movementStatus::stationary; //Set snakeBody status to stationary
		snakeBody[j].currentMovementStatus = movementStatus::stationary;
		hasReachedNextSquare = true;
	}
}

void snake::setSnakeStatus(movementStatus movementDirection)
{
	currentSnakeStatus = movementDirection;
}

void snake::setQueuedSnakeStatus(movementStatus movementDirection)
{
	queuedSnakeStatus = movementDirection;
}

void snake::setPreviousSnakeStatus(movementStatus movementDirection)
{
	previousSnakeStatus = movementDirection;
}


bool snake::checkIsInBounds(sf::RectangleShape topWall, sf::RectangleShape bottomWall, sf::RectangleShape leftWall, sf::RectangleShape rightWall, float wallThickness)
{
	bool result = false;
	if (head.getPosition().y - 50.0 < topWall.getPosition().y - 12.5)
	{
		result = true;
	}

	if (head.getPosition().y + 50.0 > bottomWall.getPosition().y + 12.5)
	{
		result = true;
	}

	if (head.getPosition().x - 50.0 < leftWall.getPosition().x - 12.5)
	{
		result = true;
	}

	if (head.getPosition().x + 50.0 > rightWall.getPosition().x + 12.5)
	{
		result = true;
	}
	return result;
}

bool snake::checkSelfCollision()
{
	bool result = false;
	for (int i = 0; i < snakeBody.size(); i++)
	{
		if (head.getPosition() == snakeBody[i].getPosition())
		{
			result = true;
			reset();
		}
	}
	return result;
}

sf::Vector2f snake::getPreviousPos()
{
	return previousPos;
}

movementStatus snake::getCurrentStatus()
{
	return currentSnakeStatus;
}

movementStatus snake::getQueuedStatus()
{
	return queuedSnakeStatus;
}

void snake::queueGrow()
{
	isGrowQueued = true;
}

void snake::dequeGrow()
{
	isGrowQueued = false;
}

bool snake::getIsGrowQueued()
{
	return isGrowQueued;
}

void snake::incrementScore()
{
	score++;
}

int snake::getScore()
{
	return score;
}

void snake::resetScore()
{
	score = 0;
}

int snake::getScoreToWin()
{
	return scoreToWin;
}

void snake::setScoreToWin(int scoreCount)
{
	scoreToWin = scoreCount;
}

bool snake::getHasDied()
{
	return hasDied;
}

void snake::setHasDied(bool isDead)
{
	hasDied = isDead;
}

