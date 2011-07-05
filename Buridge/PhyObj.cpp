//
//  PhyObj.cpp
//  Buridge
//
//  Created by Ole Andre Birkedal on 6/30/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include "main.h"
#include "PhyObj.h"

PhyObj::PhyObj( b2Vec2 Pos, float Angle, bool Dyn )
{
    // Set body type based on flag
    BodyDef.type = Dyn ? b2_dynamicBody : b2_staticBody;
    BodyDef.position = Pos;
    BodyDef.angle = Angle;
    
    // Create the body in our world object
    Body = MyWorld->CreateBody( &BodyDef );

    // By default we set the collision geometry as a box
    // FIXME: move the body shape definition out in child classes
    BodyShape.SetAsBox( 0.1, 0.1 );
    BodyFixture.shape = &BodyShape;

    SetDensity( 1.0 );
    SetFriction( 0.1 );
    
    Body->CreateFixture( &BodyFixture );
}

PhyObj::~PhyObj()
{
    MyWorld->DestroyBody( Body );
    Body = NULL;
}