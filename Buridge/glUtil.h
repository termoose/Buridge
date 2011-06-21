//
//  glUtil.h
//  gluttest
//
//  Created by Ole Andre Birkedal on 3/27/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <GLUT/glut.h>
#include <stdlib.h>

class glUtil
{
public:
    glUtil( int *argc, char **argv, short ResX, short ResY );
    ~glUtil();
    
    inline void SetDisplayFunc( void (*f)(void) ) { glutDisplayFunc( f ); }
    inline void SetMouseFunc( void (*f)(int, int, int, int) ) { glutMouseFunc( f ); }
    inline void SetReshapeFunc( void (*f)(int, int) ) { glutReshapeFunc( f ); }
    inline void SetKeyboardFunc( void (*f)(unsigned char, int, int) ) { glutKeyboardFunc( f ); }

    inline void MainLoop() { glutMainLoop(); }
private:

    
};