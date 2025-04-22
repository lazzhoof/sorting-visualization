#include <SFML/Graphics.hpp>
#include <utility>
#include <chrono>
#include <thread>
#include <iostream>
#include "generate.hpp"
#include "SortAlgorithms.hpp"
#include <Windows.h>
#include "WindowDraw.hpp"

const int WIDTH = 1280;
const int HEIGHT = 720;
const int NUM_BARS = 100;
const int SORT_DELAY = 5;
const int KOEF = HEIGHT / NUM_BARS;

std::vector initialVector = generateVector(NUM_BARS);
std::vector<int> values(generatePermutation(initialVector, KOEF));

int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	sf::RenderWindow window(sf::VideoMode(sf::Vector2u{ WIDTH, HEIGHT }), "Sorting Visualisation");

	std::srand(static_cast<unsigned>(std::time(0)));

	bool sorting = true;

	BubbleSort bubble = BubbleSort(values);

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
		}

		if (sorting)
		{
			sorting = !bubble.isSorted();
			bubble.step();
			drawBars(window, WIDTH, HEIGHT, NUM_BARS, values);
			std::this_thread::sleep_for(std::chrono::milliseconds(SORT_DELAY));
		}
	}

	return 0;
}

//TODO:need to add sound after step completed
//TODO:custom data fo sorting
//TODO:need to add GUI