#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using namespace sf;

void die(string msg)
{
	cout << msg << endl;
	exit(-1);
}

class Labels
{
	private:
		RectangleShape startBtn;
	public:
		void draw(RenderWindow& win, int alienAmount, int lives, bool inGame)
		{
			if (!inGame)
			{
				Font gameTitle;
				if (!gameTitle.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
				{
					die("couldn't load font");
				}
				Text title("Space Invaders", gameTitle, 85);
				title.setPosition(100, 100);
				win.draw(title);

				Vector2f startBtnPos(400, 300);
				startBtn.setPosition(startBtnPos);
				startBtn.setOutlineColor(Color::White);
				startBtn.setOutlineThickness(2);
				startBtn.setFillColor(Color::Green);
				startBtn.setSize(Vector2f(60, 30));

				win.draw(startBtn);

				Font font1;
				if (!font1.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
				{
					die("couldn't load font");
				}
				Text start("Start", font1, 25);
				start.setPosition(400, 300);
				win.draw(start);
			}
			else
			{
				Font font2;
				if (!font2.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
				{
					die("couldn't load font");
				}
				Text aliensDestroyed("Aliens Killed:" + to_string(alienAmount - 10), font2, 25);
				aliensDestroyed.setPosition(20, 20);
				win.draw(aliensDestroyed);
				Font font3;
				if (!font3.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
				{
					die("couldn't load font");
				}
				Text livesLeft("Lives Left:" + to_string(lives), font3, 25);
				livesLeft.setPosition(650, 20);
				win.draw(livesLeft);
			}
		}

		bool start(RenderWindow& win, Vector2f mouse)
		{
			bool gameStarted = false;

			if (startBtn.getGlobalBounds().contains(mouse))
			{
				gameStarted = true;
			}

			return gameStarted;
		}
};

