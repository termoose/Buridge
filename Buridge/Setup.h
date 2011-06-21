//
//  Setup.h
//  Buridge
//
//  Created by Ole Andre Birkedal on 6/21/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <GLUT/glut.h>
#include <iostream>

class Setup
{
public:
    static void DisplayFunc();
    static void MouseFunc( int Button, int State, int x, int y );
    static void KeyboardFunc( unsigned char key, int x, int y );
    static void ReshapeFunc( int w, int h );
    
    void GLInit();
};