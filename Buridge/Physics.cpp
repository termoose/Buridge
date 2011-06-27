//
//  Physics.cpp
//  Buridge
//
//  Created by Ole Andre Birkedal on 6/22/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include "Physics.h"

Physics::Physics()
{
    DoSleep = true;
    Gravity = b2Vec2( 0.0, -10.0 );
    
    World = new b2World( Gravity, DoSleep );
}

Physics::~Physics()
{
    delete World;
}

b2World *Physics::GetWorld()
{
    return World;
}