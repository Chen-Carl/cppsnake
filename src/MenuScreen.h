#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H

#include <SFML/Graphics.hpp>

#include "Screen.h"
#include "DifficultyScreen.h"

namespace cppsnake
{
	class MenuScreen : public Screen
	{
	public:
		MenuScreen();

		void handleInput(sf::Event &e, sf::RenderWindow &window) override;
		void update(sf::Time delta) override;
		void render(sf::RenderWindow &window) override;

	private:
		sf::Font font_;
		sf::Text snakeText_;
		sf::Text text_;
	};
}

#endif