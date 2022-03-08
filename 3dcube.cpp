#include<Windows.h>
#include<GL\glew.h>
#include<GL\freeglut.h>


void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glOrtho(-200, 200, -200, 200, -200, 200);
	glEnable(GL_DEPTH_TEST);
}

void disp()
{
	glTranslatef(10 , 10 ,10);
	glRotatef(50, 1, 0, 0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	disp();
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3d(0, 0, 0);
	glVertex3d(100, 0, 0);
	glVertex3d(100, 100, 0);
	glVertex3d(0, 100, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3d(0, 0, 100);
	glVertex3d(100, 0, 100);
	glVertex3d(100, 100, 100);
	glVertex3d(0, 100, 100);
	glEnd();
	glFlush();

}



int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow(" Tets");
	glutInitWindowSize(1000, 1000);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}