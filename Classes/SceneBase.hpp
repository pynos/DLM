//
//  SceneBase.hpp
//  DLM
//
//  Created by admin on 11/11/16.
//
//

#ifndef SceneBase_hpp
#define SceneBase_hpp

#include <stdio.h>
#include "SceneDataBase.hpp"

NS_CC_BEGIN

class SceneBase : public Ref
{
    
    SceneBase(SceneDataBase* data = nullptr);
    ~SceneBase();
    
    void show();
    void hide();
    void destroy();
    bool init(SceneDataBase* data = nullptr);
    
    CC_SYNTHESIZE(SceneDataBase*, sceneData, SceneData)
};

#endif /* SceneBase_hpp */

NS_CC_END
