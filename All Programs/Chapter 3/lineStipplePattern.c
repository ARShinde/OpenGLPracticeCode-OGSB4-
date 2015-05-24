#include <stdio.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>


void RenderScene()
{
    GLfloat y;              //Storage For varying Y Co-ordinate
    GLfloat factor=1;       //Stippling factor
    GLfloat pattern=0x0F0F; //Stipple pattern 0000 1111 0000 1111 - 0-off 1-on
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0f,0.0f,0.0f);
    
    
    glEnable(GL_LINE_STIPPLE);  //Enable Stippling
    
    for(y=-90.0f;y<90.0f;y+=20.0f)
    {
        glLineStipple(factor,pattern); //Reset the repeat factor and pattern
        
        glBegin(GL_LINES);     // Draw the lines
          glVertex2f(-80.0f,y);
          glVertex2f(80.0f,y);
        glEnd();
        
        factor++;
    }
    
    
    glFlush();
}
void ChangeSize(GLsizei w,GLsizei h)
{
    GLfloat nRange=100.0f;
    
    if(h==0)
        h=1;
    
    glViewport(0,0,w,h);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    if(w<=h)
    {
        glOrtho(-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange, nRange);
    }
    else{
        glOrtho(-nRange*w/h,nRange*w/h, -nRange, nRange, -nRange, nRange);
    }
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
}
void SetupRC()
{
    
    glClearColor(1.0f,1.0f, 1.0f, 1.0f);
}
int main(int argc, char *argv[])
{
    
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
    glutCreateWindow("Line Strap With Diff Width");
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    
    SetupRC();
    
    glutMainLoop();
    
    return 0;
}