// Car animation 
#include<GL/glut.h>
#include<math.h>
#include<unistd.h>
#include <chrono>
#include <thread>

#define pi 3.142857

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluOrtho2D(0, 200, 0, 200);
}

void createCircle(float radius , float xShift , float yShift,  int R,int G, int B){
    float theta;
   glBegin(GL_POINTS);
   glColor3f(1,1,1);

    for(float i=0;i<(2*pi);i=i+0.001){
        glVertex2f(xShift +radius*sin(i), yShift + radius*cos(i));
        
       
    }
   glEnd();
}

void lineB(float x1 , float y1 , float x2 , float y2){

glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
 glEnd();
}


void car(float z) //z is the no of time the function is called
{
	float x,y;
    createCircle(3,z,25,1,0,0);
    createCircle(3,z+15,25,1,0,0);
    lineB(z-10,25, z+15+10 , 25);
    lineB(z,40, z+10 , 40);
    lineB(z-10,25 , z-10, 30);
    lineB(z+10+15,25 , z+10+15, 30);
    lineB(z-10,30, z+15+10 , 30);

    lineB(z,40, z-5,30);
    
    lineB(z+15 , 30, z+10 , 40);
    

    
    
}



void display()
{


    for(int i= 1 ; i<200; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        	glClear(GL_COLOR_BUFFER_BIT);
	    car(i);
	    glFlush();
    }
}

int main(int argc, char** argv)
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	
	
	glutInitWindowSize(500, 500); 
	glutInitWindowPosition(50,50); 
	
	
	glutCreateWindow("Moving Car"); 
	init(); 
	glutDisplayFunc(display); 
	glutMainLoop(); 
}
