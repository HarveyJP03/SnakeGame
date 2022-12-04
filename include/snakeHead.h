#pragma once
#include <SFML/Graphics.hpp>

class snakeHead : public sf::Sprite
{
public:
	sf::RenderTexture snakeHeadTex;
	sf::RectangleShape snakeHeadBase;
	sf::CircleShape snakeEyePupilLeft;
	sf::CircleShape snakeEyePupilRight;
	sf::CircleShape snakeEyeLeft;
	sf::CircleShape snakeEyeRight;
	sf::RectangleShape snakeTongue;
	sf::RectangleShape snakeHeadBb;
	snakeHead();
};
