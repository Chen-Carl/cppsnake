#ifndef DIFFICULTYSCREEN_H
#define DIFFICULTYSCREEN_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>

#include <vector>
#include "Screen.h"
#include "Button.h"
#include "zclog.h"

namespace cppsnake
{
	class DifficultyScreen : public Screen
	{
	public:
		DifficultyScreen();

		void handleInput(sf::Event &e, sf::RenderWindow &window) override;
		void update(sf::Time delta) override;
		void render(sf::RenderWindow& window) override;
	private:
		std::vector<Key::key_ptr> btns;
	};
}

#endif
