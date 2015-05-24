#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>


// Rotation amounts
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

void renderScene()
{
	static GLfloat fElect1=0.0f;
    
    glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
    
    glColor3ub(255, 255, 0);
    glutSolidSphere(20.0f, 15, 15);
    
    
    //First Electron Orbit
    glPushMatrix();
      glColor3ub(0,12,255);
      glRotatef(fElect1,0.0f, 1.0f, 0.0f);  //Rotate Object Along with Y Axis
      glTranslatef(70.0f,0.0f,0.0f);        // Translate object 70 to X Axis
      glutSolidSphere(6.0f, 15, 15);
    glPopMatrix();

	// Second Electron Orbit
	glPushMatrix();
      glColor3ub(255,0, 0);
	  glRotatef(fElect1, 1.0f, 0.0f, 0.0f);  // Rotate Along with X Axis
	  glTranslatef(0.0f, 50.0f, 0.0f);       // Tanslate 50 to Y Axis
  	  glutSolidSphere(6.0f, 15, 15);
	 glPopMatrix();
    
    
	// Third Electron Orbit
	glPushMatrix();
      glColor3ub(0, 255,0);
      glRotatef(fElect1, 0.0f, 0.0f, 1.0f); // Rotate Along With Z axis
      glTranslatef(50.0f, 0.0f, 0.0f);      // Translate 60 to Z axiss
      glutSolidSphere(6.0f, 15, 15);
	glPopMatrix();
    
    fElect1+=5.0f;
    if(fElect1>360.0f)
        fElect1=0.0f;

        
    glutSwapBuffers();
}


void TimerFunc(int value)
{
    glutPostRedisplay();
    glutTimerFunc(100, TimerFunc, 1);
}
void changeSize(GLsizei w, GLsizei h)
{
    GLfloat fAspect;
    
    if(h==0)
        h=1;
    
    glViewport(0,0,w,h);

    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    fAspect=(float)w/(float)h;
    gluPerspective(45.0, fAspect, 1.0, 500.0f);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -200.0f);  //For Displaying scene at -200 distance
}

void SetupRC()
{
    glEnable(GL_DEPTH_TEST);
    glFrontFace(GL_CCW);
    glCullFace(GL_CULL_FACE);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB |GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutCreateWindow("Atom 2 (PerSpective)");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    
   glutTimerFunc(500, TimerFunc, 1);
    
    SetupRC();
    glutMainLoop();
    
    return 1;
}