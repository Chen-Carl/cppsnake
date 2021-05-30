#include <SFML/Graphics.hpp>

#include <memory>
#include <iostream>

#include "Snake.h"
#include "Game.h"
#include "Fruit.h"
#include "SnakeNode.h"
#include "GameOverScreen.h"

using namespace cppsnake;

const int Snake::InitialSize = 5;

Snake::Snake(int index, sf::Color color) : hitSelf_(false), index_(index)
{
	direction_ = Direction::Up;
	initNodes(color);

	pickupBuffer_.loadFromFile("Sounds/pickup.aiff");
	pickupSound_.setBuffer(pickupBuffer_);
	pickupSound_.setVolume(30);

	dieBuffer_.loadFromFile("Sounds/die.wav");
	dieSound_.setBuffer(dieBuffer_);
	dieSound_.setVolume(50);
}

void Snake::initNodes(sf::Color color)
{
	for (int i = 0; i < Snake::InitialSize; ++i)
	{
		nodes_.push_back(SnakeNode(sf::Vector2f(
			Game::Width / 2 - SnakeNode::Width / 2 - (2 * index_ - 1) * 100,
			Game::Height / 2 - (SnakeNode::Height / 2) + (SnakeNode::Height * i)), color));
	}
}

void Snake::handleInput()
{
	if (index_ == 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && direction_ != Direction::Down)
			direction_ = Direction::Up;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && direction_ != Direction::Up)
			direction_ = Direction::Down;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && direction_ != Direction::Right)
			direction_ = Direction::Left;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && direction_ != Direction::Left)
			direction_ = Direction::Right;
	}
	else if (index_ == 1)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && direction_ != Direction::Down)
			direction_ = Direction::Up;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && direction_ != Direction::Up)
			direction_ = Direction::Down;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && direction_ != Direction::Right)
			direction_ = Direction::Left;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && direction_ != Direction::Left)
			direction_ = Direction::Right;
	}
}

void Snake::update(sf::Time delta)
{
	move();
	checkEdgeCollisions();
	checkSelfCollisions();
}

void Snake::checkFruitCollisions(std::vector<Fruit>& fruits)
{
	decltype(fruits.begin()) toRemove = fruits.end();

	for (auto it = fruits.begin(); it != fruits.end(); ++it)
	{
		if (it->getBounds().intersects(nodes_[0].getBounds()))
			toRemove = it;
	}

	if (toRemove != fruits.end())
	{
		pickupSound_.play();
		grow();
		fruits.erase(toRemove);
	}
}

void Snake::grow()
{
	switch (direction_)
	{
	case Direction::Up:
		nodes_.push_back(SnakeNode(sf::Vector2f(nodes_[nodes_.size() - 1].getPosition().x,
			nodes_[nodes_.size() - 1].getPosition().y + SnakeNode::Height), nodes_.begin()->getColor()));
		break;
	case Direction::Down:
		nodes_.push_back(SnakeNode(sf::Vector2f(nodes_[nodes_.size() - 1].getPosition().x,
			nodes_[nodes_.size() - 1].getPosition().y - SnakeNode::Height), nodes_.begin()->getColor()));
		break;
	case Direction::Left:
		nodes_.push_back(SnakeNode(sf::Vector2f(nodes_[nodes_.size() - 1].getPosition().x + SnakeNode::Width,
			nodes_[nodes_.size() - 1].getPosition().y), nodes_.begin()->getColor()));
		break;
	case Direction::Right:
		nodes_.push_back(SnakeNode(sf::Vector2f(nodes_[nodes_.size() - 1].getPosition().x - SnakeNode::Width,
			nodes_[nodes_.size() - 1].getPosition().y), nodes_.begin()->getColor()));
		break;
	}
}

unsigned Snake::getSize() const
{
	return nodes_.size();
}

bool Snake::hitSelf() const
{
	return hitSelf_;
}

void Snake::checkSelfCollisions()
{
	SnakeNode& headNode = nodes_[0];

	for (decltype(nodes_.size()) i = 1; i < nodes_.size(); ++i)
	{
		if (headNode.getBounds().intersects(nodes_[i].getBounds()))
		{
			dieSound_.play();
			sf::sleep(sf::seconds(dieBuffer_.getDuration().asSeconds()));
			hitSelf_ = true;
		}
	}
}

void Snake::checkEdgeCollisions()
{
	SnakeNode& headNode = nodes_[0];

	if (headNode.getPosition().x <= 0)
		headNode.setPosition(Game::Width, headNode.getPosition().y);
	else if (headNode.getPosition().x >= Game::Width)
		headNode.setPosition(0, headNode.getPosition().y);
	else if (headNode.getPosition().y <= 0)
		headNode.setPosition(headNode.getPosition().x, Game::Height);
	else if (headNode.getPosition().y >= Game::Height)
		headNode.setPosition(headNode.getPosition().x, 0);
}

void Snake::move()
{
	for (decltype(nodes_.size()) i = nodes_.size() - 1; i > 0; --i)
	{
		nodes_[i].setPosition(nodes_.at(i - 1).getPosition());
	}

	switch (direction_)
	{
	case Direction::Up:
		nodes_[0].move(0, -SnakeNode::Height);
		break;
	case Direction::Down:
		nodes_[0].move(0, SnakeNode::Height);
		break;
	case Direction::Left:
		nodes_[0].move(-SnakeNode::Width, 0);
		break;
	case Direction::Right:
		nodes_[0].move(SnakeNode::Width, 0);
		break;
	}
}

void Snake::render(sf::RenderWindow& window)
{
	for (auto node : nodes_)
		node.render(window);
}