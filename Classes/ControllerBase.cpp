//
//  ControllerBase.cpp
//  DLM
//
//  Created by admin on 11/11/16.
//
//

#include "ControllerBase.hpp"

using namespace cocos2d;

ControllerBase::ControllerBase()
{
    
}

ControllerBase::~ControllerBase()
{
    
}

ControllerBase* ControllerBase::create()
{
    ControllerBase* cb = new ControllerBase();
    return cb;
}
