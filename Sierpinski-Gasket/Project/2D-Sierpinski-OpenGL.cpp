/*
Project 1: Sierpinski Gasket - Example 1 (2D Gasket)

Authors: Andrew Esch and Evan Lee

Date: 9/11/2022
*/

#ifdef __APPLE_CC__
#include <GLUT/glut.h> // If using MAC/UNIX architecture, import GLUT/glut.h
#else
#include <GL/glut.h> // if using other architecutres, import GL/glut.h
#endif
#include <cstdlib> // Import cstdlib


// Define a 2D point struct to reference x and y coordinates
struct Point {
  GLfloat x, y; // Define GLfloat coordinate variables
  Point(GLfloat x = 0, GLfloat y = 0): x(x), y(y) {} // Set coordinates to 0 by default
  Point midpoint(Point p) {return Point((x + p.x) / 2.0, (y + p.y) / 2.0);} // Encapsulate a midpoint function for x and y
};

// Main program display function
// Draws the Sierpinski Gasket with a finite number of points
void display() {

  glClear(GL_COLOR_BUFFER_BIT); // Clear color buffer bit

  static Point vertices[] = {Point(100, 100), Point(250, 500), Point(400, 100)}; // Create a random set of points within the window, this is the verticies for the main triangle

  // Compute and plot 100000 new points of the Sierpinski Gasket
  static Point p = vertices[0]; // Set the initial value as an arbitary vertice (use index 0, 1, or 2)
  glBegin(GL_POINTS); // Begin plotting in OpenGL
  for (int k = 0; k < 100000; k++) {
    p = p.midpoint(vertices[rand() % 3]); // Choose a random vertice and find the midpoint between current initial value and the chosen vertice
    glVertex2f(p.x, p.y); // Plot the vertice in OpenGL
  }
  glEnd(); // End plotting
  glFlush(); // Flush OpenGL points
}

// Initial program setup function for application-specific integrations
void init() {

  glClearColor(0.25, 0.0, 0.2, 1.0); // Set a deep purple background in OpenGL
  glColor3f(0.6, 1.0, 0.0); // Draw the Sierpinski Gasket using yellow color.

  // Set up the viewing volume: 500 x 500 x 1 window with origin lower left.
  glMatrixMode(GL_PROJECTION); // Set the projection mode as orthographic
  glLoadIdentity(); // Load identity matrix
  glOrtho(0.0, 500.0, 0.0, 500.0, 0.0, 1.0); // Set orthographic plane
}

// Initialize GLUT and OpenGL for main loop
int main(int argc, char** argv) {
  glutInit(&argc, argv); // Intialize OpenGL using main function pointers
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); // Set OpenGL display mode to single and RBG
  glutInitWindowSize(750, 750); // Set window size to 750 by 750, can be modified by user
  glutInitWindowPosition(0, 0); // Set window position to 0, 0; can be modified by user
  glutCreateWindow("2D Sierpinski Gasket Example - by Andrew Esch & Evan Lee"); // Set window title
  glutDisplayFunc(display); // Load display function as register callback
  init(); // Run initial function
  glutMainLoop(); // Run OpenGL as register callback until the user closes the window 
}
