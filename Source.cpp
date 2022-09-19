#include <SFML/Graphics.hpp>
#include <iostream>

int getShapeN()
{
	using namespace std;
	cout << "This program draws polygons.\nFirst choose the number of polygon sides.\nIf you want to get a circle just insert 99.\n";
	int n;
	do
	{
		cin >> n;
		cin.clear();
		cin.ignore(32767, '\n');
	} while (n < 1);
	return n;
}

double getRadius()
{
	using namespace std;
	cout << "Choose the circumscribed circles raduis (100-300 suggested)\n";
	int r;
	do
	{
		cin >> r;
		cin.clear();
		cin.ignore(32767, '\n');
	} while (r == 0);
	return r;
}

int main()
{
	using namespace sf;

	const double PI = 3.141592653589793238463;
	int nOfSides = getShapeN();
	double rOutCircle = getRadius();
	double x;
	double y;
	int windowSize = 600;
	int xOffcet = windowSize / 2;
	int yOffcet = windowSize / 2;
	double angleRad;
	VertexArray myPoligon(LineStrip, (nOfSides + 1));// create an array of lines

	RenderWindow window(VideoMode(windowSize, windowSize), "Drawing tool");

	while (window.isOpen()) {

		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик»?
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear(Color(249, 251, 253, 0));

		// Расчет координат вершин многоугольника
		for (int i = 0; i <= nOfSides; ++i) {
			angleRad = (PI / nOfSides) * 2 * i;
			x = rOutCircle * cos(angleRad);
			y = rOutCircle * sin(angleRad);
			myPoligon[i].position = Vector2f(x + xOffcet, y + yOffcet);
			myPoligon[i].color = Color::Black;
		}

		window.draw(myPoligon);

		window.display();
	}
}