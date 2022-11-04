// This application is a trivial illustration of texture mapping.  It draws
// several triangles, each with a texture mapped on to it.  The same texture
// is used for each triangle, but the mappings vary quite a bit so it looks as
// if each triangle has a different texture.

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cstdlib>
#include <cmath>
#include <iostream>

// Define a 2 x 2 red and yellow checkered pattern using RGB colors.
#define red {0xff, 0x00, 0x00}
#define yellow {0xff, 0xff, 0x00}
#define magenta {0xff, 0, 0xff}
GLubyte texture[][3] = {
    red, yellow,
    yellow, red,
};

class Camera {
  double x;      // determines the x and z positions
  double y;          // the current y position
  double dx;     // increment in theta for swinging the camera around
  double dy;         // increment in y for moving the camera up/down
public:
  Camera(): x(0), y(0), dx(0.3), dy(0.3) {}
  double getX() {return x;}
  double getY() {return y;}
  void moveRight() {glTranslatef(-dx, 0, 0);}
  void moveLeft() {glTranslatef(dx, 0, 0);}
  void moveUp() {glTranslatef(0, -dy, 0);}
  void moveDown() {glTranslatef(0, dy, 0);}
};

Camera camera;
GLfloat rotate = 0.0f;
GLfloat pause = 1.0f;
GLfloat zoom = 1.0f;
GLfloat moveX = 0.0f;
GLfloat moveY = 0.0f;
//GLfloat height = -1.0f;
bool keys[1024];

// Fixes up camera and remaps texture when window reshaped.
void reshape(int width, int height) {
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(80, GLfloat(width)/height, 1, 40);
  gluLookAt(2, -1, 5, 0, 0, 0, 0, 1, 0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glEnable(GL_TEXTURE_2D);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glTexImage2D(GL_TEXTURE_2D,
               0,                    // level 0
               3,                    // use only R, G, and B components
               2, 2,                 // texture has 2x2 texels
               0,                    // no border
               GL_RGB,               // texels are in RGB format
               GL_UNSIGNED_BYTE,     // color components are unsigned bytes
               texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

void update(int value)
{
rotate+=3.0f*pause;
if(rotate>360.f)
{
rotate-=360;
}

glutPostRedisplay();
glutTimerFunc(25,update,0);
}

// Draws three textured triangles.  Each triangle uses the same texture,
// but the mappings of texture coordinates to vertex coordinates is
// different in each triangle.
void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  glRotatef(rotate, 0.0, 0.0, 1.0);
  glScalef(zoom,zoom,zoom);
  
  glBegin(GL_TRIANGLES);
    glTexCoord2f(0.5, 1.0);    glVertex2f(-3, 3);
    glTexCoord2f(0.0, 0.0);    glVertex2f(-3, 0);
    glTexCoord2f(1.0, 0.0);    glVertex2f(0, 0);

    glTexCoord2f(4, 8);        glVertex2f(3, 3);
    glTexCoord2f(0.0, 0.0);    glVertex2f(0, 0);
    glTexCoord2f(8, 0.0);      glVertex2f(3, 0);

    glTexCoord2f(5, 5);        glVertex2f(0, 0);
    glTexCoord2f(0.0, 0.0);    glVertex2f(-1.5, -3);
    glTexCoord2f(4, 0.0);      glVertex2f(1.5, -3);
  glEnd();
  glPopMatrix();
  glFlush();
  
}

// Moves the camera according to the key pressed, then ask to refresh the
// display.
void special(unsigned char key, int, int) {
  switch (key) {
    case 'p': pause = 0.0f; break;
    case 'c': pause = 1.0f; break;
    case '=': zoom += 0.2f; break;
    case '-': zoom -= 0.2f; break;
    case 'u': camera.moveUp(); break;
    case 'd': camera.moveDown(); break;
    case 'l': camera.moveLeft(); break;
    case 'r': camera.moveRight(); break;
  }
  glutPostRedisplay();
}

// Initializes GLUT and enters the main loop.
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(520, 390);
  glutCreateWindow("Textured Triangles");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutTimerFunc(25,update,0);
  glutKeyboardFunc(special);
  glutMainLoop();
}
