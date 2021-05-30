#ifndef SNAKE_NODE_H
#define SNAKE_NODE_H

#include <SFML/Graphics.hpp>

namespace cppsnake
{
class SnakeNode
{
public:
	SnakeNode(sf::Vector2f position = sf::Vector2f(0, 0), sf::Color color = sf::Color::Blue);

	void setPosition(sf::Vector2f position);
	void setPosition(float x, float y);

	void move(float xOffset, float yOffset);

	void render(sf::RenderWindow& window);

	sf::Vector2f getPosition() const;
	sf::FloatRect getBounds() const;
	sf::Color getColor() const;

	static const float Width;
	static const float Height;

private:
	sf::RectangleShape shape_;
	sf::Vector2f position_;
	sf::Color color_;
};
}

#endif