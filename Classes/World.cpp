//
//  World.cpp
//  DLM
//
//  Created by admin on 11/14/16.
//
//D

#include "World.hpp"

using namespace cocos2d;

World::World()
: background(nullptr)
, moveTouchId(-1)
, aimTouchId(-1)
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
    if (moveTouchId > -1 && aimTouchId > -1)
        return true;
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    for (auto& touch : touches)
    {
        if (moveTouchId == -1 && touch->getLocationInView().x < visibleSize.width / 2)
        {
            moveTouchId = touch->getID();
            
            timeval time;
            gettimeofday(&time, NULL);
            unsigned long millisecs = (time.tv_sec * 1000) + (time.tv_usec / 1000);
            
            
        }
        else if (aimTouchId == -1)
        {
            aimTouchId = touch->getID();
        }
    }
    
    return true;
}

void World::onTouchesMoved(const std::vector<Touch*>& touches, Event* event)
{
    int moveThreshold = 50;
    
    for (auto& touch : touches)
    {
        Vec2 delta(touch->getLocationInView().x - touch->getStartLocationInView().x, touch->getLocationInView().y - touch->getStartLocationInView().y);
        
        if (touch->getID() == moveTouchId)
        {
            CCLOG("delta(%f,%f)", delta.x, delta.y);
            if (delta.x > moveThreshold || delta.x < -moveThreshold)
            {
                if (delta.x > 0)
                {
                    CCLOG("//facing right");
                }
                else
                {
                    CCLOG("//facing left");
                }
            }
            else if (delta.y > moveThreshold || delta.y < -moveThreshold)
            {
                if (delta.y < 0)
                {
                    CCLOG("//facing up");
                }
                else
                {
                    CCLOG("//facing down");
                }
            }
        }
        else if (touch->getID() == aimTouchId)
        {
            if (delta.y)
            {
                
            }
        }
        
    }
}

void World::onTouchesEnded(const std::vector<Touch*>& touches, Event* event)
{
    for (auto& touch : touches)
    {
        if (moveTouchId == touch->getID())
        {
            moveTouchId = -1;
            isWalking = false;
        }
        
        if (aimTouchId == touch->getID())
        {
            aimTouchId = -1;
        }
    }
}
