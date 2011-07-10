//
//  PhyWheel.cpp
//  Buridge
//
//  Created by Ole Andre Birkedal on 7/10/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include "PhyWheel.h"

PhyWheel::PhyWheel( b2Vec2 Pos, float Radius ) : PhyObj( Pos, 0.0, true )
{
    BodyShape.m_p = Pos;
    BodyShape.m_radius = Radius;
}

PhyWheel::~PhyWheel()
{
    
}