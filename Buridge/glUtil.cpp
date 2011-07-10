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
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
    glutInitWindowSize ( ResX, ResY ); 
    WindowID = glutCreateWindow ( argv[0] );
    
    glClearColor ( 0.0, 0.0, 0.0, 0.0 );
    glShadeModel ( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
}

glUtil::~glUtil()
{
    
}

void glUtil::DrawLine( const b2Vec2 &Point1, const b2Vec2 &Point2 )
{
    glBegin( GL_LINES );
    glVertex2f( Point1.x, Point1.y );
    glVertex2f( Point2.x, Point2.y );
    glEnd();
}

void glUtil::DrawQuad( const b2Vec2 &Ext )
{
    glBegin( GL_QUADS );
    glVertex2f(-Ext.x,-Ext.y );
    glVertex2f( Ext.x,-Ext.y );
    glVertex2f( Ext.x, Ext.y );
    glVertex2f(-Ext.x, Ext.y );
    glEnd();
}