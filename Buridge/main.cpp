//
//  main.cpp
//  Buridge
//
//  Created by Ole Andre Birkedal on 6/21/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <iostream>
#include "glUtil.h"
#include "Setup.h"

void DisplayFunction()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glutSolidTeapot( 1.0 );
    glFlush();
}

int main (int argc, char **argv)
{
    std::auto_ptr< glUtil > Window( new glUtil(&argc, argv, 640, 480) );

    Window->SetMouseFunc( Setup::MouseFunc );
    Window->SetKeyboardFunc( Setup::KeyboardFunc );
    Window->SetReshapeFunc( Setup::ReshapeFunc );
    Window->SetDisplayFunc( DisplayFunction );

    Window->MainLoop();
    
    return 0;
}