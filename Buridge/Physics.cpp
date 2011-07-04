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
    // Start counting the unique object Id at 0
    ObjectIdx = 0;

    DoSleep = true;
    Gravity = b2Vec2( 0.0, -10.0 );
    
    // Default values for accuracy
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

PhyObj *Physics::GetPhyObj( int32 Id ) const
{
    // FIXME: Make sure there is some santity check if the object is not found, we
    // don't want do take ->second of NULL.
    std::map< int32, PhyObj * >::const_iterator Result = Objects.find( Id );
    
    return Result->second;
}

bool Physics::RemPhyObj( int32 Id )
{
    delete GetPhyObj( Id );
    Objects.erase( Id );
    
    return false;
}

void Physics::AddPhyObj( PhyObj *Object )
{
    Objects[ ObjectIdx ] = Object;

    ObjectIdx++;
}
