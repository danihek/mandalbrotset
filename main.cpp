#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <ostream>

double map(double value, double start1, double stop1, double start2, double stop2);

int WINDOW_W = 900;
int WINDOW_H = 900;

double scalingFactor = 1;
double quality = 0.00;
double qualityF = 0.05;

int main(int argc, char *args[])
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_W, WINDOW_H), "Mandalbrot Set");
	sf::Event e;

	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {}

	while (window.isOpen())
	{
		window.clear();
	
		for (int x = 0; x < WINDOW_W; x++)
		{
			for (int y = 0; y < WINDOW_H; y++)
			{
				double a = map(x, 0, WINDOW_W, -2, 2);
				double b = map(y, 0, WINDOW_H, -2, 2);

				double ca = a;
				double cb = b;

				int n = 0;
				int z = 0;

				while (n < 500)
				{
					double aa = a * a - b * b;
					double bb = 2 * a * b;

					a = aa + ca;
					b = bb + cb;

					if (std::abs(a + b) > quality)
					{
						break;
					}
					n++;
				}

				int bright = 0;
				if (n == 500)
				{
					bright = 255;
				}

				sf::Vertex point(sf::Vector2f(x, y), sf::Color(bright, n - bright, n - bright));
				window.draw(&point, 1, sf::Points);
			}
		}
		window.display();
		quality += qualityF;
		std::cout<<quality<<std::endl;
	}

	return 0;
}

double map(double value, double start1, double stop1, double start2, double stop2)
{
	return start2 + (stop2 - start2) * ((value - start1) / (stop1 - start1));
}
