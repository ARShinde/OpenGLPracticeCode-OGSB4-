#include <stdio.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>


#define GL_PI 3.1415f

void RenderScene(void)
{
    
    GLfloat angle,x,y,z;
    glClear(GL_COLOR_BUFFER_BIT);
    
   /* glBegin(GL_LINE_STRIP);
        glVertex3f(0.0f,0.0f,0.0f);
        glVertex3f(20.0f,20.0f,0.0f);
        glVertex3f(20.0f,50.0f,0.0f);
        glVertex3f(0.0f,0.0f,0.0f);
    
    glEnd();*/
    glPushMatrix();
    
    glRotatef(30, 1.0f,0.0f, 0.0f);
    glRotatef(30, 0.0f,1.0f,0.0f);
    glBegin(GL_LINE_STRIP);
    z=-50.0f;
    for(angle=0.0f;angle<=((2.0f*GL_PI)*3.0f);angle+=0.1f)
    {
        x=50.0f*sin(angle);
        y=50.0f*cos(angle);
        
        
        glVertex3f(x,y,z);
        
        z+=0.5f;
    }
    
    
    glEnd();
    
    glPopMatrix();
    
    glutSwapBuffers();
   
}

void SetupRC(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glColor3f(1.0f,0.0f,0.0f);
    
}

void ChangeSize(GLsizei w, GLsizei h)
{
    GLfloat nRange=100.0f;
    
    if(h==0)
        h=1;
    
    glViewport(0, 0, w, h);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    if(w<=h)
    {
        glOrtho(-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange, nRange);
    }
    else{ glOrtho(-nRange*w/h, nRange*w/h, -nRange,nRange, -nRange, nRange);}
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Line Strap");
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    
    SetupRC();
    
    glutMainLoop();
    
    return 0;
    
    
}