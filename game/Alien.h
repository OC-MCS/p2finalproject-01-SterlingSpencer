#pragma once
#include <SFML/Graphics.hpp>
#include "AlienArmada.h"
#include <vector>
#include <iostream>
using namespace std;
using namespace sf;

class Alien
{
	private:
		Sprite alien;
	public:
		Alien(Texture& texture,Vector2f alienPos)
		{
			alien.setTexture(texture);
			alien.setPosition(alienPos);
			alien.setScale(0.1, 0.1);
		}

		void draw(RenderWindow& win)
		{
			win.draw(alien);
		}

		void moveDown()
		{
			alien.move(0, 1);
		}
};