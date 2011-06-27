//
//  Physics.h
//  Buridge
//
//  Created by Ole Andre Birkedal on 6/22/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <Box2D/Box2D.h>

class Physics
{
public:
    Physics();
    ~Physics();

    b2World *GetWorld();
private:
    b2World *World;
    b2Vec2 Gravity;
    
    bool DoSleep;
};