#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>


void SetupRC()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);
    glClearColor(120.0f, 110.0f, 120.0f,1.0f);
}


// Rotation amounts
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

void renderScene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
    glColor3f(1.0f, 0.0f, 0.0f);
    
    glPushMatrix();
    
    glRotatef(xRot,1.0f,0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f,0.0f);

    glBegin(GL_TRIANGLES);
    
    //nose
    glColor3ub(255,0, 0);
    glVertex3f(0.0f,0.0f,60.0f);
    glVertex3f(-15.0f,0.0f,30.0f);
    glVertex3f(15.0f,0.0f,30.0f);
    
    glColor3ub(0,255,255);
    glVertex3f(15.0f,0.0f, 30.0f);
    glVertex3f(0.0f,15.0f, 30.0f);
    glVertex3f(0.0f,0.0f,60.0f);
    
    glColor3ub(0,0,255);
    glVertex3f(0.0f, 0.0f, 60.0f);
    glVertex3f(0.0f, 15.0f, 30.0f);
    glVertex3f(-15.0f, 0.0f, 30.0f);
   
    //body
    glColor3ub(155, 155, 155);
    glVertex3f(-15.0f,0.0f,30.0f);
    glVertex3f(0.0f,15.0f,30.0f);
    glVertex3f(0.0f,0.0f,-60.0f);
    
    glColor3ub(100, 100, 100);
    glVertex3f(0.0f, 0.0f, -60.0f);
    glVertex3f(0.0f,15.0f, 30.0f);
    glVertex3f(15.0f, 0.0f, 30.0f);
    
    glColor3ub(133, 133, 133);
    glVertex3f(15.0f,0.0f,30.0f);
    glVertex3f(-15.0f,0.0f,30.0f);
    glVertex3f(0.0f,0.0f,-60.0f);
    
    
    //wing
    glColor3ub(55, 155,155);
    glVertex3f(0.0f, 2.0f, 15.0f);
    glVertex3f(-60.0f, 2.0f,-10.0f);
    glVertex3f(60.0f,2.0f,-10.0f);

    glColor3ub(55,100 , 100);
    glVertex3f(60.0f,2.0f,-10.0f);
    glVertex3f(0.0f,7.0f, -10.0f);
    glVertex3f(0.0f,2.0f,15.0f);
    
    glColor3ub(55,100 , 100);
    glVertex3f(0.0f,2.0f,15.0f);
    glVertex3f(0.0f,7.0f, -10.0f);
    glVertex3f(-60.0f,2.0f,-10.0f);
    
    //wing back cover
    glColor3ub(200, 200, 200);
    glVertex3f(-60.0f,2.0f, -10.0f);
    glVertex3f(0.0f,7.0f, -10.0f);
    glVertex3f(60.0f,2.0f, -10.0f);

    
    //flat tail horizontal
    glColor3ub(233,233,233);
    glVertex3f(0.0f,-0.5f,-45.0f);
    glVertex3f(-20.0f,-0.5f,-60.0f);
    glVertex3f(20.0f,-0.5f,-60.0f);

    glColor3ub(133,133,233);
    glVertex3f(20.0f,-0.5f,-60.0f);
    glVertex3f(0.0f,4.0f,-60.0f);
    glVertex3f(0.0f,-0.5f,-45.0f);

    glColor3ub(133,133,233);
    glVertex3f(0.0f,-0.5f,-45.0f);
    glVertex3f(0.0f,4.0f,-60.0f);
    glVertex3f(-20.0f,-0.5f,-60.0f);

    glColor3ub(133,133,133);
    glVertex3f(-20.0f,-0.5f,-60.0f);
    glVertex3f(0.0f,4.0f,-60.0f);
    glVertex3f(20.0f,-0.5f,-60.0f);

    //flat tail verticle
    glColor3ub(255, 0,0);
    glVertex3f(0.0f,0.5f,-45.0f);
    glVertex3f(3.0f,0.5f,-60.0f);
    glVertex3f(0.0f,20.0f,-65.0f);

    glColor3ub(255, 0,0);
    glVertex3f(0.0f,20.0f,-65.0f);
    glVertex3f(-3.0f,0.5f,-60.0f);
    glVertex3f(0.0f,0.5f,-45.0f);
    
    glColor3ub(133, 0,0);
    glVertex3f(3.0f,0.0f,-60.0f);
    glVertex3f(-3.0f,0.0f,-60.0f);
    glVertex3f(0.0f,20.0f,-65.0f);

    
    
    
    glEnd();
    glPopMatrix();
    
    glutSwapBuffers();
}

void changeSize(GLsizei w, GLsizei h)
{
    GLfloat fAspect=100.0f;
    
    if(h==0)
        h=1;
    
    glViewport(0, 0, w, h);
    
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //fAspect=(float)w/(float)h;

    //gluPerspective(45.0f, fAspect, 1.0f,400.0f);
    
    if(w<=h)
    { glOrtho(-fAspect, fAspect, -fAspect*h/w,fAspect*h/w,
              -fAspect, fAspect);
    }
    else{    glOrtho(-fAspect*w/h, fAspect*w/h, -fAspect,fAspect, -fAspect, fAspect);
}
    
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
  //  glTranslatef(0.0f, 0.0f, -200.0f);  //For Displaying scene at -200 distance
    
}
void SpecialKeys(int key, int x, int y)
{
    if(key == GLUT_KEY_UP)
        xRot-= 5.0f;
    
    if(key == GLUT_KEY_DOWN)
        xRot += 5.0f;
    
    if(key == GLUT_KEY_LEFT)
        yRot -= 5.0f;
    
    if(key == GLUT_KEY_RIGHT)
        yRot += 5.0f;
    
    if(key > 356.0f)
        xRot = 0.0f;
    
    if(key < -1.0f)
        xRot = 355.0f;
    
    if(key > 356.0f)
        yRot = 0.0f;
    
    if(key < -1.0f)
        yRot = 355.0f;
    
    // Refresh the Window
    glutPostRedisplay();
}


int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutCreateWindow("Jet");
    glutDisplayFunc(renderScene);
    
    glutSpecialFunc(SpecialKeys);
    glutReshapeFunc(changeSize);

    SetupRC();
    
    glutMainLoop();
    return 1;
}