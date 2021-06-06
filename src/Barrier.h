#ifndef BARRIER_H
#define BARRIER_H

#include <SFML/Graphics.hpp>

#include "Brick.h"

namespace cppsnake
{
	class Barrier
	{
		friend class GameScreen;
	public:
		Barrier(int level = 1, sf::Color color = sf::Color::Green);

		std::vector<Brick> getBricks();
		
		void render(sf::RenderWindow& window);
	private:
		void initBricks1(sf::Color color);
		void initBricks2(sf::Color color);
		void initBricks3(sf::Color color);
		void initBricks4(sf::Color color);

		int level_;

		std::vector<Brick> bricks_;
	};
}

#endif // !BARRIER_H
