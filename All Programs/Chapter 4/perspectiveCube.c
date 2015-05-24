#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>


// Rotation amounts

static GLfloat xRot = 0.0f;

static GLfloat yRot = 0.0f;

void setupRC() // this function sets up rendering context
{
    glEnable(GL_DEPTH_TEST);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void changeSize(GLsizei w,GLsizei h)
{
    GLfloat fAspect;
    
    if(h==0)
        h=1;
    
    glViewport(0, 0, w, h);
    
    
    fAspect = (GLfloat)w/(GLfloat)h;
    

    // Reset coordinate system

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    

    // Produce the perspective projection

     gluPerspective(60.0f, fAspect, 1.0, 400.0);
    
}

void renderScene()
{
    
    float fZ,bZ;

    

    // Clear the window with current clearing color

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    

    fZ = 100.0f;

    bZ = -100.0f;

    

    // Save the matrix state and do the rotations

    glPushMatrix();

    glTranslatef(0.0f, 0.0f, -300.0f);

    glRotatef(xRot, 1.0f, 0.0f, 0.0f);

    glRotatef(yRot, 0.0f, 1.0f, 0.0f);

    

    // Set material color, Red

    glColor3f(1.0f, 0.0f, 0.0f);

    

    // Front Face ///////////////////////////////////

    glBegin(GL_QUADS);

    // Pointing straight out Z

    glNormal3f(0.0f, 0.0f, 1.0f);

    

    // Left Panel

    glVertex3f(-50.0f, 50.0f, fZ);

    glVertex3f(-50.0f, -50.0f, fZ);

    glVertex3f(-35.0f, -50.0f, fZ);

    glVertex3f(-35.0f,50.0f,fZ);

    

    // Right Panel

    glVertex3f(50.0f, 50.0f, fZ);

    glVertex3f(35.0f, 50.0f, fZ);

    glVertex3f(35.0f, -50.0f, fZ);

    glVertex3f(50.0f,-50.0f,fZ);

    

    // Top Panel

    glVertex3f(-35.0f, 50.0f, fZ);

    glVertex3f(-35.0f, 35.0f, fZ);

    glVertex3f(35.0f, 35.0f, fZ);

    glVertex3f(35.0f, 50.0f,fZ);

    

    // Bottom Panel

    glVertex3f(-35.0f, -35.0f, fZ);

    glVertex3f(-35.0f, -50.0f, fZ);

    glVertex3f(35.0f, -50.0f, fZ);

    glVertex3f(35.0f, -35.0f,fZ);

    

    // Top length section ////////////////////////////

    // Normal points up Y axis

    glNormal3f(0.0f, 1.0f, 0.0f);

    glVertex3f(-50.0f, 50.0f, fZ);

    glVertex3f(50.0f, 50.0f, fZ);

    glVertex3f(50.0f, 50.0f, bZ);

    glVertex3f(-50.0f,50.0f,bZ);

    

    // Bottom section

    glNormal3f(0.0f, -1.0f, 0.0f);

    glVertex3f(-50.0f, -50.0f, fZ);

    glVertex3f(-50.0f, -50.0f, bZ);

    glVertex3f(50.0f, -50.0f, bZ);

    glVertex3f(50.0f, -50.0f, fZ);

    

    // Left section

    glNormal3f(1.0f, 0.0f, 0.0f);

    glVertex3f(50.0f, 50.0f, fZ);

    glVertex3f(50.0f, -50.0f, fZ);

    glVertex3f(50.0f, -50.0f, bZ);

    glVertex3f(50.0f, 50.0f, bZ);

    

    // Right Section

    glNormal3f(-1.0f, 0.0f, 0.0f);

    glVertex3f(-50.0f, 50.0f, fZ);

    glVertex3f(-50.0f, 50.0f, bZ);

    glVertex3f(-50.0f, -50.0f, bZ);

    glVertex3f(-50.0f, -50.0f, fZ);

    glEnd();

    

    glFrontFace(GL_CW);		// clock-wise polygons face out

    

    glBegin(GL_QUADS);

    // Back section

    // Pointing straight out Z

    glNormal3f(0.0f, 0.0f, -1.0f);

    

    // Left Panel

    glVertex3f(-50.0f, 50.0f, bZ);

    glVertex3f(-50.0f, -50.0f, bZ);

    glVertex3f(-35.0f, -50.0f, bZ);

    glVertex3f(-35.0f,50.0f,bZ);

    

    // Right Panel

    glVertex3f(50.0f, 50.0f, bZ);

    glVertex3f(35.0f, 50.0f, bZ);

    glVertex3f(35.0f, -50.0f, bZ);

    glVertex3f(50.0f,-50.0f,bZ);

    

    // Top Panel

    glVertex3f(-35.0f, 50.0f, bZ);

    glVertex3f(-35.0f, 35.0f, bZ);

    glVertex3f(35.0f, 35.0f, bZ);

    glVertex3f(35.0f, 50.0f,bZ);

    

    // Bottom Panel

    glVertex3f(-35.0f, -35.0f, bZ);

    glVertex3f(-35.0f, -50.0f, bZ);

    glVertex3f(35.0f, -50.0f, bZ);

    glVertex3f(35.0f, -35.0f,bZ);

	

    // Insides /////////////////////////////

    glColor3f(0.75f, 0.75f, 0.75f);

    

    // Normal points up Y axis

    glNormal3f(0.0f, 1.0f, 0.0f);

    glVertex3f(-35.0f, 35.0f, fZ);

    glVertex3f(35.0f, 35.0f, fZ);

    glVertex3f(35.0f, 35.0f, bZ);

    glVertex3f(-35.0f,35.0f,bZ);

    

    // Bottom section

    glNormal3f(0.0f, 1.0f, 0.0f);

    glVertex3f(-35.0f, -35.0f, fZ);

    glVertex3f(-35.0f, -35.0f, bZ);

    glVertex3f(35.0f, -35.0f, bZ);

    glVertex3f(35.0f, -35.0f, fZ);

    

    // Left section

    glNormal3f(1.0f, 0.0f, 0.0f);

    glVertex3f(-35.0f, 35.0f, fZ);

    glVertex3f(-35.0f, 35.0f, bZ);

    glVertex3f(-35.0f, -35.0f, bZ);

    glVertex3f(-35.0f, -35.0f, fZ);

    

    // Right Section

    glNormal3f(-1.0f, 0.0f, 0.0f);

    glVertex3f(35.0f, 35.0f, fZ);

    glVertex3f(35.0f, -35.0f, fZ);

    glVertex3f(35.0f, -35.0f, bZ);

    glVertex3f(35.0f, 35.0f, bZ);

    glEnd();

    

    glFrontFace(GL_CCW);		// Counter clock-wise polygons face out

    

    // Restore the matrix state

    glPopMatrix();

    

    // Buffer swap

    glutSwapBuffers();
}

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

int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutCreateWindow("Perspective Projection");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutSpecialFunc(SpecialKeys);
    
    setupRC();
    
    glutMainLoop();
    return 1;
}