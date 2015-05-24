#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>

void renderScene(void)
{
    
    //angle of revolution around the nucleus
    static GLfloat fElect1=0.0f;
    
    //clear the window with current cleaning color
    glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
    
    
    /*Important : Reset modelView Matrix*/
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    //Translate the whole scene out and into view
    //This is initial viewing transformation
     glTranslatef(0.0f, 0.0f, -100.0f);
    
    
    
    //Red Nucleous
    glColor3ub(255,0,0);
    glutSolidSphere(20.0f, 15, 15);
    
    //Yello Electrons
    glColor3ub(255, 255, 0);
    
    
    //First electron Orbit
    //Save viewing transformation
    glPushMatrix();
        glRotatef(fElect1,0.0f,1.0f,0.0f);  //rotate angle of revolution
        glTranslatef(90.0f, 0.0f,0.0f);    //translate out of origin to  orbit distance
        glutSolidSphere(6.0f, 15,15);  //deraw the electon
    glPopMatrix();   // restore the viewing transformation
    
    //Second electron Orbit
    glPushMatrix();
        glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
        glRotatef(fElect1,0.0f,1.0f,0.0f);
        glTranslatef(-70.0f, 0.0f, 0.0f);
        glutSolidSphere(6.0f, 15, 15);
    glPopMatrix();
    
    //Third electron Orbit
    glPushMatrix();
        glRotatef(360.0f, -45.0f, 0.0f, 1.0f);
        glRotatef(fElect1,0.0f,1.0f,0.0f);
        glTranslatef(0.0f, 0.0f,60.0f);
        glutSolidSphere(6.0f,15,15);
    glPopMatrix();
    
    //increment angle of revolution;
    fElect1 +=10.0f;
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
    GLfloat nRange=100.0f;
    
    if(h==0)
        h=1;
    
    glViewport(0,0,w, h);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    if(w<=h)
    {
        glOrtho(-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange*1.8f, nRange*1.8f);
    }
    else
    {
        glOrtho(-nRange*w/h, nRange*w/h,-nRange, nRange, -nRange*1.8f, nRange*1.8f);
    }
    
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void SetupRC()
{
    glEnable(GLUT_DEPTH);
    glFrontFace(GL_CCW);
    glEnable(GL_CULL_FACE);
    glClearColor(0.0f,0.0f, 0.0f, 1.0f);
}

int main(int argc,char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB |GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutCreateWindow("Atom");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutTimerFunc(500, TimerFunc, 1);
    
    SetupRC();
    
    glutMainLoop();
    
    return 0;
}