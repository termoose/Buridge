//
//  PhyWheel.h
//  Buridge
//
//  Created by Ole Andre Birkedal on 7/10/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include "PhyObj.h"

class PhyWheel : public PhyObj
{
public:
    PhyWheel( b2Vec2 Pos, float Radius );
    ~PhyWheel();
    
private:
    b2CircleShape BodyShape;
    // ...
};