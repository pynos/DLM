//
//  World.hpp
//  DLM
//
//  Created by admin on 11/14/16.
//
//

#ifndef World_hpp
#define World_hpp

#include <stdio.h>
#include "Actor.hpp"

NS_CC_BEGIN

class World : public Sprite
{
    
public:
    World();
    ~World();
    
    bool init();
    
    static World* create();
    
protected:
    
private:
    CC_SYNTHESIZE(Sprite*, background, Background);
    CC_SYNTHESIZE(std::set<Sprite*>, platforms, Platforms);
};

#endif /* World_hpp */

NS_CC_END
