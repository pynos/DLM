//
//  World.cpp
//  DLM
//
//  Created by admin on 11/14/16.
//
//

#include "World.hpp"

using namespace cocos2d;

World::World() : background(nullptr)
{
    
}


World::~World()
{
    
}

bool World::init()
{
    return Sprite::init();
}

World* World::create()
{
    World* s = new World();
    if (s->init())
    {
        s->autorelease();
        s->platforms.insert(<#value_type &&__v#>)
    }
    
}
