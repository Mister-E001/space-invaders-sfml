#ifndef SHIP_HPP
#define SHIP_HPP

//TODO: Handle blaster from ship

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

class Ship: public sf::RectangleShape
{
public:
    Ship(unsigned int windowWidth, unsigned int windowLength);
    Ship(const sf::Vector2u& screenDimensions);
    Ship(const Ship& s);
    Ship& operator =(const Ship& s);
    ~Ship();
    void move(int direction); //-1 is left, 1 is right
    friend std::ostream& operator <<(std::ostream& os, const Ship& s);
};

#endif /* SHIP_HPP */
