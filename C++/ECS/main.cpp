#include <iostream>
#include "ECS.h"

int main(int argc, char const *argv[])
{
    Entitiy player;
    player.addComponent<Position>(0,2,25);
    std::cout<<player.getComponent<Position>()->y<<"\n";

    return 0;
}

