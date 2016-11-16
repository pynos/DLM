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
#include "Player.hpp"
#include "Enemy.hpp"
#include "World.hpp"

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
    
    CC_SYNTHESIZE(float, levelSpacing, LavelSpacing)
    CC_SYNTHESIZE(float, platformHeight, PlatformHeight)
    CC_SYNTHESIZE(int, numPlatforms, NumPlatforms)
    
    CC_SYNTHESIZE(Player*, player, Player)
    CC_SYNTHESIZE(World*, world, World)
    CC_SYNTHESIZE(std::vector<Enemy*>, enemies, Enemies)
    //CC_SYNTHESIZE(std::vector<Bullet*>, bullets, Bullets)
};

NS_CC_END

#endif /* GameController_hpp */


