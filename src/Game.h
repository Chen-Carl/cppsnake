#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>
#include <memory>
#include <string>

#include "Screen.h"

namespace cppsnake
{
	class Game
	{
	public:
		Game();

		void run();
		void setBackground(const std::string &file);
		void handleInput();
		void update(sf::Time delta);
		void render();

		static const int Width = 1024;
		static const int Height = 768;

		static std::shared_ptr<Screen> screen;

	private:
		sf::RenderWindow window_;
		sf::Music bgMusic_;
		// bool isLineOn = false;

		static const sf::Time TimePerFrame;
	};
}

#endif