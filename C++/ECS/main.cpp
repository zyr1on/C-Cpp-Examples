#include <iostream>
#include "ECS.h"

Entitiy player;

int main(int argc, char const *argv[])
{
    player.addComponent<Position>(25,33,245);
    Position* pos = player.getComponent<Position>();
    pos->update();
    delete pos;
    return 0;
}

