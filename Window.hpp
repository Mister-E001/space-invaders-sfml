#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>

class Window
{
public:
    sf::RenderWindow screen;

private:
    sf::Vector2u dimensions;
    const char* name;
    static constexpr unsigned int FRAMERATE = 60;

public:
    Window(const char* title, unsigned int width, unsigned int length);
    Window(const char* title, const sf::Vector2u& screenDimensions);
    Window(const Window& w);
    Window& operator =(const Window& w);
    ~Window();
    void setDimensions(unsigned int width, unsigned int length);
    void setDimensions(const sf::Vector2u& screenDimensions);
    sf::Vector2u& getDimensions();
    friend std::ostream& operator <<(std::ostream& os, const Window& w);
};

#endif /* WINDOW_HPP */
