//
//  Setup.cpp
//  Buridge
//
//  Created by Ole Andre Birkedal on 6/21/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include "Setup.h"

void Setup::ReshapeFunc(int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w,
                 1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
    else
        glOrtho (-1.5*(GLfloat)w/(GLfloat)h,
                 1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Setup::MouseFunc( int Button, int State, int x, int y )
{
    switch( Button )
    {
        case GLUT_LEFT_BUTTON:
            std::cout << "Left button pressed!" << std::endl;
            break;
            
        default:
            break;
    }
}

void Setup::KeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key ) {
        case 27:
            exit( 0 );
            break;
            
        default:
            break;
    }
}
