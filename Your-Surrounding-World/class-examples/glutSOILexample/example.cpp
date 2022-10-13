#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include <stdio.h>

float _angle = 0.0;
GLuint _textureBrick;

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void renderScene(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);

    // Front side brick wall
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR); 
        glTranslatef(0,0,-6);
        glRotatef(_angle, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(-50.0,2.0,0.1);  glVertex3f(-50,0,1);
            glTexCoord3f(50.0,2.0,0.1);  glVertex3f(50,0,1);
            glTexCoord3f(50.0,0.0,0.1);  glVertex3f(50,-1.5,1);
            glTexCoord3f(-50.0,0.0,0.1);  glVertex3f(-50,-1.5,1);
        glEnd();
    glPopMatrix();

    glutSwapBuffers();
}

void mySpecialFunc(int key, int x, int y){
    switch (key) {
    case GLUT_KEY_RIGHT:
        _angle += 1;
        if (_angle > 360) _angle = 0.0;
        break;
    case GLUT_KEY_LEFT:
        _angle -= 1;
        if (_angle > 360) _angle = 0.0;
        break;
    }
    glutPostRedisplay();
}

GLuint loadTex(const char* texname)
{
    GLuint texture = SOIL_load_OGL_texture
                    (
                        texname,
                        SOIL_LOAD_AUTO,
                        SOIL_CREATE_NEW_ID,
                        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT

                    );

    if( 0 == texture )
    {
        printf( "SOIL loading error: '%s'\n", SOIL_last_result() );
    }

    glBindTexture(GL_TEXTURE_2D, texture);

    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR); 

    glColor3f (1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    
    glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex2f(1.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex2f(1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 1.0f);

    glEnd();   
    glDisable(GL_TEXTURE_2D);

    return texture;
}

void Initialize() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);

    _textureBrick = loadTex("/home/droo/CST-310/Your-Surrounding-World/class-examples/glutSOILexample/TVSCREEN.PNG");
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(600,600);
    glutCreateWindow("Textured House");
    // glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    glutReshapeFunc(resize);
    glutSpecialFunc(mySpecialFunc);
    glutDisplayFunc(renderScene);
    Initialize();

    glutMainLoop();

    return 0;
}