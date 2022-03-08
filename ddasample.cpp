// Q: To plot points that make up the line with endpoints (x0,y0) and (xn,yn) using DDA line drawing algorithm.  

    // Case 1: +ve slope Left to Right line 
    // Case 2: +ve slope Right to Left line 
    // Case 3: -ve slope Left to Right line 
    // Case 4: -ve slope Right to Left line 

    // Each case has two subdivisions  
    //     (i) |m|<= 1          
    //     (ii) |m|>1 
    // Note that all four cases of line drawing must be given as test cases. 

#include<bits/stdc++.h>
#include<GL/glut.h> 

using namespace std;
using ld = long double;

const int WINDOW_WIDTH = 850;
const int WINDOW_HEIGHT = 700;

void myInit();
void myDisplay();

void printLines();
void printDDALine(ld x1, ld y1, ld x2, ld y2);

const ld PADDING = 250;
const ld STEP = 1;
const ld SCALE = 5;

int main(int argc,char* argv[]) {             
    glutInit(&argc,argv);             
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);             
    glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);             
    glutCreateWindow("DDA - Line Drawing Algorithm");             
    glutDisplayFunc(myDisplay);              
    myInit();             
    glutMainLoop();             
    return 1;         
} 

void myInit() {     
    glClearColor(1.0,1.0,1.0,0.0);     
    glColor3f(0.0f,0.0f,0.0f);     
    glPointSize(2.0);     
    glMatrixMode(GL_PROJECTION);     
    glLoadIdentity();     
    gluOrtho2D(0.0,640.0,0.0,480.0); 
}     

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    printLines();
    
    glFlush();         
}


void printLines() {
    glBegin(GL_POINTS);

    // Case 1: +ve slope Left to Right line
    glColor3f(1.0f,0.0f,0.0f);     
    // | m | > 1
    printDDALine((ld)3,(ld)2, (ld)15,(ld)10);
    // | m | < 1
    printDDALine((ld)2,(ld)3, (ld)10,(ld)15);

    // Case 2: +ve slope Right to Left line
    glColor3f(0.5f,0.5f,0.0f);     
    // | m | > 1
    printDDALine((ld)-3,(ld)-2, (ld)-15,(ld)-10);
    // | m | < 1
    printDDALine((ld)-2,(ld)-3, (ld)-10,(ld)-15);
    
    //Case 3: -ve slope Left to Right line
    glColor3f(0.0f,1.0f,0.0f);     
    // | m | > 1
    printDDALine((ld)3,(ld)-2, (ld)15,(ld)-10);
    // | m | < 1
    printDDALine((ld)2,(ld)-3, (ld)10,(ld)-15);
    
    //Case 4: -ve slope Right to Left line
    glColor3f(0.0f,0.5f,0.5f);     
    // | m | > 1
    printDDALine((ld)-3,(ld)2, (ld)-15,(ld)10);
    // | m | < 1
    printDDALine((ld)-2,(ld)3, (ld)-10,(ld)15);
    
    glEnd();
}

void printDDALine(ld x1, ld y1, ld x2, ld y2) {
    
    ld pad = PADDING, scale = SCALE;
    
    x1 = x1*scale + pad; 
    x2 = x2*scale + pad; 
    y1 = y1*scale + pad; 
    y2 = y2*scale + pad;

    ld dx, dy, steps;
    ld xInc, yInc, x, y;

    dx = (x2-x1);
    dy = (y2-y1);

    if(abs(dx) > abs(dy))   steps = abs(dx);
    else                    steps = abs(dy);

    xInc = dx/steps;
    yInc = dy/steps;

    x = x1; y = y1;
    glVertex2d(x, y);

    for(long i=1;i<=steps;i++) {
        x += xInc;
        y += yInc;

        glVertex2d(x, y);
    }
}