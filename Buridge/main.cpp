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
#include "PhyObj.h"

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

    //for( unsigned int i = 0; i < Scene->GetNrOfPhyObjects(); ++i )
    for( std::map< int32, PhyObj * >::iterator it = Scene->begin();
        it != Scene->end(); ++it )
    {
        PhyObj *ThisObj = it->second;
        glLoadIdentity();
        b2Vec2 Pos = ThisObj->GetPosition();
        float Angle = ThisObj->GetAngle();
        glTranslatef( Pos.x, Pos.y, 0.0 );
        glRotatef( Angle, 0.0, 0.0, 1.0 );

        if( ThisObj->IsAwake() )
            glColor3f( 1.0-Pos.x, 0.4+Pos.x, 0.3+Pos.y );
        else
            glColor3f( 0.0, 0.0, 1.0 );

        glBegin( GL_QUADS );
        glVertex2f(-0.1,-0.1 );
        glVertex2f( 0.1,-0.1 );
        glVertex2f( 0.1, 0.1 );
        glVertex2f(-0.1, 0.1 );
        glEnd();
    }

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
    PhyObj *Object;
    for( int i = 0; i < 20; ++i )
    {
        Object = new PhyObj( b2Vec2( sin( M_PI/180.0 * i*5 )*0.9, 1.0 + i ), 180.0/M_PI*i*21 );
        Scene->AddPhyObj( Object );

//        Object = new PhyObj( b2Vec2( 0.0, 1.0 + i ), 0.0 );
//        TestObjects.push_back( Object );
    }
    
    // Test physics, ground and walls
    b2BodyDef GroundDef;
    b2PolygonShape GroundBox;
    GroundDef.position.Set( 0.0, -2.0 );
    b2FixtureDef GroundFixture;
    b2Body *GroundBody = MyWorld->CreateBody( &GroundDef );
    GroundBox.SetAsBox( 1.0, 1.0 );
    GroundFixture.shape = &GroundBox;
    GroundBody->CreateFixture( &GroundFixture );
  
    b2BodyDef RightDef;
    b2PolygonShape RightBox;
    RightDef.position.Set( 2.0, 0.0 );
    b2FixtureDef RightFixture;
    b2Body *RightBody = MyWorld->CreateBody( &RightDef );
    RightBox.SetAsBox(1.0, 1.0 );
    RightFixture.shape = &RightBox;
    RightBody->CreateFixture( &RightFixture );
    
    b2BodyDef LeftDef;
    b2PolygonShape LeftBox;
    LeftDef.position.Set(-2.0, 0.0 );
    b2FixtureDef LeftFixture;
    b2Body *LeftBody = MyWorld->CreateBody( &LeftDef );
    LeftBox.SetAsBox(1.0, 1.0 );
    LeftFixture.shape = &LeftBox;
    LeftBody->CreateFixture( &LeftFixture );

    
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