//
//  DistanceJoint.cpp
//  Buridge
//
//  Created by Ole Andre Birkedal on 7/10/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include "DistanceJoint.h"
#include "main.h"
#include "glUtil.h"

DistanceJoint::DistanceJoint( PhyObj *Obj1, PhyObj *Obj2, const b2Vec2 &LocalAnchor1, const b2Vec2 &LocalAnchor2 )
{
    // Calculate world coordinates for joint initialization
    b2Vec2 WorldAnchor1 = Obj1->GetBody()->GetWorldPoint( LocalAnchor1 );
    b2Vec2 WorldAnchor2 = Obj2->GetBody()->GetWorldPoint( LocalAnchor2 );

    
    Def.Initialize( Obj1->GetBody(), Obj2->GetBody(), WorldAnchor1, WorldAnchor2 );

    Def.collideConnected = true;

    SetFreq( 1.0 );
    SetDampening( 0.4 );

    Joint = MyWorld->CreateJoint( &Def );
}

DistanceJoint::~DistanceJoint()
{
    MyWorld->DestroyJoint( Joint );
    Joint = NULL;
}

void DistanceJoint::Render()
{
    b2Vec2 Anchor1 = Joint->GetAnchorA();
    b2Vec2 Anchor2 = Joint->GetAnchorB();

    glLoadIdentity();
    glTranslatef( 0.0, 0.0, 0.0 );
    glColor3f( 0.0, 1.0, 0.0 );

    glLineWidth( 4.0 );    
    glUtil::DrawLine( Anchor1, Anchor2 );
    glLineWidth( 1.0 );
}














