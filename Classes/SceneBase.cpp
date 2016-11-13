//
//  SceneBase.cpp
//  DLM
//
//  Created by admin on 11/11/16.
//
//

#include "SceneBase.hpp"

using namespace cocos2d;

SceneBase::SceneBase(SceneDataBase* data)
: sceneData(nullptr)
{
    setSceneData(data);
    if (data)
    {
        init(data);
    }
}

SceneBase::~SceneBase()
{
    if (sceneData)
    {
        delete sceneData;
    }
}

void SceneBase::show()
{
    
}

void SceneBase::hide()
{
    
}

bool SceneBase::init(SceneDataBase* data)
{
    if (data)
    {
        
    }
    return true;
}


