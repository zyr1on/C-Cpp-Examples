#include <iostream>
#include "ECS.h"

Entitiy player;
Position* playerPos;
Tag* playerTag;
void began() 
{
    player.addComponent<Position>(25,33,245);
    player.addComponent<Rotation>(0,0,0);
    player.addComponent<Tag>("Player");    
    
}
void start() 
{
    playerPos = player.getComponent<Position>();
    playerTag = player.getComponent<Tag>();
}
void run() 
{
    playerPos->update();
    playerTag->update();
    
    delete playerPos;
    delete playerTag;
}
int main(int argc, char const *argv[])
{
    began();
    start();
    run();    
    return 0;
}

