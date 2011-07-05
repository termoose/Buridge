//
//  StaticObj.h
//  Buridge
//
//  Created by Ole Andre Birkedal on 7/4/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include "PhyObj.h"

class StaticObj : public PhyObj
{
public:
    StaticObj( b2Vec2 Pos, float Angle );
    ~StaticObj();
    
private:
    
};