#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>

void background(){
    //---------------------Walls+Floor----------------------------
    //Back left wall
    glColor3f(0.8431373f, 0.8156863f, 0.7529413f); 
    glBegin(GL_QUADS);
    glVertex3f(0.0f,67.0f, 0.0f);		//Bottom Left
    glVertex3f(0.0f,540.0f, 0.0f);		//Top Left
    glVertex3f(922.0f,540.0f, 0.0f);	//Top Right
    glVertex3f(889.0f,127.0f, 0.0f);	//Bottom Right

    //Back left strip
    glColor3f(0.1f, 0.1f, 0.1f); 
    glBegin(GL_QUADS);
    glVertex3f(0.0f,42.0f, 0.0f);		//Bottom Left
    glVertex3f(0.0f,67.0f, 0.0f);		//Top Left
    glVertex3f(889.0f,127.0f, 0.0f);	//Top Right
    glVertex3f(886.0f,107.0f, 0.0f);	//Bottom Right

    //Back right wall
    glColor3f(0.6431373f, 0.6156863f, 0.5529413f); 
    glBegin(GL_QUADS);
    glVertex3f(888.0f,127.0f, 0.0f);	//Bottom Left
    glVertex3f(919.0f,540.0f, 0.0f);	//Top Left
    glVertex3f(959.0f,540.0f, 0.0f);	//Top Right
    glVertex3f(959.0f,102.0f, 0.0f);	//Bottom Right

    //Back right strip
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(886.0f,107.0f, 0.0f);	//Bottom Left
    glVertex3f(889.0f,127.0f, 0.0f);	//Top Left
    glVertex3f(959.0f,102.0f, 0.0f);	//Top Right
    glVertex3f(959.0f,83.0f, 0.0f);		//Bottom Right

    //Floor left
    glColor3f(0.64f, 0.576f, 0.482f);
    glBegin(GL_QUADS);
    glVertex3f(0.0f,0.0f, 0.0f);	    //Bottom Left
    glVertex3f(0.0f,42.0f, 0.0f);   	//Top Left
    glVertex3f(886.0f,107.0f, 0.0f);	//Top Right
    glVertex3f(950.0f,0.0f, 0.0f);		//Bottom Right

    //Floor right
    glColor3f(0.64f, 0.576f, 0.482f);
    glBegin(GL_TRIANGLES);
    glVertex3f(950.0f,0.0f, 0.0f);		//Bottom
    glVertex3f(959.0f,83.0f, 0.0f);   	//Middle Right
    glVertex3f(886.0f,107.0f, 0.0f);	//Top
    glVertex3f(950.0f,0.0f, 0.0f);		//Bottom


}

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
    glVertex3f(708.0f,193.0f, 0.0f);	//Bottom Left
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
    glVertex3f(616.0f,129.0f, 0.0f);	//Bottom Left
    glVertex3f(619.0f,142.0f, 0.0f);	//Top Left
    glVertex3f(699.0f,137.0f, 0.0f);	//Top Right
    glVertex3f(696.0f,125.0f, 0.0f);	//Bottom Right

    //Darker Front of PS4
    glColor3f(0.02f, 0.02f, 0.02f); 
    glBegin(GL_QUADS);
    glVertex3f(616.0f,134.0f, 0.0f);	//Bottom Left
    glVertex3f(617.0f,136.0f, 0.0f);	//Top Left
    glVertex3f(696.0f,131.0f, 0.0f);	//Top Right
    glVertex3f(699.0f,129.0f, 0.0f);	//Bottom Right


    //Top of PS4
    glColor3f(0.02f, 0.02f, 0.02f); 
    glBegin(GL_QUADS);
    glVertex3f(618.0f,141.0f, 0.0f);	//Bottom Left
    glVertex3f(629.0f,158.0f, 0.0f);	//Top Left
    glVertex3f(707.0f,155.0f, 0.0f);	//Top Right
    glVertex3f(700.0f,137.0f, 0.0f);	//Bottom Right
    
    //Side of PS4
    glColor3f(0.1f, 0.1f, 0.1f); 
    //glColor3f(1.0f, 0.1f, 0.1f); 
    glBegin(GL_QUADS);
    glVertex3f(696.0f,125.0f, 0.0f);	//Bottom Left
    glVertex3f(698.0f,138.0f, 0.0f);	//Top Left
    glVertex3f(707.0f,155.0f, 0.0f);	//Top Right
    glVertex3f(707.0f,145.0f, 0.0f);	//Bottom Right
}

void infinityBox(){
    //---------------------Rack Infinity Box Object --------------------------------
    // Front Side
    glColor3f(0.1490196f, 0.1411765f, 0.2f); 
    glBegin(GL_QUADS);
    glVertex3f(302.0f,252.0f, 0.0f); //Bottom Left
    glVertex3f(300.0f,275.0f, 0.0f); //Top Left
    glVertex3f(400.0f,277.0f, 0.0f); //Top Right
    glVertex3f(400.0f,255.0f, 0.0f); //Bottom Right

    // Left Side
    glColor3f(0.5019608f, 0.4745098f, 0.4313726f); 
    glBegin(GL_QUADS);
    glVertex3f(298.0f,261.0f, 0.0f); //Bottom Left
    glVertex3f(297.0f,279.0f, 0.0f); //Top Left
    glVertex3f(301.0f,275.0f, 0.0f); //Top Right
    glVertex3f(302.0f,252.0f, 0.0f); //Bottom Right

    // Top Side
    glColor3f(0.9607844f, 0.937255f, 0.9215687f);
    glBegin(GL_QUADS);
    glVertex3f(298.0f,279.0f, 0.0f); //Bottom Left
    glVertex3f(388.0f,281.0f, 0.0f); //Top Left
    glVertex3f(400.0f,278.0f, 0.0f); //Top Right
    glVertex3f(300.0f,276.0f, 0.0f); //Bottom Right

    // Grey Tag on Box Top
    glColor3f(0.5647059f, 0.5254902f, 0.5058824f);
    glBegin(GL_QUADS);
    glVertex3f(313.0f,276.0f, 0.0f); //Bottom Left
    glVertex3f(310.0f,279.0f, 0.0f); //Top Left
    glVertex3f(320.0f,279.0f, 0.0f); //Top Right
    glVertex3f(324.0f,276.0f, 0.0f); //Bottom Right
}




void dumbells(){
    //---------------------Right Dumbbell Object --------------------------------
    // Dumbbell Back (top half)
    glColor3f(0.1607843f, 0.1411765f, 0.1411765f);
    glBegin(GL_QUADS);
    glVertex3f(263.0f+13.0f,264.0f+3.0f, 0.0f); //Bottom Left
    glVertex3f(215.0f+13.0f,266.0f+3.0f, 0.0f); //Top Left
    glVertex3f(227.0f+13.0f,281.0f+3.0f, 0.0f); //Top Right
    glVertex3f(251.0f+13.0f,280.0f+3.0f, 0.0f); //Bottom Right

    // Dumbbell Back (bottom half)
    glColor3f(0.1607843f, 0.1411765f, 0.1411765f);
    glBegin(GL_QUADS);
    glVertex3f(227.0f+13.0f,250.0f+3.0f, 0.0f); //Bottom Left
    glVertex3f(215.0f+13.0f,266.0f+3.0f, 0.0f); //Top Left
    glVertex3f(263.0f+13.0f,264.0f+3.0f, 0.0f); //Top Right
    glVertex3f(251.0f+13.0f,250.0f+3.0f, 0.0f); //Bottom Right

    // Dumbbell Front (top half)
    glColor3f(0.1921569f, 0.1882353f, 0.1803922f);
    glBegin(GL_QUADS);
    glVertex3f(263.0f,264.0f, 0.0f); //Bottom Left
    glVertex3f(215.0f,266.0f, 0.0f); //Top Left
    glVertex3f(227.0f,281.0f, 0.0f); //Top Right
    glVertex3f(251.0f,280.0f, 0.0f); //Bottom Right

    // Dumbbell Front (bottom half)
    glColor3f(0.1921569f, 0.1882353f, 0.1803922f);
    glBegin(GL_QUADS);
    glVertex3f(227.0f,250.0f, 0.0f); //Bottom Left
    glVertex3f(215.0f,266.0f, 0.0f); //Top Left
    glVertex3f(263.0f,264.0f, 0.0f); //Top Right
    glVertex3f(251.0f,250.0f, 0.0f); //Bottom Right

    // Dumbbell Front-Back Side (top)
    glColor3f(0.4509804f, 0.4470589f, 0.4156863f);
    glBegin(GL_QUADS);
    glVertex3f(227.0f,281.0f, 0.0f); //Bottom Left
    glVertex3f(236.0f,282.0f, 0.0f); //Top Left
    glVertex3f(256.0f,281.0f, 0.0f); //Top Right
    glVertex3f(251.0f,280.0f, 0.0f); //Bottom Right

    // Dumbbell Front-Back Side (middle)
    glColor3f(0.4509804f, 0.4470589f, 0.4156863f);
    glBegin(GL_QUADS);
    glVertex3f(263.0f,264.0f, 0.0f); //Bottom Left
    glVertex3f(251.0f,280.0f, 0.0f); //Top Left
    glVertex3f(255.0f,281.0f, 0.0f); //Top Right
    glVertex3f(267.0f,266.0f, 0.0f); //Bottom Right

    // Dumbbell Front-Back Side (bottom)
    glColor3f(0.172549f, 0.1686275f, 0.1607843f);
    glBegin(GL_QUADS);
    glVertex3f(249.0f,251.0f, 0.0f); //Bottom Left
    glVertex3f(263.0f,264.0f, 0.0f); //Top Left
    glVertex3f(267.0f,266.0f, 0.0f); //Top Right
    glVertex3f(256.0f,252.0f, 0.0f); //Bottom Right

    //---------------------Left Dumbbell Object --------------------------------
    // Dumbbell Back (top half)
    glColor3f(0.1921569f, 0.1568628f, 0.1529412f);
    glBegin(GL_QUADS);
    glVertex3f(159.0f+3.0f,263.0f+5.0f, 0.0f);	//Bottom Left
    glVertex3f(173.0f+3.0f,279.0f+5.0f, 0.0f);	//Top Left
    glVertex3f(197.0f+3.0f,280.0f+5.0f, 0.0f);	//Top Right
    glVertex3f(211.0f+3.0f,265.0f+5.0f, 0.0f);	//Bottom Right

    // Dumbbell Back (bottom half)
    glColor3f(0.1921569f, 0.1568628f, 0.1529412f);
    glBegin(GL_QUADS);
    glVertex3f(173.0f+3.0f,248.0f+5.0f, 0.0f);	//Bottom Left
    glVertex3f(159.0f+3.0f,263.0f+5.0f, 0.0f);	//Top Left
    glVertex3f(211.0f+3.0f,265.0f+5.0f, 0.0f);	//Top Right
    glVertex3f(200.0f+3.0f,248.0f+5.0f, 0.0f);	//Bottom Right

    // Dumbbell Front (top half)
    glColor3f(0.1921569f, 0.1882353f, 0.1803922f);
    glBegin(GL_QUADS);
    glVertex3f(159.0f,263.0f, 0.0f);	//Bottom Left
    glVertex3f(173.0f,279.0f, 0.0f);	//Top Left
    glVertex3f(197.0f,280.0f, 0.0f);	//Top Right
    glVertex3f(211.0f,265.0f, 0.0f);	//Bottom Right

    // Dumbbell Front (bottom half)
    glColor3f(0.1921569f, 0.1882353f, 0.1803922f);
    glBegin(GL_QUADS);
    glVertex3f(173.0f,248.0f, 0.0f);	//Bottom Left
    glVertex3f(159.0f,263.0f, 0.0f);	//Top Left
    glVertex3f(211.0f,265.0f, 0.0f);	//Top Right
    glVertex3f(200.0f,248.0f, 0.0f);	//Bottom Right

    // Dumbbell Front-Back Side (top)
    glColor3f(0.4117647f, 0.3921569f, 0.3529412f);
    glBegin(GL_QUADS);
    glVertex3f(173.0f,279.0f, 0.0f);	//Bottom Left
    glVertex3f(174.0f,281.0f, 0.0f);	//Top Left
    glVertex3f(199.0f,281.0f, 0.0f);	//Top Right
    glVertex3f(197.0f,279.0f, 0.0f);	//Bottom Right

    // Dumbbell Front-Back Side (middle)
    glColor3f(0.3882353f, 0.3764706f, 0.3647059f);
    glBegin(GL_QUADS);
    glVertex3f(198.0f,281.0f, 0.0f);	//Bottom Left
    glVertex3f(210.0f,269.0f, 0.0f);	//Top Left
    glVertex3f(210.0f,267.0f, 0.0f);	//Top Right
    glVertex3f(197.0f,279.0f, 0.0f);	//Bottom Right
}
