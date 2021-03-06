// Animating recangle

#include <stdio.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>


//Initial Square Position And Size

GLfloat x1= 0.0f;
GLfloat y1=0.0f;
GLfloat rsize=25;

//step size in x and y direction

GLfloat xstep=1.0f;
GLfloat ystep=1.0f;

//keeps track of windows changing width and height
GLfloat windowWidth;
GLfloat windowHeight;


//call to draw scene
void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);  //clear the window with current cleaning color
    
    glColor3f(1.0f,0.0f, 0.0f);    //set current color to red
    
    glRectf(x1,y1,x1+rsize, y1-rsize); //draw filled reactangle with current color
    
    glutSwapBuffers(); //flush drawing commands and swap
    
}



void TimerFunction(int value)
{
    if(x1 >windowWidth - rsize || x1 < -windowWidth)
        xstep= - xstep;
    
    if(y1>windowHeight || y1 < -windowHeight+ rsize)
        ystep=-ystep;

    x1+= xstep;
    y1+=ystep;
    
    
    if(x1 > (windowWidth-rsize+xstep))
        x1=windowWidth-rsize-1;
    else if(x1< -(windowWidth+xstep))
        x1=-windowWidth-1;
    
    
    
    if(y1 > (windowHeight+ystep))
        y1=windowHeight-1;
    else if(y1< - (windowHeight-rsize+ystep))
        y1= -windowHeight+rsize-1;
    
    
    glutPostRedisplay();
    glutTimerFunc(333,TimerFunction,1);
    
}



void ChangeSize(GLsizei w,GLsizei h)
{
    GLfloat aspectRatio;
    
    printf("%d \t %d",w,h);
    
    if(h==0)
        h=1;
    
    glViewport(0,0,w,h);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    
    aspectRatio=(GLfloat)w/(GLfloat)h;
    
    if(w<=h)
    {
        glOrtho(-100.0,100.0,-100.0/aspectRatio, -100.0/aspectRatio, 1.0, -1.0);
    }
    else
    {
        glOrtho(-100.0*aspectRatio,100.0*aspectRatio,-100.0,100.0, 1.0,-1.0);
    }
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void SetupRC(void)
{
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

int main(int argc, char * argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutCreateWindow("animation");
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    
    glutTimerFunc(333,TimerFunction,1);
    SetupRC();
    
    glutMainLoop();
    
    return 0;
}
