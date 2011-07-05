//
//  Physics.h
//  Buridge
//
//  Created by Ole Andre Birkedal on 6/22/11.
//  Copyright 2011 Extab. All rights reserved.
//

#ifndef PHYSICS_H
#define PHYSICS_H

#include <map>

#include <Box2D/Box2D.h>
#include "PhyObj.h"

class Physics
{
public:
    Physics();
    ~Physics();

    b2World *GetWorld() const;
    
    void AddPhyObj( PhyObj *Object );
    bool RemPhyObj( int32 Id );
    PhyObj *GetPhyObj( int32 Id ) const;
    unsigned int GetNrOfPhyObjects() { return (unsigned int)Objects.size(); }
    
    // Iterator getters for getting the full map of objects
    std::map< int32, PhyObj * >::iterator begin();
    std::map< int32, PhyObj * >::iterator end();

    void DoStep();

private:
    b2World *World;
    b2Vec2 Gravity;

    // Map of all simulated objects in the world, each with unique Id
    std::map< int32, PhyObj * > Objects;

    bool DoSleep;
    float32 TimeStep;
    int32 VelIters;
    int32 PosIters;
    
    int32 ObjectIdx;
};

#endif