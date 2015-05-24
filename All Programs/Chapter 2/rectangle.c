/ Simple Opengl Rectangle

#include <stdio.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>

void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // this call will actully ckear tge buffer
    
    glColor3f(1.0f,0.0f,0.0f);  // this will set Current drawing color to Red
    
    glRectf(-25.0f,25.0f,25.0f,-25.0f);  // draw filled rectangle with current color
    
    glFlush();
}

void ChangeSize(GLsizei w,GLsizei h)
{
    GLfloat aspectRatio;
    	
    if(h==0)
        h=1;
    
    glViewport(0, 0, w,h); // set view port to current window size; x ,y, width , height
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    
    aspectRatio=(GLfloat)w/(GLfloat)h;
    
    if(w<=h)
    {
        glOrtho(-100.0, 100.0,-100.0/aspectRatio,-100.0/aspectRatio,1.0,-1.0);
        
        // left -x ,right +x ,bottom -y ,top +y, near z , far -z
    }
    else
        glOrtho(-100.0 * aspectRatio, 100.0 * aspectRatio,-100.0,100.0,1.0,-1.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void SetupRC()
{
    glClearColor(0.0f,0.0f,1.0f,1.0f);  // this function sets the color for cleaning the window.
}

int main(int argc,char * argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("hello GL");
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    SetupRC();
    
    glutMainLoop();
    return 0;
}



/*programme

 - glutInit(&argc,argv); This is glut specific call it initiates glut library
 - glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); 
 
   here GLUT_SINGLE | GLUT_RGBA are Flags which indicate single buffering and color mode RGBA
 
   After initialization of the glut we must tell glut library what display mode to use while creating the window. 
   There are 2 types of buffers
    1) Single Buffered - All graphics are performed on window displayes
    2) Double Buffered - In this all drawings are actully performed OFF SCREEN buffer
                      and whenever needed it swaped into view on the window.
 
   
   This method is useful for producing animation effect.
 
 - glutCreateWindow("Hello GL"); This will create Opengl Window named HelloGL
 
 - glutDisplayFunc(RenderScene);
 
   This Function gets executed whenever window gets resized / uncovered 
   [This is the place where we can put out opengl rendering calls.]
   
 - glutReshapeFunc(changeSize);
 
   This function we call when we need to change the window dimension
 
 - SetupRC();
   here we do any opengl initializations that should be performed before rendering;
 
 - glutMainLoop();
    This function stats the glut framework running. it never reutrns untill window closed.
    This function performed all os related things like specific messages and keystroke

 
 
 
 Aspect Ratio: Width of the Window / Height of the window.
 
 Orthographic Projection:
 it is uesd for clippung the volume
 - Square remains same even if we change window dimension.
 
*/