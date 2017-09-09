#include "Cell.h"

void Cell::show(sf::RenderWindow & window, const int &row)
{
	//window.draw(setupBorders());
	if (alive)
	{
		sf::RectangleShape rect(sf::Vector2f(SCALE, SCALE));
		rect.setFillColor(sf::Color::Black);
		rect.setPosition(sf::Vector2f(x * SCALE, row * SCALE));
		window.draw(rect);
	}
}

sf::VertexArray Cell::setupBorders()
{

	sf::VertexArray tmp_borders(sf::Lines, 8);
	for (int i = 0; i < tmp_borders.getVertexCount(); ++i) tmp_borders[i].color = sf::Color::Black;

	tmp_borders[0].position = sf::Vector2f(x, 0);
	tmp_borders[1].position = sf::Vector2f(x + SCALE, 0);

	tmp_borders[2].position = sf::Vector2f(x + SCALE, 0);
	tmp_borders[3].position = sf::Vector2f(x + SCALE, SCALE);

	tmp_borders[4].position = sf::Vector2f(x + SCALE, SCALE);
	tmp_borders[5].position = sf::Vector2f(x, SCALE);

	tmp_borders[6].position = sf::Vector2f(x, SCALE);
	tmp_borders[7].position = sf::Vector2f(x, 0);

	return tmp_borders;
}

void initializeCells(std::vector<Cell>& row)
{
	for (int i = 0; i < GRID_X; ++i) row[i].x = i;
}
