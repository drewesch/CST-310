
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
GLuint _textureTV;					// value for storing TV texture
GLuint _textureFloor;				// value for storing floor texture

// Function call to load textures using SOIL and shaders
GLuint loadTex(const char* texname)
{
	// Format the texture for GLU and SOIL
	GLuint texture = SOIL_load_OGL_texture
                    (
                        texname,
                        SOIL_LOAD_AUTO,
                        SOIL_CREATE_NEW_ID,
                        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT

                    );

	// If the teexture does not exist
    if( 0 == texture )
    {
        printf( "SOIL loading error: '%s'\n", SOIL_last_result() ); // Throw a loading error
    }

	// Bind texture to a GL shader
    glBindTexture(GL_TEXTURE_2D, texture);

	// Set Texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Initialize the texture using polygons and complete color
    glColor3f (1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    
	// Set the texture vertexes and coordinates  
    glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f); // Bottom left
    glTexCoord2f(1.0f, 0.0f); glVertex2f(1.0f, 0.0f); // Top left
    glTexCoord2f(1.0f, 1.0f); glVertex2f(1.0f, 1.0f); // Top right
    glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 1.0f); // Bottom right

	// End texture
    glEnd();   
    glDisable(GL_TEXTURE_2D);

	// Return completed texture using SOIL and shaders
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
	_textureTV = loadTex("./TVScreen.png"); // load TV screen texture
	_textureFloor = loadTex("./floor.jpg"); // load floor texture
}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // clear the screen 
	
	// Push textures to a new matrix
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
		glEnd();
		
		// Bind texture to a shader
		glBindTexture(GL_TEXTURE_2D, _textureFloor);

		// Formalize texture parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);

        glColor3f(1.0f,1.0f,1.0f);
		glColor3f(0.0f, 1.0f, 0.02f); 
		// Initialize the texture to 3D space
        glBegin(GL_LINES);
        glVertex3f(-10.0f,-10.0f, 0.0f);	//Bottom Left
        glVertex3f(-10.0f,-11.0f, 0.0f);	//Top Left
        glEnd();
        glColor3f(1.0f,1.0f,1.0f);

		// Draw texture
		glBegin(GL_POLYGON);  // Floor
            glTexCoord3f(-1,0,0.1);  glVertex3f(0.0f,0.0f, 0.0f); //bottom left
            glTexCoord3f(-1,.16,0.1);  glVertex3f(0.0f,67.0f, 0.0f);   //top left
            glTexCoord3f(-0.10,0.26,0.1);  glVertex3f(889.0f,127.0f, 0.0f); //top right
			glTexCoord3f(0.0,0.21,0.1); glVertex3f(959.0f,102.0f, 0.0f);   	//Middle Right
			glTexCoord3f(0,0,0.1);  glVertex3f(950.0f,0.0f, 0.0f);		//Bottom //bottom right
    	glEnd();
		glDisable(GL_TEXTURE_2D);

	// Save matrix
	glPopMatrix();



	glPushMatrix();
		//glColor3f(1.0f, 1.0f, 1.0f);

		// Reload texture matrix in main matrix
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
		drawDumbbellCircle(239.0f, 265.0f, 6.0f, 100);
		infinityBox();
		drawRackFrontLines();
		drawRackFrontStands();
		glEnd();
	// Save main matrix for objects	
	glPopMatrix();
	
	// Reinitalize texture matrixes to display in order
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
		glEnd();
		
		// Bind TV textures
		glBindTexture(GL_TEXTURE_2D, _textureTV);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);

		// Initalize in 3D space
        glColor3f(0.0f, 1.0f, 0.02f); 
        glBegin(GL_LINES);
        glVertex3f(-10.0f,-10.0f, 0.0f);	//Bottom Left
        glVertex3f(-10.0f,-11.0f, 0.0f);	//Top Left
        glEnd();
        glColor3f(1.0f,1.0f,1.0f);

		// Draw texture coordinates
		glBegin(GL_QUADS);  // Wall
            glTexCoord3f(-.94,.92,0.1);  glVertex3f(542.0f,347.0f, -1.0f); //top left
            glTexCoord3f(-0.04,0.93,0.1);  glVertex3f(922.0f,348.0f, -1.0f); //top right
            glTexCoord3f(-0.07,0.26,0.1);  glVertex3f(910.0f,188.0f, -1.0f); //bottom right
            glTexCoord3f(-0.95,0.3,0.1);  glVertex3f(539.0f,199.0f, -1.0f); //bottom left
    	glEnd();
		glDisable(GL_TEXTURE_2D);

		
		


//--------------------------------------------------
	// Save all graphics to a final matrix
	glPopMatrix();
	
	glutSwapBuffers();		   // send all output to display 
}

// Handle camera movement using arrow key inputs
void cameraMovement(int key, int x, int y){
	float move = 2.0f;
    switch (key) {
    case GLUT_KEY_RIGHT:
		// Move camera to the right, forces all matrix calculations to move correspondingly
		glTranslatef(-move, 0.0, 0.0);
        break;
    case GLUT_KEY_LEFT:
		// Move camera to the left, forces all matrix calculations to move correspondingly
		glTranslatef(move, 0.0, 0.0);
        break;
	case GLUT_KEY_UP:
		// Move camera upwards, forces all matrix calculations to move correspondingly
		glTranslatef(0.0, -move, 0.0);
        break;
    case GLUT_KEY_DOWN:
		// Move camera downwards, forces all matrix calculations to move correspondingly
		glTranslatef(0.0, move, 0.0);
        break;
	}
    glutPostRedisplay();
}

// Handle rotations using "a" and "d", update ortho matrix
void rotationHandler(unsigned char key, int x, int y) {
	float rot = 0.5f; // Rotation amount
	if (key == 'a') {
		// Rotate left
		glRotatef(rot, 0.0, 0.0, -0.5);
	} else if (key == 'd') {
		// Rotate right
		glRotatef(rot, 0.0, 0.0, 0.5);
	}
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
	glutSpecialFunc(cameraMovement); // Handle GLUT keys for special inputs
	glutKeyboardFunc(rotationHandler); // Handle non GLUT special key inputs
	myInit();						// Call init function            
	glutMainLoop(); 		     // go into a perpetual loop
}