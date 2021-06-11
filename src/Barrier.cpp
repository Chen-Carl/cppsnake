#include <SFML/Graphics.hpp>

#include "Barrier.h"
#include "Brick.h"
#include "Game.h"

#define brickWidth 15

using namespace cppsnake;

Barrier::Barrier(int level, sf::Color color) : level_(level)
{
	switch (level_)
	{
	case 1://design barrier of level_1 here
		initBricks1(color);
		initBricks2(color);
		break;
	case 2://design barrier of level_2 here
		initBricks1(color);
		initBricks2(color);
		initBricks3(color);
		break;
	case 3://design barrier of level_3 here
		initBricks1(color);
		initBricks2(color);
		initBricks3(color);
		initBricks4(color);
		break;
	default:
		break;
	}
}

void Barrier::initBricks1(sf::Color color)
{
	bricks_.push_back(Brick(brickWidth, 100, sf::Vector2f(
		(Game::Width) / 5,
		Game::Height / 5 - 50),
		color));
	bricks_.push_back(Brick(90, brickWidth, sf::Vector2f(
		(Game::Width) / 5 + brickWidth,
		Game::Height / 5 - 50),
		color));
	bricks_.push_back(Brick(brickWidth, 100, sf::Vector2f(
		4 * (Game::Width) / 5,
		4 * Game::Height / 5 - 40),
		color));
	bricks_.push_back(Brick(90, brickWidth, sf::Vector2f(
		4 * (Game::Width) / 5 - 90,
		4 * Game::Height / 5 + 45),
		color));
}

void Barrier::initBricks2(sf::Color color)
{
	bricks_.push_back(Brick(brickWidth, 100, sf::Vector2f(
		4 * (Game::Width) / 5,
		Game::Height / 5 - 50),
		color));
	bricks_.push_back(Brick(90, brickWidth, sf::Vector2f(
		4 * (Game::Width) / 5 - 90,
		Game::Height / 5 - 50),
		color));
	bricks_.push_back(Brick(brickWidth, 100, sf::Vector2f(
		(Game::Width) / 5,
		4 * Game::Height / 5 - 40),
		color));
	bricks_.push_back(Brick(90, brickWidth, sf::Vector2f(
		(Game::Width) / 5 + brickWidth,
		4 * Game::Height / 5 + 45),
		color));
}

void Barrier::initBricks3(sf::Color color)
{
	bricks_.push_back(Brick(brickWidth, 150, sf::Vector2f(
		7 * (Game::Width) / 8,
		Game::Height / 2 - 75),
		color));
	bricks_.push_back(Brick(150, brickWidth, sf::Vector2f(
		(Game::Width) / 2 - 75,
		Game::Height / 8 - 50),
		color));
	bricks_.push_back(Brick(brickWidth, 150, sf::Vector2f(
		(Game::Width) / 8,
		Game::Height / 2 - 75),
		color));
	bricks_.push_back(Brick(150, brickWidth, sf::Vector2f(
		(Game::Width) / 2 - 75,
		7 * Game::Height / 8 + 50),
		color));
}

void Barrier::initBricks4(sf::Color color)
{
	bricks_.push_back(Brick(brickWidth, 150, sf::Vector2f(
		2 * (Game::Width) / 3,
		Game::Height / 2 - 75),
		color));
	bricks_.push_back(Brick(150, brickWidth, sf::Vector2f(
		(Game::Width) / 2 - 75,
		Game::Height / 3 - 50),
		color));
	bricks_.push_back(Brick(brickWidth, 150, sf::Vector2f(
		(Game::Width) / 3,
		Game::Height / 2 - 75),
		color));
	bricks_.push_back(Brick(150, brickWidth, sf::Vector2f(
		(Game::Width) / 2 - 75,
		2 * Game::Height / 3 + 50),
		color));
}

std::vector<Brick> Barrier::getBricks()
{
	return bricks_;
}

void Barrier::render(sf::RenderWindow& window)
{
	for (auto brick : bricks_)
		brick.render(window);
}