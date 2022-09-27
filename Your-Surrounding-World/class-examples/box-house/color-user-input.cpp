#include <GL/glut.h>
#include <math.h>

const int screenWidth = 640;
const int screenHeight = 480;
GLdouble A,B,C,D;
float r,g,b = 0;


void renderScene(void) {
        // clear the screen 
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
        for (GLdouble x = 0; x < 4.0 ; x += 0.005)
        {
        GLdouble func = exp(-x) * cos (2 * 3.14159265 * x);
    glVertex2d(A * x + B, C * func + D);
        }
        glEnd ();
        glFlush(); // send all output to display
}

void getInput(unsigned char Key, int x, int y)
{
switch(Key)
{
    case 'r':
        r = 1.0;
        g = 0.0;
        b = 0.0;
        //openGL code
                glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
        glColor3f(r,g,b);
        for (GLdouble x = 0; x < 4.0 ; x += 0.005)
        {
        GLdouble func = exp(-x) * cos (2 * 3.14159265 * x);
    glVertex2d(A * x + B, C * func + D);
        }
        glEnd ();
        glFlush(); // send all output to display
        
        break;
    case 'g':
        r = 0.0;
        g = 1.0;
        b = 0.0;
        //openGL code
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
        glColor3f(r,g,b);
        for (GLdouble x = 0; x < 4.0 ; x += 0.005)
        {
        GLdouble func = exp(-x) * cos (2 * 3.14159265 * x);
    glVertex2d(A * x + B, C * func + D);
        }
        glEnd ();
        glFlush(); // send all output to display
        break;
    case 'b':
        r = 0.0;
        g = 0.0;
        b = 1.0;
        //openGL code
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
        glColor3f(r,g,b);
        for (GLdouble x = 0; x < 4.0 ; x += 0.005)
        {
        GLdouble func = exp(-x) * cos (2 * 3.14159265 * x);
    glVertex2d(A * x + B, C * func + D);
        }
        glEnd ();
        glFlush(); // send all output to display
        break;
    case 27:
        exit(1);
        break;
};
}

void init (void)
{
   
   glClearColor(1.0,1.0,1.0,0.0);
   glColor3f(r, g, b);
   glPointSize(2.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
  gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
                                          // background color is white
                                          // drawing color is black
                                          // a 'dot' is 2 by 2 pixels
                                          // set "camera shape"
               A = screenWidth / 4.0; // set values used for scaling and shifting
                 B = 0.0;
                 C = D = screenHeight / 2.0; 
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH| GLUT_SINGLE | GLUT_RGBA);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(screenWidth,screenHeight);
  glutCreateWindow("GCU - My Triangle");
  glutKeyboardFunc(getInput);
  glutDisplayFunc(renderScene);
  init();
  glutMainLoop();
  return 0;
}