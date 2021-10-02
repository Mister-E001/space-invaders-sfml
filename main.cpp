#include "SpaceInvaders.hpp"

int main(int argc, char** argv)
{
    unsigned int width = 1200;
    unsigned int length = 600;

    if(argc == 3)
    {
        width = atoi(argv[1]);
        length = atoi(argv[2]);
    }

    SpaceInvaders si(width, length);
    si.play();

    return 0;
}
