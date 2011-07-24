//
//  PhyGround.cpp
//  Buridge
//
//  Created by Ole Andre Birkedal on 7/8/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <GLUT/GLUT.h>
#include "PhyGround.h"

PhyGround::PhyGround() : PhyObj( b2Vec2(0.0, 0.0), 0.0, false )
{
    Vertices.clear();
}

PhyGround::~PhyGround()
{
    Vertices.clear();
}

void PhyGround::Create()
{
    // Go through all vertices in list and add them to edge list in the
    // fixture of the body.
    for( auto it = Vertices.begin(); it != Vertices.end() - 1; ++it )
    {
        BodyShape.SetAsEdge( *it, *(it + 1) );
        Body->CreateFixture( &BodyFixture );
    }
}

void PhyGround::Render()
{
    glLoadIdentity();
    b2Vec2 Pos = GetPosition();
    float Angle = GetAngle();
    glTranslatef( Pos.x, Pos.y, 0.0 );
    glRotatef( Angle, 0.0, 0.0, 1.0 );
    glLineWidth( 5.0 );
    glColor3f( 1.0, 1.0, 1.0 );

    glBegin( GL_LINE_STRIP );
    for( auto it = Vertices.begin(); it != Vertices.end(); ++it )
    {
        glVertex2f( (*it).x, (*it).y );
    }
    glEnd();

    glLineWidth( 1.0 );
}

void PhyGround::AddPoint( const b2Vec2 &Point )
{
    Vertices.push_back( Point );
}