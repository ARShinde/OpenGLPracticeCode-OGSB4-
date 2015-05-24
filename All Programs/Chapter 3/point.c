#include <stdio.h>
#include <stdlib.h>
#include <Carbon/Carbon.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <math.h>

//define a constant for the value of PI
#define GL_PI 3.1415f

void RenderScene(void)
{
    GLfloat x,y,z,angle;
    

    
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    glPushMatrix();
    glRotatef(30, 1.0f,0.0f, 0.0f);
    glRotatef(30, 0.0f,1.0f,0.0f);
    
    glBegin(GL_POINTS);   //screwed me bigtime
    
    z=-50.0f;
    for(angle=0.0f; angle <= (2.0f*GL_PI)*3.0f; angle+=0.1f)
    {
	   	x=50.0f*sin(angle);
	   	y=50.0f*cos(angle);
        
	   	glVertex3f(x,y,z);      //specify a point And move the Z value up a little
        
	   	z+=0.5f;
    }
    glEnd();
    
    glPopMatrix();
    
    glutSwapBuffers();
    
}



void ChangeSize(GLsizei w, GLsizei h)
{
    
    GLfloat nRange =100.0f;  // creating canvas of 100*100*100 px
    
    if(h==0)
        h=1;
    
    glViewport(0,0,w,h);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    
    if(w<=h)
    {glOrtho(-nRange,nRange,-nRange*h/w,nRange*h/w,-nRange,nRange);
        
    }
    else{glOrtho(-nRange*w/h, nRange*w/h, -nRange,nRange, -nRange, nRange);}
    
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
}

void SetupRC(void)
{
    glClearColor(0.0f, 0.0f, 0.0f,1.0f);

    glColor3f(0.0f,1.0f,0.0f);

}


int main(int argc, char *argv[])
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutCreateWindow("Point");
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    
    SetupRC();
    
    glutMainLoop();
    
    return 0;
}