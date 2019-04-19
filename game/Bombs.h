#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Bombs
{
	private:

	public:

		Bombs()
		{
			texture();

		}

		void texture()
		{
			Texture bombTexture;
			if (!bombTexture.loadFromFile("bomb.png"))
			{
				cout << "Unable to load bomb texture!" << endl;
				exit(EXIT_FAILURE);
			}
			Sprite bomb;
			bomb.setTexture(bombTexture);
		}

		void draw(RenderWindow& win)
		{

		}

		void moveDown()
		{

		}
};