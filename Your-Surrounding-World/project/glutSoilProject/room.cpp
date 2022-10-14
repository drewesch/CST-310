
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//#include <GL/gl.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>

// Other includes
//#include "Shader.h"
#include "roomObjects.h"

using namespace std;
const int screenWidth = 950;	   // width of screen window in pixels 
const int screenHeight = 1080/2;	   // height of screen window in pixels
GLdouble A, B, C, D;               // values used for scaling and shifting
GLuint _textureTVScreen;




//Load textures
GLuint loadTex(const char* texname)
{
    GLuint texture = SOIL_load_OGL_texture
                    (
                        texname,
                        SOIL_LOAD_AUTO,
                        SOIL_CREATE_NEW_ID,
                        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT

                    );

    if( 0 == texture )
    {
        printf( "SOIL loading error: '%s'\n", SOIL_last_result() );
    }

    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glColor3f (1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    
    glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex2f(1.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex2f(1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 1.0f);

    glEnd();   
    glDisable(GL_TEXTURE_2D);

    return texture;
}



//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
 void myInit(void)
 {
    glClearColor(0.0,0.0,0.0,1.0);       // background color is black
    glColor3f(1.0f, 1.0f, 1.0f);         // drawing color is white
    glPointSize(2.0);		         // a 'dot' is 2 by 2 pixels
    glMatrixMode(GL_PROJECTION); 	 // set "camera shape"
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
		 A = screenWidth / 4.0; // set values used for scaling and shifting
		 B = 0.0;
		 C = D = screenHeight / 2.0;

	_textureTVScreen = loadTex("./TVScreen.png");
}


//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // clear the screen 

	glEnable(GL_TEXTURE_2D);
	//glColor3f(1.0f, 1.0f, 1.0f);
	glPushMatrix();
	


		
	glBindTexture(GL_TEXTURE_2D, _textureTVScreen);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR); 
    glTranslatef(0,0,-6);
    
	
	
	// glRotatef(0, 0.0, 1.0, 0.0);
    // glBegin(GL_QUADS);  // Wall
    //     glTexCoord3f(-1.0,1.0,0.1);  glVertex3f(-5,0,1);
    //     glTexCoord3f(0,1.0,0.1);  glVertex3f(0,0,1);
    //     glTexCoord3f(0.0,0.0,0.1);  glVertex3f(0,-1.5,1);
    //     glTexCoord3f(-1.0,0.0,0.1);  glVertex3f(-5,-1.5,1);
    // glEnd();

	/*
	//---------------------Objects--------------------------------


	background();

	//---------------------Main Objects--------------------------------
	drawRackBackStands();
	drawRackBackLines();

	drawRackMiddleLines();

	drawTVStandLower();
	drawLowerTVStandLegs();
	drawPrinterBox();

	drawTVStandMiddle();
	drawMiddleTVStandLegs();
	drawPS4();
	drawPS4Games();

	drawTVStandTop();

	drawTVLegs();
	drawTV();

	dumbells();
	drawDumbbellCircle(239.0f, 265.0f, 6.0f, 100);
	infinityBox();
	drawRackFrontLines();
	drawRackFrontStands();

	*/

	glPopMatrix();
	//------------------------------------------------------



        
 





	//--------------------------------------------------
	//glEnd();	
	glFlush();		   // send all output to display 
}










//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("Andrew and Evan's Apartment"); // open the screen window
	
	//glEnable(GL_DEPTH_TEST);
	
	glutDisplayFunc(myDisplay);     // register redraw function
	myInit();                   
	glutMainLoop(); 		     // go into a perpetual loop
	return 0;
}