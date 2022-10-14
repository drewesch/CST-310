#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include <stdio.h>

#include "test.h"

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

                         glColor3f(0.0f, 1.0f, 0.02f); 
        glBegin(GL_QUADS);
        glVertex3f(-10.0f,-10.0f, 0.0f);	//Bottom Left
        glVertex3f(-10.0f,10.0f, 0.0f);	//Top Left
        glVertex3f(10.0f,10.0f, 0.0f);	//Top Right
        glVertex3f(10.0f,-10.0f, 0.0f);	//Bottom Right
        glEnd();
        glColor3f(1.0f,1.0f,1.0f);

        // glRotatef(_angle, 0.0, 1.0, 0.0);
        // glBegin(GL_QUADS);  // Wall
        //     glTexCoord3f(-1.0,1.0,0.1);  glVertex3f(-5,0,1);
        //     glTexCoord3f(0,1.0,0.1);  glVertex3f(0,0,1);
        //     glTexCoord3f(0.0,0.0,0.1);  glVertex3f(0,-1.5,1);
        //     glTexCoord3f(-1.0,0.0,0.1);  glVertex3f(-5,-1.5,1);
        // glEnd();


        

        
    glPopMatrix();

    //glDisable(GL_TEXTURE_2D);
    

    //glutSwapBuffers();
    glFlush();
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

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR); 

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
    gluOrtho2D(0.0, (GLdouble)1000, 0.0, (GLdouble)700);
    //glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);

    _textureBrick = loadTex("./TVSCREEN.PNG");
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(600,600);
    glutCreateWindow("Textured House");
    //glEnable(GL_DEPTH_TEST);

    glutReshapeFunc(resize);
    glutSpecialFunc(mySpecialFunc);
    glutDisplayFunc(renderScene);
    Initialize();

    glutMainLoop();

    return 0;
}