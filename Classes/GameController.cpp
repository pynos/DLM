//
//  GameController.cpp
//  DLM
//
//  Created by admin on 11/11/16.
//
//

#include "GameController.hpp"

using namespace cocos2d;

GameController::GameController() :
player(nullptr)
{
    numPlatforms = 3;
}

GameController::~GameController()
{
    
}

GameController* GameController::create(Node* scene)
{
    GameController* gc = new GameController();
    gc->scene = scene;
    return gc;
}

GameController* GameController::createTestGame(Node* scene)
{
    GameController* gc = create(scene);
    gc->createEnvironment();
    gc->spawnPlayers(0);
    gc->spawnEnemy(2);
    
    return gc;
}

void GameController::createEnvironment()
{
    world = World::create();
    scene->addChild(world);
    
    auto spritecache = SpriteFrameCache::getInstance();
    spritecache->addSpriteFramesWithFile("game_art.plist");
    
    if (scene)
    {
        auto visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        
        Sprite* bg = Sprite::createWithSpriteFrameName("phone_bg.png");
        if (bg)
        {
            bg->setAnchorPoint( Vec2(0,0) );
            //bg->setScale(visibleSize.height / bg->getContentSize().height);
            bg->setPosition(Vec2(0,0));// Vec2(origin.x, origin.y) );
            scene->addChild(bg);
        }
        
        Sprite* s = Sprite::createWithSpriteFrameName("platform.png");
        platformHeight = s->getContentSize().height;
        levelSpacing = (visibleSize.height - (s->getContentSize().height * numPlatforms)) / numPlatforms;
        
        for (int i = 0; i < numPlatforms; i++)
        {
            if (i > 0)
                s = Sprite::createWithSpriteFrameName("platform.png");
            
            s->setAnchorPoint(Vec2(0,1));
            s->setPosition(origin.x, getLevelPositionY(i));
            float scale = visibleSize.width / s->getContentSize().width;
            s->setScaleX(scale);
            CCLOG("width: %d", int(scale * s->getContentSize().width));
            
            scene->addChild(s);
        }
    }
}

float GameController::getLevelPositionY(int level)
{
    Vec2 vec = Director::getInstance()->getVisibleOrigin();
    vec.y += ( (platformHeight + levelSpacing) * level + platformHeight);
    return vec.y;
}

void GameController::spawnPlayers(int level)
{
    if (scene)
    {
        auto visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        
        player = (Player*)Player::createWithSpriteFrameName("enemy_test/frame_0001.png");
        player->setAnchorPoint( Vec2(0.5, 0.5) );
        player->setScaleX(-1);
        player->setPosition(origin.x + player->getContentSize().width / 2, getLevelPositionY(level) + player->getContentSize().height / 2);
        
        scene->addChild(player);
    }
}

void GameController::spawnEnemy(int level)
{
    if (scene)
    {
        auto visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        
        Enemy* s = (Enemy*)Enemy::createWithSpriteFrameName("enemy_test/frame_0001.png");
        s->setAnchorPoint( Vec2(0.5, 0.5) );
        s->setScale(0.5);
        s->setPosition(origin.x + visibleSize.width - s->getContentSize().width * s->getScale() / 2, getLevelPositionY(1) + s->getContentSize().height * s->getScale() / 2);
        
        scene->addChild(s);
        getEnemies().push_back(s);
    }
}

void GameController::spawnBullet()
{
    
}

void GameController::spawnExplosion()
{
    
}

