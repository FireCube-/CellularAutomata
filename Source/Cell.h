#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

#include "Constants.h"

struct Cell
{
	int x = 0;
	bool alive = false;

	Cell() = default;
	Cell(const Cell &c) = default;
	Cell(const int &xx, const bool &aa) : x(xx), alive(aa) {}

	void show(sf::RenderWindow &window, const int &row);
	
	friend void initializeCells(std::vector<Cell> &row);

private:
	sf::VertexArray setupBorders();

};
