#include <iostream>
#include "Button.h"

Button::Button(double x, double y, double xscale, double yscale) : isActive(true), PreBehRel(false)
{
    setTexture("./images/default.jpg");
    setPosition(x, y);
    setScale(xscale, yscale);
}

void Button::setTexture(std::string file)
{
    img.loadFromFile(file);
    sprite.setTexture(img);
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
        setTexture("./images/press.jpg");
        return false;
    }
    bool flag = false;
    auto position = sf::Mouse::getPosition(window);
    sf::FloatRect box = sprite.getGlobalBounds();       // get the reponse area
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
            setTexture("./images/press.jpg");
            PreBehRel = true;
        }
        else
            setTexture("./images/hover.jpg");
    }
    else
        setTexture("./images/default.jpg");
    if (flag)
    {
        std::cout << "true" << std::endl;
    }
    return flag;
}

void Button::render(sf::RenderWindow &window)
{
    // isActive = true;
    window.draw(sprite);
}

Key::Key(char ch, double x, double y) : Button(x, y, 0.6, 0.6)
{
    if (!font.loadFromFile("./Fonts/game_over.ttf"))
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