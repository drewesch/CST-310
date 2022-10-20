#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

const int screenWidth = 950;	   // width of screen window in pixels 
const int screenHeight = 1080/2;	   // height of screen window in pixels

GLdouble A, B, C, D;               // values used for scaling and shifting

float x = 2.5;
float y = -5.0;
float lx = 0.0;
float ly = 1.0;

float angle = 0.0;

void myInit(void)
 {
    glClearColor(0.0,0.0,0.0,0.0);       // background color is white
    glColor3f(0.0f, 0.0f, 0.0f);         // drawing color is black 
    glPointSize(2.0);		         // a 'dot' is 2 by 2 pixels
    glMatrixMode(GL_PROJECTION); 	 // set "camera shape"
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST); //  Enables Depth Testing
    gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
		 A = screenWidth / 4.0; // set values used for scaling and shifting
		 B = 0.0;
		 C = D = screenHeight / 2.0;
}

void drawPyramid(float x, float y, float c1, float c2, float c3)
{
    glColor3f(c1, c2, c3);
    glBegin(GL_QUADS);

    // Bottom face
    glVertex3f(0.0 + x, 0.0 + y, 0.0);
    glVertex3f(0.0 + x, 0.0 + y, 100.0);
    glVertex3f(100.0 + x, 0.0 + y, 100.0);
    glVertex3f(100.0 + x, 0.0 + y, 0.0);
    glEnd();

    // Front face
    glColor3f(c1, c2, c3);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0 + x, 0.0 + y, 0.0);
    glVertex3f(50.0 + x, 100.0 + y, 50.0);
    glVertex3f(100.0 + x, 0.0 + y, 0.0);

    // Left side face
    glVertex3f(0.0 + x, 0.0 + y, 0.0);
    glVertex3f(50.0 + x, 100.0 + y, 50.0);
    glVertex3f(0.0 + x, 0.0 + y, 100.0);

    // Right side face
    glVertex3f(100.0 + x, 0.0 + y, 0.0);
    glVertex3f(50.0 + x, 100.0 + y, 50.0);
    glVertex3f(100.0 + x, 0.0 + y, 100.0);

    // Back face
    glVertex3f(0.0 + x, 0.0 + y, 100.0);
    glVertex3f(50.0 + x, 100.0 + y, 50.0);
    glVertex3f(100.0 + x, 0.0 + y, 100.0);
    glEnd();

}

void drawPyramid2(float x, float y, float c1, float c2, float c3)
{
    // Front face
    glColor3f(c1, c2, c3);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0 + x, 0.0 + y, 0.0);
    glVertex3f(50.0 + x, 100.0 + y, 50.0);
    glVertex3f(100.0 + x, 0.0 + y, 0.0);
    glEnd();

}

void timer(int)
{
    glutPostRedisplay(); // OpenGL will call the display function
    glutTimerFunc(1000/60,timer,0); // Every 1/60th of second we need to call the function. Peridically it'll call itself

    angle+=0.8; // control the speed of rotation
    if(angle>360.0)
        angle=angle-360.0; //For handling overflow
}

void reshape(int w, int h)
{
    //viewport
    glViewport(0,0,(GLsizei)w,(GLsizei)h); //Viewport is specified as whole screen
    glMatrixMode(GL_PROJECTION); // Switched to Projection Matrix and This function switches matrix mode
    glLoadIdentity(); // Resets the parameters of the Projection matrix
    gluPerspective(60,1,2.0,50.0); // Spcifies new projection
    glMatrixMode(GL_MODELVIEW); // Switch Back to modelview matrix

}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);     // clear the screen
    glPushMatrix();
        drawPyramid(150.0, 200.0, 1.0, 0.0, 0.0);
        drawPyramid(400.0, 200.0, 0.0, 1.0, 0.0);
        drawPyramid(650.0, 200.0, 0.0, 0.0, 1.0);
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

int main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("Pyramid Example"); // open the screen window
	glutDisplayFunc(myDisplay);     // register redraw function
    glutReshapeFunc(reshape); // Viewport Callback function. Whenever Window is reshaped this function is called
    glutTimerFunc(0,timer,0); //
    glutSpecialFunc(cameraMovement); // Handle GLUT keys for special inputs
	myInit();                   
	glutMainLoop(); 		     // go into a perpetual loop
}