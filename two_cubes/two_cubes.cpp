// when you set the glPushMatrix(); it distinguishes where
//to start the transformations for an object
// to set where to stop these transformations you would call
//glPopMatrix();

// for instance, if you take the push and pop matrix code out of
//this file
// cube1 would act normal, but cube2 would be rotating it’s
//own way as well
// as including the rotation from cube1

#include <GL/gl.h>
#include <GL/glut.h>

GLfloat angle = 0.0; //angle for cube1
GLfloat tangle = 0.0; //angle for cube2
GLfloat x1=1.5, y1=0, z1=-10,x2=-1.5,y2=0,z2=-10;
 int inc=1;
 char f = 'l';
 
 bool* keyStates = new bool[256];
 
 
void keyOperations (void) {  
if (keyStates['a']) { // If the 'a' key has been pressed  
x1 -= 0.1;
x2 -= 0.1; // Perform 'a' key operations  
}  

if (keyStates['d']) { // If the 'a' key has been pressed  
x1 += 0.1;
x2 += 0.1; // Perform 'a' key operations  
}

if (keyStates['w']) { // If the 'a' key has been pressed  
z1 = -20;
//x2 += 0.1; // Perform 'a' key operations  
}

  
if(!keyStates['w']){
z1 = -10;
}

}  
 
void cube (void) {
glPushMatrix(); //set where to start the current object transformations
glTranslatef(x1,y1,z1); //move cube1 to the right
//glRotatef(angle, 1.0, 0.0, 0.0);
//glRotatef(angle, 0.0, 1.0, 0.0);
//glRotatef(angle, 0.0, 0.0, 1.0);
glColor3f(1.0, 0.0, 0.0); //change cube1 to red
glutWireCube(2);
glPopMatrix(); //end the current object transformations
}

void cube2 (void) {
glPushMatrix(); //set where to start the current object
//transformations
glTranslatef(x2,y2,z2); //move cube2 to the left
//glRotatef(tangle, 1.0, 0.0, 0.0);
//glRotatef(tangle, 0.0, 1.0, 0.0);
//glRotatef(tangle, 0.0, 0.0, 1.0);
glColor3f(0.0, 1.0, 0.0); //change cube2 to green
glutWireCube(2);
glPopMatrix(); //end the current object transformations
}

void display (void) {
keyOperations();
glClearColor (0.0,0.0,0.0,1.0);
glClear (GL_COLOR_BUFFER_BIT);
glLoadIdentity();
gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
cube();
cube2();
glutSwapBuffers();
angle+= 1.0;
tangle+= 2.0;
}

void keyPressed (unsigned char key, int x, int y) {  
keyStates[key] = true; // Set the state of the current key to pressed  
}  
  
void keyUp (unsigned char key, int x, int y) { 
 
keyStates[key] = false; // Set the state of the current key to not pressed  
}  

void reshape (int w, int h) {
glViewport (0, 0, (GLsizei)w, (GLsizei)h);
glMatrixMode (GL_PROJECTION);
glLoadIdentity ();
gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
glMatrixMode (GL_MODELVIEW);
}

int main (int argc, char **argv) {
glutInit (&argc, argv);
glutInitDisplayMode (GLUT_DOUBLE);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100, 100);
glutCreateWindow ("A basic OpenGL Window");
glutDisplayFunc (display);
glutIdleFunc (display);
glutReshapeFunc (reshape);

glutKeyboardFunc(keyPressed); // Tell GLUT to use the method "keyPressed" for key presses  
glutKeyboardUpFunc(keyUp); // Tell GLUT to use the method "keyUp" for key up events  
  
  
glutMainLoop ();
return 0;
}

