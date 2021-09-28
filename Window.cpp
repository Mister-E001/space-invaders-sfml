#include "Window.hpp"

Window::Window(const char* title, unsigned int width, unsigned int length)
:screen(), dimensions(width, length), name(title)
{
    screen.create(sf::VideoMode(dimensions.x, dimensions.y), name);
    screen.setFramerateLimit(FRAMERATE);
}

Window::Window(const char* title, const sf::Vector2u& screenDimensions)
:Window(title, screenDimensions.x, screenDimensions.y)
{

}

Window::Window(const Window& w)
:Window(w.name, w.dimensions)
{

}

Window& Window::operator =(const Window& w)
{
    Window(w.name, w.dimensions);
    return *this;
}

Window::~Window()
{
    if(screen.isOpen())
    {
        screen.close();
    }
}

void Window::setDimensions(unsigned int width, unsigned int length)
{
    dimensions.x = width;
    dimensions.y = length;
}

void Window::setDimensions(const sf::Vector2u& screenDimensions)
{
    dimensions = screenDimensions;
}

sf::Vector2u& Window::getDimensions()
{
    return dimensions;
}

std::ostream& operator <<(std::ostream& os, const Window& w)
{
    os<<"Name: "<<w.name<<std::endl;
    os<<"Dimensions: ("<<w.dimensions.x<<" x "<<w.dimensions.y<<")";

    return os;
}
