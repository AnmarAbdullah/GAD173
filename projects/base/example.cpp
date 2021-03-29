#include "example.h"


Example::Example(): App()
{
}

Example::~Example()
{
}

Example &Example::inst()
{
	static Example s_instance;
	return s_instance;
}

bool Example::start()
{
	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);
	
	// Over here it's as if we are defining the texture, or drawing, thats why, the png files are the picture that we included into the project to be the design of each tile. every texture is representing a picture/design
	CtileTexture = kage::TextureManager::getTexture("data/Ctile.png");
	RtileTexture = kage::TextureManager::getTexture("data/Rtile.png");
	GtileTexture = kage::TextureManager::getTexture("data/Gtile.png");
	YtileTexture = kage::TextureManager::getTexture("data/Ytile.png");
	BRtileTexture = kage::TextureManager::getTexture("data/BRtile.png");
	GRtileTexture = kage::TextureManager::getTexture("data/GRtile.png");
	BDRtileTexture = kage::TextureManager::getTexture("data/BDRtile.png");
	RDRtileTexture = kage::TextureManager::getTexture("data/RDRtile.png");


	// Over we are assigning each tile on its own texture, by each other their pointers.

	Ctile.setTexture(*CtileTexture);
	Rtile.setTexture(*RtileTexture);
	Gtile.setTexture(*GtileTexture);
	Ytile.setTexture(*YtileTexture);
	BRtile.setTexture(*BRtileTexture);
	GRtile.setTexture(*GRtileTexture);
	BDRtile.setTexture(*BDRtileTexture);
	RDRtile.setTexture(*RDRtileTexture);

	// In here I am just setting the position of these tiles according to my UI design.
	Ctile.setPosition(sf::Vector2f(300, 210));
	Rtile.setPosition(sf::Vector2f(300, 270));
	Gtile.setPosition(sf::Vector2f(300, 320));
	Ytile.setPosition(sf::Vector2f(300, 370));
	BRtile.setPosition(sf::Vector2f(300, 440));
	GRtile.setPosition(sf::Vector2f(300, 490));
	BDRtile.setPosition(sf::Vector2f(300, 540));
	RDRtile.setPosition(sf::Vector2f(300, 590));


	for (size_t y = 0; y < 16; y++)
	{
		for (size_t x = 0; x < 11; x++)
		{
			int i = x + y * 11;

			tiles[i].setPosition(sf::Vector2f(OFFSET_X + x * TILE_X + 493, OFFSET_Y + y * TILE_Y + 181));

			if (map[i] == 0)
			{
			
			}
			if (map[i] == 1)
			{

			}
			if (map[i] == 2)
			{
			
			}
			if (map[i] == 3)
			{
			
			}
			if (map[i] == 4)
			{

			}
			if (map[i] == 5)
			{

			}
			if (map[i] == 6)
			{

			}
			if (map[i] == 7)
			{

			}
			if (map[i] == 8)
			{

			}

		}

	}

	
	return true;
}





void Example::update(float deltaT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	// In here I was only testing to print out the mouse position in the console.	
	//std::cout << mousePosition.x << " " << mousePosition.y << std::endl;
	//std::cout << mousePosition.x << " " << mousePosition.y << //" " << mouseOnTileX << " " << mouseOnTileY << " " << i << std::endl;

	
	// Over here we created a new window that will include the buttons of every tile.
	// Once any of the buttons are clicked, the value of the chosentile will change according to what tile was chosen. since each tile will represent a number, and we must also include the texture of these tiles.
	ImGui::Begin("Kage2D");

		if (ImGui::Button("Exit"))
		{
			m_running = false;
		}
		
		if(ImGui::ImageButton(*CtileTexture)) 
		{
			chosenTile = 1;
		}
		if (ImGui::ImageButton(*RtileTexture))
		{
			chosenTile = 2;
		}
		if (ImGui::ImageButton(*GtileTexture))
		{
			chosenTile = 3;
		}
		if (ImGui::ImageButton(*YtileTexture))
		{
			chosenTile = 4;
		}
		if (ImGui::ImageButton(*BRtileTexture))
		{
			chosenTile = 5;
		}
		if (ImGui::ImageButton(*GRtileTexture))
		{
			chosenTile = 6;
		}		
		if (ImGui::ImageButton(*BDRtileTexture))
		{
			chosenTile = 7;
		}
		if (ImGui::ImageButton(*RDRtileTexture))
		{
			chosenTile = 8;
		}

	
	ImGui::End();


	sf::Vector2i mousePosition = sf::Mouse::getPosition();
	sf::Vector2f offsetMousePosition = sf::Vector2f(mousePosition.x + -500, mousePosition.y + -210);
			
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) &&

		// In here we are assigning what we can call the borders of the grid..To be able to draw tiles inside the grid and inside only. if we draw tiles outside. it may crash the software.
		mousePosition.x >= 499 && mousePosition.x <= 1399 &&
		mousePosition.y >= 211 && mousePosition.y <= 691)
	{		
		int mouseOnTileX = offsetMousePosition.x / TILE_X;
		int mouseOnTileY = offsetMousePosition.y / TILE_Y;

		int i = mouseOnTileX + mouseOnTileY * 11;

		// In here we are assigning each ID to its own tile, 1 will be the Cyan tile, 2 will be red, etc..
		if(chosenTile == 1)
		{
			tiles[i].setTexture(*CtileTexture);
			map[i] = 1;
		}

		if (chosenTile == 2)
		{
			tiles[i].setTexture(*RtileTexture);
			map[i] = 2;
		}
		if (chosenTile == 3)
		{
			tiles[i].setTexture(*GtileTexture);
			map[i] = 3;
		}
		if (chosenTile == 4)
		{
			tiles[i].setTexture(*YtileTexture);
			map[i] = 4;
		}
		if (chosenTile == 5)
		{
			tiles[i].setTexture(*BRtileTexture);
			map[i] = 5;
		}
		if (chosenTile == 6)
		{
			tiles[i].setTexture(*GRtileTexture);
			map[i] = 6;
		}
		if (chosenTile == 7)
		{
			tiles[i].setTexture(*BDRtileTexture);
			map[i] = 7;
		}
		if (chosenTile == 8)
		{
			tiles[i].setTexture(*RDRtileTexture);
			map[i] = 8;
		}

	}
}

void Example::render()
{
	m_window.draw(*m_backgroundSprite);
	grid.Render(m_window);

	m_window.draw(Ctile);
	m_window.draw(Rtile);
	m_window.draw(Gtile);
	m_window.draw(Ytile);
	m_window.draw(BRtile);
	m_window.draw(GRtile);
	m_window.draw(BDRtile);
	m_window.draw(RDRtile);
	
	for (size_t i = 0; i < 176; i++)
	{
		m_window.draw(tiles[i]);
	}
	
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}

