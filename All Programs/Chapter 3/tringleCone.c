#include <stdio.h>
#include <stdlib.h>
#include <openGL/gl.h>
#include <GLUT/glut.h>

#define GL_PI 3.14f

void RenderScene()
{
    GLfloat x,y,angle;
    int iPivot=1;
    
    
    glEnable(GL_DEPTH_TEST);  //used for hidden surface removal [alike zindex] this is call for enable depth testing
    
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); //clear window and the depth buffer
    
    
    //save matrix state and do the rotation
    glPushMatrix();
    glRotatef(70.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(10.0f, 0.0f, 1.0f, 0.0f);
    
    //begin tringle fan
    glBegin(GL_TRIANGLE_FAN);
    
      glVertex3f(0.0f,0.0f,75.0f);// pinnacle of the cone moved up by z-axis to produce cone
    
    for(angle=0.0f; angle< (2.0f*GL_PI);angle+=(GL_PI/8.0f))
    {
        //calculate x and y positions of the next vertex
        x =50.0f*sin(angle);
        y=50.0f*cos(angle);
        
        //alternet color between red and green
        if((iPivot % 2)==0)
        {glColor3f(0.0f,1.0f,0.0f);
        }
        else{glColor3f(1.0f,0.0f,0.0f);}
        
        iPivot++;
        
        glVertex2f(x,y); //Specify next vertex of tringle fan
    }
    
    glEnd(); //done with drawing for cone
    
    
    
    //Begin a new tringle fan to cover the bottom
    glBegin(GL_TRIANGLE_FAN);
    
    glVertex2f(0.0f,0.0f);  // here we are setting center of fan as origin [Note :on above tringle fan for cone we have used vertex at glVertex3f positions]
    
    for(angle=0.0f; angle < (2.0f*GL_PI);angle += (GL_PI /8.0f))
    {
        x=50.0f*sin(angle);
        y=50.0f*cos(angle);
        
        if(iPivot %2 ==0)
            glColor3f(0.0f,1.0f,0.0f);
        else
            glColor3f(1.0f,0.0f,0.0f);
        
        iPivot++;
        glVertex2f(x,y); //Specify next vertext for the tringle fan
    }
    
    glEnd(); //end of drawing bottom of the fan
    
    glPopMatrix();
    
    glutSwapBuffers();
    
}


//This Function does any needed initialization on rendering context
void SetupRC()
{
    //glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  //black color
    glColor3f(0.0f,1.0f,0.0f);             //Setting drawing color to green
    
    glShadeModel(GL_FLAT);                 //Setting shademodel to flat (means it will give solid color) [more on chapter 5]
    /* glShadeModel(GL_SMOOTH); */         //When we use this type of shademodel we get tringles smooth shade
    
    glFrontFace(GL_CW);                   //Clockwise- wound polygons are front facing this is revered beacause we are using tringle fans
}

void ChangeSize(GLsizei w, GLsizei h)
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
    else{ glOrtho(-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange, nRange);}

    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
}


int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA |GLUT_DEPTH);
    glutCreateWindow("tringle Fan");
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    
    SetupRC();
    
    glutMainLoop();
    
    return 0;
}