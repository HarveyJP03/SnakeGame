#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "rectangle.h"
#include "wall.h"
#include "boundWalls.h"
#include "grid.h"
#include "snakeHead.h"
#include "snake.h"
#include "enums.h"
#include "food.h"
#include "text.h"

using namespace std;

int main()
{	
	int windowHeight = 800;
	int windowWidth = 1200;
	sf::VideoMode windowSize = sf::VideoMode(windowWidth, windowHeight);

	sf::RenderWindow window(windowSize, "Snake"); //Window width and height, window title
	window.setPosition(sf::Vector2i(100, 100)); //set where window is positioned on screen
	window.setFramerateLimit(60);

	boundWalls boundaryWalls(sf::Vector2i(windowWidth, windowHeight), 25); //Create object boundary walls that is composed of 4 wall objects

	Grid grid; // Create grid
	grid.setUp();

	snake snakePlayer; //Create snake
	food food(windowWidth, windowHeight);
	text tutorialText(string("Use WASD to move"), 60, sf::Vector2f(50, 50));
	text scoreCounter(string("Score:" + to_string(snakePlayer.getScore())), 25, sf::Vector2f(0, -4));
	text gameOverText(string("Game Over"), 80, sf::Vector2f(450, 300));
	text scoreSummary(string("Your score was: " + to_string(snakePlayer.getScore())), 60, sf::Vector2f(400, 380));
	text winText(string("You Win!"), 80, sf::Vector2f(450, 300));
	

	sf::Clock clock;
	sf::Time deltaTime; //Used to get delta time, which is needed for smooth snake movement
		
	while (window.isOpen()) //Run until user closes window
	{
		sf::Event event;
		while (window.pollEvent(event)) //Check user events
		{
			if (event.type == sf::Event::Closed)
			{
				window.close(); //Close window is user has pressed close button
			}

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::W) 
				{
					if (!(snakePlayer.getCurrentStatus() == movementStatus::movingDown)) //Does not allow snake to turn 180 and go back on itself
						snakePlayer.setQueuedSnakeStatus(movementStatus::movingUp);
					if (snakePlayer.getCurrentStatus() == movementStatus::stationary)
					{
						snakePlayer.resetScore(); //If the player has died and starts again resert score here so previous score can be seen on game over screen
					}
				} 
				if (event.key.code == sf::Keyboard::S) 
				{
					if (!(snakePlayer.getCurrentStatus() == movementStatus::movingUp))
						snakePlayer.setQueuedSnakeStatus(movementStatus::movingDown);
					if (snakePlayer.getCurrentStatus() == movementStatus::stationary)
					{
						snakePlayer.resetScore();
					}
				} 
				if (event.key.code == sf::Keyboard::A) 
				{
					if (!(snakePlayer.getCurrentStatus() == movementStatus::movingRight) && (!(snakePlayer.getCurrentStatus() == movementStatus::stationary)))
						snakePlayer.setQueuedSnakeStatus(movementStatus::movingLeft);
					if (snakePlayer.getCurrentStatus() == movementStatus::stationary)
					{
						snakePlayer.resetScore();
					}
				}
				if (event.key.code == sf::Keyboard::D)
				{
					if (!(snakePlayer.getCurrentStatus() == movementStatus::movingLeft))
						snakePlayer.setQueuedSnakeStatus(movementStatus::movingRight);
					if (snakePlayer.getCurrentStatus() == movementStatus::stationary)
					{
						snakePlayer.resetScore();
					}
				}
			}

		}

		if (snakePlayer.getHasReachedNextSquare())
		{	
			if (snakePlayer.getIsGrowQueued()) //If the snake has eaten a fruit a grow is queued, and wil grow once it has reached the next square
			{
				snakePlayer.dequeGrow();
				snakePlayer.grow();
				snakePlayer.incrementScore();
			}
			snakePlayer.setPreviousSnakeStatus(snakePlayer.getCurrentStatus()); //Sets the previous status to is current one, which changes below
			snakePlayer.setSnakeStatus(snakePlayer.getQueuedStatus()); //Set new snake status only when it has reached a grid position
		}
		
		snakePlayer.handleBodyMovement(deltaTime); 

		
		// Move snake after checking what status it has been set to above
		if (snakePlayer.getCurrentStatus() == movementStatus::movingUp)
		{
			snakePlayer.moveUp(deltaTime);
		}

		if (snakePlayer.getCurrentStatus() == movementStatus::movingDown)
		{
			snakePlayer.moveDown(deltaTime);
		}

		if (snakePlayer.getCurrentStatus() == movementStatus::movingLeft)
		{
			snakePlayer.moveLeft(deltaTime);
		}

		if (snakePlayer.getCurrentStatus() == movementStatus::movingRight)
		{
			snakePlayer.moveRight(deltaTime);
		}

		if(snakePlayer.checkIsInBounds(boundaryWalls.getTopWall(), boundaryWalls.getBottomWall(), boundaryWalls.getLeftWall(), boundaryWalls.getRightWall(), 25)) //Check for collision with walls
		{
			snakePlayer.setHasDied(true); //So that game over screen does not show when the game is first launcehd
			snakePlayer.reset();
		}
		if (snakePlayer.checkSelfCollision()) //Check if the snake has colided with itself
		{
			snakePlayer.setHasDied(true);
			snakePlayer.reset();
		}

		if (snakePlayer.getSnakeHeadPosition() == food.getPosition()) 
		{
			snakePlayer.queueGrow();
			food.resetFoodPosition();
			if (snakePlayer.getSnakeHeadPosition() == food.getPosition()) // To prevent food from spawning where snake head is
			{
				food.resetFoodPosition();
			}
			for (int i = 0; i < snakePlayer.getSnakeBodySize(); i++) //To prevent food from spawning where the snake body is 
			{
				if (snakePlayer.getSnakeBodySegment(i).getPosition() == food.getPosition())
				{
					food.resetFoodPosition();
				}
			}
		}

		deltaTime = clock.restart(); // Update deltatime
		
		window.clear(sf::Color(50, 205, 50));
	
		window.draw(grid);
		window.draw(boundaryWalls.getTopWall());
		window.draw(boundaryWalls.getBottomWall());
		window.draw(boundaryWalls.getLeftWall());
		window.draw(boundaryWalls.getRightWall());//Draw 4 walls and grid
		window.draw(food);
		
		if (snakePlayer.getCurrentStatus() == movementStatus::stationary)
		{
			window.draw(tutorialText);
		}
		else
		{
			scoreCounter.update(string("Score:" + to_string(snakePlayer.getScore())));
			window.draw(scoreCounter);
		}

		if (snakePlayer.getCurrentStatus() == movementStatus::stationary)
		{
			if (snakePlayer.getHasDied())
			{
				window.draw(gameOverText);
				scoreSummary.update(string("Your Score Was: " + to_string(snakePlayer.getScore()))); //Update score counter toext with new score
				window.draw(scoreSummary);
			}
		}

		if (snakePlayer.getScoreToWin() == snakePlayer.getScore())
		{
			snakePlayer.setHasDied(false); //So game over screen does not show
			window.draw(winText);
			snakePlayer.reset();
			scoreSummary.update(string("Your Score Was: " + to_string(snakePlayer.getScore())));
			window.draw(scoreSummary);
		}


		window.draw(snakePlayer.getSnakeHead()); //Draw snake
		
		for (int i = 0; i < snakePlayer.getSnakeBodySize(); i++)
		{
			window.draw(snakePlayer.getSnakeBodySegment(i));
		}

		window.display();
	}
	
	return 0;
}

