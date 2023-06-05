#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;
#define RAD (3.14/180)

void init(){
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT); 
    glColor3f(1.0,1.0,1.0);
    gluOrtho2D(0.0,1200,0.0,700);
}


void draw_koch(float xa,float ya,float xb,float yb,int n){
    float xc,xd,yc,yd,midx,midy;
    xc = (2*xa+xb)/3;
    yc = (2*ya+yb)/3;
    xd = (2*xb+xa)/3;
    yd = (2*yb+ya)/3;

    midx = xc + ((xd-xc)*cos(60*RAD))+((yd-yc)*sin(60*RAD));
    midy = yc - ((xd-xc)*sin(60*RAD))+((yd-yc)*cos(60*RAD));

    if(n > 0){
        draw_koch(xa,ya,xc,yc,n-1);
        draw_koch(xc,yc,midx,midy,n-1);
        draw_koch(midx,midy,xd,yd,n-1);
        draw_koch(xd,yd,xb,yb,n-1);
    }
    else{
        glVertex2i(xa,ya);
        glVertex2i(xc,yc);
        glVertex2i(xc,yc);
        glVertex2i(midx,midy);
        glVertex2i(midx,midy);
        glVertex2i(xd,yd);
        glVertex2i(xd,yd);
        glVertex2i(xb,yb);
    }
}

void draw(int n){
    glBegin(GL_LINES);
    draw_koch(600,100,800,400,n);
    draw_koch(800,400,400,400,n);
    draw_koch(400,400,600,100,n);
    glEnd();
    glFlush();
}

int main(int argc,char** argv){
    int n;
    cout<<"Enter The number of itterations : ";
    cin>>n;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1200,700);
    glutInitWindowPosition(000,000);
    glutCreateWindow("Koch Curve");
    init();
    draw(n);
    glutMainLoop();
}
