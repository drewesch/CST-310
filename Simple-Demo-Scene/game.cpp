
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include <stdio.h>
#include "objects.h"

using namespace std;
const int screenWidth = 950;	   // width of screen window in pixels 
const int screenHeight = 800;	   // height of screen window in pixels
GLdouble A, B, C, D;               // values used for scaling and shifting
GLuint _textureEnemy;					// value for storing TV texture
GLuint _textureSpaceship;				// value for storing floor texture
GLfloat xShip = 0;


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
	_textureEnemy = loadTex("./enemy.png"); // load TV screen texture
	_textureSpaceship = loadTex("./spaceship.png"); // load floor texture

    
    
}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // clear the screen 
	

    //---------------------Background--------------------------------

    glColor3f(0.05f,0.05f,0.05f);
    glBegin(GL_QUADS);
        glVertex3f(0.0f,0.0f, 0.0f);	            //Bottom Left
        glVertex3f(0.0f,screenHeight, 0.0f);	    //Top Left
        glVertex3f(screenWidth,screenHeight, 0.0f);	//Top Right
        glVertex3f(screenWidth,0.0f, 0.0f);	        //Bottom Right
    glEnd();

    //------------------------------------------------------------------
    
 //createSwarm(_textureEnemy);
    /*
    GLfloat xpos = 0;
    int counter = 0;
    GLfloat ypos = 0;
    int m,k = 1;
    
 	for (int i = 2; i >= 1; i--){

        for (int j = 1; j <= m; j++){
            xpos += 50;
        }

        for (k = 1; k <= (2 * i -1); k++){
            createEnemy(_textureEnemy,xpos,ypos);
            xpos += 50;
        }
        m++;
        //xpos = counter * 50;
        xpos = 0;
        ypos -= 50;
    }
    */
    

//createEnemy(_textureEnemy,500,500);
createShip(_textureSpaceship,xShip);
	

		
		


//--------------------------------------------------

	glFlush();
	glutSwapBuffers();		   // send all output to display 
}

// Handle camera movement using arrow key inputs
void shipMovement(int key, int x, int y){
    switch (key) {
    case GLUT_KEY_RIGHT:
		// Move camera to the right, forces all matrix calculations to move correspondingly
		if(xShip <= screenWidth/2 + 15){
            xShip += 9.0f;
        }
        break;
    case GLUT_KEY_LEFT:
		// Move camera to the left, forces all matrix calculations to move correspondingly
		if(xShip >= -(screenWidth/2) + 85){
            xShip -= 9.0f;
        }
        break;
	}
    glutPostRedisplay();
}

void update(int value)
{
glutPostRedisplay();
glutTimerFunc(25,update,0);
}


void special(unsigned char key, int, int) {
  switch (key) {
    case 'a': break;
    case 'd': break;
    case 'k': break;
  }
  glutPostRedisplay();
}


//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("Andrew and Evan's Galiga"); // open the screen window
	glutDisplayFunc(myDisplay);     // register redraw function
	glutSpecialFunc(shipMovement); // Handle GLUT keys for special inputs
    glutKeyboardFunc(special);
	glutTimerFunc(25,update,0);
	myInit();						// Call init function            
	glutMainLoop(); 		     // go into a perpetual loop
}