// Q: To create an output window and draw a checkerboard using OpenGL.

#include<GL/glut.h> 

const int WINDOW_WIDTH = 850;
const int WINDOW_HEIGHT = 700;

void myInit();
void myDisplay();

void printCheckerBoard();
void printBoardBorder(int start_X, int start_Y, int end_X, int end_Y);
void printSquares(int min_x, int min_y, int step);

int main(int argc,char* argv[]) {             
    glutInit(&argc,argv);             
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);             
    glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);             
    glutCreateWindow("Checkerboard");             
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
    
    printCheckerBoard();
    
    glFlush();         
}

void printCheckerBoard() {
    // board_length -> number of unit squares by length/ X-axis
    // board_height -> number of unit squares by height/ Y-axis
    // padding -> translates the board by (padding, padding)
    // step -> denotes pixel width and length of each square in board
    
    int board_length = 8;
    int board_height = 8;
    int padding = 50;
    int step = 25;
    
    if(padding < 10) padding = 10;

    printBoardBorder(padding, padding, padding+board_length*step, padding+board_height*step);  

    for(int row=0; row<board_height; row++) {
        int start;

        if(row&1)   start = 1;
        else        start = 0;

        while(start < board_length) {
            printSquares(padding + start*step, padding + row*step, step);
            start += 2;
        }
    }    
    
}

void printSquares(int x, int y, int step) {         
    //1-2-3-4-1 Quad

    glBegin(GL_QUADS);         
   
    glVertex2d(x,y);            //1       
    glVertex2d(x+step,y);       //2       
    glVertex2d(x+step,y+step);  //3       
    glVertex2d(x,y+step);       //4       
            
    glEnd();         
}      

void printBoardBorder(int x1, int y1, int x2, int y2) {  
    //1-2-3-4-....-n-1 Lines

    glBegin(GL_LINE_LOOP);         
   
    glVertex2d(x1,y1);   //1      
    glVertex2d(x2,y1);   //2      
    glVertex2d(x2,y2);   //3   
    glVertex2d(x1,y2);   //4   
   
    glEnd();         
}      