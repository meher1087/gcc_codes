/*
 * smiley.c
 *
 *  Created on: Apr 10, 2014
 *      Author: kamath
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>
int sub_menu1;
int sub_menu2;
int sub_menu3;
int sub_menu4;
float theta1=0;
int flag=2;
/* Make the face rotate by increasing the angle of rotation in idle function*/
void idlefunc()
{
	theta1=theta1+1;
	if(theta1>360) theta1=0;
	glutPostRedisplay();			/* let message loop call display function */
}
void mytimer(int v)
{
	idlefunc();						/* call idle function every 100 millisecond */
	glutTimerFunc(100,mytimer,60);   /* register mytimer as a timer function
				 	 	 	 	 	    it will be called every 100 milliseconds
				 	 	 	 	 	 */
	glutPostRedisplay();
}
/* Draw a circle centered at x,y with color a,b,c */
void circle(int x,int y,int a,int b,int c)
{
	float rtheta,theta,r=150;
    glBegin(GL_POLYGON);
	for(theta=0;theta<360;theta++)
	{
		rtheta=theta*3.142/180;
		glColor3f(a,b,c);
		glVertex3f(x+r*cos(rtheta),y+r*sin(rtheta),0);
	}
	glEnd();
}
/* Draw eyes which are quad strips */
void rightoletter(int x,int y)
{
	GLfloat thr,x1,x2,y1,y2;
	int i;
	glColor3f(1,0,0);		// red color eyes
	glBegin(GL_QUAD_STRIP);
	for(i=0;i<=196;i++)
	{
		thr=3.142*i/6.0;
		x1=5*cos(thr);		// inner radius 5
		y1=5*sin(thr);
		x2=10*cos(thr);		// outer radius 10
		y2=10*sin(thr);
		glVertex3f(x1+x+45,y1+y+45,0);
		glVertex3f(x2+x+45,y2+y+45,0);
	}
	glEnd();
}
/* Draw eyes which are quad strips */
void leftoletter(int x,int y)
{
	GLfloat thr,x1,x2,y1,y2;
	int i;
	glColor3f(1,0,0);       // red color eyes
	glBegin(GL_QUAD_STRIP);
	for(i=0;i<=196;i++)
	{
		thr=3.142*i/6;
		x1=5*cos(thr);		// inner radius 5
		y1=5*sin(thr);
		x2=10*cos(thr);		// outer radius 10
		y2=10*sin(thr);
		glVertex3f(x1+x-45,y1+y+45,0);
		glVertex3f(x2+x-45,y2+y+45,0);
	}
	glEnd();
}
/*
 * Draw an arc to depict smiling face
 */
void smile(int x,int y)
{
	float rtheta,theta,r=90;
	do
	{
	glBegin(GL_POINTS);
    for(theta=225;theta<315;theta++)
	{
		rtheta=theta*3.142/180;
		glColor3f(0,0,0);
		glVertex3f(x+r*cos(rtheta),y+r*sin(rtheta),0);
	}
	glEnd();
	r=r+0.5;
	}while(r<92);
}
/*
 * Inverted arc from 45 degrees to 135 degrees to denote sad face
 */
void sad(int x,int y)
{
	float rtheta,theta,r=90;
	do
	{
	glBegin(GL_POINTS);
    for(theta=45;theta<135;theta++)
	{
		rtheta=theta*3.142/180;
		glColor3f(0,0,0);
		glVertex3f(x+r*cos(rtheta),y-150+r*sin(rtheta),0);
	}
	glEnd();
	r=r+0.5;
	}while(r<92);
}
/*
 * Surprise is shown as filled circle using polygon
 */
void surprise(int x,int y)
{
	float rtheta,theta,r=1;
	do
	{
    glBegin(GL_POLYGON);
	for(theta=0;theta<360;theta++)
	{
		rtheta=theta*3.142/180;
		glColor3f(0,0,0);
		glVertex3f(x+r*cos(rtheta),y-84+r*sin(rtheta),0);
	}
	glEnd();
	r=r+0.05;
	}while(r<24);
}
/*
 * Draw an arc and fill inside using polygon
 * uncomment the commented lines in this function
 * to get the smiling face to laugh
 */
void laugh(int x,int y)
{
	float rtheta,theta,r=90;
//	do
//	{
    for(theta=225;theta<315;theta++)
	{
		rtheta=theta*3.142/180;
		glColor3f(0,0,0);				// select black color for the mouth
		glBegin(GL_POLYGON);
		glVertex3f(x+r*cos(rtheta),y+r*sin(rtheta),0);
		glVertex3f(x+r*cos(225*3.142/180),y+r*sin(225*3.142/180),0);
		glVertex3f(x+r*cos(315*3.142/180),y+r*sin(315*3.142/180),0);
		glEnd();
	}
//	y--;
//	}while(y>-15);
}
void nose(int x,int y)
{
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex3f(x,y+30,0);
	glVertex3f(x,y-45,0);
	glEnd();
	glFlush();
}
/*
 * These sample functions could have been written in one only
 */
void sample(int a,int b,int c)
{
		circle(0,0,a,b,c);
		rightoletter(0,0);
        leftoletter(0,0);
		smile(0,0);			//smile
		nose(0,0);
		glFlush();
}
void sample1(int a,int b,int c)
{
		circle(0,0,a,b,c);
		rightoletter(0,0);
        leftoletter(0,0);
		sad(0,0);			//sad
		nose(0,0);
		glFlush();
}
void sample2(int a,int b,int c)
{
		circle(0,0,a,b,c);
		rightoletter(0,0);
        leftoletter(0,0);
		surprise(0,0);   // surprise
		nose(0,0);
		glFlush();
}
void sample3(int a,int b,int c)
{
		circle(0,0,a,b,c);
		rightoletter(0,0);
        leftoletter(0,0);
		laugh(0,0);			// laugh
		nose(0,0);
		glFlush();
}
void smenu1_func(int n)
{
	/*
	 * could have reduced number of lines by typing
	 * flag=n-1;
	 *  instead of switch
	 */
	switch(n)
	{
		case 1:flag=0;
			   break;
		case 2:flag=1;
			   break;
		case 3:flag=2;
			   break;
	}
	glutPostRedisplay();
}
void smenu2_func(int n)
{
	/*
		 * could have reduced number of lines by typing
		 * flag=n-1;
		 *  instead of switch
		 */
	switch(n)
	{
		case 4:flag=3;
			   break;
		case 5:flag=4;
			   break;
		case 6:flag=5;
			   break;
	}
	glutPostRedisplay();
}
void smenu3_func(int n)
{
	/*
		 * could have reduced number of lines by typing
		 * flag=n-1;
		 *  instead of switch
		 */
	switch(n)
	{
		case 7:flag=6;
			   break;
		case 8:flag=7;
			   break;
		case 9:flag=8;
			   break;
	}
	glutPostRedisplay();
}
void smenu4_func(int n)
{
	/*
		 * could have reduced number of lines by typing
		 * flag=n-1;
		 *  instead of switch
		 */
	switch(n)
	{
		case 10:flag=9;
			   break;
		case 11:flag=10;
			   break;
		case 12:flag=11;
			   break;
	}
	glutPostRedisplay();
}
void menu_func(int n)
{
	/*
	 * if exit button is pressed quit the program
	 */
	if(n==13)
		exit(0);
}
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-250,250,-250,250,-250,250);
    glMatrixMode(GL_MODELVIEW);
	glClearColor(0,0,0,0);
}
/*
 * In this function you draw the face after rotation
 */
void display()
{
int i;
	glClearColor(0,0,0,0);   // set background color to black
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(0,0,0,0);
	char s1[]="right click on the window for menu";
	char s2[]="the above graphics is used in mobile applications";

	glColor3f(1,1,1);    //set white color
	glRasterPos2i(-200,200);
	for(i=0;i<strlen(s1);i++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13,s1[i]);
	glRasterPos2i(-200,-200);
	for(i=0;i<strlen(s2);i++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13,s2[i]);
	glLoadIdentity();
	glRotatef(theta1,0,1,0);      // change back the last three to 1,0,0 for x axis rotation
	/*
	 * call sample=> smiling face
	 * call sample1=> sad face
	 * call sample2=> surprise face
	 * call sample3=> laugh face
	 */
	if(flag==0)
	{
		sample(0,1,0);
	}
	if(flag==1)
	{
		sample(0,0,1);
	}
	if(flag==2)
	{
		sample(1,1,0);
	}
	if(flag==3)
	{
		sample1(0,1,1);
	}
	if(flag==4)
	{
		sample1(1,0,1);
	}
	if(flag==5)
	{
		sample1(1,1,1);
	}
	if(flag==6)
	{
		sample2(1,1,0);
	}
	if(flag==7)
	{
		sample2(0,1,1);
	}
	if(flag==8)
	{
		sample2(1,1,1);
	}
	if(flag==9)
	{
		sample3(0,1,0);
	}
	if(flag==10)
	{
		sample3(1,0,1);
	}
	if(flag==11)
	{
		sample3(0,0,1);
	}
	glFlush();
	glutSwapBuffers();

}
void myreshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w>h)
	{
		glOrtho(-250*w/h,250*w/h,-250,250,-250,250);
	}
	else
	{
		glOrtho(-250,250,-250*h/w,250*h/w,-250,250);
	}
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}
int main(int argc,char**argv)
{
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);  // use double buffering
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500,500);
glutInit(&argc,argv);
   	glutCreateWindow("smiley");
	myinit();
	glutDisplayFunc(display);
	/*
	 * Create menus
	 */
	sub_menu1=glutCreateMenu(smenu1_func);
	glutAddMenuEntry("green",1);
	glutAddMenuEntry("blue",2);
	glutAddMenuEntry("yellow",3);
	sub_menu2=glutCreateMenu(smenu2_func);
	glutAddMenuEntry("cyan",4);
	glutAddMenuEntry("magenta",5);
	glutAddMenuEntry("white",6);
	sub_menu3=glutCreateMenu(smenu3_func);
	glutAddMenuEntry("yellow",7);
	glutAddMenuEntry("cyan",8);
	glutAddMenuEntry("white",9);
	sub_menu4=glutCreateMenu(smenu4_func);
	glutAddMenuEntry("green",10);
	glutAddMenuEntry("magenta",11);
	glutAddMenuEntry("blue",12);
	glutCreateMenu(menu_func);
	glutAddSubMenu("smile",sub_menu1);
	glutAddSubMenu("sad",sub_menu2);
	glutAddSubMenu("surprise",sub_menu3);
	glutAddSubMenu("laugh",sub_menu4);
	glutAddMenuEntry("quit",13);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	/*
	 * register idle function for callback
	 */
	glutIdleFunc(idlefunc);
	glEnable(GL_DEPTH_TEST);			//enable depth test
	glutReshapeFunc(myreshape);
	glutTimerFunc(100,mytimer,60);
	glutMainLoop();
return 0;
}

