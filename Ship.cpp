#include "Ship.hpp"

Ship::Ship(unsigned int windowWidth, unsigned int windowLength): sf::RectangleShape(sf::Vector2f(windowWidth / 20.f, windowLength / 10.f))
{
    sf::Vector2f position;
    sf::Vector2f dimensions = getSize();

    position.x = (windowWidth / 2.f) - (dimensions.x / 2.f);
    position.y = (windowLength / 1.05f) - dimensions.y;

    setPosition(position);
}

Ship::Ship(const sf::Vector2u& screenDimensions)
:Ship(screenDimensions.x, screenDimensions.y)
{

}

Ship::Ship(const Ship& s): sf::RectangleShape(s.getSize())
{
    setPosition(s.getPosition());
}

Ship& Ship::operator =(const Ship& s)
{
    setSize(s.getSize());
    setPosition(s.getPosition());

    return *this;
}

Ship::~Ship()
{

}

//TODO: Review/Fix?
void Ship::move(int direction)
{
    sf::Vector2f currentPosition = getPosition();
    const sf::Vector2f dimensions = getSize();

    const unsigned int windowWidth = 20 * getSize().x;
    int distanceMoved = direction * (windowWidth / 100.f);

    if(0 <= currentPosition.x + distanceMoved && currentPosition.x + distanceMoved + dimensions.x <= windowWidth)
    {
        currentPosition.x += distanceMoved;
    }

    setPosition(currentPosition);
}

std::ostream& operator <<(std::ostream& os, const Ship& s)
{
    sf::Vector2f dimensions = s.getSize();
    sf::Vector2f position = s.getPosition();
    os<<"Dimensions: ("<<dimensions.x<<" x "<<dimensions.y<<")"<<std::endl;
    os<<"Position: ("<<position.x<<", "<<position.y<<")";

    return os;
}
