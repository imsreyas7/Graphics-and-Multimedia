// Q: To create an output window and draw a house using POINTS,LINES,TRIANGLES and QUADS/POLYGON.

#include<GL/glut.h> 

const int WINDOW_WIDTH = 850;
const int WINDOW_HEIGHT = 700;

void myInit();
void myDisplay();

void makeBorder();
void makeDoorFrame();
void makeOuterTiles();
    
void printLine(int x1, int y1, int x2, int y2);
void printLineLoop(int x1, int y1, int x2, int y2);
void printTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
void printQuad(int x1, int y1, int x2, int y2);

int main(int argc,char* argv[]) {             
    glutInit(&argc,argv);             
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);             
    glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);             
    glutCreateWindow("Dual House");             
    glutDisplayFunc(myDisplay);              
    myInit();             
    glutMainLoop();             
    return 1;         
} 

void myInit() {     
    glClearColor(1.0,1.0,1.0,0.0);     
    glColor3f(0.0f,0.0f,0.0f);     
    glPointSize(10);     
    glMatrixMode(GL_PROJECTION);     
    glLoadIdentity();     
    gluOrtho2D(0.0,640.0,0.0,480.0); 
}     

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    makeBorder();
    makeDoorFrame();
    makeOuterTiles();

    glFlush();         
}

void makeBorder() {
    printTriangle(35,150, 115,150, 75,180);
    printLineLoop(50,100, 100,150); 

    printTriangle(135,150, 215,150, 175,180);
    printLineLoop(150,100, 200,150); 
}

void makeDoorFrame() {
    printQuad(62,100, 65,122);
    printQuad(85,100, 88,122);
    printQuad(62,120, 88,122);

    printQuad(162,100, 165,122);
    printQuad(185,100, 188,122);
    printQuad(162,120, 188,122);
}

void makeOuterTiles() {
    printLineLoop(62,85,88,95);
    printQuad(62,70,88,80);
    printLineLoop(62,55,88,65);
    printQuad(50,40,71,50);
    printQuad(79,40,100,50);

    printLineLoop(162,85,188,95);
    printQuad(162,70,188,80);
    printLineLoop(162,55,188,65);
    printQuad(150,40,171,50);
    printQuad(179,40,200,50);

    printQuad(105,40,122,50);
    printQuad(128,40,145,50);
}

void printLine(int x1, int y1, int x2, int y2) {       
    //1-2 Line

    glBegin(GL_LINES);         
    
    glVertex2d(x1,y1);    //1 
    glVertex2d(x2,y2);    //2  

    glEnd();         
}      

void printLineLoop(int x1, int y1, int x2, int y2) {  
    //1-2-3-4-....-n-1 Lines

    glBegin(GL_LINE_LOOP);         
   
    glVertex2d(x1,y1);   //1      
    glVertex2d(x2,y1);   //2      
    glVertex2d(x2,y2);   //3   
    glVertex2d(x1,y2);   //4   
   
    glEnd();         
}      

void printTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {      
    //1-2-3-1 Triangle   

    glBegin(GL_TRIANGLES);         
   
    glVertex2d(x1,y1);    //1     
    glVertex2d(x2,y2);   //2   
    glVertex2d(x3,y3);   //3   
   
    glEnd();         
}      

void printQuad(int x1, int y1, int x2, int y2) {         
    //1-2-3-4 Quad

    glBegin(GL_QUADS);         
   
    glVertex2d(x1,y1);   //1      
    glVertex2d(x2,y1);   //2      
    glVertex2d(x2,y2);   //3   
    glVertex2d(x1,y2);   //4   
           
    glEnd();         
}      