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
#include "DistanceJoint.h"

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

    // The definitions of BodyShape are all in derived classes
    BodyFixture.shape = &BodyShape;
    
    Children.clear();
    
    // By default each object has no parent, meaning it's
    // at the top level aka. having the scene as its parent
    Parent = NULL;
}

PhyObj::~PhyObj()
{
    // Destroy all joints attached to body
    for( std::vector< DistanceJoint * >::iterator it = Joints.begin();
        it != Joints.end(); ++it )
    {
        delete *it;
    }

    Joints.clear();

    MyWorld->DestroyBody( Body );
    Body = NULL;
}

void PhyObj::Create()
{
    Body->CreateFixture( &BodyFixture );
}

void PhyObj::AddChild( PhyObj *Obj )
{
    // FIXME: also do Scene->AddPhyObj here? to get it in
    // Objects std::map. Maybe!

    Obj->SetParent( this );
    Children.push_back( Obj );
    Scene->AddPhyObj( Obj );
}

void PhyObj::CreateJoint( PhyObj *Obj, const b2Vec2 &Anchor1, const b2Vec2 &Anchor2 )
{
    // Create distance joint from this in point Anchor1 to Obj in point Anchor2
    DistanceJoint *Joint = new DistanceJoint( this, Obj, Anchor1, Anchor2 );
    
    // Joint is only available in the list of the object where it was created (for now)
    Joints.push_back( Joint );
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

    // By default draw axis aligned bounding box for all Fixtures
    // Useful for a debug type view
    for( b2Fixture* f = Body->GetFixtureList(); f; f = f->GetNext() )
    {
        const b2Vec2 AABB = f->GetAABB().GetExtents();
        
        glUtil::DrawQuad( AABB );
    }
}

void PhyObj::RenderJoints()
{
    for( std::vector< DistanceJoint * >::iterator it = Joints.begin();
        it != Joints.end(); ++it )
    {
        (*it)->Render();
    }
}

void PhyObj::ApplyForce( const b2Vec2 &Force )
{
    // Always apply force to center of mass
    Body->ApplyForce( Force, b2Vec2(0.0, 0.0) );
}









