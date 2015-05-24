#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#define GL_PI 3.1415f


void RenderScene(void)
{
    GLfloat x,y,z,angle;
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f,0.0f,1.0f);
    
    
    
    glBegin(GL_LINES);
       /*glVertex3f(0.0f,0.0f,0.0f);
       glVertex3f(50.0f, 50.0f, 50.0f);
       glVertex3f(75.0f,75.0f,75.0f);
       */
    
    
    z=0.0f;
    for(angle=0.0f;angle<= GL_PI; angle+= (GL_PI/20.0f))
    {
         //top half of the circle
        x=50.0f*sin(angle);
        y=50.0f*cos(angle);
        glVertex3f(x,y,z);  //x1 y1 (first point)
    
        //printf("x1 y1 z1\t %f\t%f\t%f\n",x,y,z);
       
         //Bottom half of the circle
        x=50.0f*sin(angle+GL_PI);
        y=50.0f*cos(angle+GL_PI);
        glVertex3f(x,y,z);   //x2 y2 (second point)
        
        //printf("x2 y2 z2 \t %f\t%f\t%f\n",x,y,z);
    }   
  
  /*glVertex3f(0.0f,50.0f,z);   //x1 y1
    glVertex3f(0.0f,-50.0f,z);  //x2 y2
    
    glVertex3f(50.0f,50.0f,z);   //x1 y1
    glVertex3f(-50.0f,-50.0f,z); //x2 y2
    
    glVertex3f(50.0f,0.0f,z);    //x1 y1
    glVertex3f(-50.0f,0.0f,z);   //x2 y2

    glVertex3f(50.0f,-50.0f,z);  //x1 y1
    glVertex3f(-50.0f,50.0f,z);  //x2 y2
    */
    
    glEnd();
    
    glFlush();
}

void ChangeSize(GLsizei w, GLsizei h)
{
    GLfloat nRange=100.0;
    
   if(h==0)
       h=1;
    
    glViewport(0,0, w, h);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    if(w<=h)
    {
        glOrtho(-nRange,nRange,-nRange*h/w, nRange*h/w, -nRange, nRange);
    }
    else{glOrtho(-nRange*w/h,nRange*w/h,-nRange,nRange,-nRange,nRange);}
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void SetupRC(void)
{
    glClearColor(1.0f, 1.0f,1.0f, 1.0f); //black color
    
    
}

int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Line");
    glutInitWindowSize(800, 400);
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    
    SetupRC();
    
    glutMainLoop();
    
    return 0;
}


/*

 Execution Of for loop
 x1 y1 z1	 0.000000	50.000000	0.000000
 x2 y2 z2 	 0.004633	-50.000000	0.000000
 x1 y1 z1	 7.821495	49.384453	0.000000
 x2 y2 z2 	 -7.816915	-49.385178	0.000000
 x1 y1 z1	 15.450409	47.552967	0.000000
 x2 y2 z2 	 -15.446008	-47.554398	0.000000
 x1 y1 z1	 22.698906	44.550640	0.000000
 x2 y2 z2 	 -22.694778	-44.552746	0.000000
 x1 y1 z1	 29.388514	40.451393	0.000000
 x2 y2 z2 	 -29.384764	-40.454117	0.000000
 x1 y1 z1	 35.354519	35.356159	0.000000
 x2 y2 z2 	 -35.351250	-35.359428	0.000000
 x1 y1 z1	 40.450031	29.390387	0.000000
 x2 y2 z2 	 -40.447311	-29.394133	0.000000
 x1 y1 z1	 44.549591	22.700972	0.000000
 x2 y2 z2 	 -44.547485	-22.705099	0.000000
 x1 y1 z1	 47.552254	15.452611	0.000000
 x2 y2 z2 	 -47.550819	-15.457023	0.000000
 x1 y1 z1	 49.384090	7.823779	0.000000
 x2 y2 z2 	 -49.383366	-7.828366	0.000000
 x1 y1 z1	 50.000000	0.002310	0.000000
 x2 y2 z2 	 -50.000000	-0.006937	0.000000
 x1 y1 z1	 49.384815	-7.819215	0.000000
 x2 y2 z2 	 -49.385540	7.814639	0.000000
 x1 y1 z1	 47.553680	-15.448216	0.000000
 x2 y2 z2 	 -47.555115	15.443805	0.000000
 x1 y1 z1	 44.551689	-22.696854	0.000000
 x2 y2 z2 	 -44.553783	22.692736	0.000000
 x1 y1 z1	 40.452751	-29.386646	0.000000
 x2 y2 z2 	 -40.455467	29.382908	0.000000
 x1 y1 z1	 35.357792	-35.352886	0.000000
 x2 y2 z2 	 -35.361057	35.349617	0.000000
 x1 y1 z1	 29.392260	-40.448673	0.000000
 x2 y2 z2 	 -29.395998	40.445957	0.000000
 x1 y1 z1	 22.703035	-44.548538	0.000000
 x2 y2 z2 	 -22.707151	44.546440	0.000000
 x1 y1 z1	 15.454820	-47.551537	0.000000
 x2 y2 z2 	 -15.459214	47.550106	0.000000
 x1 y1 z1	 7.826078	-49.383728	0.000000
 x2 y2 z2 	 -7.830643	49.383003	0.000000
 x1 y1 z1	 0.004645	-50.000000	0.000000
 x2 y2 z2 	 -0.009266	50.000000	0.000000
*/