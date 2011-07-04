//
//  Physics.h
//  Buridge
//
//  Created by Ole Andre Birkedal on 6/22/11.
//  Copyright 2011 Extab. All rights reserved.
//

#ifndef PHYSICS_H
#define PHYSICS_H

#include <vector>

#include <Box2D/Box2D.h>
#include "PhyObj.h"

class Physics
{
public:
    Physics();
    ~Physics();

    b2World *GetWorld() const;
    
    void AddPhyObj( PhyObj *Object );
    PhyObj *GetPhyObj( unsigned int Index ) const;
    unsigned int GetNrOfPhyObjects() { return (unsigned int)Objects.size(); }

    void DoStep();

private:
    b2World *World;
    b2Vec2 Gravity;

    // List of all simulated objects in the world
    std::vector< PhyObj * > Objects;

    bool DoSleep;
    float32 TimeStep;
    int32 VelIters;
    int32 PosIters;
};

#endif