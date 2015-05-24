#include <stdio.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>


void RenderScene()
{
    GLfloat y;
    GLfloat fSizes[2];
    GLfloat fCurrSize;
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0f,0.0f,0.0f);
    
    
    glGetFloatv(GL_LINE_WIDTH_RANGE,fSizes); // Get line size metrices and save small value
    
    fCurrSize=fSizes[0];
    
    for(y=-90.0f;y<90.0f;y+=20.0f)   // Setp Y Axis 20 Units at a time
    {
        glLineWidth(fCurrSize); //SetLine Width
        
        
        //Draw the line
        glBegin(GL_LINES);

            glVertex2f(-80.0f,y);
            glVertex2f(80.0f,y);
    
        glEnd();
        
        fCurrSize+= 1.0f; // Increase the line width
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