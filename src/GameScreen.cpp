#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <random>
#include <memory>
#include <chrono>
#include <ctime>
#include <iostream>

#include "GameScreen.h"
#include "GameOverScreen.h"
#include "Game.h"

using namespace cppsnake;

static std::default_random_engine engine;
static std::uniform_int_distribution<int> xDistribution(10, Game::Width - SnakeNode::Width - 10);
static std::uniform_int_distribution<int> yDistribution(10, Game::Height - SnakeNode::Height - 10);

GameScreen::GameScreen(int level) : barrier_(level, sf::Color(128, 0, 128))
{
	snake_1 = Snake(1, sf::Color::Blue);
	snake_0 = Snake(0, sf::Color::Green);
	barrier_ = Barrier(level, sf::Color(128, 0, 128));
	engine.seed(std::time(NULL));
	std::thread generateFruits(&checkFruitSize, this);
	generateFruits.detach();
}

void GameScreen::handleInput(sf::Event &e, sf::RenderWindow &window)
{
	snake_1.handleInput();
	snake_0.handleInput();
}

void GameScreen::update(sf::Time delta)
{
	snake_1.update(delta);

	mutex_.lock();
	snake_1.checkFruitCollisions(fruit_);
	mutex_.unlock();

	snake_0.update(delta);

	mutex_.lock();
	snake_0.checkFruitCollisions(fruit_);
	mutex_.unlock();

	snake_0.checkBarrierCollisions(barrier_);
	snake_1.checkBarrierCollisions(barrier_);

	checkMutualCollisions(snake_0, snake_1);

	if (snake_1.hitSelf())
		Game::Screen = std::make_shared<GameOverScreen>(0, snake_0.getSize());
	if (snake_0.hitSelf())
		Game::Screen = std::make_shared<GameOverScreen>(1, snake_1.getSize());
}

void GameScreen::render(sf::RenderWindow &window)
{
	snake_1.render(window);
	snake_0.render(window);

	barrier_.render(window);

	for (auto fruit : fruit_)
		fruit.render(window);
}

void GameScreen::generateFruit()
{
	// fruit_.push_back(Fruit(sf::Vector2f(xDistribution(engine), yDistribution(engine))));

	int x = xDistribution(engine);
	int y = yDistribution(engine);
	for (decltype(barrier_.bricks_.size()) i = 0; i < barrier_.bricks_.size(); ++i)
	{
		if (Fruit(sf::Vector2f(x, y)).getBounds().intersects(barrier_.bricks_[i].getBounds()))
		{
			return;
		}
	}
	fruit_.push_back(Fruit(sf::Vector2f(x, y)));
}

void GameScreen::checkFruitSize()
{
	// sf::Clock clock;
	// sf::Time dura = sf::seconds(0.01f);
	// sf::Time elapsed;
	while (1)
	{
		if (fruit_.size() < 5)
		{
			mutex_.lock();
			generateFruit();
			mutex_.unlock();
			std::this_thread::yield();
		}
		std::chrono::milliseconds dura(100);
		std::this_thread::sleep_for(dura);
		// elapsed = clock.getElapsedTime();
		// if (elapsed > dura)
		// {
		// 	fruit_.erase(fruit_.begin());
		// }
	}
}
