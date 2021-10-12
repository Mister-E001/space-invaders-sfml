#include "Window.hpp"

Window::Window(const char* title, unsigned int width, unsigned int length) : sf::RenderWindow(sf::VideoMode(width, length), title)
{
    setFramerateLimit(FRAMERATE);
}

Window::Window(const char* title, const sf::Vector2u& screenDimensions)
:Window(title, screenDimensions.x, screenDimensions.y)
{

}

Window::Window(const Window& w)
:Window(w.name, w.getSize())
{

}

Window& Window::operator =(const Window& w)
{
    Window(w.name, w.getSize());
    return *this;
}

Window::~Window()
{
    if(isOpen())
    {
        close();
    }
}

std::ostream& operator <<(std::ostream& os, const Window& w)
{
    os<<"Name: "<<w.name<<std::endl;
    const sf::Vector2u& dimensions = w.getSize();
    os<<"Dimensions: ("<<dimensions.x<<" x "<<dimensions.y<<")";

    return os;
}
