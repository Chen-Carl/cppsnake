#include <SFML/Graphics.hpp>

#include "DifficultyScreen.h"
#include "GameScreen.h"
#include "Game.h"

using namespace cppsnake;

DifficultyScreen::DifficultyScreen()
{
	font_.loadFromFile("Fonts/game_over.ttf");
	text_.setFont(font_);
	text_.setCharacterSize(56);
	text_.setString(
		"\n\nPlease choose the level of difficulty"
		"\n\nPress [1] to choose level 1"
		"\n\nPress [2] to choose level 2"
		"\n\nPress [3] to choose level 3");
	text_.setFillColor(sf::Color::Red);

	sf::FloatRect textBounds = text_.getLocalBounds();
	text_.setOrigin(textBounds.left + textBounds.width / 2,
		textBounds.top + textBounds.height / 2);
	text_.setPosition(Game::Width / 2 + 150, Game::Height / 2);
}

void DifficultyScreen::handleInput(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		//Level = 1;
		Game::Screen = std::make_shared<GameScreen>(1);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		//Level = 2;
		Game::Screen = std::make_shared<GameScreen>(2);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		//Level = 3;
		Game::Screen = std::make_shared<GameScreen>(3);
	}
}

void DifficultyScreen::update(sf::Time delta)
{
}

void DifficultyScreen::render(sf::RenderWindow& window)
{
	window.draw(text_);
}