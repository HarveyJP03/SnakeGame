#include "snakeHead.h"

snakeHead::snakeHead()
{
	snakeHeadBase.setSize(sf::Vector2f(50.0f, 50.0f));
	snakeHeadBase.setFillColor(sf::Color::Red); //Set up snake head
	
	snakeEyePupilLeft.setRadius(5.0f);
	snakeEyePupilLeft.setOrigin(5.0f, 5.0f);
	snakeEyePupilLeft.setPosition(12.0f, 38.0f);
	snakeEyePupilLeft.setFillColor(sf::Color::Black);
	snakeEyePupilLeft.setPointCount(80.0f);

	snakeEyePupilRight.setRadius(5.0f);
	snakeEyePupilRight.setOrigin(5.0f, 5.0f);
	snakeEyePupilRight.setPosition(38.0f, 38.0f);
	snakeEyePupilRight.setFillColor(sf::Color::Black);
	snakeEyePupilRight.setPointCount(80.0f); //Set up the snakes eyes

	snakeEyeLeft.setRadius(8.0f);
	snakeEyeLeft.setOrigin(8.0f, 8.0f);
	snakeEyeLeft.setPosition(12.0f, 36.0f);
	snakeEyeLeft.setFillColor(sf::Color::White);
	snakeEyeLeft.setPointCount(20.0f);

	snakeEyeRight.setRadius(8.0f);
	snakeEyeRight.setOrigin(8.0f, 8.0f);
	snakeEyeRight.setPosition(38.0f, 36.0f);
	snakeEyeRight.setFillColor(sf::Color::White);
	snakeEyeRight.setPointCount(40.0f);

	snakeTongue.setSize(sf::Vector2f(20.0f, 10.0f));
	snakeTongue.setOrigin(snakeTongue.getSize().x / 2.0f, snakeTongue.getSize().y / 2.0f);
	snakeTongue.setPosition(25, 55);
	snakeTongue.setFillColor(sf::Color(255, 105, 180)); //Set up snake tongue
	
	snakeHeadTex.create(50.0f, 60.0f);
	setPosition(400, 150);
	setOrigin(25, 35);
	setRotation(90);
	snakeHeadTex.draw(snakeHeadBase);
	snakeHeadTex.draw(snakeEyeLeft);
	snakeHeadTex.draw(snakeEyeRight);
	snakeHeadTex.draw(snakeEyePupilLeft);
	snakeHeadTex.draw(snakeEyePupilRight);
	snakeHeadTex.draw(snakeTongue);
	setTexture(snakeHeadTex.getTexture()); //Add elements of snake head into a sprite so it can all be rotated easily
}