#include <SFML/Graphics.hpp>
#include <iostream>

#include "DifficultyScreen.h"
#include "GameScreen.h"
#include "Game.h"

using namespace cppsnake;

DifficultyScreen::DifficultyScreen()
{
	for (size_t i = 0; i < 3; i++)
	{
		auto btn = std::shared_ptr<Key>(new Key('A', Game::Width / 2 + 150, Game::Height / 2 + 80 * (i - 1)));
		btns.push_back(btn);
	}
}

void DifficultyScreen::handleInput(sf::Event &e, sf::RenderWindow& window)
{
	int clicked = 0;
	for (size_t i = 0; i < btns.size(); i++)
	{
		if (btns[i]->onClick(e, window))
		{
			std::cout << "onButtonClicked" << std::endl;
			clicked = i + 1;
		}
	}
	if (clicked != 0)
		Game::Screen = std::make_shared<GameScreen>(clicked);
}

void DifficultyScreen::update(sf::Time delta)
{
}

void DifficultyScreen::render(sf::RenderWindow& window)
{
	// std::cout << btns.size() << std::endl;
	for (auto &x : btns)
	{
		x->render(window);
	}
}