#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>


void renderScene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
    glColor3f(1.0f,0.0f, 0.0f);
 
    glPushMatrix();
    glBegin(GL_TRIANGLES);

    glColor3ub(0,0,255);
    glVertex3f(-40.0f,-40.0f, 0.0f);
    glColor3ub(0,255,0);

    glVertex3f(0.0f,40.0f, 0.0f);
    glColor3ub(255,0,0);
 
    glVertex3f(40.0f,-40.0f,0.0f);
    
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
}

void changeSize(GLsizei w, GLsizei h)
{
    GLfloat fAngle=100.0f;
    
    if(h==0)
        h=1;
    
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    if(w<=h)
    {
        glOrtho(-fAngle, fAngle, -fAngle*h/w, fAngle*h/w, -fAngle, fAngle);
    }
    else
        glOrtho(-fAngle*w/h, fAngle*w/h, -fAngle, fAngle*w/h, -fAngle, fAngle);
    
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    }

void SetupRC()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    
}

int main(int argc,char * argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA |GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Color Tringle");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    
    SetupRC();
    
    glutMainLoop();
    return 1;
}