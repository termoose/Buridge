//
//  Physics.cpp
//  Buridge
//
//  Created by Ole Andre Birkedal on 6/22/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include "Physics.h"
#include "PhyBox.h"
#include "PhyGround.h"

Physics::Physics()
{
    // Start counting the unique object Id at 0
    ObjectIdx = 0;

    DoSleep = true;
    Gravity = b2Vec2( 0.0, -10.0 );
    
    // Default values for accuracy in simulation
    TimeStep = 1.0 / 60.0;
    VelIters = 10;
    PosIters = 10;
    
    World = new b2World( Gravity, DoSleep );
}

Physics::~Physics()
{
    // Delete all physical objects in vector
    for( std::map< int32, PhyObj * >::iterator it = Objects.begin();
        it != Objects.end(); ++it )
    {
        delete it->second;
    }

    Objects.clear();

    delete World;
}

void Physics::DoStep()
{
    World->Step( TimeStep, VelIters, PosIters );
    World->ClearForces();
}

b2World *Physics::GetWorld() const
{
    return World;
}

void Physics::RenderAll()
{
    for( std::map< int32, PhyObj * >::iterator it = Objects.begin();
        it != Objects.end(); ++it )
    {
        // Calls the Render function that is deepest in the inheritence tree
        (*it).second->Render();
    }
}

PhyObj *Physics::GetPhyObj( const int32 &Id ) const
{
    std::map< int32, PhyObj * >::const_iterator Result = Objects.find( Id );

    // Element not found in map
    if( Result == Objects.end() )
        return NULL;

    return Result->second;
}

bool Physics::RemPhyObj( const int32 &Id )
{
    PhyObj *Obj = GetPhyObj( Id );
    
    // If element is not found in map, do nothing
    if( Obj == NULL )
        return false;
    
    delete Obj;
    Obj = NULL;

    Objects.erase( Id );
    
    return true;
}

void Physics::AddPhyObj( PhyObj *Object )
{
    // Insert into std::map
    Objects[ ObjectIdx ] = Object;

    ObjectIdx++;
}
