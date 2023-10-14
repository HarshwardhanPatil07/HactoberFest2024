#include<GL/glut.h>
#include <cmath>

void init()
{
 glClearColor(0,0,0,0);
 glMatrixMode(GL_PROJECTION);
 glOrtho(-100,100,-100,100,20,-20);
}


void display()
{
  glClear(GL_COLOR_BUFFER_BIT);



    glColor3f(1.0,0.0,1.0);
 


        glBegin(GL_LINES);
        glColor3f(1.0,0.0,0.0);
        for(int i=0;i<360;i++)
            {
             float theta1= (i+0.5)*3.142/180;
             float theta2= (i-0.5)*3.142/180;
             glVertex2f(90*cos(theta1),90*sin(theta1));
             glVertex2f(90*cos(theta2),90*sin(theta2));
        }
        glEnd();

        float rad, x ,y;



        glBegin(GL_LINES);
        glColor3f(1.0,0.0,1.0);
        rad = 90;
        x=0.0f;y=0.0f;
        while(x<=rad)
        {
            y= sqrt((rad*rad - x*x));
            glVertex2f(x,y);
            glVertex2f(x,-y);
            glVertex2f(-x,y);
            glVertex2f(-x,-y);
            glVertex2f(y,x);
            glVertex2f(-y,x);
            glVertex2f(y,-x);
            glVertex2f(-y,-x);
            x=x+2;
        }
        glEnd();


        glBegin(GL_POLYGON);
        glColor3f(0.0,0.0,0.0);
        for(int i=0;i<360;i++)
        {
            float theta1= (i+0.5)*3.142/180;
            glVertex2f(80*cos(theta1),80*sin(theta1));
        }
        glEnd();




        glBegin(GL_LINES);
        glColor3f(0.0,0.0,1.0);
        rad = 80;
        x=0.0f;y=0.0f;
        while(x<=rad)
        {
            y= sqrt((rad*rad - x*x));
            glVertex2f(x,y);
            glVertex2f(x,-y);
            glVertex2f(-x,y);
            glVertex2f(-x,-y);
            
            x=x+2;
        }
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0.0,0.0,1.0);
        for(int i=0;i<360;i++)
            {
             float theta1= (i+0.5)*3.142/180;
             float theta2= (i-0.5)*3.142/180;
             glVertex2f(80*cos(theta1),80*sin(theta1));
             glVertex2f(80*cos(theta2),80*sin(theta2));
        }
        glEnd();




        glBegin(GL_POLYGON);
        glColor3f(0.0,0.0,0.0);
        for(int i=0;i<360;i++)
        {
            float theta1= (i+0.5)*3.142/180;
            glVertex2f(70*cos(theta1),70*sin(theta1));
        }
        glEnd();


        glBegin(GL_LINES);
        glColor3f(0.6,0.1,0.2);
        rad = 70;
        x=0.0f;y=0.0f;
        while(x<=rad)
        {
            y= sqrt((rad*rad - x*x));
            glVertex2f(x,y);
            glVertex2f(x,-y);
            glVertex2f(-x,y);
            glVertex2f(-x,-y);
            glVertex2f(y,x);
            glVertex2f(-y,x);
            glVertex2f(y,-x);
            glVertex2f(-y,-x);
            x=x+2;
        }
        glEnd();

        glBegin(GL_LINES);
        glColor3f(1.0,0.0,1.0);
        for(int i=0;i<360;i++)
            {
             float theta1= (i+0.5)*3.142/180;
             float theta2= (i-0.5)*3.142/180;
             glVertex2f(70*cos(theta1),70*sin(theta1));
             glVertex2f(70*cos(theta2),70*sin(theta2));
        }
        glEnd();




        glBegin(GL_POLYGON);
        glColor3f(0.0,0.0,0.0);
        for(int i=0;i<360;i++)
        {
            float theta1= (i+0.5)*3.142/180;
            glVertex2f(60*cos(theta1),60*sin(theta1));
        }
        glEnd();


        glBegin(GL_LINES);
        glColor3f(1.0,1.0,1.0);
        rad = 60;
        x=0.0f;y=0.0f;
        while(x<=rad)
        {
            y= sqrt((rad*rad - x*x));
            glVertex2f(x,y);
            glVertex2f(x,-y);
            glVertex2f(-x,y);
            glVertex2f(-x,-y);
            glVertex2f(y,x);
            glVertex2f(-y,x);
            glVertex2f(y,-x);
            glVertex2f(-y,-x);
            x=x+2;
        }
        glEnd();

        glBegin(GL_LINES);
        glColor3f(1.0,1.0,1.0);
        for(int i=0;i<360;i++)
            {
             float theta1= (i+0.5)*3.142/180;
             float theta2= (i-0.5)*3.142/180;
             glVertex2f(60*cos(theta1),60*sin(theta1));
             glVertex2f(60*cos(theta2),60*sin(theta2));
        }
        glEnd();





        glBegin(GL_POLYGON);
        glColor3f(0.0,0.0,0.0);
        for(int i=0;i<360;i++)
        {
            float theta1= (i+0.5)*3.142/180;
            glVertex2f(50*cos(theta1),50*sin(theta1));
        }
        glEnd();


        glBegin(GL_LINES);
        glColor3f(0.0,0.9,0.3);
        rad = 50;
        x=0.0f;y=0.0f;
        while(x<=rad)
        {
            y= sqrt((rad*rad - x*x));
           
            glVertex2f(y,x);
            glVertex2f(-y,x);
            glVertex2f(y,-x);
            glVertex2f(-y,-x);
            x=x+2;
        }
        glEnd();


        glBegin(GL_LINES);
        glColor3f(0.0,1.0,0.0);
        for(int i=0;i<360;i++)
            {
             float theta1= (i+0.5)*3.142/180;
             float theta2= (i-0.5)*3.142/180;
             glVertex2f(50*cos(theta1),50*sin(theta1));
             glVertex2f(50*cos(theta2),50*sin(theta2));
        }
        glEnd();





        glBegin(GL_POLYGON);
        glColor3f(0.0,0.0,0.0);
        for(int i=0;i<360;i++)
        {
            float theta1= (i+0.5)*3.142/180;
            glVertex2f(40*cos(theta1),40*sin(theta1));
        }
        glEnd();


        glBegin(GL_LINES);
        glColor3f(0.0,0.9,0.7);
        rad = 40;
        x=0.0f;y=0.0f;
        while(x<=rad)
        {
            y= sqrt((rad*rad - x*x));
            glVertex2f(x,y);
            glVertex2f(x,-y);
            glVertex2f(-x,y);
            glVertex2f(-x,-y);
            /*
            glVertex2f(y,x);
            glVertex2f(-y,x);
            glVertex2f(y,-x);
            glVertex2f(-y,-x);
            */
            x=x+2;
        }
        glEnd();


        glBegin(GL_LINES);
        glColor3f(0.0,1.0,0.3);
        for(int i=0;i<360;i++)
            {
             float theta1= (i+0.5)*3.142/180;
             float theta2= (i-0.5)*3.142/180;
             glVertex2f(40*cos(theta1),40*sin(theta1));
             glVertex2f(40*cos(theta2),40*sin(theta2));
        }
        glEnd();




        glBegin(GL_POLYGON);
        glColor3f(0.0,0.0,0.0);
        for(int i=0;i<360;i++)
        {
            float theta1= (i+0.5)*3.142/180;
            glVertex2f(30*cos(theta1),30*sin(theta1));
        }
        glEnd();


        glBegin(GL_LINES);
        glColor3f(0.0,0.1,0.9);
        rad = 30;
        x=0.0f;y=0.0f;
        while(x<=rad)
        {
            y= sqrt((rad*rad - x*x));
            glVertex2f(x,y);
            glVertex2f(x,-y);
            glVertex2f(-x,y);
            glVertex2f(-x,-y);
            glVertex2f(y,x);
            glVertex2f(-y,x);
            glVertex2f(y,-x);
            glVertex2f(-y,-x);
            x=x+2;
        }
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0.1,0.3,1.0);
        for(int i=0;i<360;i++)
            {
             float theta1= (i+0.5)*3.142/180;
             float theta2= (i-0.5)*3.142/180;
             glVertex2f(30*cos(theta1),30*sin(theta1));
             glVertex2f(30*cos(theta2),30*sin(theta2));
        }
        glEnd();



        glBegin(GL_POLYGON);
        glColor3f(0.0,0.0,0.0);
        for(int i=0;i<360;i++)
        {
            float theta1= (i+0.5)*3.142/180;
            glVertex2f(20*cos(theta1),20*sin(theta1));
        }
        glEnd();


        glBegin(GL_LINES);
        glColor3f(0.5,0.5,0.0);
        rad = 20;
        x=0.0f;y=0.0f;
        while(x<=rad)
        {
            y= sqrt((rad*rad - x*x));
            glVertex2f(x,y);
            glVertex2f(x,-y);
            glVertex2f(-x,y);
            glVertex2f(-x,-y);
            glVertex2f(y,x);
            glVertex2f(-y,x);
            glVertex2f(y,-x);
            glVertex2f(-y,-x);
            x=x+2;
        }
        glEnd();

        glBegin(GL_LINES);
        glColor3f(1.0,0.6,0.0);
        for(int i=0;i<360;i++)
            {
             float theta1= (i+0.5)*3.142/180;
             float theta2= (i-0.5)*3.142/180;
             glVertex2f(20*cos(theta1),20*sin(theta1));
             glVertex2f(20*cos(theta2),20*sin(theta2));
        }
        glEnd();





        glBegin(GL_POLYGON);
        glColor3f(0.0,0.0,0.0);
        for(int i=0;i<360;i++)
        {
            float theta1= (i+0.5)*3.142/180;
            glVertex2f(10*cos(theta1),10*sin(theta1));
        }
        glEnd();


        glBegin(GL_LINES);
        glColor3f(0.9,0.9,0.3);
        rad = 10;
        x=0.0f;y=0.0f;
        while(x<=rad)
        {
            y= sqrt((rad*rad - x*x));
            glVertex2f(x,y);
            glVertex2f(x,-y);
            glVertex2f(-x,y);
            glVertex2f(-x,-y);
            glVertex2f(y,x);
            glVertex2f(-y,x);
            glVertex2f(y,-x);
            glVertex2f(-y,-x);
            x=x+2;
        }
        glEnd();

        glBegin(GL_LINES);
        glColor3f(1.0,1.0,0.0);
        for(int i=0;i<360;i++)
            {
             float theta1= (i+0.5)*3.142/180;
             float theta2= (i-0.5)*3.142/180;
             glVertex2f(10*cos(theta1),10*sin(theta1));
             glVertex2f(10*cos(theta2),10*sin(theta2));
        }
        glEnd();

  glFlush();
}





int main(int argc,char **argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_RGB);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(800,100);
 glutCreateWindow("Sumyak circles pattern");
 init();
 glutDisplayFunc(display);
 glutMainLoop();
}
