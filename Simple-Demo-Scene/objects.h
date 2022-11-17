#include <GL/glut.h>
#include <SOIL/SOIL.h>

void createEnemy(GLuint _textureEnemy, GLfloat x, GLfloat y){
    // Push textures to a new matrix
	//glEnable(GL_TEXTURE_2D);
	glPushMatrix();
		
		// Bind texture to a shader
		//glBindTexture(GL_TEXTURE_2D, _textureEnemy);

		// Formalize texture parameters
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);

        
        glColor3f(1.0f,1.0f,1.0f);

		// Draw texture
		glBegin(GL_QUADS);  // Floor
            glTexCoord3f(0,0,0);  glVertex3f(100.0f + x,700.0f + y, 0.0f); //bottom left
            glTexCoord3f(0,1,0);  glVertex3f(100.0f + x,750.0f + y, 0.0f);   //top left
			glTexCoord3f(1,1,0); glVertex3f(150.0f + x,750.0f + y, 0.0f);   	//Top Right
			glTexCoord3f(1,0,0);  glVertex3f(150.0f + x,700.0f + y, 0.0f);		//bottom right
    	glEnd();
		//glDisable(GL_TEXTURE_2D);

        
	// Save matrix
	glPopMatrix();
}

void createShip(GLuint _textureSpaceship){
    // Push textures to a new matrix
	//glEnable(GL_TEXTURE_2D);
	glPushMatrix();
		
		// Bind texture to a shader
		//glBindTexture(GL_TEXTURE_2D, _textureSpaceship);

		// Formalize texture parameters
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);

        
        glColor3f(1.0f,1.0f,1.0f);

		// Draw texture
		glBegin(GL_QUADS);  // Floor
            glTexCoord3f(0,0,0);  glVertex3f(400.0f,100.0f, 0.0f); //bottom left
            glTexCoord3f(0,1,0);  glVertex3f(400.0f,150.0f, 0.0f);   //top left
			glTexCoord3f(1,1,0); glVertex3f(450.0f,150.0f, 0.0f);   	//Top Right
			glTexCoord3f(1,0,0);  glVertex3f(450.0f,100.0f, 0.0f);		//bottom right
    	glEnd();
		//glDisable(GL_TEXTURE_2D);

        
	// Save matrix
	glPopMatrix();
}

void createSwarm(GLuint _textureEnemy){
	GLfloat xpos = 0;
    int counter = 0;
    GLfloat ypos = 0;
    int m,k = 1;
    
 	for (int i = 8; i >= 1; i--){

        for (int j = 1; j <= m; j++){
            xpos += 50;
        }

        for (k = 1; k <= (2 * i -1); k++){
            createEnemy(_textureEnemy,xpos,ypos);
            xpos += 50;
        }
        m++;
        //xpos = counter * 50;
        xpos = 0;
        ypos -= 50;
    }
}

