#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/gl.h>
#include <GLUT/GLUT.h>

void renderScene(void)
{
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0f,1.0f,0.0f);
    
    glBegin(GL_TRIANGLES);
    
    //tringle on quadrant 1 [below 3 co-ordinates display tringle on first quadrant]
      glVertex2f(0.0f, 0.0f);  //vo
      glVertex2f(20.0f, 20.0f); //v1
      glVertex2f(50.0f,0.0f);    //v2

    //tringle on quadrant 2 [below 3 co-ordinates display tringle on second quadrant]
      glVertex2f(-50.0f, 0.0f);  //vo
      glVertex2f(-70.0f, 50.0f); //v1
      glVertex2f(-10.0f,0.0f);    //v2
    
    glEnd();
    
    /*      Sometimes We Need to draw connected tringles so here we use Gl_tringle strip
    glBegin(GL_TRIANGLE_STRIP);
     glVertex2f(0.0f, 0.0f);    //vo
     glVertex2f(20.0f, 20.0f);  //v1
     glVertex2f(50.0f,0.0f);    //v2
     glVertex2f(70.0f, 10.0f);  //v3
     glVertex2f(30.0f, -50.0f); //v4
     glVertex2f(10.0f,0.0f);    //v5
    glEnd();
    */
    glFlush();
    
}
void changeSize(GLsizei w, GLsizei h)
{
    GLfloat nRange=100.0f;
    
    if(h==0)
    {
        h=1;
    }
    glViewport(0, 0, w, h);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    if(w<=h)
    {
        glOrtho(-nRange, nRange, -nRange*h/w,nRange*h/w, -nRange, nRange);
    }
    else
    {glOrtho(-nRange*w/h,nRange*w/h, -nRange, nRange, -nRange, nRange);}

    
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


}

void SetupRC(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
}

int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGBA);
    glutCreateWindow("basic tringles");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    
    SetupRC();
    
    glutMainLoop();
    
    return 0;
}
