#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <SFML/Graphics.hpp>
#include <thread>
#include <mutex>

#include "Screen.h"
#include "Snake.h"
#include "Fruit.h"

namespace cppsnake
{
	class GameScreen : public Screen
	{
	public:
		GameScreen();

		void handleInput(sf::RenderWindow &window) override;
		void update(sf::Time delta) override;
		void render(sf::RenderWindow &window) override;

		void generateFruit();
		void checkFruitSize();

	private:
		Snake snake_1 = Snake(1, sf::Color::Green);
		Snake snake_0 = Snake(0, sf::Color::Blue);
		int maxFruitSize = 5;
		std::vector<Fruit> fruit_;
		std::mutex mutex_;
	};
}

#endif