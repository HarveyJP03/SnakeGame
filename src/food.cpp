#include "food.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>  

food::food(int windowWidth, int windowHeight)
{
	int numOfGridSquares = ((windowWidth - 50) / 50) * ((windowHeight - 50) / 50);
	int endOfRowSquareNum = ((windowWidth - 50) / 50) - 1;
	int rowLength = ((windowWidth - 50) / 50) - 1;
	positions.resize(numOfGridSquares); // Fill a vector of positions where the food can spawn
	
	for (int i = 0; i < numOfGridSquares; i++)
	{
		if (i == 0)
		{
			positions[i] = sf::Vector2f(50, 50);
		}
		else
		{
			positions[i] = sf::Vector2f(positions[i - 1].x + 50, positions[i - 1].y);
		}
		
		if (i > endOfRowSquareNum)
		{
			endOfRowSquareNum = (endOfRowSquareNum + rowLength) + 1;
			positions[i] = sf::Vector2f(positions[0].x, positions[endOfRowSquareNum - rowLength].y + 50);
		}
	}

	setRadius(12.5f);
	setOrigin(12.5f, 12.5f);
	setPointCount(40);
	setFillColor(sf::Color::Blue);
	
	srand(time(NULL));
	int foodPosition = rand() % 344 + 1;
	setPosition(positions[foodPosition]); //Randomly choose a numbered position from the vector 
}

void food::resetFoodPosition()
{
	int foodPosition = rand() % 344 + 1;
	setPosition(positions[foodPosition]); //Randomly choose a numbered position from the vector to move the food to
}