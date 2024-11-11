#include <iostream>
#include"ECS.h"

Entitiy player;
Entitiy enemy;
int main(int argc, char const *argv[])
{
    player.addComponent<Position>(25,33,45);
    std::cout << player.getComponent<Position>()->x << std::endl;

    player.addComponent<Rotation>(5,12,13);
    Rotation* playerRot = player.getComponent<Rotation>();
    std::cout << playerRot->x << std::endl;

    player.addComponent<Tag>("player");
    enemy.addComponent<Tag>("enemy");
    // std::unique_ptr controls memory flow
    
    //if(pressed W) but its slower
    player.getComponent<Position>()->y++;

    // if(pressed q) faster
    playerRot->x--;
    return 0;
}

