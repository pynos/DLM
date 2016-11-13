//
//  GameController.hpp
//  DLM
//
//  Created by admin on 11/11/16.
//
//

#ifndef GameController_hpp
#define GameController_hpp

#include <stdio.h>

NS_CC_BEGIN

class GameController : public Ref

{
public:
    GameController();
    ~GameController();
    
    static GameController* create(Node* scene);
    
    static GameController* createTestGame(Node* scene);
    
    
protected:
    
    
private:
    Node* scene;
    void createEnvironment();
    void spawnPlayers(int level = 0);
    void spawnEnemy(int level = 0);
    void spawnBullet();
    void spawnExplosion();
    
    float getLevelPositionY(int level);
    
    CC_SYNTHESIZE(float, levelSpacing, LavelSpacing);
    CC_SYNTHESIZE(float, platformHeight, PlatformHeight);
    CC_SYNTHESIZE(int, numPlatforms, NumPlatforms);
};

NS_CC_END

#endif /* GameController_hpp */


