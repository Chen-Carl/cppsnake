#include <SFML/Graphics.hpp>

#include "Fruit.h"

using namespace cppsnake;

const float Fruit::Radius = 18.f;

Fruit::Fruit(sf::Vector2f position)
{
	sf::Texture *texture = new sf::Texture();

	shape_.setPosition(position);
	shape_.setRadius(Fruit::Radius);
	shape_.setFillColor(sf::Color::White);

	srand((unsigned)time(NULL));
	int N = 1 + rand() % 8;
	if (N == 1)
	{
		texture->loadFromFile("./images/apple.png");
		color_ = sf::Color::White;
	}
	else if (N == 2)
	{
		texture->loadFromFile("./images/avocado.png");
		color_ = sf::Color::Yellow;
	}
	else if (N == 3 || N == 4)
	{
		texture->loadFromFile("./images/grapes.png");
		color_ = sf::Color::Blue;
	}
	else if (N == 5 || N == 6)
	{
		texture->loadFromFile("./images/orange.png");
		color_ = sf::Color::Red;
	}
	else if (N == 7 || N == 8)
	{
		texture->loadFromFile("./images/watermelon.png");
		color_ = sf::Color::White;
	}
	shape_.setTexture(texture);
}

void Fruit::render(sf::RenderWindow &window)
{
	window.draw(shape_);
}

sf::FloatRect Fruit::getBounds() const
{
	return shape_.getGlobalBounds();
}

sf::Color Fruit::getFruitColor() const
{
	return color_;
}
