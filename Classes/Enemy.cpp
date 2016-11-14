//
//  Enemy.cpp
//  DLM
//
//  Created by admin on 11/13/16.
//
//

#include "Enemy.hpp"

using namespace cocos2d;

Enemy::Enemy()
{
    
}

Enemy::~Enemy()
{
    
}

bool Enemy::init()
{
    return Actor::init();
}

int Enemy::hit(int _damage)
{
    setHealth(health - _damage);
    if (health > 0)
    {
        kill();
    }
    
    return health;
}

Enemy* Enemy::create(float _speed, int _health, int _damage)
{
    Enemy* s = new Enemy();
    if (s->init())
    {
        s->autorelease();
        s->setSpeed(_speed);
        s->setHealth(_health);
        s->setDamage(_damage);
        return s;
    }
    
    CC_SAFE_DELETE(s);
    return nullptr;
}

void Enemy::kill() {}
