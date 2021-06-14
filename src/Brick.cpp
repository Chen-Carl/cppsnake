#include <SFML/Graphics.hpp>
#include <iostream>

#include "Brick.h"

using namespace cppsnake;

Brick::Brick(float width, float height, sf::Vector2f position, sf::Color color)
	: position_(position), color_(color)
{
	/*texture_.loadFromFile("Photo/brick.png");
	sf::Texture::bind(&texture_);*/
	shape_.setPosition(position_);
	// shape_.setFillColor(color_);
	shape_.setSize(sf::Vector2f(width, height));
	shape_.setOutlineColor(sf::Color::White);
	shape_.setOutlineThickness(-1.f);
	sf::Texture *texture = new sf::Texture();
	texture->loadFromFile("/home/zoecarl/snake/images/brick.jpg");
	shape_.setTexture(texture);
}

void Brick::render(sf::RenderWindow &window)
{
	window.draw(shape_);
}

sf::FloatRect Brick::getBounds() const
{
	return shape_.getGlobalBounds();
}