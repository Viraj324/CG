#include <GL/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

#define pi 3.14

int frmnum = 0;

void drawdisk(double rad){
	int i;
	glBegin(GL_POLYGON);
	for(i = 0;i<32;++i){
		GLdouble angle = 2 * pi *i/32;
		glVertex2d(rad*cos(angle),rad*sin(angle));
	}
	glEnd();
}

void drawbase(){
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2d(1,-1);
	glVertex2d(1,0);
	glVertex2d(6,0);
	glVertex2d(6,-1);
	glEnd();
	glFlush();
}

void drawflag(){
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2d(0,0);
	glVertex2d(1.5,0);
	glVertex2d(1.5,0.5);
	glVertex2d(0,0.5);
	glEnd();
	
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2d(0,0.5);
	glVertex2d(1.5,0.5);
	glVertex2d(1.5,1);
	glVertex2d(0,1);
	glEnd();
	
	glColor3f(1.0,0.5,0.5);
	glBegin(GL_POLYGON);
	glVertex2d(0,1);
	glVertex2d(1.5,1);
	glVertex2d(1.5,1.5);
	glVertex2d(0,1.5);
	glEnd();
}

void drawchakra(){
	int i;
	glColor3f(0.0,0.0,1.0);
	drawdisk(0.5);
	glColor3f(1.0,1.0,1.0);
	drawdisk(0.4);
	glColor3f(0.0,0.0,1.0);
	for(i = 0;i<24;++i){
		glRotatef(360/24,0,0,1);
		glBegin(GL_LINES);
		glVertex2d(0,0);
		glVertex2d(0.5,0);
		glEnd();
	}
}

void drawsun(){
	int i;
	glColor3f(1.0,1.0,0.0);
	drawdisk(1);
	for(i = 0;i<15;++i){
		glRotatef(360/15,0,0,1);
		glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(1.5,0);
		glEnd();
	}
}	


void draw(){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	drawbase();
	
	glColor3f(0.0,0.0,0.0);
	glLineWidth(50);
	glBegin(GL_LINES);
	glVertex2d(3,0);
	glVertex2d(3,3.5);
	glEnd();
	glLineWidth(1.0);
	
	glPushMatrix();
	glTranslated(3.02f,2.1f*(frmnum%300)/300,0);
	drawflag();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(3.77f,0.75+2.1f*(frmnum%300)/300,0);
	glScaled(0.5,0.5,0);
	drawchakra();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(6,3,0);
	glRotated(frmnum*0.7f,0,0,1);
	glScaled(0.5,0.5,1);
	drawsun();
	glPopMatrix();
	
	glutSwapBuffers();
}
	
	
void doframe(int v){
	frmnum++;
	glutPostRedisplay();
	glutTimerFunc(10,doframe,0);
}

void init(){
	glClearColor(0.5f,0.5f,0.8f,0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,7,-1,4,-1,1);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(1366,768);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Flag Hosting");
	init();
	glutDisplayFunc(draw);
	glutTimerFunc(100,doframe,0);
	glutMainLoop();
}
	
	
	
	
	
	
	
	
	
	
