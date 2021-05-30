#include <SFML/Graphics.hpp>

#include <random>
#include <memory>

#include "GameScreen.h"
#include "GameOverScreen.h"
#include "Game.h"

using namespace cppsnake;

GameScreen::GameScreen()
{
	snake_1 = Snake(1, sf::Color::Blue);
	snake_0 = Snake(0, sf::Color::Green);
}

void GameScreen::handleInput(sf::RenderWindow &window)
{
	snake_1.handleInput();
	snake_0.handleInput();
}

void GameScreen::update(sf::Time delta)
{
	if (fruit_.size() == 0)
		generateFruit();

	snake_1.update(delta);
	snake_1.checkFruitCollisions(fruit_);
	snake_0.update(delta);
	snake_0.checkFruitCollisions(fruit_);
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

	for (auto fruit : fruit_)
		fruit.render(window);
}

void GameScreen::generateFruit()
{
	static std::default_random_engine engine;
	engine.seed(time(NULL));
	static std::uniform_int_distribution<int> xDistribution(0, Game::Width - SnakeNode::Width);
	static std::uniform_int_distribution<int> yDistribution(0, Game::Height - SnakeNode::Height);

	fruit_.push_back(Fruit(sf::Vector2f(xDistribution(engine), yDistribution(engine))));
}
