#ifndef __GameScene_H__
#define __GameScene_H__

#include "cocos2d.h"
#include "GameController.hpp"

NS_CC_BEGIN

class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
    
    GameController* gameController;
};

#endif // __GameScene_H__

NS_CC_END
