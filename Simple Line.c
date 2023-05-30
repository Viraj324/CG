#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>
#include <GL/glu.h>

int steps;

void setpixel(GLint x,GLint y){
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}

void Dda(float x1,float y1,float x2,float y2){
	float x,y,xin,yin,dx,dy;
	
	dx = (x2-x1);
	dy = (y2-y1);

	if(abs(dx) > abs(dy)){
		steps = abs(dx);
	}
	else{
		steps = abs(dy);
	}

	xin = (dx)/steps;
	yin = (dy)/steps;

	x = x1;
	y = y1;

	setpixel(x,y);

	for(int i = 1;i<= steps;i++){
		x = x + xin;
		y = y + yin;
		setpixel(x,y);
	}

	glFlush();
}

void draw(){
	float x1,y1;
	
	Dda(500,00,500,1000);
	Dda(00,500,1000,500);
}

void init(){
	glClear(GL_COLOR_BUFFER_BIT);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("Tryy");
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(0,1,0);
	gluOrtho2D(0,640,0,480);
}

int main(int argc,char** argv){
	glutInit(&argc,argv);
	init();
	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}
