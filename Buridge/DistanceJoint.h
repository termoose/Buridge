//
//  DistanceJoint.h
//  Buridge
//
//  Created by Ole Andre Birkedal on 7/10/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <iostream>
#include <Box2D/Box2D.h>
#include "PhyObj.h"

class DistanceJoint
{
public:
    DistanceJoint( PhyObj *Obj1, PhyObj *Obj2, const b2Vec2 &LocalAnchor1, const b2Vec2 &LocalAnchor2 );
    ~DistanceJoint();

    void SetFreq( const float &Freq ) { Def.frequencyHz = Freq; }
    void SetDampening( const float &Dampening ) { Def.dampingRatio = Dampening; }
    
    void Render();

private:
    b2DistanceJointDef Def;
    b2Joint *Joint;


};
