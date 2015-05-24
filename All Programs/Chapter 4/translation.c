#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>


void renderScene(void)
{
   // glClearColor(0.0f, 0.0f, 1.0f, 0.0f);

    glColor3f(1.0f,0.0f, 0.0f);
   
    //First apply transformations
    glTranslatef(0.0f ,0.3f, 0.0f);  //translating object to Yazis 0.3point
    glRotatef(45.0f, 1.0f, 1.0f, 1.0f);  //rotate function in 45 deg from poing 1,1,1
    glScalef(2.0f,1.0f,2.0f);  // non uniform scaling of cube
   
    glutWireCube(30.0f);  // draws a cube

    glFlush();
}


void changeSize(GLsizei w, GLsizei h)
{
    GLfloat nRange=100.0f;
    
    if(h==0)
        h=1;
    
    glViewport(0,0,w, h);
    
    if(w<=h)
    {
        glOrtho(-nRange, nRange, -nRange*h/w, nRange, -nRange, nRange);
    }
    else
    {
        glOrtho(-nRange*w/h, nRange*w/h,-nRange, nRange, -nRange, nRange);
    }
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void SetupRC()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f,1.0f, 1.0f, 0.0f);
}

int main(int argc,char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Rotation / Transformation / Scaling example");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    
    SetupRC();
    
    glutMainLoop();
    
    return 0;
}