#ifndef DIFFICULTYSCREEN_H
#define DIFFICULTYSCREEN_H

#include <SFML/Graphics.hpp>

#include "Screen.h"

namespace cppsnake
{
	class DifficultyScreen : public Screen
	{
	public:
		DifficultyScreen();

		void handleInput(sf::RenderWindow& window)override;
		void update(sf::Time delta) override;
		void render(sf::RenderWindow& window) override;
	private:
		sf::Font font_;
		sf::Text text_;
	};
}
#endif // !DIFFICULTYSCREEN_H
