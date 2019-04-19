#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
using namespace std;
using namespace sf;

class Missiles
{
	private:
		Sprite missile;
	public:
		Missiles(Vector2f shipPosition, Texture& missileTexture)
		{
			missile.setPosition(shipPosition);
			missile.setTexture(missileTexture);
		}

		void draw(RenderWindow& win)
		{
			win.draw(missile);
		}

		void inFlight()
		{
			missile.move(0, -5);
		}
};