//For the equilateral Triangle, the point of origin is given as (0, 0) and the size(length) of one side is given as 50px
//Same cordinates for Rotaton ,Translation,Scaling

#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

static int flag;

int length,xi,yi,choice;
double angle,ET[3][3],ETResult[3][3];


void drawET(double ET[3][3]){
	int i;
	glBegin(GL_LINE_LOOP);
	for(i = 0;i<3;i++){
		glVertex2i(ET[i][0],ET[i][1]);
	}
	glEnd();
}

void display(){
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	gluOrtho2D(-320,320,-240,240);
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex2i(-320,0);
		glVertex2i(320,0);
		glVertex2i(0,-240);
		glVertex2i(0,240);
	glEnd();
	
	glColor3f(1,0,0);
	drawET(ET);
	glFlush();
}

void mutlti3x3(double ET[3][3],double temp[3][3]){
	double sum;
	int i,j,k;
	for(i = 0;i<3;i++){
		for(j=0;j<3;j++){
		sum = 0;
			for(k = 0;k<3;k++){
				sum = sum+ET[i][k]*temp[k][j];
			}
			ETResult[i][j] = sum;
		}
	}
}

void trasnlationET(){
	double tx,ty,temp[3][3];
	cout<<"\nTranslating Equilateral Triangle";
	cout<<"\nEnter tx";
	cin>>tx;
	cout<<"\nEnter ty";
	cin>>ty;
	
	temp[3][3] = {0};
	temp[0][0] = 1;
	temp[1][1] = 1;
	temp[2][2] = 1;
	temp[2][0] = tx;
	temp[2][1] = ty;
	
	mutlti3x3(ET,temp);
	glColor3f(0.0,1.0,0.0);
	drawET(ETResult);
}

void rotationET(){
	double rx,ry,angle,temp[3][3];
	
	cout<<"***ROTATION**\n";
	cout<<"\nArbitary Point(x,y) : ";
	cin>>rx;
	cin>>ry;
	cout<<"\nAngle n Degrees : ";
	cin>>angle;
	
	angle = angle*(3.14/180);
	
	temp[3][3] = {0};
	temp[0][0] = cos(angle);
	temp[0][1] = sin(angle);
	temp[1][0] = -sin(angle);
	temp[1][1] = cos(angle);
	temp[2][0] = (-(rx*cos(angle))+(ry*sin(angle))+rx);
	temp[2][1] = (-(rx*sin(angle))-(ry*cos(angle))+ry);
	temp[2][2] = 1;
	
	mutlti3x3(ET,temp);
	glColor3f(0.0,1.0,0.0);
	drawET(ETResult);
}

void scaleET(){
	double sx,sy,temp[3][3];
	
	cout<<"\nScaling Equilateral Triangle";
	cout<<"\nSx : ";
	cin>>sx;
	cout<<"\nSy : ";
	cin>>sy;
	
	temp[3][3] = 0;
	temp[0][0] = sx;
	temp[1][1] = sy;
	temp[2][2] = 1;
	
	mutlti3x3(ET,temp);
	glColor3f(1.0,1.0,0.0);
	drawET(ETResult);
}

void Menu(int item){
	switch(item){
		case 1:
			trasnlationET();
			break;
		case 2:
			rotationET();
			break;
		case 3:
			scaleET();
			break;
		case 4:
			exit(0);
			break;
		default:
			cout<<"Invalid Input";
			break;
	}
}


int main(int argc,char** argv){
	int choice  = 0,i,j;
	cout<<"\n Menu";
	cout<<"\n1. To Draw Equilateral Trianglel";
	cout<<"\n2. To Exit";
	cout<<"\n Enter your choice.. : ";
	cin>>choice;
	
	switch(choice){
		int i,j;
		case 1:
			flag = 0;
			cout<<"\nEnter the X cordinates of the base point : ";
			cin>>xi;
			cout<<"\nEnter the Y cordinates of the base point : ";
			cin>>yi;
			cout<<"\nEnter the length of the side : ";
			cin>>length;
			
			for(i = 0;i<3;i++){
				for(j = 0;j<3;j++){
					ET[i][j] = 1;
				}
			}
			ET[0][0] = xi;
			ET[0][1] = yi;
			ET[1][0] = xi + length;
			ET[1][1] = yi;
			ET[2][0] = length/2+xi;
			ET[1][1] = (sqrt(3)/2*length)+yi;
			break;
      case 2:
          		exit(0);
          		break;
       default :
          		cout<<"\n Invalid Input..";
          		break;       				
	}
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(640,480);
	glutCreateWindow("2d transformations");
	
	glutDisplayFunc(display);
	glutCreateMenu(Menu);
		glutAddMenuEntry("1.Translation",1);
		glutAddMenuEntry("2.Rotation",2);
		glutAddMenuEntry("3.Scaling",3);
		glutAddMenuEntry("4.Exit",4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
}
