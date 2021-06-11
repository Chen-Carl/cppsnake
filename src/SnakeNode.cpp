#include <SFML/Graphics.hpp>

#include "SnakeNode.h"

using namespace cppsnake;

const float SnakeNode::Width = 15.f;
const float SnakeNode::Height = 15.f;

SnakeNode::SnakeNode(sf::Vector2f position, sf::Color color)
: position_(position), color_(color)
{
	shape_.setPosition(position_);
	// shape_.setFillColor(color_);
	shape_.setSize(sf::Vector2f(SnakeNode::Width, SnakeNode::Height));
	// shape_.setOutlineColor(sf::Color::White);
	// shape_.setOutlineThickness(-0.5f);

	sf::Texture *texture = new sf::Texture();
	if (color_ == sf::Color::Blue)
	{
		texture->loadFromFile("./images/snakeNodeBlue.jpg");
	}
	else if (color_ == sf::Color::Green)
	{
		texture->loadFromFile("./images/snakeNodeGreen.jpg");
	}
	texture->setSmooth(true);
	shape_.setTexture(texture);
}

void SnakeNode::setPosition(sf::Vector2f position)
{
	position_ = position;
	shape_.setPosition(position_);
}

void SnakeNode::setPosition(float x, float y)
{
	position_.x = x;
	position_.y = y;
	shape_.setPosition(position_);
}

void SnakeNode::move(float xOffset, float yOffset)
{
	position_.x += xOffset;
	position_.y += yOffset;
	shape_.setPosition(position_);
}

sf::FloatRect SnakeNode::getBounds() const
{
	return shape_.getGlobalBounds();
}

sf::Vector2f SnakeNode::getPosition() const
{
	return position_;
}

sf::Color SnakeNode::getColor() const
{
	return color_;
}


void SnakeNode::render(sf::RenderWindow& window)
{
	window.draw(shape_);
}