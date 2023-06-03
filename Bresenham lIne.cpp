#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

void plotp(int x,int y){
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void Bresnham(int x1,int y1,int x2,int y2){
	int dx,dy,incx,incy,inc1,inc2,x,y,e;
	dx = x2 - x1;
	dy = y2 - y1;
	if(dx < 0){
		dx = -dx;
	}
	if(dy < 0){
		dy = -dy;
	}
	incx = 1;
	if(x2 < x1){
		incx = -1;
	}
	incy = 1;
	if(y2 < y1){
		incy = -1;
	}
	x = x1;
	y = y1;
	if(dx >= dy){
		plotp(x,y);
		e = 2 * dy - dx;
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		for(int i = 0;i<dx;i++){
			if(e >=0){
				y += incy;
				e += inc1;
			}
			else{
				e += inc2;
			}
			x += incx;
			plotp(x,y);
		}
	}
	else{
		plotp(x,y);
		e = 2 * dx - dy;
		inc1 = 2 * (dx - dy);
		inc2 = 2 * dx;
		for(int i = 0;i<dy;i++){
			if(e >=0){
				x += incx;
				e += inc1;
			}
			else{
				e += inc2;
			}
			y += incy;
			plotp(x,y);
		}		
	}
	glFlush();
}

void draw(){
	glColor3f(0,0,0);
	Bresnham(100,500,350,500);
}

void init(){
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0,800,800,0);
}

int main(int argc,char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(800,800);
	glutCreateWindow("Bresenham Line");
	init();
	glutDisplayFunc(draw);
	glutMainLoop();
}


