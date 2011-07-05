//
//  StaticObj.cpp
//  Buridge
//
//  Created by Ole Andre Birkedal on 7/4/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include "StaticObj.h"

StaticObj::StaticObj( b2Vec2 Pos, float Angle) : PhyObj( Pos, Angle, false )
{
    // We want more than 8 vertices to represent our ground, more like 32.
    // Modify Box2D or find another way?

    //BodyShape.Set(const b2Vec2 *vertices, int32 vertexCount);

    BodyFixture.shape = &BodyShape;
    
}