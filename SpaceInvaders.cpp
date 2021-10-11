#include "SpaceInvaders.hpp"

SpaceInvaders::SpaceInvaders(unsigned int windowWidth, unsigned int windowLength)
:window("Space Invaders", windowWidth, windowLength)
{

}

SpaceInvaders::SpaceInvaders(const sf::Vector2u& dimensions)
:window("Space Invaders", dimensions)
{

}

SpaceInvaders::SpaceInvaders(const SpaceInvaders& si)
:window(si.window)
{

}

SpaceInvaders& SpaceInvaders::operator =(const SpaceInvaders& si)
{
    window = si.window;

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
                    
                    break;
                }

                default:
                {
                    break;
                }
            }
        }

        window.clear();
        //Draw stuff here
        window.display();
    }
}

std::ostream& operator <<(std::ostream& os, const SpaceInvaders& si)
{
    os<<"Window Information"<<std::endl;
    os<<si.window;
    return os;
}
