//
//  main.h
//  Buridge
//
//  Created by Ole Andre Birkedal on 6/30/11.
//  Copyright 2011 Extab. All rights reserved.
//

#ifndef MAIN_H
#define MAIN_H

#include "Physics.h"

extern Physics *Scene;

// Keep pointer so we don't have to do Scene->GetWorld() all the time
extern b2World *MyWorld;

#endif