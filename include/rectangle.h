#pragma once
#include <SFML/Graphics.hpp>

class rectangle : public sf::RectangleShape
{
public:
	sf::FloatRect rectBb;
	rectangle();
};
