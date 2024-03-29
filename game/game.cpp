//=========================================================
// This is just the starting point for your final project.
// You are expected to modify and add classes/files as needed.
// The code below is the original code for our first graphics
// project (moving the little green ship). 
//========================================================
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include "Missiles.h"
#include "AlienArmada.h"
#include "Labels.h"
#include "Human.h"
#include "ProjectileMgr.h"
using namespace sf; 

//============================================================
// Sterling Spencer
// Programming II: Final Assignment
// Professor Harbert
// Due: 4/19/19
//============================================================

// note: a Sprite represents an image on screen. A sprite knows and remembers its own position
// ship.move(offsetX, offsetY) adds offsetX, offsetY to 
// the current position of the ship. 
// x is horizontal, y is vertical. 
// 0,0 is in the UPPER LEFT of the screen, y increases DOWN the screen




int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	// load textures from file into memory. This doesn't display anything yet.
	// Notice we do this *before* going into animation loop.
	Texture shipTexture;
	if (!shipTexture.loadFromFile("ship.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture starsTexture;
	if (!starsTexture.loadFromFile("stars.jpg"))
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}

	// A sprite is a thing we can draw and manipulate on the screen.
	// We have to give it a "texture" to specify what it looks like

	Sprite background;
	background.setTexture(starsTexture);
	// The texture file is 640x480, so scale it up a little to cover 800x600 window
	background.setScale(1.5, 1.5);

	// create sprite and texture it
	Sprite ship;
	ship.setTexture(shipTexture);


	// initial position of the ship will be approx middle of screen
	float shipX = window.getSize().x / 5.0f;
	float shipY = (window.getSize().y / 5.0f) * 4.0f;
	ship.setPosition(shipX, shipY);

	Projectiles projectile;
	Labels UI;
	AlienArmada alienFleet;
	Human player = Human(&projectile, &ship);
	bool starting = false;

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it
		Event event;
		
		
		
		
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
			
			//else if (event.type == Event::KeyPressed)
			//{
			//	if (event.key.code == Keyboard::Space)
			//	{
			//		// handle space bar
			//		getPositon(ship)
			//	}
			//}
			else if (event.type == Event::MouseButtonReleased)
			{
				// maybe they just clicked on one of the settings "buttons"
				// check for this and handle it.
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				if (!starting)
				{
					starting = UI.start(window, mousePos);
				}
			}
			else
				player.humanUpdate(event);
		}

		//===========================================================
		// Everything from here to the end of the loop is where you put your
		// code to produce ONE frame of the animation. The next iteration of the loop will
		// render the next frame, and so on. All this happens ~ 60 times/second.
		//===========================================================

			// draw background first, so everything that's drawn later 
			// will appear on top of background
			window.draw(background);

			if (starting)
			{
				player.moveShip();

				// draw the ship on top of background 
				// (the ship from previous frame was erased when we drew background)
				window.draw(ship);
				alienFleet.moveDown();
				alienFleet.draw(window);
				projectile.draw(window);
				UI.draw(window, 10, 3, true);
			}
			else
			{
				UI.draw(window, 10, 3, false);
			}

			


			// end the current frame; this makes everything that we have 
			// already "drawn" actually show up on the screen
			window.display();

			// At this point the frame we have built is now visible on screen.
			// Now control will go back to the top of the animation loop
			// to build the next frame. Since we begin by drawing the
			// background, each frame is rebuilt from scratch.
	} // end body of animation loop

	return 0;
}

