#include <SFML/Graphics.hpp>
#include <utility>
#include <chrono>
#include <thread>
#include <iostream>
#include "generate.hpp"
#include "sorts.hpp"
#include <Windows.h>

const int WIDTH = 1280;
const int HEIGHT = 720;
const int NUM_BARS = 100;
const int SORT_DELAY = 5;
const int KOEF = HEIGHT / NUM_BARS;

std::vector initialVector = generateVector(NUM_BARS);
std::vector<int> values(generatePermutation(initialVector, KOEF));
int i = 0, j = 0;

void drawBars(sf::RenderWindow& window)
{
	window.clear();
	float barWidth = static_cast<float>(WIDTH) / NUM_BARS;

	for (int x = 0; x < NUM_BARS; x++)
	{
		sf::RectangleShape bar(sf::Vector2f(barWidth, values[x]));
		bar.setPosition(sf::Vector2f{ x * barWidth, static_cast<float>(HEIGHT - values[x]) });
		bar.setFillColor(sf::Color::White);
		window.draw(bar);
	}

	window.display();
}

int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	sf::RenderWindow window(sf::VideoMode(sf::Vector2u{ WIDTH, HEIGHT }), "Sorting Visualisation");

	std::srand(static_cast<unsigned>(std::time(0)));

	bool sorting = true;

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
			sorting = bubbleSortStep(values, &i, &j, NUM_BARS);
			drawBars(window);
			std::this_thread::sleep_for(std::chrono::milliseconds(SORT_DELAY));
		}
	}

	return 0;
}
