#ifndef BRICK_H
#define BRICK_H

#include <SFML/Graphics.hpp>

namespace cppsnake
{
	class Brick
	{
	public:
		Brick(float width, float height, sf::Vector2f position = sf::Vector2f(0, 0), sf::Color color = sf::Color(128, 0, 128));

		void render(sf::RenderWindow& window);

		sf::FloatRect getBounds() const;

	private:
		sf::RectangleShape shape_;
		sf::Vector2f position_;
		sf::Color color_;
		// sf::Texture texture_;
	};
}
#endif // !BRICK_H
