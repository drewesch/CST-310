#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>

void drawTV(){
    //TV screen border
    glColor3f(0.0f, 0.0f, 0.0f); 
    glBegin(GL_QUADS);
    glVertex3f(539.0f,199.0f, 0.0f);	//Bottom Left
    glVertex3f(542.0f,347.0f, 0.0f);	//Top Left	
    glVertex3f(922.0f,348.0f, 0.0f);	//Top Right
    glVertex3f(910.0f,188.0f, 0.0f);	//Bottom Right

    //TV screen
    glColor3f(0.25f, 0.25f, 0.25f); 
    glBegin(GL_QUADS);
    glVertex3f(543.0f,203.0f, 0.0f);	//Bottom Left
    glVertex3f(546.0f,343.0f, 0.0f);	//Top Left	
    glVertex3f(918.0f,344.0f, 0.0f);	//Top Right
    glVertex3f(906.0f,192.0f, 0.0f);	//Bottom Right

    //TV bottom light
    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_QUADS);
    glVertex3f(708.0f,192.0f, 0.0f);	//Bottom Left
    glVertex3f(708.0f,197.0f, 0.0f);	//Top Left
    glVertex3f(723.0f,196.0f, 0.0f);	//Top Right
    glVertex3f(723.0f,193.0f, 0.0f);	//Bottom Right
}

void drawTVStandTop(){
    //TV stand top
    glColor3f(0.153f, 0.149f, 0.133f); 
    glBegin(GL_QUADS);
    glVertex3f(545.0f,178.0f, 0.0f);	//Bottom Left
    glVertex3f(549.0f,201.0f, 0.0f);	//Top Left
    glVertex3f(871.0f,191.0f, 0.0f);	//Top Right
    glVertex3f(912.0f,167.0f, 0.0f);	//Bottom Right

    //TV stand front
    glColor3f(0.05f, 0.05f, 0.05f); 
    glBegin(GL_QUADS);
    glVertex3f(544.0f,175.0f, 0.0f);	//Bottom Left
    glVertex3f(544.0f,179.0f, 0.0f);	//Top Left
    glVertex3f(910.0f,168.0f, 0.0f);	//Top Right
    glVertex3f(910.0f,163.0f, 0.0f);	//Bottom Right
}

void drawTVStandMiddle(){
    //Middle TV stand top layer
    glColor3f(0.153f, 0.149f, 0.133f); 
    glBegin(GL_QUADS);
    glVertex3f(594.0f,125.0f, 0.0f);	//Bottom Left
    glVertex3f(590.0f,153.0f, 0.0f);	//Top Left
    glVertex3f(818.0f,145.0f, 0.0f);	//Top Right
    glVertex3f(854.0f,116.0f, 0.0f);	//Bottom Right
}

void drawTVStandLower(){
    //Lower TV stand top layer
    glColor3f(0.153f, 0.149f, 0.133f); 
    glBegin(GL_QUADS);
    glVertex3f(544.0f,60.0f, 0.0f);		//Bottom Left
    glVertex3f(550.0f,92.0f, 0.0f);		//Top Left
    glVertex3f(860.0f,81.0f, 0.0f);		//Top Right
    glVertex3f(900.0f,41.0f, 0.0f);		//Bottom Right
}

void drawPS4(){
    //Lighter Front of PS4
    glColor3f(0.2745f, 0.2745f, 0.2745f); 
    glBegin(GL_QUADS);
    glVertex3f(616.0f,127.0f, 0.0f);	//Bottom Left
    glVertex3f(617.0f,138.0f, 0.0f);	//Top Left
    glVertex3f(700.0f,136.0f, 0.0f);	//Top Right
    glVertex3f(701.0f,125.0f, 0.0f);	//Bottom Right

    //Darker Front of PS4
    glColor3f(0.02f, 0.02f, 0.02f); 
    glBegin(GL_QUADS);
    glVertex3f(616.0f,134.0f, 0.0f);	//Bottom Left
    glVertex3f(617.0f,136.0f, 0.0f);	//Top Left
    glVertex3f(701.0f,133.0f, 0.0f);	//Top Right
    glVertex3f(701.0f,131.0f, 0.0f);	//Bottom Right

    //Top of PS4
    glColor3f(0.02f, 0.02f, 0.02f); 
    glBegin(GL_QUADS);
    glVertex3f(616.0f,139.0f, 0.0f);	//Bottom Left
    glVertex3f(618.0f,158.0f, 0.0f);	//Top Left
    glVertex3f(700.0f,155.0f, 0.0f);	//Top Right
    glVertex3f(700.0f,137.0f, 0.0f);	//Bottom Right
}