#include<GL/gl.h>
#include<GL/glu.h>
#include <GL/glut.h>

void init()
{
    glClearColor(0.0,0.0,0.0,1.0);
    glEnable(GL_DEPTH_TEST); //  Enables Depth Testing
}

float angle = 30.0;

void drawPyramid(float x, float y, float c1, float c2, float c3)
{
    glColor3f(c1, c2, c3);
    glBegin(GL_QUADS); // Turns 4 consecutive Vertices into a single quadrilateral
    glVertex3f(0.0 + x, 0.0 + y, 0.0);
    glVertex3f(0.0 + x, 0.0 + y, 1.0);
    glVertex3f(1.0 + x, 0.0 + y, 1.0);
    glVertex3f(1.0 + x, 0.0 + y, 0.0);
    glEnd();

    // Front face
    glColor3f(c1, c2, c3);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0 + x, 0.0 + y, 0.0);
    glVertex3f(0.5 + x, 1.0 + y, 0.5);
    glVertex3f(1.0 + x, 0.0 + y, 0.0);

    // Left side face
    glColor3f(c1, c2, c3);
    glVertex3f(0.0 + x, 0.0 + y, 0.0);
    glVertex3f(0.5 + x, 1.0 + y, 0.5);
    glVertex3f(0.0 + x, 0.0 + y, 1.0);

    // Right side face
    glColor3f(c1, c2, c3);
    glVertex3f(1.0 + x, 0.0 + y, 0.0);
    glVertex3f(0.5 + x, 1.0 + y, 0.5);
    glVertex3f(1.0 + x, 0.0 + y, 1.0);

    // Back face
    glColor3f(c1, c2, c3);
    glVertex3f(0.0 + x, 0.0 + y, 1.0);
    glVertex3f(0.5 + x, 1.0 + y, 0.5);
    glVertex3f(1.0 + x, 0.0 + y, 1.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // These 2 Flags Clears the frame buffer and depth Buffer
    glLoadIdentity(); // Resets Previous Frame

    glTranslatef(-1.0,-3.0,-10.0); //Here origin -8.0 is far away from the camera so that we can see
    // glRotatef(angle, 0.0, 1.0, 0.0);
    //draw

    drawPyramid(0.5, 0.5, 1.0, 0.0, 0.0);
    drawPyramid(2.0, 0.5, 0.0, 1.0, 0.0);
    drawPyramid(3.5, 0.5, 0.0, 0.0, 1.0);

    glEnd();

    glutSwapBuffers();
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

void timer(int)
{
    glutPostRedisplay(); // OpenGL will call the display function
    glutTimerFunc(1000/60,timer,0); // Every 1/60th of second we need to call the function. Peridically it'll call itself

    angle+=0.8; // control the speed of rotation
    if(angle>360.0)
        angle=angle-360.0; //For handling overflow
}

// Handle camera movement using arrow key inputs
void cameraMovement(int key, int x, int y){
	float move = 10.0f;
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

int main(int argc, char**argv)
{
    glutInit(&argc, argv); // Glut Initialization
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); //Display Mode Initialization

    glutInitWindowPosition(200,100); // Determines Window Position
    glutInitWindowSize(500,500); // Determines the Size of the Window
    glutCreateWindow("Pyramid Example"); // Creates Window Named 3D Cube Rotation

    glutDisplayFunc(display); // Visualizes anything drawn on the display function. Callback Function
    glutSpecialFunc(cameraMovement); // Handle GLUT keys for special inputs
    glutReshapeFunc(reshape); // Viewport Callback function. Whenever Window is reshaped this function is called
    glutTimerFunc(0,timer,0);
    init();
    glutMainLoop(); // Keeps the program running

}