#include <GL/glut.h>

void init(void) {
    glColor3f(1.0f, 1.0f, 1.0f);
}

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5,-0.5,0.0);
        glVertex3f(-0.5,0.5,0.0);
        glVertex3f(0.5,0.5,0.0);
        glVertex3f(0.5,-0.5,0.0);
    glEnd();
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(320,320);
    glutCreateWindow("GCU – My Rectangle");
    glutDisplayFunc(renderScene);
    init();
    glutMainLoop();
    return 0;
}