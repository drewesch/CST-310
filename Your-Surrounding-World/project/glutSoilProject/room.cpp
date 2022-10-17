
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include <stdio.h>

#include "roomObjects.h"

using namespace std;
const int screenWidth = 950;	   // width of screen window in pixels 
const int screenHeight = 1080/2;	   // height of screen window in pixels
GLdouble A, B, C, D;               // values used for scaling and shifting
GLuint _textureTV;
GLuint _textureFloor;

// float _angleHorizontal = 0.0;
// float _angleVertical = 0.0;

float xPos = 0.0;
float yPos = 0.0;

float xAngle = 0.0;
float yAngle = 0.0;

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

    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR); 

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
    glClearColor(1.0,1.0,1.0,0.0);       // background color is white
    glColor3f(0.0f, 0.0f, 0.0f);         // drawing color is black 
    glPointSize(2.0);		         // a 'dot' is 2 by 2 pixels
    glMatrixMode(GL_PROJECTION); 	 // set "camera shape"
    glLoadIdentity();
	glOrtho(0, (GLdouble)screenWidth, 0, (GLdouble)screenHeight, -1.0, 10.0);
    
	//gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
		 A = screenWidth / 4.0; // set values used for scaling and shifting
		 B = 0.0;
		 C = D = screenHeight / 2.0;
	_textureTV = loadTex("./TVScreen.png");
	_textureFloor = loadTex("./floor.jpg");
}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // clear the screen 
	
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
		glEnd();
		glBindTexture(GL_TEXTURE_2D, _textureFloor);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);
		//glTranslatef(0,0,-100);
        glColor3f(1.0f,1.0f,1.0f);
		
		glColor3f(0.0f, 1.0f, 0.02f); 
        glBegin(GL_LINES);
        glVertex3f(-10.0f,-10.0f, 0.0f);	//Bottom Left
        glVertex3f(-10.0f,-11.0f, 0.0f);	//Top Left
        glEnd();
        glColor3f(1.0f,1.0f,1.0f);


		glBegin(GL_POLYGON);  // Floor
            glTexCoord3f(-1,0,0.1);  glVertex3f(0.0f,0.0f, 0.0f); //bottom left
            glTexCoord3f(-1,.16,0.1);  glVertex3f(0.0f,67.0f, 0.0f);   //top left
            glTexCoord3f(-0.10,0.26,0.1);  glVertex3f(889.0f,127.0f, 0.0f); //top right
			glTexCoord3f(0.0,0.21,0.1); glVertex3f(959.0f,102.0f, 0.0f);   	//Middle Right
			glTexCoord3f(0,0,0.1);  glVertex3f(950.0f,0.0f, 0.0f);		//Bottom //bottom right
    	glEnd();
		glDisable(GL_TEXTURE_2D);

	glPopMatrix();



	glPushMatrix();
		//glColor3f(1.0f, 1.0f, 1.0f);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR); 
	
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
		infinityBox();
		drawRackFrontLines();
		drawRackFrontStands();
		glEnd();	
	glPopMatrix();
	//glFlush();
	
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
		glEnd();
		
		glBindTexture(GL_TEXTURE_2D, _textureTV);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);
		//glTranslatef(0,0,-100);

        glColor3f(0.0f, 1.0f, 0.02f); 
        glBegin(GL_LINES);
        glVertex3f(-10.0f,-10.0f, 0.0f);	//Bottom Left
        glVertex3f(-10.0f,-11.0f, 0.0f);	//Top Left
        glEnd();
        glColor3f(1.0f,1.0f,1.0f);

		
		glBegin(GL_QUADS);  // Wall
            glTexCoord3f(-.94,.92,0.1);  glVertex3f(542.0f,347.0f, -1.0f); //top left
            glTexCoord3f(-0.04,0.93,0.1);  glVertex3f(922.0f,348.0f, -1.0f); //top right
            glTexCoord3f(-0.07,0.26,0.1);  glVertex3f(910.0f,188.0f, -1.0f); //bottom right
            glTexCoord3f(-0.95,0.3,0.1);  glVertex3f(539.0f,199.0f, -1.0f); //bottom left
    	glEnd();
		glDisable(GL_TEXTURE_2D);


		
		


//--------------------------------------------------
	glPopMatrix();
	
	glutSwapBuffers();		   // send all output to display 
}

void keyboardRotate(int key, int x, int y){
	float rot = 0.1f;
    switch (key) {
    case GLUT_KEY_RIGHT:
		glRotatef(rot, 0.5, 0.0, 0.0);
        break;
    case GLUT_KEY_LEFT:
		glRotatef(rot, -0.5, 0.0, 0.0);
        break;
	case GLUT_KEY_UP:
		glRotatef(rot, 0.0, 0.5, 0.0);
        break;
    case GLUT_KEY_DOWN:
		glRotatef(rot, 0.0, -0.5, 0.0);
        break;
    }
    glutPostRedisplay();
}


void keyboardMovement(int key, int x, int y){
	float move = 10.0f;
    switch (key) {
    case GLUT_KEY_RIGHT:
		glTranslatef(move, 0.0, 0.0);
        break;
    case GLUT_KEY_LEFT:
		glTranslatef(-move, 0.0, 0.0);
        break;
	case GLUT_KEY_UP:
		glTranslatef(0.0, move, 0.0);
        break;
    case GLUT_KEY_DOWN:
		glTranslatef(0.0, -move, 0.0);
        break;
    }
    glutPostRedisplay();
}

//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("Andrew and Evan's Apartment"); // open the screen window
	glutDisplayFunc(myDisplay);     // register redraw function
	glutSpecialFunc(keyboardMovement);
	myInit();
	//gluLookAt(0,0,-10,_angleHorizontal,_angleVertical,0,0,1,0);                   
	glutMainLoop(); 		     // go into a perpetual loop
}