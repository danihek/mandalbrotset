#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>

double map(double value, double start1, double stop1, double start2, double stop2);

int WINDOW_W = 512;
int WINDOW_H = 512;

double xscalingFactor = 1;
double yscalingFactor = 1;

int main()
{	
	
	sf::RenderWindow window(sf::VideoMode(WINDOW_W, WINDOW_H), "Mandalbrot Set");
	sf::Event e;

	while (window.isOpen())
	{
		window.clear();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			yscalingFactor=xscalingFactor-0.01;	
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			yscalingFactor=yscalingFactor+0.01;	
		}
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			xscalingFactor=xscalingFactor-0.01;	
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			xscalingFactor=yscalingFactor+0.01;	
		}

		for (int x = 0; x < WINDOW_W; x++)
		{
			for (int y = 0; y < WINDOW_H; y++)
			{
				double a = map(x, 0, WINDOW_W, xscalingFactor, -xscalingFactor);
				double b = map(y, 0, WINDOW_H, yscalingFactor, -yscalingFactor);

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

					if (std::abs(a + b) > 16)
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
	}

	return 0;
}

double map(double value, double start1, double stop1, double start2, double stop2)
{
	return start2 + (stop2 - start2) * ((value - start1) / (stop1 - start1));
}
