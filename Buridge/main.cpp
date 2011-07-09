//
//  main.cpp
//  Buridge
//
//  Created by Ole Andre Birkedal on 6/21/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <iostream>
#include <vector>

#include "main.h"
#include "glUtil.h"
#include "Setup.h"
#include "Physics.h"
#include "PhyBox.h"
#include "PhyGround.h"

#include <Box2D/Box2D.h>

b2Body *BoxBody;
float32 TimeStep = 1.0 / 60.0;
int32 VelIters = 6;
int32 PosIters = 2;

b2World *MyWorld;
Physics *Scene;

std::vector< PhyObj * > TestObjects;

void DisplayFunction( void )
{
    Scene->DoStep();

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );  

    // Renders all Objects in the Scene
    Scene->RenderAll();

    glutSwapBuffers();
}

void Timer( int )
{
    glutPostRedisplay();
    glutTimerFunc( 16, Timer, 0 );
}

int main ( int argc, char **argv )
{
    glUtil *Window = new glUtil( &argc, argv, 640, 480 );

    // Global Scene and World object
    Scene = new Physics();
    MyWorld = Scene->GetWorld();

    // Test code    
    PhyBox *Object;
    b2Vec2 Extents(0.05, 0.05);
    for( int i = 0; i < 60; ++i )
    {
        Object = new PhyBox( b2Vec2( sin( M_PI/180.0 * i*5 )*0.9, 1.0 + i*2 ), 0.0, Extents );
        Object->Create();
        Scene->AddPhyObj( Object );
    }

    PhyGround *Ground = new PhyGround( b2Vec2(0.0, 0.0), 0.0 );
    Ground->AddPoint( b2Vec2(-1.0, 1.0) );
    Ground->AddPoint( b2Vec2(-1.0,-1.0) );
    Ground->AddPoint( b2Vec2( 0.0, 0.0) );
    Ground->AddPoint( b2Vec2( 1.0,-1.0) );
    Ground->AddPoint( b2Vec2( 1.0, 1.0) );
    Ground->Create();
    Scene->AddPhyObj( Ground );

    Window->SetDisplayFunc( DisplayFunction );
    Window->SetMouseFunc( Setup::MouseFunc );
    Window->SetKeyboardFunc( Setup::KeyboardFunc );
    Window->SetReshapeFunc( Setup::ReshapeFunc );
    Window->SetTimerFunc( Timer, 16 );

    Window->MainLoop();
    
    delete Scene;
    delete Window;
    
    return 0;
}