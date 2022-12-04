#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "GridSquare.h"

using namespace std;

class Grid : public sf::Sprite
{
public:
	sf::RenderTexture gridSquareTex;
	gridSquare gridTile;
	gridSquare altGridTile;
	void setUp();
};

