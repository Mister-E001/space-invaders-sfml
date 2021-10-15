#include "SpaceInvaders.hpp"

SpaceInvaders::SpaceInvaders(unsigned int windowWidth, unsigned int windowLength)
:window("Space Invaders", windowWidth, windowLength), player(windowWidth, windowLength)
{

}

SpaceInvaders::SpaceInvaders(const sf::Vector2u& dimensions)
:window("Space Invaders", dimensions), player(dimensions)
{

}

SpaceInvaders::SpaceInvaders(const SpaceInvaders& si)
:window(si.window), player(si.player)
{

}

SpaceInvaders& SpaceInvaders::operator =(const SpaceInvaders& si)
{
    window = si.window;
    player = si.player;

    return *this;
}

SpaceInvaders::~SpaceInvaders()
{

}

void SpaceInvaders::play()
{
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                {
                    window.close();
                    break;
                }

                case sf::Event::Resized:
                {
                    //TODO: Handle resizing
                    break;
                }

                default:
                {
                    break;
                }
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            player.move(-1);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            player.move(1);
        }

        window.clear();
        //Draw stuff here
        window.draw(player);
        window.display();
    }
}

std::ostream& operator <<(std::ostream& os, const SpaceInvaders& si)
{
    os<<"Window Information"<<std::endl;
    os<<si.window;
    return os;
}
