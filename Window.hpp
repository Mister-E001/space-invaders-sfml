#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>

class Window: public sf::RenderWindow
{
private:
    const char* name = "Space Invaders"; //As far as I can tell, there's no method in sf::RenderWindow to get the window name; I'll fix this later
    static constexpr unsigned int FRAMERATE = 60;

public:
    Window(const char* title, unsigned int width, unsigned int length);
    Window(const char* title, const sf::Vector2u& screenDimensions);
    Window(const Window& w);
    Window& operator =(const Window& w);
    ~Window();
    friend std::ostream& operator <<(std::ostream& os, const Window& w);
};

#endif /* WINDOW_HPP */
