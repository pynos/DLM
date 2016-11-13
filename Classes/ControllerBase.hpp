//
//  ControllerBase.hpp
//  DLM
//
//  Created by admin on 11/11/16.
//
//

#ifndef ControllerBase_hpp
#define ControllerBase_hpp

#include <stdio.h>

NS_CC_BEGIN

class ControllerBase : public Ref
{

public:
    ControllerBase();
    ~ControllerBase();

    static ControllerBase* create();

protected:

private:
    static Vector<ControllerBase*> controllers;
    static ControllerBase* getControllerByName(std::string name);
    
};

#endif /* ControllerBase_hpp */

NS_CC_END
