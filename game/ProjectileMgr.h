#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "Missiles.h"
#include "Bombs.h"
using namespace std;
using namespace sf;

class Projectiles {
	private:
		list<Missiles> missileList;
		list<Bombs> bombList;
		Texture missileTexture;
	public:
		Projectiles()
		{
			if (!missileTexture.loadFromFile("missile.png"))
			{
				cout << "Unable to load missile texture!" << endl;
				exit(EXIT_FAILURE);
			}
		}

		void draw(RenderWindow& win)
		{
			list<Missiles>::iterator iter;
			for (iter = missileList.begin(); iter != missileList.end(); iter++)
			{
				iter->inFlight();
				iter->draw(win);
			}
		}

		void addMissile(Vector2f shipPosition)
		{
			missileList.push_back(Missiles(shipPosition, missileTexture));
		}
};
