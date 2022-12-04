#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;

class food : public sf::CircleShape
{	
public:
	food(int windowWidth, int windowHeight);
	void resetFoodPosition();
	vector<sf::Vector2f> positions;
};
