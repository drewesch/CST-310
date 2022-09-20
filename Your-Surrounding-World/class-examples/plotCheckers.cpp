
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;
const int screenWidth = 400;	   // width of screen window in pixels 
const int screenHeight = 400;	   // height of screen window in pixels
GLdouble A, B, C, D;               // values used for scaling and shifting
//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
 void myInit(void)
 {
    glClearColor(0.5,0.5,0.5,0.0);       // background color is white
    glColor3f(0.0f, 0.0f, 0.0f);         // drawing color is black 
    glPointSize(2.0);		         // a 'dot' is 2 by 2 pixels
    glMatrixMode(GL_PROJECTION); 	 // set "camera shape"
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
		 A = screenWidth / 4.0; // set values used for scaling and shifting
		 B = 0.0;
		 C = D = screenHeight / 2.0;
}

void drawCheckers(int i, int j) {
	if (j % 2 == 0) {
		// Black then white
		cout << "BTW\n";
		glColor3f(0.0f, 0.0f, 0.0f); // Draw with black color

		glVertex3f(0.0f + (i*50.0f), 0.0f + (j*50.0f), 1.0f); // Define vertices in counter-clockwise (CCW) order
		glVertex3f(50.0f + (i*50.0f), 0.0f + (j*50.0f), 1.0f); // so that the normal (front-face) is facing you
		glVertex3f(50.0f + (i*50.0f), 50.0f + (j*50.0f), 1.0f);
		glVertex3f(0.0f + (i*50.0f), 50.0f + (j*50.0f), 1.0f);

		glColor3f(1.0f, 1.0f, 1.0f); // Draw with white color

		glVertex3f(50.0f + (i*50.0f), 0.0f + (j*50.0f), 1.0f); // Define vertices in counter-clockwise (CCW) order
		glVertex3f(100.0f + (i*50.0f), 0.0f + (j*50.0f), 1.0f); // so that the normal (front-face) is facing you
		glVertex3f(100.0f + (i*50.0f), 50.0f + (j*50.0f), 1.0f);
		glVertex3f(50.0f + (i*50.0f), 50.0f + (j*50.0f), 1.0f);
		
	} else {
		// White then black
		cout << "WTB\n";
		glColor3f(1.0f, 1.0f, 1.0f); // Draw with white color

		glVertex3f(0.0f + (i*50.0f), 0.0f + (j*50.0f), 1.0f); // Define vertices in counter-clockwise (CCW) order
		glVertex3f(50.0f + (i*50.0f), 0.0f + (j*50.0f), 1.0f); // so that the normal (front-face) is facing you
		glVertex3f(50.0f + (i*50.0f), 50.0f + (j*50.0f), 1.0f);
		glVertex3f(0.0f + (i*50.0f), 50.0f + (j*50.0f), 1.0f);

		glColor3f(0.0f, 0.0f, 0.0f); // Draw with black color

		glVertex3f(50.0f + (i*50.0f), 0.0f + (j*50.0f), 1.0f); // Define vertices in counter-clockwise (CCW) order
		glVertex3f(100.0f + (i*50.0f), 0.0f + (j*50.0f), 1.0f); // so that the normal (front-face) is facing you
		glVertex3f(100.0f + (i*50.0f), 50.0f + (j*50.0f), 1.0f);
		glVertex3f(50.0f + (i*50.0f), 50.0f + (j*50.0f), 1.0f);
	}
}

//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
	glPushMatrix();
	glRotatef(45.0f, 0, 0, 1);

	for (int i = 0; i < 8; i+=2) {
		for (int j = 0; j < 8; j++) {
			glBegin(GL_QUADS); // Each set of 4 vertices form a quad
			drawCheckers(i,j);
			glEnd();
		}
	}

	glPopMatrix();

	glFlush();		   // send all output to display 
}
//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("my first attempt"); // open the screen window
	glutDisplayFunc(myDisplay);     // register redraw function
	myInit();                   
	glutMainLoop(); 		     // go into a perpetual loop
}