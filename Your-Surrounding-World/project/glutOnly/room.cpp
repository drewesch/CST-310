
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
const int screenWidth = 1200;	   // width of screen window in pixels 
const int screenHeight = 1080/2;	   // height of screen window in pixels
GLdouble A, B, C, D;               // values used for scaling and shifting
//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
 void myInit(void)
 {
    glClearColor(1.0,1.0,1.0,0.0);       // background color is white
    glColor3f(0.0f, 0.0f, 0.0f);         // drawing color is black 
    glPointSize(2.0);		         // a 'dot' is 2 by 2 pixels
    glMatrixMode(GL_PROJECTION); 	 // set "camera shape"
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
		 A = screenWidth / 4.0; // set values used for scaling and shifting
		 B = 0.0;
		 C = D = screenHeight / 2.0;
}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
//---------------------Objects--------------------------------

//---------------------Walls+Floor----------------------------
//Back left wall
glColor3f(0.8431373f, 0.8156863f, 0.7529413f); 
glBegin(GL_QUADS);
glVertex3f(5.0f,67.0f, 0.0f);
glVertex3f(889.0f,127.0f, 0.0f);
glVertex3f(922.0f,538.0f, 0.0f);
glVertex3f(5.0f,537.0f, 0.0f);

//Back left strip
glColor3f(0.1f, 0.1f, 0.1f); 
glBegin(GL_QUADS);
glVertex3f(5.0f,42.0f, 0.0f);
glVertex3f(886.0f,107.0f, 0.0f);
glVertex3f(889.0f,127.0f, 0.0f);
glVertex3f(5.0f,65.0f, 0.0f);



//---------------------Main Objects--------------------------------
   //TV screen
glColor3f(0.0f, 0.0f, 0.0f); 
glBegin(GL_QUADS);
glVertex3f(539.0f,199.0f, 0.0f);
glVertex3f(542.0f,347.0f, 0.0f);
glVertex3f(922.0f,348.0f, 0.0f);
glVertex3f(910.0f,188.0f, 0.0f);















//--------------------------------------------------
	glEnd();	
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