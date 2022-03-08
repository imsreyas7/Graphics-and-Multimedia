#include<GL/glut.h>
#include<stdlib.h>
#define baseX 320
#define baseY 200
#define Rad 50
int g = 0;

void myInit() {
glClearColor(1.0,1.0,1.0,0.0);
glColor3f(0.0f,0.0f,0.0f);
glPointSize(3);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,640.0,0.0,480.0);
}

void drawCircle(int r, int X, int Y){
int x = 0, y = r;
int p = 1-r;
glBegin(GL_POINTS);
while(y>x){
x++;
if(p<0){
p += 1 + 2*x;
}
else{
y--;
p += 1 + 2*(x-y);
}
glVertex2d(X+x, Y+y);
glVertex2d(X+x, Y-y);
glVertex2d(X-x, Y+y);
glVertex2d(X-x, Y-y);
glVertex2d(X+y, Y+x);
glVertex2d(X+y, Y-x);
glVertex2d(X-y, Y+x);
glVertex2d(X-y, Y-x);
}
glEnd();
glFlush();
}

void myDisplay() {
glClear(GL_COLOR_BUFFER_BIT);
//glBegin(GL_LINE_STRIP);
// glVertex2d(baseX, 480);
// glVertex2d(baseX, baseY+Rad);
//glEnd();
drawCircle(Rad, baseX, baseY);
}

void disp(){
//for(int i=0;i<10000;i++){
// if(i%2==0){
// myDisplay();
// }
// else myDisplay1();
//}
int xMin = 260, xMax = 400, x = xMin, buff = 100000;
while(true){
glClear(GL_COLOR_BUFFER_BIT);
drawCircle(Rad, x, baseY);
_sleep(10);
x++;
//buff = 100000;
//while(buff--);
if(x>xMax)x=xMin;
}
glFlush();
}
int main(int argc,char* argv[]) {
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(640,480);
glutCreateWindow("Pendulum");
glutDisplayFunc(disp);
myInit();
glutMainLoop();
} 