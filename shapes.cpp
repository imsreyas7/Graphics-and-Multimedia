// Q: To create an output window using OPENGL and to draw the following basic output primitives 
//    - POINTS
//    - LINES
//    - LINE_STRIP
//    - LINE_LOOP
//    - TRIANGLES
//    - QUADS
//    - QUAD_STRIP
//    - POLYGON.

// Reference: https://docs.microsoft.com/en-us/windows/win32/opengl/glbegin

#include<GL/glut.h> 

const int WINDOW_WIDTH = 850;
const int WINDOW_HEIGHT = 700;

void myInit();
void myDisplay();

void printPoints();
void printLines();
void printLineStrip();
void printLineLoop();
void printTriangles();
void printQuads();
void printQuadStrip();
void printPolygon();

int main(int argc,char* argv[]) {             
    glutInit(&argc,argv);             
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);             
    glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);             
    glutCreateWindow("Basic Shapes");             
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
    
    printPoints();
    printLines();   
    printLineStrip();
    printLineLoop();      
    printTriangles();
    printQuads();
    printQuadStrip();
    printPolygon();

    glFlush();         
}

void printPoints() {         
    //1 - pt1, 2 - pt2, 3 - pt3, ...

    glBegin(GL_POINTS);         
   
    glVertex2d(10,10);    //1     
    glVertex2d(20,20);    //2     
    glVertex2d(20,10);    //3     
    glVertex2d(10,20);    //4     
   
    glEnd();         
}      

void printLines() {       
    //1-2 Line

    glBegin(GL_LINES);         
    
    glVertex2d(30,30);    //1 
    glVertex2d(40,40);    //2  
    
    glVertex2d(30,40);         
    glVertex2d(40,30);         

    glEnd();         
}      

void printLineStrip() {   
    //1-2-3-4-..-(n-1)-n Lines

    glBegin(GL_LINE_STRIP);         
   
    glVertex2d(50,50);    //1     
    glVertex2d(60,50);    //2     
    glVertex2d(60,60);    //3     
    glVertex2d(50,60);    //4     
   
    glEnd();         
}      

void printLineLoop() {  
    //1-2-3-4-....-n-1 Lines

    glBegin(GL_LINE_LOOP);         
   
    glVertex2d(70,70);   //1      
    glVertex2d(80,70);   //2      
    glVertex2d(80,80);   //3   
    glVertex2d(70,80);   //4   
   
    glEnd();         
}      

void printTriangles() {      
    //1-2-3-1 Triangle   

    glBegin(GL_TRIANGLES);         
   
    glVertex2d(90,90);    //1     
    glVertex2d(90,100);   //2   
    glVertex2d(100,90);   //3   
   
    glVertex2d(100,110);         
    glVertex2d(90,110);         
    glVertex2d(100,100);         
   
    glEnd();         
}      

void printQuads() {         
    //1-2-3-4-1 Quad

    glBegin(GL_QUADS);         
   
    glVertex2d(110,110);  //1       
    glVertex2d(120,110);  //2       
    glVertex2d(120,120);  //3       
    glVertex2d(110,120);  //4       
            
    glVertex2d(130,130);         
    glVertex2d(140,130);         
    glVertex2d(140,150);         
    glVertex2d(130,150);         
            
    glEnd();         
}      

void printQuadStrip() {         
    //1-2-4-3 Quad1
    //3-4-6-5 Quad2

    glBegin(GL_QUAD_STRIP);         
   
    glVertex2d(150,150);       //1  
    glVertex2d(160,150);       //2
    
    glVertex2d(150,160);       //3
    glVertex2d(160,160);       //4
            
    glVertex2d(150,170);       //5
    glVertex2d(160,170);       //6
            
    glEnd();         
}      

void printPolygon() {
    //(1,2,3,4,..,n) Convex polygon

    glBegin(GL_POLYGON);         
   
    glVertex2d(180,180);       //1  
    glVertex2d(200,180);       //2  
    glVertex2d(220,190);       //3  
    glVertex2d(220,210);       //4  
    glVertex2d(200,230);       //5  
    glVertex2d(180,230);       //6  
    glVertex2d(180,190);       //7
            
    glEnd();
}