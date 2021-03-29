#pragma once
#include <SFML/Graphics.hpp>

#define HORI_LINES 17
#define VERT_LINES 12

#define GRID_SIZE_X 900
#define GRID_SIZE_Y 481
class Grid
{
public:
	
	// Here we created a constructor and a deconstructor for the grid.
	Grid();
	~Grid();
	
	// Over here, we are creating a line, the will represent and draw the grid, we are using an array to be able to draw multiple lines to draw the whole grid.
	sf::RectangleShape line[HORI_LINES]; // These are the Horizontal line
	sf::RectangleShape lone[VERT_LINES]; // These are the Vertical lines, I called it lones, dont question me!
	
	
	void Render(sf::RenderWindow& window);

};





