//
//  glUtil.cpp
//  gluttest
//
//  Created by Ole Andre Birkedal on 3/27/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <iostream>
#include "glUtil.h"


glUtil::glUtil(int *argc, char **argv, short ResX, short ResY)
{
    glutInit( argc, argv );
    glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize ( ResX, ResY ); 
    glutCreateWindow ( argv[0] );
    
    glClearColor ( 0.0, 0.0, 0.0, 0.0 );
    glShadeModel ( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );

}

glUtil::~glUtil()
{
    
}
