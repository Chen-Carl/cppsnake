#include <iostream>
#include "Button.h"

Button::Button(double x, double y, double xscale, double yscale, int index) : isActive(true), PreBehRel(false)
{
    path = "/home/zoecarl/snake/images/Level" + std::to_string(index + 1) + ".png";
    setTexture(path);
    setPosition(x, y);
    setScale(xscale, yscale);
}

void Button::setTexture(std::string file)
{
    img.loadFromFile(file);
    sprite.setTexture(img);
}

void Button::setFillColor(sf::Color color)
{
    sprite.setColor(color);
}

void Button::setPosition(int x, int y)
{
    sprite.setPosition(x, y);
}

void Button::setScale(float x, float y)
{
    sprite.setScale(x, y);
}

void Button::deactive()
{
    isActive = false;
}

bool Button::onClick(sf::Event &e, sf::RenderWindow &window)
{
    if (!isActive)
    {
        // press
        setTexture(path);
        setFillColor(sf::Color::White);
        return false;
    }
    bool flag = false;
    auto position = sf::Mouse::getPosition(window);
    sf::FloatRect box = sprite.getGlobalBounds();       // get the response area
    if (position.x >= box.left && position.x <= (box.left + box.width) && position.y >= box.top && position.y <= (box.top + box.height))
    {
        if (e.type == sf::Event::MouseButtonReleased && PreBehRel)
        {
            PreBehRel = false;
            flag = true;
        }
        else
            flag = false;

        if (e.type == sf::Event::MouseButtonPressed)
        {
            // press
            setTexture(path);
            PreBehRel = true;
            setFillColor(sf::Color::White);
        }
        else
        {
            // hover
            setTexture(path);
            setFillColor(sf::Color::Blue);
        }
    }
    else
    {
        // default
        setTexture(path);
        setFillColor(sf::Color::White);
    }
    return flag;
}

void Button::render(sf::RenderWindow &window)
{
    // isActive = true;
    window.draw(sprite);
}

Key::Key(char ch, double x, double y, int index) : Button(x, y, 0.6, 0.6, index)
{
    if (!font.loadFromFile("/home/zoecarl/snake/Fonts/game_over.ttf"))
        std::cerr << "error: cannot load font file" << std::endl;
    text.setFont(font);
    text.setString(std::string(1, ch));
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(sf::Vector2f(x + 25, y + 10));
}

void Key::render(sf::RenderWindow &window)
{
    Button::render(window);
    window.draw(text);
}