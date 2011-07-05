//
//  PhyObj.h
//  Buridge
//
//  Created by Ole Andre Birkedal on 6/30/11.
//  Copyright 2011 Extab. All rights reserved.
//

#ifndef PHYOBJ_H
#define PHYOBJ_H

#include <iostream>
#include <Box2D/Box2D.h>

class PhyObj
{
public:
    PhyObj( b2Vec2 Pos=b2Vec2(0.0, 0.0), float Angle=0.0, bool Dyn=true );
    ~PhyObj();
    
    inline b2Vec2 GetPosition() const { return Body->GetPosition(); }
    inline float GetAngle() const { return Body->GetAngle(); }
    inline bool IsActive() const { return Body->IsActive(); }
    inline bool IsAwake() const { return Body->IsAwake(); }
    
    inline void SetDensity( float Density ) { BodyFixture.density = Density; }
    inline void SetFriction( float Friction ) { BodyFixture.friction = Friction; }
    
protected:
    b2Body *Body;
    b2BodyDef BodyDef;
    b2PolygonShape BodyShape;
    b2FixtureDef BodyFixture;

    bool Dynamic;
    
private:
    // ...
};

#endif