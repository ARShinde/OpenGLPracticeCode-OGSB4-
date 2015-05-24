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
	static GLfloat fElect2=0.0f;
    
    glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glColor3ub(255, 255, 0);
    glutSolidSphere(20.0f, 15, 15);  //Sun
    
    glColor3ub(0,12,255);
    
    glPushMatrix();
    
    glRotatef(fElect1,0.0f, 1.0f, 0.0f);
    glTranslatef(70.0f,0.0f,0.0f);
    glutSolidSphere(6.0f, 15, 15);   //Earth
    
    
    glColor3ub(255,255,255);
    glRotatef(fElect2,0.0f,1.0f,0.0f);
    glTranslatef(15.0f, 0.0f, 0.0f);
    glutSolidSphere(4.0f,15, 15); //moon

    glPopMatrix();
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    fElect1+=5.0f;
    if(fElect1>360.0f)
        fElect1=0.0f;
    
    fElect2+=10.0f;
    if(fElect2>360.0f)
        fElect2=0.0f;
        
    glutSwapBuffers();
}


void TimerFunc(int value)
{
    glutPostRedisplay();
    glutTimerFunc(100, TimerFunc, 1);
}
void changeSize(GLsizei w, GLsizei h)
{
    GLfloat nRange=100.0f;
    
    if(h==0)
        h=1;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    glViewport(0,0,w,h);
    
    if(w<=h)
    {
        glOrtho(nRange, -nRange, nRange, -nRange, nRange, -nRange);
    }
    else
    {
        glOrtho(nRange, -nRange, nRange, -nRange, nRange, -nRange);

    }
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
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
    glutCreateWindow("Atom");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    
   glutTimerFunc(500, TimerFunc, 1);
    
    SetupRC();
    glutMainLoop();
    
    return 1;
}