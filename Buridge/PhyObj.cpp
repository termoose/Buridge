//
//  PhyObj.cpp
//  Buridge
//
//  Created by Ole Andre Birkedal on 6/30/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <GLUT/GLUT.h>
#include "main.h"
#include "PhyObj.h"
#include "glUtil.h"

PhyObj::PhyObj( b2Vec2 Pos, float Angle, bool Dyn )
{
    // Set body type based on flag
    BodyDef.type = Dyn ? b2_dynamicBody : b2_staticBody;
    BodyDef.position = Pos;
    BodyDef.angle = Angle;

    // Create the body in our world object
    Body = MyWorld->CreateBody( &BodyDef );

    SetDensity( 1.0 );
    SetFriction( 0.1 );

    // FIXME: move the body shape definition out in child classes
    // PhyBox, PhyGround
    BodyFixture.shape = &BodyShape;
}

PhyObj::~PhyObj()
{
    MyWorld->DestroyBody( Body );
    Body = NULL;
}

void PhyObj::Create()
{
    Body->CreateFixture( &BodyFixture );
}

void PhyObj::Render()
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
    
    // Draw axis aligned bounding box for all Fixtures in Body
    // Useful for a debug type view
    for( b2Fixture* f = Body->GetFixtureList(); f; f = f->GetNext() )
    {
        const b2Vec2 AABB = f->GetAABB().GetExtents();
        
        glUtil::DrawQuad( AABB );
    }
}

void PhyObj::ApplyForce( const b2Vec2 &Force )
{
    // Always apply force to center of mass
    Body->ApplyForce( Force, b2Vec2(0.0, 0.0) );
}









