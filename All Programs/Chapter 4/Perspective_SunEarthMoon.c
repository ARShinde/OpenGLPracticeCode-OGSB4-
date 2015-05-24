
//Called to draw scene
void renderScene(void)
{
    static GLfloat fEarth=0.0f;
    static GLfloat fMoonRot=0.0f;
    
    //Clear the window with current clearing color
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
   //Save the matrix state and do the rotation
    
    glMatrixMode(GL_MODELVIEW);
   // glLoadIdentity();
    
    glPushMatrix();
        glTranslatef(0.0f,0.0f, -300.0f);  //Translate thae whole scene out and do the rotation
    
        //Sun
        glColor3ub(225, 0, 0);
        glutSolidSphere(30, 20, 20);

        //Earth
        glRotatef(fEarth, 0.0f, 1.0f, 0.0f);
        glColor3ub(0, 0, 245);
        glTranslatef(105.0f, 0.0f, 0.0f);
        glutSolidSphere(15,10, 10);
    
        //Moon
        glColor3ub(200, 200, 200);
        glRotatef(fMoonRot, 0.0f, 1.0f, 0.0f);
        glTranslatef(40.0f, 0.0f, 0.0f);
    
        fMoonRot+=15.0f;  //code for moving  moon around earth
        if(fMoonRot>360.0f)
            fMoonRot=0.0f;
    
        glutSolidSphere(6.0f, 15, 15);
    glPopMatrix();
    
    
    fEarth+=5.0f;   //code for moving earth around sun
    if(fEarth>360.0f)
    fEarth=0.0f;
    
    glutSwapBuffers();

}

//change viewing volume and viewport It gets called when window is resized
void changeSize(GLsizei w, GLsizei h)
{
    GLfloat fAspect;
    
    //Prevent divide by zero
    if(h==0)
        h=1;
    
    //Set viewport to windows dimension
    glViewport(0,0,w, h);
    
    fAspect= (GLfloat)w/(GLfloat)h;
    
    //reset co-ordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    //produce the perspective projection
    gluPerspective(45.0f, fAspect, 1.0f, 425.0f); //field of view 45 degree near amd far planes 1.0f and 425.0f

    //modelview matrix reset
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
}

void setupRC()
{
    glEnable(GL_DEPTH_TEST);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
    
    glClearColor(0.0f, 0.0f, 0.0f,1.0f);
}

void timerFunc()
{
    glutPostRedisplay();
    glutTimerFunc(100, timerFunc, 1);
}

int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Solar");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutTimerFunc(500, timerFunc, 1);
    
    setupRC();
    
    glutMainLoop();
    
    return 1;
    
}