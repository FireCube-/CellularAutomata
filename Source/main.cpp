#include <SFML\Graphics.hpp>
#include <vector>
#include <bitset>

#include "Constants.h"
#include "Cell.h"

std::vector<std::vector<Cell>> setupCells();

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Cellular Automaton");

	auto cells = setupCells();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear(sf::Color::White);

		int row = cells.size();
		std::vector<Cell> next(GRID_X);
		initializeCells(next);
		cells.push_back(next);
		for (int col = 0; col < cells[row].size(); ++col)
		{
			std::bitset<3> prev(0b000);
			for (int i = -1; i <= 1; i++)
			{
				if (col == 0 && i == -1) prev[2] = 0;
				else if (col == cells[row].size() - 1 && i == 1) prev[0] = 0;
				else if (cells[row - 1][col + i].alive) prev[1 - i] = 1;
			}

			for (int i = 0; i < 8; i++)
			{
				if (prev == PATTERNS[i] && RULE & int(pow(2, i)))
					cells[row][col].alive = true;
			}
		}

		if (row == int(floor(HEIGHT / SCALE))) 
		{
			for (int i = 0; i < cells.size(); ++i)
				for (int j = 0; j < cells[i].size(); ++j)
					cells[i][j].show(window, i);
			window.display();
		}
	}
}

std::vector<std::vector<Cell>> setupCells()
{
	std::vector<std::vector<Cell>> cells;
	std::vector<Cell> firstRow(GRID_X);

	firstRow[floor(GRID_X / 2) + 1].alive = true;
	cells.push_back(firstRow);

	initializeCells(cells[0]);

	return cells;
}
