#ifndef GAME_OVER_SCREEN_H
#define GAME_OVER_SCREEN_H

#include <SFML/Graphics.hpp>

#include "Screen.h"

namespace cppsnake
{
	class GameOverScreen : public Screen
	{
	public:
		GameOverScreen(int winner, std::size_t score);

		void handleInput(sf::Event &e, sf::RenderWindow &window) override;
		void update(sf::Time delta) override;
		void render(sf::RenderWindow &window) override;

	private:
		sf::Font font_;
		sf::Text text_;

		unsigned score_;
	};
}

#endif