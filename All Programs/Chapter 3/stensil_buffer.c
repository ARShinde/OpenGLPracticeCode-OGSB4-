#include <stdio.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>



void renderScene(void)
{
    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 1.0f);
    //glClear(GL_COLOR_BUFFER_BIT);
    // Now set scissor to smaller red sub region
    //glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
    //glScissor(100, 100, 600, 400);
    //glEnable(GL_SCISSOR_TEST);
    //glClear(GL_COLOR_BUFFER_BIT);
    // Finally, an even smaller green rectangle
    //glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
    //glScissor(200, 200, 400, 200);
    //glClear(GL_COLOR_BUFFER_BIT);
    glTranslatef(0.0f,0.2f, 0.0f);
    glRotatef(45.0f, 1.0f, 1.0f, 1.0f);
    glScalef(2.0f, 1.0f, 1.0f);
   // glutWireCube(50.0f);
    // Turn scissor back off for next render glDisable(GL_SCISSOR_TEST);
    glutSwapBuffers();
}



void changeSize(GLsizei w,GLsizei h)
{
    GLfloat nRange=100.0f;
    
    if(h==0)
        h=1;
    
    glViewport(0, 0,w, h);
    
    
    if(w<=h)
    {
        glOrtho(-nRange,nRange, -nRange*h/w, nRange*h/w, -nRange, nRange);
    }
    else{
        glOrtho(-nRange*w/h,nRange*w/h,-nRange, nRange , -nRange,nRange);
    }
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
}

void SetupRC()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0,1.0,0.0f);
}

int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
    glutCreateWindow("Polygon");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    
    SetupRC();
    
    glutMainLoop();
    
    return 0;
}