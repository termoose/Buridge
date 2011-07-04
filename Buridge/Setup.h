//
//  Setup.h
//  Buridge
//
//  Created by Ole Andre Birkedal on 6/21/11.
//  Copyright 2011 Extab. All rights reserved.
//

#ifndef SETUP_H
#define SETUP_H

#include <GLUT/GLUT.h>
#include <Box2D/Box2D.h>
#include <iostream>

class Setup
{
public:
    static void StaticDisplayFunc();
    static void MouseFunc( int Button, int State, int x, int y );
    static void KeyboardFunc( unsigned char key, int x, int y );
    static void ReshapeFunc( int w, int h );
    
    void GLInit();
    
private:

};

#endif