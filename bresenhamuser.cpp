// Q: To plot points that make up the line with endpoints (x0,y0) and (xn,yn) using Bresenham's line drawing algorithm.  
// I/P: Point (x1,y1), Point (x2,y2)
// O/P: Line joining (x1,y1) - (x2,y2)

#include<bits/stdc++.h>
#include<GL/glut.h> 

using namespace std;
using ld = long double;

const int WINDOW_WIDTH = 850;
const int WINDOW_HEIGHT = 700;

void myInit();
void myDisplay();

void printLines();
void printBresenhamLine(ld x1, ld y1, ld x2, ld y2);

const ld PADDING = 250;
const ld STEP = 1;
const ld SCALE = 5;

int main(int argc,char* argv[]) {             
    glutInit(&argc,argv);             
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);             
    glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);             
    glutCreateWindow("Bresenham's Line Drawing Algorithm");             
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

    ld x1, x2, y1, y2;
    cout << "\n------------------------------------------\n";
    cout << "\t\t Bresenham's Line drawing Algorithm \n";
    cout << "\nStarting point (x1, y1) \n";
    cout << "\tx1 : "; cin>>x1;
    cout << "\ty1 : "; cin>>y1;

    cout << "\nEnding point (x2, y2) \n";
    cout << "\tx2 : "; cin>>x2;
    cout << "\ty2 : "; cin>>y2;

    printBresenhamLine(x1,y1, x2,y2);

    printf("\nLine between (%.2Lf,%.2Lf) & (%.2Lf, %.2Lf) is drawn.. \n\n", x1,y1,x2,y2);
    
    glEnd();
}

void printBresenhamLine(ld x1, ld y1, ld x2, ld y2) {
    // m : slope;
    ld pad = PADDING, scale = SCALE;
    
    x1 = x1*scale + pad; 
    x2 = x2*scale + pad; 
    y1 = y1*scale + pad; 
    y2 = y2*scale + pad;

    ld dx, dy;
    ld x, y, xEnd, p, mirrorLine;
    bool printMirror = false;
    
    dx = abs(x2-x1);
    dy = abs(y2-y1);

    p = 2*dy - dx;

    if(x1 > x2) swap(x1,x2), swap(y1, y2);

    x = x1;
    y = y1;
    xEnd = x2;

    glVertex2d(x,y);

    if(y1 > y2) {
        mirrorLine = y;
        printMirror = true;
        y2 = y1 + (y1 - y2);
    }

    while(x < xEnd) {
        x ++;
        
        if(p < 0) {
            p += 2*dy;
        } else {
            y ++;
            p = 2*(dy-dx);
        }

        if(printMirror) glVertex2d(x,mirrorLine - (y-mirrorLine));
        else            glVertex2d(x,y);
        
    }
}