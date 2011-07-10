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
#include <vector>
#include <Box2D/Box2D.h>

// Forward declare. Do we have to do it this way?
class DistanceJoint;

class PhyObj
{
public:
    PhyObj( b2Vec2 Pos=b2Vec2(0.0, 0.0), float Angle=0.0, bool Dyn=true );
    ~PhyObj();
    
    void Create();
    
    inline b2Vec2 GetPosition() const { return Body->GetPosition(); }
    inline float GetAngle() const { return Body->GetAngle(); }
    
    inline b2Body *GetBody() { return Body; }
    
    inline bool IsActive() const { return Body->IsActive(); }
    inline bool IsAwake() const { return Body->IsAwake(); }

    inline void SetDensity( const float &Density ) { BodyFixture.density = Density; }
    inline void SetFriction( const float &Friction ) { BodyFixture.friction = Friction; }

    virtual void Render();
    
    void RenderJoints(); // Calling the Render() function for all joints in object

    void ApplyForce( const b2Vec2 &Force );
    void AddChild( PhyObj *Obj );
    inline void SetParent( PhyObj *Obj ) { Parent = Obj; }
    
    // Joints the two objects by the specified anchor points, given in local
    // coordinates of the respective objective. If not specified, create joint
    // from center of objects.
    void CreateJoint( PhyObj *Obj, const b2Vec2 &Anchor1=b2Vec2(0.0, 0.0), const b2Vec2 &Anchor2=b2Vec2(0.0, 0.0) );
    
    
protected:
    b2Body *Body;
    b2BodyDef BodyDef;
    b2PolygonShape BodyShape;
    b2FixtureDef BodyFixture;

    std::vector< DistanceJoint * > Joints;
    PhyObj *Parent;
    std::vector< PhyObj * > Children;

    
private:

    // ...
};

#endif