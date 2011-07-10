//
//  Setup.cpp
//  Buridge
//
//  Created by Ole Andre Birkedal on 6/21/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include "Setup.h"
#include "main.h"
#include "PhyObj.h"

void Setup::ReshapeFunc( int w, int h )
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    std::cout << "Width: " << w << " Height: " << h << std::endl;
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        gluOrtho2D( -1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w, 1.5*(GLfloat)h/(GLfloat)w );
    else
        gluOrtho2D( -1.5*(GLfloat)w/(GLfloat)h, 1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5 );
}

void Setup::MouseFunc( int Button, int State, int x, int y )
{
    switch( Button )
    {
        case GLUT_LEFT_BUTTON:
        {
            //PhyObj *Object = new PhyObj( b2Vec2( 0, 1.0 ), 0.0 );
            //PhyObj *Object = new PhyObj( b2Vec2( 640.0/x - 1, 480.0/y - 1 ), 0.0 );
            //Scene->AddPhyObj( Object );
            //Scene->RemPhyObj( 9 );
            Scene->GetPhyObj( 1 )->ApplyForce( b2Vec2(0.0, 0.5) );
            std::cout << "Left button pressed! << " << 640.0/x << " " << 480.0/y << std::endl;
            glutSwapBuffers();
            break;
        }
            
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
