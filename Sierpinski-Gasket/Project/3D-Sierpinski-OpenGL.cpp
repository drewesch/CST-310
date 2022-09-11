/*
Project 1: Sierpinski Gasket - Example 2 (3D Gasket)

Authors: Andrew Esch and Evan Lee

Date: 9/11/2022
*/

#ifdef __APPLE_CC__
#include <GLUT/glut.h> // If using MAC/UNIX architecture, import GLUT/glut.h
#else
#include <GL/glut.h> // if using other architecutres, import GL/glut.h
#endif
#include <cstdlib> // Import cstdlib

// Define a 3D point struct to reference x, y, and z coordinates
struct Point {
  GLfloat x, y, z; // Define GLfloat coordinate variables
  Point(GLfloat x, GLfloat y, GLfloat z): x(x), y(y), z(z) {} // Set coordinates to 0 by default
  Point midpoint(Point p) {return Point((x+p.x)/2, (y+p.y)/2, (z+p.z)/2);} // Encapsulate a midpoint function for x, y, and z
};

// Reshape function for dynamic 3D display
void reshape(GLint w, GLint h) {
  glViewport(0, 0, w, h); // Set viewport based on defined width and height
  glMatrixMode(GL_PROJECTION); // Set orthographic projection mode
  glLoadIdentity(); // Load identity matrix
  gluPerspective(100.0, GLfloat(w)/GLfloat(h), 10.0, 1500.0); // Set dynamic perspective viewing volumne
}

// Main program display function
// Clears OpenGL color buffers
void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color buffer bit and depth (for 3D Gasket)
}

// Draws the "next 500 points".  The function contains locally the definitions
// of the vertices and the current point as static objects so that their values
// are retained between calls.
void generatePoints() {


  static Point vertices[4] = { // Create a random set of points within the window, this is the verticies for the main tetrahedron
    Point(-350, -225, -200),
    Point(-150, -400, -600),
    Point(250, -225, -300),
    Point(0, 450, -400)
  };
  static Point lastPoint = vertices[0]; // Set the initial value as an arbitary vertice (use index 0, 1, 2, or 3)

  // Compute and plot 1000 new points of the Sierpinski Gasket
  glBegin(GL_POINTS);
  for (int i = 0; i <= 1000; i++) {
    lastPoint = lastPoint.midpoint(vertices[rand() % 4]); // Choose a random vertice and find the midpoint between current initial value and the chosen vertice
    GLfloat intensity = (600 + lastPoint.z) / 400.0; // Set color intensity variable based on distance, this gives the "3D" effect
    glColor3f(intensity, intensity, 0.25); // Set color intensity 
    glVertex3f(lastPoint.x, lastPoint.y, lastPoint.z); // Plot the vertice in OpenGL
  }
  glEnd(); // End plotting
  glFlush(); // Flush OpenGL points
}

// Initial program setup function for application-specific integrations
// Implements depth buffering
void init() {
  glEnable(GL_DEPTH_TEST); // Depth buffering

  // Set a blue background
  glClearColor(0.0, 0.0, 1.0, 1.0);
  glColor3f(1.0, 1.0, 1.0);
}

// Initialize GLUT and OpenGL for main loop
int main(int argc, char** argv) {
  glutInit(&argc, argv); // Intialize OpenGL using main function pointers
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // Set OpenGL display mode to single, RBG, and depth mode
  glutInitWindowSize(750, 750); // Set window size to 750 by 750, can be modified by user
  glutInitWindowPosition(0, 0); // Set window position to 0, 0; can be modified by user
  glutCreateWindow("Sierpinski Gasket Tetrahedron Example - by Andrew Esch & Evan Lee");
  glutDisplayFunc(display); // Load display function as register callback
  glutMainLoop(); // Run OpenGL as register callback until the user closes the window 
  glutReshapeFunc(reshape); // Initialize reshape function
  glutIdleFunc(generatePoints);
  init(); // Run initial function
  glutMainLoop(); // Run OpenGL as register callback until the user closes the window 
}
