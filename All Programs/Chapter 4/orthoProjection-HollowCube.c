#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>

// Rotation amounts
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

static GLfloat fAngle=0.0f;
void renderScene()
{
    float fz=100.0f; // frontzone
    float bz=-100.0f; //backzone
    
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glColor3f(1.0f, 0.0f, 0.0f); //set red  color of the boxs
    
    //Save the matrix state and do the roatation
    glPushMatrix();
 
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);

    /////FrontFace///////

    glBegin(GL_QUADS);
    
    glNormal3f(0.0f, 0.0f, 1.0f); // this tell you it is pointing directly towards +ve Z Axis
    
    //left
    glVertex3f(-50.0f,50.0f,fz);
    glVertex3f(-50.0f,-50.0f,fz);
    glVertex3f(-35.0f,-50.0f,fz);
    glVertex3f(-35.0f,50.0f,fz);
    
    //right
    glVertex3f(50.0f, 50.0f,fz);
    glVertex3f(50.0f, -50.0f,fz);
    glVertex3f(35.0f, -50.0f,fz);
    glVertex3f(35.0f, 50.0f,fz);
    
    
    //top
    glVertex3f(-35.0f, 50.0f,fz);
    glVertex3f(-35.0f, 35.0f,fz);
    glVertex3f(35.0f, 35.0f,fz);
    glVertex3f(35.0f, 50.0f,fz);
    
    //bottom
    glVertex3f(-35.0f, -35.0f,fz);
    glVertex3f(-35.0f, -50.0f,fz);
    glVertex3f(35.0f, -50.0f,fz);
    glVertex3f(35.0f, -35.0f,fz);
    
    
    //Top Section
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-50.0f, 50.0f, fz);
    glVertex3f(50.0f, 50.0f, fz);
    glVertex3f(50.0f, 50.0f, bz);
    glVertex3f(-50.0f,50.0f,bz);
    
    
    // Bottom section
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(-50.0f, -50.0f, fz);
    glVertex3f(-50.0f, -50.0f, bz);
    glVertex3f(50.0f, -50.0f, bz);
    glVertex3f(50.0f, -50.0f, fz);
    
    // Left section
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(50.0f, 50.0f, fz);
    glVertex3f(50.0f, -50.0f, fz);
    glVertex3f(50.0f, -50.0f, bz);
    glVertex3f(50.0f, 50.0f, bz);
    
    // Right Section
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-50.0f, 50.0f, fz);
    glVertex3f(-50.0f, 50.0f, bz);
    glVertex3f(-50.0f, -50.0f, bz);
    glVertex3f(-50.0f, -50.0f, fz);

    glEnd();
    
    //BackFACE
    glBegin(GL_QUADS);
    
    // Pointing straight out Z
    glNormal3f(0.0f, 0.0f, -1.0f);// this tells you it is pointing straingt to minus -z axis
    
    // Left Panel
    glVertex3f(-50.0f, 50.0f, bz);
    glVertex3f(-50.0f, -50.0f, bz);
    glVertex3f(-35.0f, -50.0f, bz);
    glVertex3f(-35.0f,50.0f,bz);
    
    // Right Panel
    glVertex3f(50.0f, 50.0f, bz);
    glVertex3f(35.0f, 50.0f, bz);
    glVertex3f(35.0f, -50.0f, bz);
    glVertex3f(50.0f,-50.0f,bz);
    
    // Top Panel
    glVertex3f(-35.0f, 50.0f, bz);
    glVertex3f(-35.0f, 35.0f, bz);
    glVertex3f(35.0f, 35.0f, bz);
    glVertex3f(35.0f, 50.0f,bz);
    
    // Bottom Panel
    glVertex3f(-35.0f, -35.0f, bz);
    glVertex3f(-35.0f, -50.0f, bz);
    glVertex3f(35.0f, -50.0f, bz);
    glVertex3f(35.0f, -35.0f,bz);
	
    // Insides - Inner connector /////////////////////////////
    glColor3f(0.75f, 0.75f, 0.75f);  //gray color
    
    // Normal points up Y axis
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-35.0f, 35.0f, fz);
    glVertex3f(35.0f, 35.0f, fz);
    glVertex3f(35.0f, 35.0f, bz);
    glVertex3f(-35.0f,35.0f,bz);
    
    // Bottom section
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-35.0f, -35.0f, fz);
    glVertex3f(-35.0f, -35.0f, bz);
    glVertex3f(35.0f, -35.0f, bz);
    glVertex3f(35.0f, -35.0f, fz);
    
    // Left section
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-35.0f, 35.0f, fz);
    glVertex3f(-35.0f, 35.0f, bz);
    glVertex3f(-35.0f, -35.0f, bz);
    glVertex3f(-35.0f, -35.0f, bz);
    
    // Right Section
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(35.0f, 35.0f, fz);
    glVertex3f(35.0f, -35.0f, fz);
    glVertex3f(35.0f, -35.0f, bz);
    glVertex3f(35.0f, 35.0f, bz);
    glEnd();


     glFrontFace(GL_CW);		// Counter clock-wise polygons face out
    
    glBegin(GL_QUADS);
    
    //top panel
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-50.0f, 50.0f, bz);
    glVertex3f(-50.0f,-50.0f, bz);
    glVertex3f(-50.0f,-35.0f, bz);
    glVertex3f(-35.0f,50.0f,bz);
    
    // Right Panel
    glVertex3f(50.0f, 50.0f, bz);
    glVertex3f(35.0f, 50.0f, bz);
    glVertex3f(35.0f, -50.0f, bz);
    glVertex3f(50.0f,-50.0f,bz);
    
    // Top Panel
    glVertex3f(-35.0f, 50.0f, bz);
    glVertex3f(-35.0f, 35.0f, bz);
    glVertex3f(35.0f, 35.0f, bz);
    glVertex3f(35.0f, 50.0f,bz);
    
    // Bottom Panel
    glVertex3f(-35.0f, -35.0f, bz);
    glVertex3f(-35.0f, -50.0f, bz);
    glVertex3f(35.0f, -50.0f, bz);
    glVertex3f(35.0f, -35.0f,bz );
    
    // Insides /////////////////////////////
    glColor3f(0.75f, 0.75f, 0.75f);
    
    // Normal points up Y axis
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-35.0f, 35.0f, fz);
    glVertex3f(35.0f, 35.0f, fz);
    glVertex3f(35.0f, 35.0f, bz);
    glVertex3f(-35.0f,35.0f,bz);
    
    // Bottom section
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-35.0f, -35.0f, fz);
    glVertex3f(-35.0f, -35.0f, bz);
    glVertex3f(35.0f, -35.0f, bz);
    glVertex3f(35.0f, -35.0f, fz);
    
    // Left section
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-35.0f, 35.0f, fz);
    glVertex3f(-35.0f, 35.0f, bz);
    glVertex3f(-35.0f, -35.0f, bz);
    glVertex3f(-35.0f, -35.0f, fz);
    
    // Right Section
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(35.0f, 35.0f, fz);
    glVertex3f(35.0f, -35.0f, fz);
    glVertex3f(35.0f, -35.0f, bz);
    glVertex3f(35.0f, 35.0f, bz);
    
    glEnd();
   
    glFrontFace(GL_CCW);
    
    glPopMatrix();

    glutSwapBuffers();
}

void changeSize(GLsizei w, GLsizei h)
{
    GLfloat nRange=120.0f;
    
    if(h==0)
        h=1;
    
    glViewport(0, 0, w, h);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    if (w <= h)
        glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange*2.0f, nRange*2.0f);
    else
        glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange*2.0f, nRange*2.0f);

    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


//setting up with rendering context
void SetupRC()
{
    glEnable(GL_DEPTH_TEST);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

// Respond to arrow keys
void SpecialKeys(int key, int x, int y)
{
	if(key == GLUT_KEY_UP)
		xRot-= 5.0f;
    
	if(key == GLUT_KEY_DOWN)
		xRot += 5.0f;
    
	if(key == GLUT_KEY_LEFT)
		yRot -= 5.0f;
    
	if(key == GLUT_KEY_RIGHT)
		yRot += 5.0f;
    
    xRot = (GLfloat)((const int)xRot % 360);
    yRot = (GLfloat)((const int)yRot % 360);
    
	// Refresh the Window
	glutPostRedisplay();
}




int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Orthographic Projection");

    glutReshapeFunc(changeSize);
        glutSpecialFunc(SpecialKeys);
        glutDisplayFunc(renderScene);
    SetupRC();
    glutMainLoop();
    
    return 0;
    
}