// This program is a flyby around the RGB color cube.  One intersting note
// is that because the cube is a convex polyhedron and it is the only thing
// in the scene, we can render it using backface culling only. i.e., there
// is no need for a depth buffer.

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>
#include <iostream>

// Colors
GLfloat WHITE[] = {1, 1, 1};
GLfloat RED[] = {1, 0, 0};
GLfloat GREEN[] = {0, 1, 0};
GLfloat MAGENTA[] = {1, 0, 1};
GLfloat rotateCube = 0.0f;
GLfloat zoom = 1.0f;

//GLfloat rotate = 0.0f;

// A camera.  It moves horizontally in a circle centered at the origin of
// radius 10.  It moves vertically straight up and down.
class Camera {
  double theta;      // determines the x and z positions
  double y;          // the current y position
  double dTheta;     // increment in theta for swinging the camera around
  double dy;         // increment in y for moving the camera up/down
public:
  Camera(): theta(0), y(0), dTheta(0.04), dy(1) {}
  double getX() {return (10 * cos(theta)) - 10;}
  double getY() {return y;}
  double getZ() {return 10 * sin(theta);}
  void moveRight() {theta += dTheta;}
  void moveLeft() {theta -= dTheta;}
  void moveUp() {y += dy;}
  void moveDown() {y -= dy;}
};

// The cube has opposite corners at (0,0,0) and (1,1,1), which are black and
// white respectively.  The x-axis is the red gradient, the y-axis is the
// green gradient, and the z-axis is the blue gradient.  The cube's position
// and colors are fixed.
namespace Cube {

const int NUM_VERTICES = 8;
const int NUM_FACES = 6;

GLint vertices[NUM_VERTICES][3] = {
  {0, 0, 0}, {0, 0, 1}, {0, 1, 0}, {0, 1, 1},
  {1, 0, 0}, {1, 0, 1}, {1, 1, 0}, {1, 1, 1}};

GLint faces[NUM_FACES][4] = {
  {1, 5, 7, 3}, {5, 4, 6, 7}, {4, 0, 2, 6},
  {3, 7, 6, 2}, {0, 1, 3, 2}, {0, 4, 5, 1}};

GLfloat vertexColors[NUM_VERTICES][3] = {
  {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 1.0},
  {1.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {1.0, 1.0, 0.0}, {1.0, 1.0, 1.0}};

void draw() {
  glPushMatrix();
  glRotatef(rotateCube,1,1,1);
  glScalef(zoom,zoom,zoom);
  glBegin(GL_QUADS);
  for (int i = 0; i < NUM_FACES; i++) {
    for (int j = 0; j < 4; j++) {
      glColor3fv((GLfloat*)&vertexColors[faces[i][j]]);
      glVertex3iv((GLint*)&vertices[faces[i][j]]);
    }
  }
  glEnd();
  glPopMatrix();
}
}

class BouncingCube {
float xpos;
float ypos;
float zpos;
float velocity = .1f;

GLint vertices[8][3] = {
  {0, 0, 0}, {0, 0, 1}, {0, 1, 0}, {0, 1, 1},
  {1, 0, 0}, {1, 0, 1}, {1, 1, 0}, {1, 1, 1}};

GLint faces[6][4] = {
  {1, 5, 7, 3}, {5, 4, 6, 7}, {4, 0, 2, 6},
  {3, 7, 6, 2}, {0, 1, 3, 2}, {0, 4, 5, 1}};

GLfloat vertexColors[8][3] = {
  {0.80, 1.0, 0.80}, {1.0, 0.50, 1.0}, {0.30, 1.0, 0.70}, {0.80, 0.70, 0.40},
  {1.0, 0.80, 1.0}, {1.0, 0.50, 1.0}, {1.0, 0.90, 0.90}, {1.0, 0.80, 1.0}};

public:
  BouncingCube(float x, float y, float z): xpos(x), ypos(y), zpos(z) {}

void draw() {
  if (xpos > 10){
    velocity *= -1;
  }
  else if(xpos < -10){
    velocity *= -1;
  }
  xpos += velocity;
  glPushMatrix();
  glTranslatef(xpos,ypos,zpos);
  glScalef(zoom,zoom,zoom);
  glBegin(GL_QUADS);
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      glColor3fv((GLfloat*)&vertexColors[faces[i][j]]);
      glVertex3iv((GLint*)&vertices[faces[i][j]]);
    }
  }
  glEnd();
  glPopMatrix();
}
};

class Plane {
  int displayListId;
  int xpos;
  int angle;
public:
  Plane(int xpos, int angle): xpos(xpos), angle(angle) {}
  void create() {
    displayListId = glGenLists(1);
    glNewList(displayListId, GL_COMPILE);
    GLfloat lightPosition[] = {4, 3, 7, 1};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glColor3f(0,0,1);

    glPushMatrix();
    
    glRotatef(angle,0,1,0);
    
    glBegin(GL_QUADS);
    glNormal3d(0, 1, 0);
    
    glVertex3d(xpos, 15, -15);
    glVertex3d(xpos, 15, 15);
    glVertex3d(xpos, -15, 15);
    glVertex3d(xpos, -15, -15);

       
    glEnd();
    glPopMatrix();
    glEndList();
  }
  void draw() {
    glCallList(displayListId);
  }
};

// Display and Animation. To draw we just clear the window and draw the cube.
// Because our main window is double buffered we have to swap the buffers to
// make the drawing visible. Animation is achieved by successively moving our
// camera and drawing. The function nextAnimationFrame() moves the camera to
// the next point and draws. The way that we get animation in OpenGL is to
// register nextFrame as the idle function; this is done in main().


Camera camera;
bool stopped = false;
GLfloat pause = 1.0f;
BouncingCube cube1 = BouncingCube(-5,3,-4);
BouncingCube cube2 = BouncingCube(5,3,2);
Plane plane1 = Plane(-18,0);
Plane plane2 = Plane(-17,180);


void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  // gluLookAt(camera.getX(), camera.getY(), camera.getZ(), 1.0, 0.0, 1.0, 0.0, 1.0, 0.0);
  Cube::draw();

  cube1.draw();
  cube2.draw();
  plane1.draw();
  plane2.draw();
  
  
  glFlush();
  glutSwapBuffers();
}

// We'll be flying around the cube by moving the camera along the orbit of the
// curve u->(8*cos(u), 7*cos(u)-1, 4*cos(u/3)+2).  We keep the camera looking
// at the center of the cube (0.5, 0.5, 0.5) and vary the up vector to achieve
// a weird tumbling effect.
void timer(int v) {
  static GLfloat u = 0.0;
  u += 0.01*pause;
  glLoadIdentity();
  
  //IMPORTANT --> moving the camera. Will need to change to stop and rotate.
  // gluLookAt(8*cos(u), 7*cos(u)-1, 2*cos(u/3) + 2,
  //       .5 + camera.getX(), .5 + camera.getY(), .5 + camera.getZ(),
  //       cos(u), 1, 0);
  
   gluLookAt(2*cos(u), -3, -30*sin(u),
        .5 + camera.getX(), .5 + camera.getY(), .5 + camera.getZ(),
        0, 1, 0);


  

  
  //gluLookAt(8, 7, 4, .5, .5, .5, cos(u), 1, 0); //Ex. Static camera position looking at positon .5,.5,.5
  // printf("Camera current pos: x - %f y - %f z - %f", camera.getX(), camera.getY(), camera.getZ());

  glutPostRedisplay();
  glutTimerFunc(1000/60.0, timer, v);
}

// When the window is reshaped we have to recompute the camera settings to
// match the new window shape.  Set the viewport to (0,0)-(w,h).  Set the
// camera to have a 60 degree vertical field of view, aspect ratio w/h, near
// clipping plane distance 0.5 and far clipping plane distance 40.
void reshape(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, GLfloat(w) / GLfloat(h), 0.5, 40.0);
  glMatrixMode(GL_MODELVIEW);
}

void special(unsigned char key, int, int) {
  // Keyboard functionality
  switch (key) {
    case 'u': if(stopped){camera.moveUp();} break;
    case 'd': if(stopped){camera.moveDown();} break;
    case 's': stopped = true; pause = 0.0f; break;
    case 'c': stopped = false; pause = 1.0f; break;
    case '=': zoom += 0.6f; break;
    case '-': zoom -= 0.6f; break;
    case 'r': rotateCube += 35.0f; break;
  }
  glutPostRedisplay();
}

// Application specific initialization:  The only thing we really need to do
// is enable back face culling because the only thing in the scene is a cube
// which is a convex polyhedron.
void init() {
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
  plane1.create();
  plane2.create();
  
}

// The usual main for a GLUT application.
int main(int argc, char** argv) {
  
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("The RGB Color Cube");
  glutReshapeFunc(reshape);
  glutTimerFunc(100, timer, 0);
  glutDisplayFunc(display);
  glutKeyboardFunc(special);
  init();
  glutMainLoop();
}