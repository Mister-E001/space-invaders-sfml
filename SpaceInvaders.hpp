#ifndef SPACEINVADERS_HPP
#define SPACEINVADERS_HPP

#include <SFML/System/Vector2.hpp>
#include <iostream>
#include "Window.hpp"

class SpaceInvaders
{
private:
    Window window;

public:
    SpaceInvaders(unsigned int windowWidth, unsigned int windowLength);
    SpaceInvaders(const sf::Vector2u& dimensions);
    SpaceInvaders(const SpaceInvaders& si);
    SpaceInvaders& operator =(const SpaceInvaders& si);
    ~SpaceInvaders();
    void play();
    friend std::ostream& operator <<(std::ostream& os, const SpaceInvaders& si);
};

#endif /* SPACEINVADERS_HPP */
