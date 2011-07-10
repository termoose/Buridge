//
//  PhyBox.cpp
//  Buridge
//
//  Created by Ole Andre Birkedal on 7/8/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <GLUT/GLUT.h>
#include "glUtil.h"
#include "PhyBox.h"
#include "DistanceJoint.h"

PhyBox::PhyBox( b2Vec2 Pos, float Angle, b2Vec2 Extents ) : PhyObj( Pos, Angle, true )
{
    this->Extents = Extents;
    BodyShape.SetAsBox( Extents.x, Extents.y );
}

PhyBox::~PhyBox()
{
    
}

void PhyBox::Render()
{
    glLoadIdentity();
    b2Vec2 Pos = GetPosition();
    float Angle = GetAngle();
    glTranslatef( Pos.x, Pos.y, 0.0 );
    glRotatef( Angle, 0.0, 0.0, 1.0 );
    
    if( IsAwake() )
        glColor3f( 0.8, 0.4, 0.8 );
    else
        glColor3f( 0.0, 0.5, 1.0 );

    glUtil::DrawQuad( Extents );
}