//
//  Player.cpp
//  DLM
//
//  Created by admin on 11/13/16.
//
//

#include "Player.hpp"

using namespace cocos2d;

Player::Player()
{
    
}

Player::~Player()
{
    
}

bool Player::init()
{
    return Actor::init();
}

Player* Player::create(int _lives, int _weaponType)
{
    Player* p = new Player();
    if (p->init())
    {
        p->autorelease();
        p->setLives(_lives);
        p->setWeaponType(_weaponType);
        return p;
    }
    
    CC_SAFE_DELETE(p);
    return nullptr;
}
