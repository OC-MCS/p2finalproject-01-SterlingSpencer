#pragma once
#include <list>
#include <SFML/Graphics.hpp>
#include "Alien.h"
#include <ctime>
#include <iostream>
using namespace std;
using namespace sf;

class AlienArmada
{
	private:
		list<Alien> alienList;
		Texture alienTexture;
	public:
		AlienArmada()
		{
			texture();
			for (int i = 0; i < 10; i++)
			{
				alienList.push_back(Alien(alienTexture, Vector2f(i * 80, 20)));
			}
		}
		void draw(RenderWindow& win)
		{
			list<Alien>::iterator iter;
			for (iter = alienList.begin(); iter != alienList.end(); iter++)
			{
				iter->draw(win);
			}
		}
		void missileCheck()
		{

		}
		void dropBomb()
		{
			srand(time(0));
			rand() % alienList.size();
		}
		void texture()
		{
			if (!alienTexture.loadFromFile("small-alien-png-355.png"))
			{
				cout << "Unable to load alien texture!" << endl;
				exit(EXIT_FAILURE);
			}
		}

		void moveDown()
		{
			list<Alien>::iterator iter;
			for (iter = alienList.begin(); iter != alienList.end(); iter++)
			{
				iter->moveDown();
			}
		}
};