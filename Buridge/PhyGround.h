//
//  PhyGround.h
//  Buridge
//
//  Created by Ole Andre Birkedal on 7/8/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <vector>

#include "PhyObj.h"

class PhyGround : public PhyObj
{
public:
    PhyGround( b2Vec2 Pos, float Angle);
    ~PhyGround();

    void AddPoint( const b2Vec2 &Point );
    void Create();
    
    void Render();
    
private:
    std::vector< b2Vec2 > Vertices;
};