#include <math.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>

#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

#include <iostream>

// Other includes
#include "Shader.h"


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
    glColor3f(0.20f, 0.20f, 0.20f); 
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
    glColor3f(0.15f, 0.15f, 0.15f);
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
    glEnd();
}

void drawRackBackStands() {
    //---------Left Back Rack Stand---------
    // Stand Leg
    glColor3f(0.1607843f, 0.1411765f, 0.1294118f); 
    glBegin(GL_QUADS);
    glVertex3f(129.0f,49.0f, 0.0f);	//Bottom Left
    glVertex3f(108.0f,377.0f, 0.0f);	//Top Left
    glVertex3f(114.0f,377.0f, 0.0f);	//Top Right
    glVertex3f(134.0f,51.0f, 0.0f);	//Bottom Right

    // Bottom Tab
    glColor3f(0.1019608f, 0.08627451f, 0.09019608f); 
    glBegin(GL_QUADS);
    glVertex3f(127.0f,60.0f, 0.0f);	//Bottom Left
    glVertex3f(125.0f,71.0f, 0.0f);	//Top Left
    glVertex3f(135.0f,72.0f, 0.0f);	//Top Right
    glVertex3f(135.0f,61.0f, 0.0f);	//Bottom Right

    // Next Tab Up
    glColor3f(0.1019608f, 0.08627451f, 0.09019608f); 
    glBegin(GL_QUADS);
    glVertex3f(120.0f,162.0f, 0.0f);	//Bottom Left
    glVertex3f(120.0f,171.0f, 0.0f);	//Top Left
    glVertex3f(129.0f,172.0f, 0.0f);	//Top Right
    glVertex3f(129.0f,163.0f, 0.0f);	//Bottom Right


    // Next Tab Up
    glColor3f(0.1019608f, 0.08627451f, 0.09019608f); 
    glBegin(GL_QUADS);
    glVertex3f(113.0f,247.0f, 0.0f);	//Bottom Left
    glVertex3f(112.0f,258.0f, 0.0f);	//Top Left
    glVertex3f(125.0f,258.0f, 0.0f);	//Top Right
    glVertex3f(125.0f,246.0f, 0.0f);	//Bottom Right

    // Top Tab
    glColor3f(0.1019608f, 0.08627451f, 0.09019608f); 
    glBegin(GL_QUADS);
    glVertex3f(108.0f,343.0f, 0.0f);	//Bottom Left
    glVertex3f(108.0f,354.0f, 0.0f);	//Top Left
    glVertex3f(117.0f,354.0f, 0.0f);	//Top Right
    glVertex3f(118.0f,343.0f, 0.0f);	//Bottom Right


    //---------Right Back Rack Stand---------
    // Stand Leg
    glColor3f(0.1607843f, 0.1411765f, 0.1294118f); 
    glBegin(GL_QUADS);
    glVertex3f(407.0f,70.0f, 0.0f);	//Bottom Left
    glVertex3f(401.0f,372.0f, 0.0f);	//Top Left
    glVertex3f(407.0f,372.0f, 0.0f);	//Top Right
    glVertex3f(414.0f,71.0f, 0.0f);	//Bottom Right
    
    // Bottom Tab
    glColor3f(0.08235294f, 0.07843138f, 0.07058824f); 
    glBegin(GL_QUADS);
    glVertex3f(406.0f,84.0f, 0.0f);	//Bottom Left
    glVertex3f(405.0f,95.0f, 0.0f);	//Top Left
    glVertex3f(414.0f,96.0f, 0.0f);	//Top Right
    glVertex3f(414.0f,83.0f, 0.0f);	//Bottom Right

    // Next Tab Up
    glColor3f(0.08235294f, 0.07843138f, 0.07058824f); 
    glBegin(GL_QUADS);
    glVertex3f(406.0f,174.0f, 0.0f);	//Bottom Left
    glVertex3f(405.0f,184.0f, 0.0f);	//Top Left
    glVertex3f(412.0f,184.0f, 0.0f);	//Top Right
    glVertex3f(412.0f,173.0f, 0.0f);	//Bottom Right

    // Next Tab Up
    glColor3f(0.08235294f, 0.07843138f, 0.07058824f); 
    glBegin(GL_QUADS);
    glVertex3f(403.0f,253.0f, 0.0f);	//Bottom Left
    glVertex3f(404.0f,264.0f, 0.0f);	//Top Left
    glVertex3f(410.0f,264.0f, 0.0f);	//Top Right
    glVertex3f(411.0f,254.0f, 0.0f);	//Bottom Right

    // Top Tab
    glColor3f(0.08235294f, 0.07843138f, 0.07058824f); 
    glBegin(GL_QUADS);
    glVertex3f(401.0f,342.0f, 0.0f);	//Bottom Left
    glVertex3f(401.0f,351.0f, 0.0f);	//Top Left
    glVertex3f(408.0f,352.0f, 0.0f);	//Top Right
    glVertex3f(408.0f,342.0f, 0.0f);	//Bottom Right
    glEnd();
}

void drawRackBackLines() {
    
        //---------Next Row Up---------
    // Front Lines
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(123.0f,142.0f-78.0f, 0.0f);	//Top Right
    glVertex3f(413.0f,160.0f-78.0f, 0.0f);	//Bottom Right
    glVertex3f(123.0f,149.0f-78.0f, 0.0f);	//Bottom Left
    glVertex3f(413.0f,166.0f-78.0f, 0.0f);	//Top Left
    glEnd();


    // Cascading Lines (from left to right)
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex3f(124.0f,143.0f-78.0f, 0.0f);	//Bottom Right
    glVertex3f(145.0f,149.0f-78.0f, 0.0f);	//Bottom Left
    glVertex3f(158.0f,145.0f-78.0f, 0.0f);	//Top Left
    glVertex3f(169.0f,151.0f-78.0f, 0.0f);	//Top Right
    glVertex3f(181.0f,145.0f-78.0f, 0.0f);	//Bottom Right
    glVertex3f(194.0f,152.0f-78.0f, 0.0f);	//Bottom Left
    glVertex3f(205.0f,148.0f-78.0f, 0.0f);	//Top Left
    glVertex3f(217.0f,153.0f-78.0f, 0.0f);	//Top Right
    glVertex3f(229.0f,149.0f-78.0f, 0.0f);	//Bottom Right
    glVertex3f(240.0f,154.0f-78.0f, 0.0f);	//Bottom Left
    glVertex3f(251.0f,150.0f-78.0f, 0.0f);	//Top Left
    glVertex3f(263.0f,156.0f-78.0f, 0.0f);	//Top Right
    glVertex3f(273.0f,152.0f-78.0f, 0.0f);	//Bottom Right
    glVertex3f(284.0f,157.0f-78.0f, 0.0f);	//Bottom Left
    glVertex3f(296.0f,153.0f-78.0f, 0.0f);	//Top Left
    glVertex3f(306.0f,159.0f-78.0f, 0.0f);	//Top Right
    glVertex3f(318.0f,155.0f-78.0f, 0.0f);	//Bottom Right
    glVertex3f(328.0f,160.0f-78.0f, 0.0f);	//Bottom Left
    glVertex3f(338.0f,155.0f-78.0f, 0.0f);	//Top Left
    glVertex3f(349.0f,160.0f-78.0f, 0.0f);	//Top Right
    glVertex3f(359.0f,157.0f-78.0f, 0.0f);	//Bottom Right
    glVertex3f(370.0f,161.0f-78.0f, 0.0f);	//Bottom Left
    glVertex3f(380.0f,157.0f-78.0f, 0.0f);	//Top Left
    glVertex3f(390.0f,163.0f-78.0f, 0.0f);	//Top Right
    glVertex3f(407.0f,160.0f-78.0f, 0.0f);	//Bottom Right
    glEnd();
    
   
    //---------Next Row Up---------
    // Front Lines
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(123.0f,142.0f+20.0f, 0.0f);	//Top Right
    glVertex3f(413.0f,160.0f+20.0f, 0.0f);	//Bottom Right
    glVertex3f(120.0f,149.0f+20.0f, 0.0f);	//Bottom Left
    glVertex3f(413.0f,166.0f+20.0f, 0.0f);	//Top Left
    glEnd();


    // Cascading Lines (from left to right)
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex3f(124.0f,143.0f+20.0f, 0.0f);	//Bottom Right
    glVertex3f(145.0f,149.0f+20.0f, 0.0f);	//Bottom Left
    glVertex3f(158.0f,145.0f+20.0f, 0.0f);	//Top Left
    glVertex3f(169.0f,151.0f+20.0f, 0.0f);	//Top Right
    glVertex3f(181.0f,145.0f+20.0f, 0.0f);	//Bottom Right
    glVertex3f(194.0f,152.0f+20.0f, 0.0f);	//Bottom Left
    glVertex3f(205.0f,148.0f+20.0f, 0.0f);	//Top Left
    glVertex3f(217.0f,153.0f+20.0f, 0.0f);	//Top Right
    glVertex3f(229.0f,149.0f+20.0f, 0.0f);	//Bottom Right
    glVertex3f(240.0f,154.0f+20.0f, 0.0f);	//Bottom Left
    glVertex3f(251.0f,150.0f+20.0f, 0.0f);	//Top Left
    glVertex3f(263.0f,156.0f+20.0f, 0.0f);	//Top Right
    glVertex3f(273.0f,152.0f+20.0f, 0.0f);	//Bottom Right
    glVertex3f(284.0f,157.0f+20.0f, 0.0f);	//Bottom Left
    glVertex3f(296.0f,153.0f+20.0f, 0.0f);	//Top Left
    glVertex3f(306.0f,159.0f+20.0f, 0.0f);	//Top Right
    glVertex3f(318.0f,155.0f+20.0f, 0.0f);	//Bottom Right
    glVertex3f(328.0f,160.0f+20.0f, 0.0f);	//Bottom Left
    glVertex3f(338.0f,155.0f+20.0f, 0.0f);	//Top Left
    glVertex3f(349.0f,160.0f+20.0f, 0.0f);	//Top Right
    glVertex3f(359.0f,157.0f+20.0f, 0.0f);	//Bottom Right
    glVertex3f(370.0f,161.0f+20.0f, 0.0f);	//Bottom Left
    glVertex3f(380.0f,157.0f+20.0f, 0.0f);	//Top Left
    glVertex3f(390.0f,163.0f+20.0f, 0.0f);	//Top Right
    glVertex3f(407.0f,160.0f+20.0f, 0.0f);	//Bottom Right
    glEnd();

    
    //---------Next Row Up---------
    // Front Lines
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(110.0f,241.0f+8.0f, 0.0f);	//Top Right
    glVertex3f(408.0f,249.0f+8.0f, 0.0f);	//Bottom Right
    glVertex3f(114.0f,247.0f+8.0f, 0.0f);	//Bottom Left
    glVertex3f(410.0f,255.0f+8.0f, 0.0f);	//Top Left
    glEnd();


    // Cascading Lines (from left to right)
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex3f(109.0f,242.0f+8.0f, 0.0f);	//Top Right
    glVertex3f(115.0f,246.0f+8.0f, 0.0f);	//Bottom Right
    glVertex3f(129.0f,241.0f+8.0f, 0.0f);	//Bottom Left
    glVertex3f(140.0f,247.0f+8.0f, 0.0f);	//Top Left
    glVertex3f(153.0f,242.0f+8.0f, 0.0f);	//Top Right
    glVertex3f(165.0f,247.0f+8.0f, 0.0f);	//Bottom Right
    glVertex3f(177.0f,243.0f+8.0f, 0.0f);	//Bottom Left
    glVertex3f(189.0f,248.0f+8.0f, 0.0f);	//Top Left
    glVertex3f(202.0f,244.0f+8.0f, 0.0f);	//Top Right
    glVertex3f(212.0f,249.0f+8.0f, 0.0f);	//Bottom Right
    glVertex3f(225.0f,244.0f+8.0f, 0.0f);	//Bottom Left
    glVertex3f(235.0f,250.0f+8.0f, 0.0f);	//Top Left
    glVertex3f(247.0f,244.0f+8.0f, 0.0f);	//Top Right
    glVertex3f(259.0f,250.0f+8.0f, 0.0f);	//Bottom Right
    glVertex3f(271.0f,245.0f+8.0f, 0.0f);	//Bottom Left
    glVertex3f(281.0f,251.0f+8.0f, 0.0f);	//Top Left
    glVertex3f(293.0f,246.0f+8.0f, 0.0f);	//Top Right
    glVertex3f(303.0f,251.0f+8.0f, 0.0f);	//Bottom Right
    glVertex3f(315.0f,247.0f+8.0f, 0.0f);	//Bottom Left
    glVertex3f(325.0f,251.0f+8.0f, 0.0f);	//Top Left
    glVertex3f(336.0f,247.0f+8.0f, 0.0f);	//Top Right
    glVertex3f(348.0f,253.0f+8.0f, 0.0f);	//Bottom Right
    glVertex3f(357.0f,248.0f+8.0f, 0.0f);	//Bottom Left
    glVertex3f(369.0f,253.0f+8.0f, 0.0f);	//Top Left
    glVertex3f(378.0f,248.0f+8.0f, 0.0f);	//Top Right
    glVertex3f(389.0f,254.0f+8.0f, 0.0f);	//Bottom Right
    glVertex3f(398.0f,249.0f+8.0f, 0.0f);	//Bottom Left
    glVertex3f(409.0f,254.0f+8.0f, 0.0f);	//Top Left
    glVertex3f(411.0f,249.0f+8.0f, 0.0f);	//Top Right
    glEnd();
    
}

void drawRackMiddleLines() {
    glBegin(GL_LINES);
    
    //vertical lines
    glVertex3f(130.0f,71.0f, 0.0f);	//Bottom Left
    glVertex3f(102.0f,29.0f, 0.0f);	//Top Left

    glVertex3f(161.0f,73.0f, 0.0f);	//Top Right
    glVertex3f(141.0f,32.0f, 0.0f);	//Bottom Right

    glVertex3f(240.0f,80.0f, 0.0f);	//Bottom Left
    glVertex3f(233.0f,41.0f, 0.0f);	//Top Left

    glVertex3f(314.0f,87.0f, 0.0f);	//Top Right
    glVertex3f(320.0f,49.0f, 0.0f);	//Bottom Right

    glVertex3f(387.0f,93.0f, 0.0f);	//Bottom Left
    glVertex3f(401.0f,59.0f, 0.0f);	//Top Left

    glVertex3f(124.0f,171.0f, 0.0f);	//Top Right
    glVertex3f(101.0f,147.0f, 0.0f);	//Bottom Right

    glVertex3f(154.0f,172.0f, 0.0f);	//Bottom Left
    glVertex3f(135.0f,148.0f, 0.0f);	//Top Left

    glVertex3f(236.0f,175.0f, 0.0f);	//Top Right
    glVertex3f(229.0f,155.0f, 0.0f);	//Bottom Right

    glVertex3f(312.0f,180.0f, 0.0f);	//Bottom Left
    glVertex3f(316.0f,158.0f, 0.0f);	//Top Left

    glVertex3f(383.0f,183.0f, 0.0f);	//Top Right
    glVertex3f(399.0f,163.0f, 0.0f);	//Bottom Right

    glVertex3f(410.0f,185.0f, 0.0f);	//Bottom Left
    glVertex3f(428.0f,163.0f, 0.0f);	//Top Left

    glVertex3f(121.0f,257.0f, 0.0f);	//Top Right
    glVertex3f(93.0f,247.0f, 0.0f);	//Bottom Right

    glVertex3f(407.0f,262.0f, 0.0f);	//Bottom Left
    glVertex3f(427.0f,250.0f, 0.0f);	//Top Left

    //bottom horizontal lines
    glVertex3f(112.0f,35.0f, 0.0f);	//Top Left
    glVertex3f(425.0f,67.0f, 0.0f);	//Top Right

    glVertex3f(112.0f,40.0f, 0.0f);	//Top Left
    glVertex3f(425.0f,72.0f, 0.0f);	//Top Right

    glVertex3f(112.0f,45.0f, 0.0f);	//Top Left
    glVertex3f(425.0f,77.0f, 0.0f);	//Top Right

    glVertex3f(112.0f,50.0f, 0.0f);	//Top Left
    glVertex3f(425.0f,82.0f, 0.0f);	//Top Right

    glVertex3f(112.0f,55.0f, 0.0f);	//Top Left
    glVertex3f(425.0f,87.0f, 0.0f);	//Top Right


    //lower middle horizontal lines
    glVertex3f(108.0f,153.0f, 0.0f);	//Bottom Left
    glVertex3f(421.0f,169.0f, 0.0f);	//Top Left
    
    glVertex3f(112.0f,157.0f, 0.0f);	//Bottom Left
    glVertex3f(420.0f,172.0f, 0.0f);	//Top Left
    
    glVertex3f(112.0f,160.0f, 0.0f);	//Bottom Left
    glVertex3f(419.0f,176.0f, 0.0f);	//Top Left

    glVertex3f(114.0f,163.0f, 0.0f);	//Bottom Left
    glVertex3f(417.0f,179.0f, 0.0f);	//Top Left

    //upper middle horizontal lines
    glVertex3f(100.0f,250.0f, 0.0f);	//Bottom Left
    glVertex3f(418.0f,258.0f, 0.0f);	//Top Left
    
    glVertex3f(107.0f,252.0f, 0.0f);	//Bottom Left
    glVertex3f(413.0f,260.0f, 0.0f);	//Top Left
    
    glVertex3f(110.0f,254.0f, 0.0f);	//Bottom Left
    glVertex3f(410.0f,262.0f, 0.0f);	//Top Left

    //top horizontal lines
    glVertex3f(90.0f,352.0f, 0.0f);	//Bottom Left
    glVertex3f(420.0f,347.0f, 0.0f);	//Top Left

    glVertex3f(90.0f,354.0f, 0.0f);	//Bottom Left
    glVertex3f(420.0f,349.0f, 0.0f);	//Top Left


    glEnd();
}

void drawRackFrontLines() {
    //---------Bottom Row---------
    // Front Lines
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(112.0f,24.0f,0.0f);	// Bottom Left
    glVertex3f(425.0f,54.0f,0.0f);	// Bottom Right
    glVertex3f(112.0f,30.0f, 0.0f);	//Top Left
    glVertex3f(425.0f,62.0f, 0.0f);	//Top Right
    glEnd();

    // Cascading Lines (from left to right)
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex3f(121.0f,24.0f, 0.0f);	//Bottom Left
    glVertex3f(128.0f,32.0f, 0.0f);	//Top Left
    glVertex3f(139.0f,27.0f, 0.0f);	//Top Right
    glVertex3f(151.0f,32.0f, 0.0f);	//Bottom Right
    glVertex3f(163.0f,28.0f, 0.0f);	//Bottom Left
    glVertex3f(173.0f,35.0f, 0.0f);	//Top Left
    glVertex3f(186.0f,31.0f, 0.0f);	//Top Right
    glVertex3f(197.0f,37.0f, 0.0f);	//Bottom Right
    glVertex3f(209.0f,34.0f, 0.0f);	//Bottom Left
    glVertex3f(221.0f,39.0f, 0.0f);	//Top Left
    glVertex3f(232.0f,35.0f, 0.0f);	//Top Right
    glVertex3f(243.0f,42.0f, 0.0f);	//Bottom Right
    glVertex3f(255.0f,38.0f, 0.0f);	//Bottom Left
    glVertex3f(264.0f,43.0f, 0.0f);	//Top Left
    glVertex3f(277.0f,40.0f, 0.0f);	//Top Right
    glVertex3f(288.0f,45.0f, 0.0f);	//Bottom Right
    glVertex3f(299.0f,42.0f, 0.0f);	//Bottom Left
    glVertex3f(309.0f,48.0f, 0.0f);	//Top Left
    glVertex3f(319.0f,44.0f, 0.0f);	//Top Right
    glVertex3f(330.0f,50.0f, 0.0f);	//Bottom Right
    glVertex3f(342.0f,46.0f, 0.0f);	//Bottom Left
    glVertex3f(351.0f,52.0f, 0.0f);	//Top Left
    glVertex3f(362.0f,49.0f, 0.0f);	//Top Right
    glVertex3f(372.0f,55.0f, 0.0f);	//Bottom Right
    glVertex3f(382.0f,50.0f, 0.0f);	//Bottom Left
    glVertex3f(393.0f,57.0f, 0.0f);	//Top Left
    glVertex3f(403.0f,52.0f, 0.0f);	//Top Right
    glVertex3f(412.0f,59.0f, 0.0f);	//Bottom Right
    glVertex3f(420.0f,55.0f, 0.0f);	//Bottom Left
    glEnd();


    //---------Next Row Up---------
    // Front Lines
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(105.0f,142.0f, 0.0f);	//Top Right
    glVertex3f(423.0f,160.0f, 0.0f);	//Bottom Right
    glVertex3f(104.0f,149.0f, 0.0f);	//Bottom Left
    glVertex3f(423.0f,166.0f, 0.0f);	//Top Left
    glEnd();


    // Cascading Lines (from left to right)
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex3f(114.0f,143.0f, 0.0f);	//Top Left
    glVertex3f(121.0f,148.0f, 0.0f);	//Top Right
    glVertex3f(133.0f,143.0f, 0.0f);	//Bottom Right
    glVertex3f(145.0f,149.0f, 0.0f);	//Bottom Left
    glVertex3f(158.0f,145.0f, 0.0f);	//Top Left
    glVertex3f(169.0f,151.0f, 0.0f);	//Top Right
    glVertex3f(181.0f,145.0f, 0.0f);	//Bottom Right
    glVertex3f(194.0f,152.0f, 0.0f);	//Bottom Left
    glVertex3f(205.0f,148.0f, 0.0f);	//Top Left
    glVertex3f(217.0f,153.0f, 0.0f);	//Top Right
    glVertex3f(229.0f,149.0f, 0.0f);	//Bottom Right
    glVertex3f(240.0f,154.0f, 0.0f);	//Bottom Left
    glVertex3f(251.0f,150.0f, 0.0f);	//Top Left
    glVertex3f(263.0f,156.0f, 0.0f);	//Top Right
    glVertex3f(273.0f,152.0f, 0.0f);	//Bottom Right
    glVertex3f(284.0f,157.0f, 0.0f);	//Bottom Left
    glVertex3f(296.0f,153.0f, 0.0f);	//Top Left
    glVertex3f(306.0f,159.0f, 0.0f);	//Top Right
    glVertex3f(318.0f,155.0f, 0.0f);	//Bottom Right
    glVertex3f(328.0f,160.0f, 0.0f);	//Bottom Left
    glVertex3f(338.0f,155.0f, 0.0f);	//Top Left
    glVertex3f(349.0f,160.0f, 0.0f);	//Top Right
    glVertex3f(359.0f,157.0f, 0.0f);	//Bottom Right
    glVertex3f(370.0f,161.0f, 0.0f);	//Bottom Left
    glVertex3f(380.0f,157.0f, 0.0f);	//Top Left
    glVertex3f(390.0f,163.0f, 0.0f);	//Top Right
    glVertex3f(400.0f,160.0f, 0.0f);	//Bottom Right
    glVertex3f(412.0f,164.0f, 0.0f);	//Bottom Left
    glVertex3f(418.0f,160.0f, 0.0f);	//Top Left
    glEnd();


    //---------Next Row Up---------
    // Front Lines
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(97.0f,239.0f, 0.0f);	//Top Right
    glVertex3f(422.0f,249.0f, 0.0f);	//Bottom Right
    glVertex3f(100.0f,247.0f, 0.0f);	//Bottom Left
    glVertex3f(423.0f,255.0f, 0.0f);	//Top Left
    glEnd();


    // Cascading Lines (from left to right)
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex3f(106.0f,242.0f, 0.0f);	//Top Right
    glVertex3f(115.0f,246.0f, 0.0f);	//Bottom Right
    glVertex3f(129.0f,241.0f, 0.0f);	//Bottom Left
    glVertex3f(140.0f,247.0f, 0.0f);	//Top Left
    glVertex3f(153.0f,242.0f, 0.0f);	//Top Right
    glVertex3f(165.0f,247.0f, 0.0f);	//Bottom Right
    glVertex3f(177.0f,243.0f, 0.0f);	//Bottom Left
    glVertex3f(189.0f,248.0f, 0.0f);	//Top Left
    glVertex3f(202.0f,244.0f, 0.0f);	//Top Right
    glVertex3f(212.0f,249.0f, 0.0f);	//Bottom Right
    glVertex3f(225.0f,244.0f, 0.0f);	//Bottom Left
    glVertex3f(235.0f,250.0f, 0.0f);	//Top Left
    glVertex3f(247.0f,244.0f, 0.0f);	//Top Right
    glVertex3f(259.0f,250.0f, 0.0f);	//Bottom Right
    glVertex3f(271.0f,245.0f, 0.0f);	//Bottom Left
    glVertex3f(281.0f,251.0f, 0.0f);	//Top Left
    glVertex3f(293.0f,246.0f, 0.0f);	//Top Right
    glVertex3f(303.0f,251.0f, 0.0f);	//Bottom Right
    glVertex3f(315.0f,247.0f, 0.0f);	//Bottom Left
    glVertex3f(325.0f,251.0f, 0.0f);	//Top Left
    glVertex3f(336.0f,247.0f, 0.0f);	//Top Right
    glVertex3f(348.0f,253.0f, 0.0f);	//Bottom Right
    glVertex3f(357.0f,248.0f, 0.0f);	//Bottom Left
    glVertex3f(369.0f,253.0f, 0.0f);	//Top Left
    glVertex3f(378.0f,248.0f, 0.0f);	//Top Right
    glVertex3f(389.0f,254.0f, 0.0f);	//Bottom Right
    glVertex3f(398.0f,249.0f, 0.0f);	//Bottom Left
    glVertex3f(409.0f,254.0f, 0.0f);	//Top Left
    glVertex3f(415.0f,249.0f, 0.0f);	//Top Right
    glEnd();


    //---------Top Row---------
    // Front Lines
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(91.0f,349.0f, 0.0f);	//Top Right
    glVertex3f(422.0f,345.0f, 0.0f);	//Bottom Right
    glVertex3f(90.0f,356.0f, 0.0f);	//Bottom Left
    glVertex3f(420.0f,351.0f, 0.0f);	//Top Left
    glEnd();


    // Cascading Lines (from left to right)
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex3f(124.0f,346.0f, 0.0f);	//Bottom Left
    glVertex3f(131.0f,354.0f, 0.0f);	//Top Left
    glVertex3f(143.0f,346.0f, 0.0f);	//Top Right
    glVertex3f(154.0f,354.0f, 0.0f);	//Bottom Right
    glVertex3f(164.0f,345.0f, 0.0f);	//Bottom Left
    glVertex3f(174.0f,353.0f, 0.0f);	//Top Left
    glVertex3f(185.0f,346.0f, 0.0f);	//Top Right
    glVertex3f(195.0f,353.0f, 0.0f);	//Bottom Right
    glVertex3f(207.0f,344.0f, 0.0f);	//Bottom Left
    glVertex3f(219.0f,353.0f, 0.0f);	//Top Left
    glVertex3f(226.0f,344.0f, 0.0f);	//Top Right
    glVertex3f(236.0f,352.0f, 0.0f);	//Bottom Right
    glVertex3f(247.0f,344.0f, 0.0f);	//Bottom Left
    glVertex3f(256.0f,353.0f, 0.0f);	//Top Left
    glVertex3f(268.0f,343.0f, 0.0f);	//Top Right
    glVertex3f(278.0f,353.0f, 0.0f);	//Bottom Right
    glVertex3f(286.0f,344.0f, 0.0f);	//Bottom Left
    glVertex3f(297.0f,352.0f, 0.0f);	//Top Left
    glVertex3f(305.0f,343.0f, 0.0f);	//Top Right
    glVertex3f(315.0f,353.0f, 0.0f);	//Bottom Right
    glVertex3f(325.0f,344.0f, 0.0f);	//Bottom Left
    glVertex3f(334.0f,352.0f, 0.0f);	//Top Left
    glVertex3f(343.0f,342.0f, 0.0f);	//Top Right
    glVertex3f(353.0f,351.0f, 0.0f);	//Bottom Right
    glVertex3f(362.0f,343.0f, 0.0f);	//Bottom Left
    glVertex3f(369.0f,351.0f, 0.0f);	//Top Left
    glVertex3f(379.0f,342.0f, 0.0f);	//Top Right
    glVertex3f(390.0f,351.0f, 0.0f);	//Bottom Right
    glVertex3f(403.0f,343.0f, 0.0f);	//Bottom Left
    glEnd();

}

void drawRackFrontStands() {
    //---------Left Front Rack Stand---------
    // Stand Leg
    glColor3f(0.1607843f, 0.1411765f, 0.1294118f); 
    glBegin(GL_QUADS);
    glVertex3f(104.0f,3.0f, 0.0f);	//Bottom Left
    glVertex3f(80.0f,386.0f, 0.0f);	//Top Left
    glVertex3f(88.0f,386.0f, 0.0f);	//Top Right
    glVertex3f(113.0f,4.0f, 0.0f);	//Bottom Right

    // Bottom Tab
    glColor3f(0.09411766f, 0.07843138f, 0.07450981f);
    glBegin(GL_QUADS);
    glVertex3f(102.0f,21.0f, 0.0f);	//Bottom Left
    glVertex3f(101.0f,31.0f, 0.0f);	//Top Left
    glVertex3f(113.0f,33.0f, 0.0f);	//Top Right
    glVertex3f(114.0f,22.0f, 0.0f);	//Bottom Right

    // Next Tab Up
    glColor3f(0.09411766f, 0.07843138f, 0.07450981f);
    glBegin(GL_QUADS);
    glVertex3f(94.0f,137.0f, 0.0f);	//Bottom Left
    glVertex3f(93.0f,149.0f, 0.0f);	//Top Left
    glVertex3f(105.0f,150.0f, 0.0f);	//Top Right
    glVertex3f(106.0f,138.0f, 0.0f);	//Bottom Right

    // Next Tab Up
    glColor3f(0.09411766f, 0.07843138f, 0.07450981f);
    glBegin(GL_QUADS);
    glVertex3f(87.0f,236.0f, 0.0f);	//Bottom Left
    glVertex3f(87.0f,247.0f, 0.0f);	//Top Left
    glVertex3f(99.0f,248.0f, 0.0f);	//Top Right
    glVertex3f(100.0f,237.0f, 0.0f);	//Bottom Right

    // Top Tab
    glColor3f(0.09411766f, 0.07843138f, 0.07450981f);
    glBegin(GL_QUADS);
    glVertex3f(82.0f,345.0f, 0.0f);	//Bottom Left
    glVertex3f(81.0f,355.0f, 0.0f);	//Top Left
    glVertex3f(92.0f,356.0f, 0.0f);	//Top Right
    glVertex3f(93.0f,345.0f, 0.0f);	//Bottom Right

    //---------Right Front Rack Stand---------
    // Stand Leg
    glColor3f(0.1607843f, 0.1411765f, 0.1294118f); 
    glBegin(GL_QUADS);
    glVertex3f(425.0f,35.0f, 0.0f);	//Bottom Left
    glVertex3f(419.0f,379.0f, 0.0f);	//Top Left
    glVertex3f(425.0f,378.0f, 0.0f);	//Top Right
    glVertex3f(431.0f,35.0f, 0.0f);	//Bottom Right

    // Bottom Tab
    glColor3f(0.08627451f, 0.06666667f, 0.07450981f); 
    glBegin(GL_QUADS);
    glVertex3f(423.0f,54.0f, 0.0f);	//Bottom Left
    glVertex3f(423.0f,63.0f, 0.0f);	//Top Left
    glVertex3f(432.0f,63.0f, 0.0f);	//Top Right
    glVertex3f(432.0f,54.0f, 0.0f);	//Bottom Right

    // Next Tab Up
    glColor3f(0.08627451f, 0.06666667f, 0.07450981f); 
    glBegin(GL_QUADS);
    glVertex3f(421.0f,160.0f, 0.0f);	//Bottom Left
    glVertex3f(421.0f,168.0f, 0.0f);	//Top Left
    glVertex3f(430.0f,169.0f, 0.0f);	//Top Right
    glVertex3f(430.0f,160.0f, 0.0f);	//Bottom Right

    // Next Tab Up
    glColor3f(0.08627451f, 0.06666667f, 0.07450981f);
    glBegin(GL_QUADS);
    glVertex3f(420.0f,247.0f, 0.0f);	//Bottom Left
    glVertex3f(420.0f,256.0f, 0.0f);	//Top Left
    glVertex3f(429.0f,256.0f, 0.0f);	//Top Right
    glVertex3f(429.0f,247.0f, 0.0f);	//Bottom Right

    // Top Tab
    glColor3f(0.08627451f, 0.06666667f, 0.07450981f);
    glBegin(GL_QUADS);
    glVertex3f(418.0f,342.0f, 0.0f);	//Bottom Left
    glVertex3f(418.0f,352.0f, 0.0f);	//Top Left
    glVertex3f(427.0f,352.0f, 0.0f);	//Top Right
    glVertex3f(427.0f,342.0f, 0.0f);	//Bottom Right
    glEnd();
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
    glEnd();
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
    glVertex3f(544.0f,170.0f, 0.0f);	//Bottom Left
    glVertex3f(544.0f,179.0f, 0.0f);	//Top Left
    glVertex3f(910.0f,168.0f, 0.0f);	//Top Right
    glVertex3f(908.0f,158.0f, 0.0f);	//Bottom Right
    glEnd();
}

void drawTVStandMiddle(){
    //Middle TV stand top layer
    glColor3f(0.153f, 0.149f, 0.133f); 
    glBegin(GL_QUADS);
    glVertex3f(590.0f,125.0f, 0.0f);	//Bottom Left
    glVertex3f(590.0f,153.0f, 0.0f);	//Top Left
    glVertex3f(818.0f,145.0f, 0.0f);	//Top Right
    glVertex3f(854.0f,116.0f, 0.0f);	//Bottom Right

    //Middle TV stand front layer
    glColor3f(0.05f, 0.05f, 0.05f); 
    glBegin(GL_QUADS);
    glVertex3f(590.0f,121.0f, 0.0f);	//Bottom Left
    glVertex3f(590.0f,125.0f, 0.0f);	//Top Left
    glVertex3f(854.0f,116.0f, 0.0f);	//Top Right
    glVertex3f(854.0f,112.0f, 0.0f);	//Bottom Right
    glEnd();
}

void drawTVLegs(){
    glBegin(GL_QUADS);

    //front left leg
    glColor3f(0.5f, 0.5f, 0.5f); 
    glVertex3f(553.0f,182.0f, 0.0f);	//Bottom Left
    glVertex3f(572.0f,197.0f, 0.0f);	//Top Left
    glVertex3f(578.0f,197.0f, 0.0f);	//Top Right
    glVertex3f(558.0f,182.0f, 0.0f);	//Bottom Right

    //front right leg
    glColor3f(0.5f, 0.5f, 0.5f); 
    glVertex3f(887.0f,173.0f, 0.0f);	//Bottom Left
    glVertex3f(860.0f,191.0f, 0.0f);	//Top Left
    glVertex3f(868.0f,190.0f, 0.0f);	//Top Right
    glVertex3f(893.0f,173.0f, 0.0f);	//Bottom Right

    //back right leg
    glColor3f(0.3f, 0.3f, 0.3f); 
    glVertex3f(848.0f,188.0f, 0.0f);	//Bottom Left
    glVertex3f(855.0f,190.0f, 0.0f);	//Top Left
    glVertex3f(860.0f,190.0f, 0.0f);	//Top Right
    glVertex3f(852.0f,185.0f, 0.0f);	//Bottom Right
    glEnd();
}

void drawTVStandLower(){
    //Lower TV stand top layer
    glColor3f(0.153f, 0.149f, 0.133f); 
    glBegin(GL_QUADS);
    glVertex3f(544.0f,50.0f, 0.0f);		//Bottom Left
    glVertex3f(550.0f,92.0f, 0.0f);		//Top Left
    glVertex3f(860.0f,81.0f, 0.0f);		//Top Right
    glVertex3f(900.0f,31.0f, 0.0f);		//Bottom Right

    //Rounded TV stand left
    glColor3f(0.153f, 0.149f, 0.133f); 
    glBegin(GL_QUADS);
    glVertex3f(544.0f,45.0f, 0.0f);		//Bottom Left
    glVertex3f(544.0f,50.0f, 0.0f);		//Top Left
    glVertex3f(725.0f,75.0f, 0.0f);		//Top Right
    glVertex3f(721.0f,30.0f, 0.0f);		//Bottom Right

    //Rounded TV stand right
    glColor3f(0.153f, 0.149f, 0.133f); 
    glBegin(GL_QUADS);
    glVertex3f(721.0f,30.0f, 0.0f);		//Bottom Left
    glVertex3f(725.0f,75.0f, 0.0f);		//Top Left
    glVertex3f(900.0f,31.0f, 0.0f);		//Top Right
    glVertex3f(900.0f,26.0f, 0.0f);		//Bottom Right
    glEnd();
}


void drawLowerTVStandLegs(){
    
    glBegin(GL_QUADS);

    //left leg
    glColor3f(0.6176471f, 0.5588236f, 0.5882353f); 
    glVertex3f(594.0f,60.0f, 0.0f);	//Bottom Left
    glVertex3f(594.0f,123.0f, 0.0f);	//Top Left
    glVertex3f(603.0f,122.0f, 0.0f);	//Top Right
    glVertex3f(603.0f,59.0f, 0.0f);	//Bottom Right

    //middle leg
    glColor3f(0.5176471f, 0.4588236f, 0.4882353f); 
    glVertex3f(696.0f,83.0f, 0.0f);	//Bottom Left
    glVertex3f(696.0f,125.0f, 0.0f);	//Top Left
    glVertex3f(703.0f,125.0f, 0.0f);	//Top Right
    glVertex3f(703.0f,83.0f, 0.0f);	//Bottom Right

    //back right leg
    glColor3f(0.6176471f, 0.5588236f, 0.5882353f); 
    glVertex3f(834.0f,48.0f, 0.0f);	//Bottom Left
    glVertex3f(832.0f,115.0f, 0.0f);	//Top Left
    glVertex3f(840.0f,115.0f, 0.0f);	//Top Right
    glVertex3f(842.0f,49.0f, 0.0f);	//Bottom Right

    //right leg
    glColor3f(0.6176471f, 0.5588236f, 0.5882353f); 
    glVertex3f(834.0f,48.0f, 0.0f);	//Bottom Left
    glVertex3f(832.0f,115.0f, 0.0f);	//Top Left
    glVertex3f(840.0f,115.0f, 0.0f);	//Top Right
    glVertex3f(842.0f,49.0f, 0.0f);	//Bottom Right
    glEnd();
}

void drawMiddleTVStandLegs(){
    
    glBegin(GL_QUADS);

    //left leg
    glColor3f(0.6176471f, 0.5588236f, 0.5882353f); 
    glVertex3f(594.0f,128.0f, 0.0f);	//Bottom Left 
    glVertex3f(594.0f,200.0f, 0.0f);	//Top Left 
    glVertex3f(603.0f,200.0f, 0.0f);	//Top Right
    glVertex3f(603.0f,127.0f, 0.0f);	//Bottom Right

    //middle leg
    glColor3f(0.4176471f, 0.3588236f, 0.3882353f); 
    glVertex3f(696.0f,140.0f, 0.0f);	//Bottom Left
    glVertex3f(696.0f,200.0f, 0.0f);	//Top Left
    glVertex3f(703.0f,200.0f, 0.0f);	//Top Right
    glVertex3f(703.0f,140.0f, 0.0f);	//Bottom Right

    //back right leg
    glColor3f(0.4176471f, 0.3588236f, 0.3882353f); 
    glVertex3f(809.0f,141.0f, 0.0f);	//Bottom Left
    glVertex3f(809.0f,165.0f, 0.0f);	//Top Left
    glVertex3f(817.0f,166.0f, 0.0f);	//Top Right
    glVertex3f(817.0f,142.0f, 0.0f);	//Bottom Right

    //right leg
    glColor3f(0.6176471f, 0.5588236f, 0.5882353f); 
    glVertex3f(832.0f,120.0f, 0.0f);	//Bottom Left
    glVertex3f(827.0f,200.0f, 0.0f);	//Top Left
    glVertex3f(835.0f,200.0f, 0.0f);	//Top Right
    glVertex3f(840.0f,120.0f, 0.0f);	//Bottom Right
    glEnd();
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
    glEnd();
}

void drawPS4Games(){
    glBegin(GL_QUADS);

    //left stack front side
    glColor3f(0.06f, 0.1f, 0.4f); 
    glVertex3f(720.0f,126.0f, 0.0f);	//Bottom Left
    glVertex3f(720.0f,137.0f, 0.0f);	//Top Left
    glVertex3f(765.0f,134.0f, 0.0f);	//Top Right
    glVertex3f(765.0f,123.0f, 0.0f);	//Bottom Right

    //left stack top side
    glColor3f(0.7f, 0.7f, 0.7f); 
    glVertex3f(720.0f,137.0f, 0.0f);	//Bottom Left
    glVertex3f(715.0f,150.0f, 0.0f);	//Top Left
    glVertex3f(757.0f,148.0f, 0.0f);	//Top Right
    glVertex3f(765.0f,134.0f, 0.0f);	//Bottom Right

    //left stack
    glColor3f(0.3f, 0.3f, 0.3f); 
    glVertex3f(714.0f,140.0f, 0.0f);	//Bottom Left
    glVertex3f(715.0f,150.0f, 0.0f);	//Top Left
    glVertex3f(720.0f,137.0f, 0.0f);	//Top Right
    glVertex3f(720.0f,126.0f, 0.0f);	//Bottom Right

    //right stack front side
    glColor3f(0.06f, 0.1f, 0.4f);
    glVertex3f(767.0f,123.0f, 0.0f);	//Bottom Left
    glVertex3f(768.0f,134.0f, 0.0f);	//Top Left
    glVertex3f(815.0f,130.0f, 0.0f);	//Top Right
    glVertex3f(816.0f,120.0f, 0.0f);	//Bottom Right

    //right stack top side
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex3f(768.0f,134.0f, 0.0f);	//Bottom Left
    glVertex3f(760.0f,147.0f, 0.0f);	//Top Left
    glVertex3f(804.0f,145.0f, 0.0f);	//Top Right
    glVertex3f(816.0f,131.0f, 0.0f);	//Bottom Right
    glEnd();

    //game lines
    glBegin(GL_LINES);
    glColor3f(0.06f, 0.05f, 0.05f); 
    glVertex3f(720.0f,133.0f, 0.0f);
    glVertex3f(765.0f,130.0f, 0.0f);

    glVertex3f(720.0f,130.0f, 0.0f);
    glVertex3f(765.0f,127.0f, 0.0f);

    glVertex3f(768.0f,130.0f, 0.0f);
    glVertex3f(815.0f,126.0f, 0.0f);
  
    glVertex3f(768.0f,126.0f, 0.0f);
    glVertex3f(815.0f,122.0f, 0.0f);


    
    glEnd();

}

void drawPrinterBox(){
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.67f, 0.65f); 
//front side    
    glVertex3f(721.0f,50.0f, 0.0f);	//Bottom Left
    glVertex3f(722.0f,91.0f, 0.0f);	//Top Left
    glVertex3f(828.0f,85.0f, 0.0f);	//Top Right
    glVertex3f(825.0f,43.0f, 0.0f);	//Bottom Right

    //left side
    glColor3f(0.50f, 0.45f, 0.45f); 
    glVertex3f(721.0f,50.0f, 0.0f);	//Bottom Right
    glVertex3f(707.0f,86.0f, 0.0f);	//Bottom Left
    glVertex3f(708.0f,120.0f, 0.0f);	//Top Left
    glVertex3f(722.0f,92.0f, 0.0f);	//Top Right

    //top side
    glColor3f(0.55f, 0.5f, 0.5f);   
    glVertex3f(722.0f,91.0f, 0.0f);	//Bottom Left
    glVertex3f(708.0f,120.0f, 0.0f);	//Top Left
    glVertex3f(810.0f,112.0f, 0.0f);	//Top Right
    glVertex3f(827.0f,83.0f, 0.0f);	//Bottom Right

    //blue stripe
    glColor3f(0.2f, 0.3f, 0.5f);   
    glVertex3f(722.0f,91.0f, 0.0f);	//Bottom Left
    glVertex3f(718.0f,98.0f, 0.0f);	//Top Left
    glVertex3f(823.0f,92.0f, 0.0f);	//Top Right
    glVertex3f(827.0f,83.0f, 0.0f);	//Bottom Right
    glEnd();

    //box lines
    glColor3f(0.50f, 0.45f, 0.45f); 
    glBegin(GL_LINE_STRIP);
    glVertex3f(722.0f,91.0f, 0.0f);
    glVertex3f(742.0f,70.0f, 0.0f);
    glVertex3f(720.0f,51.0f, 0.0f);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex3f(743.0f,69.0f, 0.0f);
    glVertex3f(804.0f,65.0f, 0.0f);
    glVertex3f(827.0f,83.0f, 0.0f);
    glVertex3f(804.0f,65.0f, 0.0f);
    glVertex3f(825.0f,45.0f, 0.0f);
    glEnd();

    //
    glBegin(GL_QUADS);
    //barcode
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex3f(768.0f,57.0f, 0.0f);	//Bottom Left
    glVertex3f(768.0f,62.0f, 0.0f);	//Top Left
    glVertex3f(779.0f,62.0f, 0.0f);	//Top Right
    glVertex3f(779.0f,57.0f, 0.0f);	//Bottom Right

    //black picture
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex3f(771.0f,98.0f, 0.0f);	//Bottom Left
    glVertex3f(760.0f,120.0f, 0.0f);	//Top Left
    glVertex3f(796.0f,120.0f, 0.0f);	//Top Right
    glVertex3f(805.0f,96.0f, 0.0f);	//Bottom Right

    glEnd();
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
    glEnd();
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
    glEnd();
}

void drawDumbbellCircle(float cx, float cy, float r, int num_segments) {
    glColor3f(0.16f, 0.16f, 0.16f);
    glBegin(GL_POLYGON);
    glLineWidth(2.0);
    for (int ii = 0; ii < num_segments; ii++)   {
        float theta = 2.0f * 3.1415f * float(ii) / float(num_segments);//get the current angle 
        float x = r * cosf(theta);//calculate the x component 
        float y = r * sinf(theta);//calculate the y component 
        glVertex2f(x + cx, y + cy);//output vertex 
    }
    glEnd();
    glLineWidth(1.0);
}

void showTVPic(){
    GLuint tex_2d;
    GLdouble eyex,eyey,eyez = 0;
    GLdouble centerx,centerz = 0;
    GLdouble centery = 1;
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();
    glClear (GL_COLOR_BUFFER_BIT);
    glClearColor (1.0,1.0,1.0,1.0);
    //gluLookAt (eyex,eyey,eyez,centerx,centery,centerz,0,1,0);
    gluLookAt (0,0,0,0,1,0,0,1,0);

    glEnable(GL_TEXTURE_2D);
     tex_2d = SOIL_load_OGL_texture
    (
        "glutSoilProject/TVSCREEN.PNG",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
     if( 0 == tex_2d )
    {
        printf( "SOIL loading error: '%s'\n", SOIL_last_result() );
        exit(1);
    }

   glBindTexture(GL_TEXTURE_2D, tex_2d);

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
    glFlush ();
    //glutSwapBuffers();
}

void showTVPic2(){
    GLuint texture1;
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object
    // Set our texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Load, create texture and generate mipmaps
    int width, height;
    
    unsigned char* image = SOIL_load_image("Container1.jpg", &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
}