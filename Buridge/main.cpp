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
#include "Physics.h"

#include <Box2D/Box2D.h>

b2World *World;
b2Body *BoxBody;
float32 TimeStep = 1.0 / 60.0;
int32 VelIters = 6;
int32 PosIters = 2;

void DisplayFunction(void)
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    World->Step( TimeStep, VelIters, PosIters );
    //World->ClearForces();
    b2Vec2 Position = BoxBody->GetPosition();
    float32 angle = BoxBody->GetAngle();
    std::cout << "pos: " << Position.y << " " << Position.y << std::endl;

    //std::cout << "Angle: " << angle << std::endl;
    //glMatrixMode(GL_MODELVIEW);
    
    glLoadIdentity();
    glTranslatef( Position.x, Position.y - 2, 20.0 );
    glRotatef( angle * 180 / M_PI, 0.0, 0.0, 1.0 );
    glutSolidCube( 0.1 );
    
    glutSwapBuffers();
}

void Timer(int)
{
    glutPostRedisplay();
    glutTimerFunc( 16, Timer, 0 );
}

int main (int argc, char **argv)
{
    glUtil *Window = new glUtil(&argc, argv, 640, 480);
    
    Physics *Scene = new Physics();
    World = Scene->GetWorld();
    b2BodyDef GroundDef;
    b2PolygonShape GroundBox;

    GroundDef.position.Set( 0.0, -10.0 );
    b2FixtureDef GroundFixture;
    b2Body *GroundBody = Scene->GetWorld()->CreateBody( &GroundDef );
    GroundBox.SetAsBox( 50.0, 10.0 );
    GroundFixture.shape = &GroundBox;
    GroundBody->CreateFixture( &GroundFixture );
    
    b2BodyDef BoxDef;
    BoxDef.type = b2_dynamicBody;
    BoxDef.position.Set( 0.0, 3.0 );
    BoxDef.angle = M_PI / 6;
    BoxBody = World->CreateBody( &BoxDef );
    b2PolygonShape DynBox;
    DynBox.SetAsBox( 1.0, 1.0 );
    b2FixtureDef BoxFixture;
    BoxFixture.shape = &DynBox;
    BoxFixture.density = 0.001;
    BoxFixture.friction = 0.3;
    BoxBody->CreateFixture( &BoxFixture );
    World->ClearForces();
    
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