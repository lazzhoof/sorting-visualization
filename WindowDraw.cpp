#include <SFML/Graphics.hpp>

void drawBars(sf::RenderWindow& window, const int WIDTH, const int HEIGHT, const int NUM_BARS, std::vector<int>& values)
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
