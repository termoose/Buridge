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
    for( std::vector< PhyObj * >::iterator it = Objects.begin();
        it != Objects.end(); ++it )
    {
        delete *it;
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

PhyObj *Physics::GetPhyObj( unsigned int Index ) const
{
    if ( Index < Objects.size() )
        return Objects[ Index ];

    return NULL;
}

void Physics::AddPhyObj( PhyObj *Object )
{
    // Set unique ID to number of objects + 1
    Object->SetId( (unsigned int)Objects.size() + 1 );
    
    // Push PhyObj to end of list
    Objects.push_back( Object );
}