#include "Grid.h"

void Grid::setUp()
{						
	setPosition(25, 25);	
	gridSquareTex.create(100, 100);
	gridTile.setPosition(25, 25);

	gridSquareTex.draw(gridTile);
	
	altGridTile.setPosition(75, 75);
	gridSquareTex.draw(altGridTile);
	gridSquareTex.setRepeated(true);
	setTexture(gridSquareTex.getTexture());
	setTextureRect(sf::IntRect(0, 0, 1920, 1080)); //Gird will always fill the window
}
