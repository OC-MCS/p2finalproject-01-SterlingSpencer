#pragma once
#include <SFML/Graphics.hpp>
#include "ProjectileMgr.h"
using namespace std;
using namespace sf;

class Human
{
	private:
		Sprite *player;
		Projectiles *projectiles;
	public:
		Human() 
		{
		
		}
		Human(Projectiles *projectiles, Sprite *ship) {
			this->projectiles = projectiles;
			this->player = ship;
		}
		 void humanUpdate(Event event) 
		 {
			if(Keyboard::isKeyPressed(Keyboard::Space))
			{
				projectiles->addMissile(player->getPosition());
			}
		 }
		void bombHit()
		{

		}

		void moveShip()
		{
			const float DISTANCE = 5.0;

			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				// left arrow is pressed: move our ship left 5 pixels
				// 2nd parm is y direction. We don't want to move up/down, so it's zero.
				player->move(-DISTANCE, 0);
			}
			else if (Keyboard::isKeyPressed(Keyboard::D))
			{
				// right arrow is pressed: move our ship right 5 pixels
				player->move(DISTANCE, 0);
			}
		}
};