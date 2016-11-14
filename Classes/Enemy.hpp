//
//  Enemy.hpp
//  DLM
//
//  Created by admin on 11/13/16.
//
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>
#include "Actor.hpp"

NS_CC_BEGIN

class Enemy : public Actor
{
public:
    Enemy();
    ~Enemy();
    
    bool init();
    
    static Enemy* create(float _speed, int _health, int _damage);
    
    int hit(int _damage);
    
protected:
    
private:
    
    void kill();
    
    CC_SYNTHESIZE(int, health, Health);
    CC_SYNTHESIZE(int, damage, Damage);
    CC_SYNTHESIZE(float, speed, Speed);
};

#endif /* Enemy_hpp */

NS_CC_END
