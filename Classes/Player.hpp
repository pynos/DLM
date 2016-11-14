//
//  Player.hpp
//  DLM
//
//  Created by admin on 11/13/16.
//
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Actor.hpp"

NS_CC_BEGIN

class Player : public Actor
{
public:
    Player();
    ~Player();
    
    bool init();
    
    static Player* create(int _lives, int _weaponType);
    
protected:
    
private:
    
    CC_SYNTHESIZE(int, lives, Lives);
    CC_SYNTHESIZE(int, weaponType, WeaponType);
    
};

#endif /* Player_hpp */

NS_CC_END
