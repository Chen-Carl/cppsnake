#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>

#include "SnakeNode.h"
#include "Fruit.h"
#include "Barrier.h"

namespace cppsnake
{
enum class Direction
{
	Left, Right, Up, Down
};

class Snake
{
	friend void checkMutualCollisions(Snake &snake1, Snake &snake2)
	{
		SnakeNode& headNode1 = snake1.nodes_[0];
		SnakeNode& headNode2 = snake2.nodes_[0];

		for (decltype(snake1.nodes_.size()) i = 1; i < snake1.nodes_.size(); ++i)
		{
			if (headNode2.getBounds().intersects(snake1.nodes_[i].getBounds()))
			{
				snake2.dieSound_.play();
				sf::sleep(sf::seconds(snake2.dieBuffer_.getDuration().asSeconds()));
				snake2.hitSelf_ = true;
			}
		}
		
		for (decltype(snake2.nodes_.size()) i = 1; i < snake2.nodes_.size(); ++i)
		{
			if (headNode1.getBounds().intersects(snake2.nodes_[i].getBounds()))
			{
				snake1.dieSound_.play();
				sf::sleep(sf::seconds(snake1.dieBuffer_.getDuration().asSeconds()));
				snake1.hitSelf_ = true;
			}
		}
	}

public:
	Snake(int index = 0, sf::Color color = sf::Color::Green);

	void handleInput();
	void update(sf::Time delta);
	void render(sf::RenderWindow& window);

	void checkBarrierCollisions(Barrier& barrier);
	void checkFruitCollisions(std::vector<Fruit>& fruits);

	bool hitSelf() const;

	unsigned getSize() const;

private:
	void move();
	void grow();
	void shrink();
	void checkEdgeCollisions();
	void checkSelfCollisions();

	void initNodes(sf::Color color = sf::Color::Green);

	bool hitSelf_;
	int index_;

	sf::Vector2f position_;
	Direction direction_;

	sf::SoundBuffer pickupBuffer_;
	sf::Sound pickupSound_;

	sf::SoundBuffer dieBuffer_;
	sf::Sound dieSound_;

	std::vector<SnakeNode> nodes_;

	static const int InitialSize;
};

}

#endif