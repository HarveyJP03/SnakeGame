#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

class text : public sf::Text
{
public:
	text();
	text(string textString, int textSize, sf::Vector2f position);
	sf::Font font;
	void update(string textString);
};
