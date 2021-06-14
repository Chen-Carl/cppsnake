#ifndef __BUTTON_H__
#define __BUTTON_H__

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>

class Button
{
// add friend class

private:
    sf::Texture img;
    sf::Sprite sprite;
    std::string path;

public:
    Button(double x = 0, double y = 0, double xscale = 1, double yscale = 1, int index = 0);

    bool isActive;
    bool PreBehRel;

    void setTexture(std::string s);
    void setPosition(int x, int y);
    void setScale(float x, float y);
    void deactive();
    bool onClick(sf::Event &e, sf::RenderWindow &window);
    void render(sf::RenderWindow &);
    void setFillColor(sf::Color color);
};

class Key : public Button
{
public:
    typedef std::shared_ptr<Key> key_ptr;

private:
    sf::Font font;
    sf::Text text;

public:
    Key(char ch = 'A', double x = 0, double y = 0, int index = 0);

    void render(sf::RenderWindow &window);
};

#endif