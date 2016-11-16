//
//  World.cpp
//  DLM
//
//  Created by admin on 11/14/16.
//
//D

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
        s->addTouchListeners();
        return s;
    }
    
    CC_SAFE_DELETE(s);
    return nullptr;
    
}

void World::addTouchListeners()
{
    auto touchListener = EventListenerTouchAllAtOnce::create();
    touchListener->onTouchesBegan = CC_CALLBACK_2(World::onTouchesBegan, this);
    touchListener->onTouchesMoved = CC_CALLBACK_2(World::onTouchesMoved, this);
    touchListener->onTouchesEnded = CC_CALLBACK_2(World::onTouchesEnded, this);
    auto dispatcher = this->getEventDispatcher();
    dispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}

void World::removeTouchListeners()
{
    //TODO tony
}

bool World::onTouchesBegan(const std::vector<Touch*>& touches, Event* event)
{
    CCLOG("touchesBegan");
    return true;
}

void World::onTouchesMoved(const std::vector<Touch*>& touches, Event* event)
{
    CCLOG("touchesMoved");
}

void World::onTouchesEnded(const std::vector<Touch*>& touches, Event* event)
{
    CCLOG("touchesEnded");
}
