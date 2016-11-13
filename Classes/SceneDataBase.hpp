//
//  SceneDataBase.hpp
//  DLM
//
//  Created by admin on 11/11/16.
//
//

#ifndef SceneDataBase_hpp
#define SceneDataBase_hpp

#include <stdio.h>

NS_CC_BEGIN

class SceneDataBase
{
public:
    SceneDataBase(std::string name);
    ~SceneDataBase();
    
    SceneDataBase* clone();
    static SceneDataBase* create(std::string data);
    
protected:
    
private:
    std::string _sceneName;
};

#endif /* SceneDataBase_hpp */

NS_CC_END
