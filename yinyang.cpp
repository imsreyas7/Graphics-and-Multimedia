#include<GL/glut.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>
using namespace std;

void myInit() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0, 0.0, 0.0, 1.0);
    //glColor3f(0.0, 0.0, 0.0);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1000, 1000, -1000, 1000);

    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);

}

void plottop(int x, int y, int xc, int yc) {
    glVertex2d(x + xc, y + yc);
    //glVertex2d(x + xc, -y + yc);
    glVertex2d(-x + xc, y + yc);
    //glVertex2d(-x + xc, -y + yc);

    glVertex2d(y + xc, x + yc);
    //glVertex2d(y + xc, -x + yc);
    glVertex2d(-y + xc, x + yc);
    //glVertex2d(-y + xc, -x + yc);
}

void plotbot(int x, int y, int xc, int yc) {
    //glVertex2d(x + xc, y + yc);
    glVertex2d(x + xc, -y + yc);
    //glVertex2d(-x + xc, y + yc);
    glVertex2d(-x + xc, -y + yc);

    //glVertex2d(y + xc, x + yc);
    glVertex2d(y + xc, -x + yc);
    //glVertex2d(-y + xc, x + yc);
    glVertex2d(-y + xc, -x + yc);
}

void midpointcircle(int xc, int yc, int r, int choice) {
    int x = r, y = 0, pk = 1 - r;

    glBegin(GL_POINTS);
    if (choice == 1)
        plottop(x, y, xc, yc);
    else
        plotbot(x, y, xc, yc);

    while (x > y) {
        y++;

        if (pk < 0) {
            pk += (2 * y) + 1;
        }
        else {
            x--;
            pk += (2 * y) - (2 * x) + 1;
        }
        if (choice == 1)
            plottop(x, y, xc, yc);
        else
            plotbot(x, y, xc, yc);
    }
    glEnd();
}

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    
   
    
    
    for (GLfloat i = 0;i < 150;i += 0.1) {
        glColor3d(0, 0, 0);
        midpointcircle(150, 300, i, 1);
    }
    
    for (GLfloat i = 0;i < 150;i += 0.1) {
        glColor3d(1, 1, 1);
        midpointcircle(450, 300, i, 2);
    }

    glColor3d(1, 1, 1);
    for (GLfloat i = 0;i < 50;i+=0.1)
        midpointcircle(150, 200, i, 1);
    for (GLfloat i = 0;i < 50;i+=0.1)
        midpointcircle(150, 200, i, 2);
    glColor3d(0, 0, 0);
    for (GLfloat i = 0;i < 50;i+=0.1)
        midpointcircle(450, 400, i, 1);
    for (GLfloat i = 0;i < 50;i+=0.1)
        midpointcircle(450, 400, i, 2);

    glColor3d(0, 0, 0);
    for (GLfloat i = 0;i < 300;i += 0.1)
        midpointcircle(300, 300, i, 2);
    glColor3d(1, 1, 1);
    for (GLfloat i = 0;i < 300;i += 0.1)
        midpointcircle(300, 300, i, 1);




    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("YinYang");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 1;
}
