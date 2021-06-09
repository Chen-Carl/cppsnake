#include <SFML/Graphics.hpp>

#include <memory>

#include "MenuScreen.h"
#include "Game.h"

using namespace cppsnake;

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 25.f);

std::shared_ptr<Screen> Game::Screen = std::make_shared<MenuScreen>();

Game::Game()
	: window_(sf::VideoMode(Game::Width + 300, Game::Height), "sfSnake")
{
	bgMusic_.openFromFile("Music/bg_music.wav");
	bgMusic_.setLoop(true);
	bgMusic_.play();
}

void Game::handleInput()
{
	sf::Event event;

	while (window_.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window_.close();
	}
	Game::Screen->handleInput(event, window_);
}

void Game::update(sf::Time delta)
{
	Game::Screen->update(delta);
}

void Game::setBackground(const std::string &file)
{
	
	sf::Texture bg;
	sf::Texture bgLine;
	bg.loadFromFile(file);
	bgLine.loadFromFile("./images/bgLine.png");
	sf::RectangleShape background(sf::Vector2f(Game::Width + 300, Game::Height));
	background.setTexture(&bg);

	// if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::L) && !isLineOn)
	// 	isLineOn = !isLineOn;
	// if (isLineOn)
	// {
	// 	background.setTexture(&bgLine);
	// }

	window_.draw(background);
}

void Game::render()
{
	window_.clear();
	setBackground("./images/background.jpg");
	Game::Screen->render(window_);
	window_.display();
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (window_.isOpen())
	{
		sf::Time delta = clock.restart();
		timeSinceLastUpdate += delta;

		while (timeSinceLastUpdate > Game::TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			handleInput();
			update(TimePerFrame);
		}

		render();
	}
}