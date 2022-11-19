
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <cmath>
#include <iostream>
#include "objects.h"

using namespace std;
const int screenWidth = 950;	   // width of screen window in pixels 
const int screenHeight = 800;	   // height of screen window in pixels
GLdouble A, B, C, D;               // values used for scaling and shifting
GLuint _textureEnemy;					// value for storing TV texture
GLuint _textureSpaceship;				// value for storing floor texture
GLfloat xShip = 50;
int laserNum = 0;


const int NUM_OF_STARS = 50;
int starX[NUM_OF_STARS];
int starY[NUM_OF_STARS];
int starW[NUM_OF_STARS];
int starH[NUM_OF_STARS];


// Function call to load textures using SOIL and shaders
GLuint loadTex(const char* texname)
{
	// Format the texture for GLU and SOIL
	GLuint texture = SOIL_load_OGL_texture
                    (
                        texname,
                        SOIL_LOAD_AUTO,
                        SOIL_CREATE_NEW_ID,
                        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT

                    );

	// If the teexture does not exist
    if( 0 == texture )
    {
        printf( "SOIL loading error: '%s'\n", SOIL_last_result() ); // Throw a loading error
    }

	// Bind texture to a GL shader
    glBindTexture(GL_TEXTURE_2D, texture);

	// Set Texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Initialize the texture using polygons and complete color
    glColor3f (1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    
	// Set the texture vertexes and coordinates  
    glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f); // Bottom left
    glTexCoord2f(1.0f, 0.0f); glVertex2f(1.0f, 0.0f); // Top left
    glTexCoord2f(1.0f, 1.0f); glVertex2f(1.0f, 1.0f); // Top right
    glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 1.0f); // Bottom right

	// End texture
    glEnd();   
    glDisable(GL_TEXTURE_2D);

	// Return completed texture using SOIL and shaders
    return texture;
}

class Laser {
    float xpos;
    float ypos;
    float velocity = 5.0f;

    public:
        Laser() {}
        Laser(float x, float y): xpos(x), ypos(y){}
        ~Laser(){}
    
    void drawLaser(){
        glColor3f(.8,.1,.1);
        glPushMatrix();
        
        glBegin(GL_QUADS);
            glVertex3f(xpos-3, ypos-8, 0); //bottom left
            glVertex3f(xpos-3, ypos+8, 0); //top left
            glVertex3f(xpos+3, ypos+8, 0); //top right
            glVertex3f(xpos+3, ypos-8, 0);   //bottom right
        glEnd();
        glPopMatrix();

        ypos += velocity;
        
    }

    int laserCollision(float xEnemy[12], float yEnemy[12]){
        //cout << ypos << endl;
        for (int i = 0; i< 12; i++){
            if(xpos >= xEnemy[i] + 100.0f && xpos <= xEnemy[i] + 150.0f){ //if xposition of laser alligns with enemy width 
                                                                          //and yposition of laser alligns with enemy height
                if (ypos >= yEnemy[i] + 700.0f && ypos <= yEnemy[i]+ 750.0f){
                    cout << "X-COLLISION and Y-COLLISION!" << endl;
                return i;
                }
                
            }
        
        }
        return -1;

    }


};

Laser laserArr[5]; //create a array to hold laser objects
float enemyXPosArr[12] = {-50.0, 150.0, 350.0, 550.0, 750.0, 50.0, 250.0, 450.0, 650.0, 150.0, 350.0, 550.0};
float enemyYPosArr[12] = {0.0, 0.0, 0.0, 0.0, 0.0, -100.0, -100.0, -100.0, -100.0, -200.0, -200.0, -200.0};
float gamePosX = 0.0;
int isRedScreen = 0;
float redColor = 0.05;
float greenColor = 0.05;

//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
 void myInit(void)
 {
    glClearColor(1.0,1.0,1.0,0.0);       // background color is white
    glColor3f(0.0f, 0.0f, 0.0f);         // drawing color is black 
    glPointSize(2.0);		         // a 'dot' is 2 by 2 pixels
    glMatrixMode(GL_PROJECTION); 	 // set "camera shape"
    glLoadIdentity();
	glOrtho(0, (GLdouble)screenWidth, 0, (GLdouble)screenHeight, -1.0, 10.0);
    
	//gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
		 A = screenWidth / 4.0; // set values used for scaling and shifting
		 B = 0.0;
		 C = D = screenHeight / 2.0;
	_textureEnemy = loadTex("./enemy.png"); // load TV screen texture
	_textureSpaceship = loadTex("./spaceship.png"); // load floor texture
    
    srand(time(0));
	for(int i = 0; i < NUM_OF_STARS; i++){
		starX[i] = rand()%screenWidth;
		starY[i] = rand()%screenHeight;
	    starW[i] = rand()%3;
		starH[i] = rand()%3;
    }
    
}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // clear the screen 
	

    //---------------------Background--------------------------------

    glColor3f(redColor,0.05f,0.05f);
    glBegin(GL_QUADS);
        glVertex3f(0.0f,0.0f, 0.0f);	            //Bottom Left
        glVertex3f(0.0f,screenHeight, 0.0f);	    //Top Left
        glVertex3f(screenWidth,screenHeight, 0.0f);	//Top Right
        glVertex3f(screenWidth,0.0f, 0.0f);	        //Bottom Right
    glEnd();

    //------------------------------------------------------------------

    // Create Swarm of Enemy Spaceship Objects
    for (int i = 0; i < 12; i++) {
        
        createEnemy(_textureEnemy,enemyXPosArr[i],enemyYPosArr[i]);
    }


//createEnemy(_textureEnemy,500,500);
createShip(_textureSpaceship,xShip);

for (int i = 0; i < laserNum; i++){
    laserArr[i].drawLaser();
    int enemyIndexHit = laserArr[i].laserCollision(enemyXPosArr,enemyYPosArr);
    if ( enemyIndexHit != -1){
        enemyYPosArr[enemyIndexHit] -= 10000;
    }
}
drawStars(starX,starY,starW,starH);

		
		


//--------------------------------------------------

	glFlush();
	glutSwapBuffers();		   // send all output to display 
}

// Handle camera movement using arrow key inputs
void shipMovement(int key, int x, int y){
    switch (key) {
    case GLUT_KEY_RIGHT:
		// Move camera to the right, forces all matrix calculations to move correspondingly
		if(xShip <= screenWidth/2 + 15){
            xShip += 15.0f;
        }
        break;
    case GLUT_KEY_LEFT:
		// Move camera to the left, forces all matrix calculations to move correspondingly
		if(xShip >= -(screenWidth/2) + 85){
            xShip -= 15.0f;
        }
        break;
	}
    glutPostRedisplay();
}

void update(int value)
{
    // Update enemy game position variable
    gamePosX += 0.04;

    // Update all enemy spaceship positions
    for (int i = 0; i < 12; i++) {
        // Move enemies and right and left continuously
        // Use the cosine function to generate this movement mathematically
        float newPos = 5*cos(gamePosX);
        enemyXPosArr[i] += newPos;

        // Move enemies down over time, until they reach a certain point
        enemyYPosArr[i] -= 0.4;

        // If they reach the bottom limit, send the enemy spaceship to the top of the screen
        if (enemyYPosArr[i] < -550.0 && enemyYPosArr[i] > -850.0) {
            // If this is the first time an enemy hits the bottom, turn on red screen
            if (!isRedScreen) {
                isRedScreen = 1;
                printf("Game over!\n");
                redColor = 1;
            }
        }
    }

        for(int i = 0; i < NUM_OF_STARS; i++){
		starY[i]--;
        if (starY[i] < 0){
            starY[i] += 900;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(25,update,0);
}


void special(unsigned char key, int, int) {
  switch (key) {
    case 's': laserArr[laserNum] = Laser(425+xShip,155.0f); laserNum++; break;
  }
  
  glutPostRedisplay();
}


//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("Andrew and Evan's Galiga"); // open the screen window
	glutDisplayFunc(myDisplay);     // register redraw function
	glutSpecialFunc(shipMovement); // Handle GLUT keys for special inputs
    glutKeyboardFunc(special);
	glutTimerFunc(25,update,0);
	myInit();						// Call init function            
	glutMainLoop(); 		     // go into a perpetual loop
}