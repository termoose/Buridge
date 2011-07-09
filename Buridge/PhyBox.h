//
//  PhyBox.h
//  Buridge
//
//  Created by Ole Andre Birkedal on 7/8/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include "PhyObj.h"

class PhyBox : public PhyObj
{
public:
    PhyBox( b2Vec2 Pos, float Angle, b2Vec2 Extents );
    ~PhyBox();
    
    void Render();

private:
    b2Vec2 Extents;
    
};