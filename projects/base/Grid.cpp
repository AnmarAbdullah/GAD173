#include <Grid.h>

// In the constructor we are drawing the Grid itself, the line size and position along with a for loop to keep drawing line until it reaches our UI design cell count.

Grid::Grid() 
{
	for (size_t i = 0; i < HORI_LINES; i++) 
	{
		line[i].setSize(sf::Vector2f(GRID_SIZE_X, 2));
		line[i].setPosition(sf::Vector2f(491, 180 + i * 30));
	}

	for (size_t e = 0; e < VERT_LINES; e++)
	{
		lone[e].setSize(sf::Vector2f(2, GRID_SIZE_Y));
		lone[e].setPosition(sf::Vector2f(491 + e * 81.75, 180));
	}
}

Grid::~Grid() 
{

}

// Here is the rendering, an easy step to just render what we want to draw into the Kage2d Window. With the for loops as well to render all the lines count included in the array
void Grid::Render(sf::RenderWindow& window)
{
	for (size_t i = 0; i < HORI_LINES; i++)
	{
		window.draw(line[i]);
	}
	for (size_t e = 0; e < VERT_LINES; e++)
	{
		window.draw(lone[e]);
	}
};