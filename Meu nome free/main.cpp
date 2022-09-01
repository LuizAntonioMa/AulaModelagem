#include<GL/freeglut.h>
#include<iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>

GLfloat escala = 1;
float tx=0, ty=0;
float angulo =0;
void desenha(void)
{
    float theta, r,g,b;
    int i;

    glClear( GL_COLOR_BUFFER_BIT );
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);

    glScalef(escala, escala, 0);
    glTranslatef(tx,ty,0);
    glRotatef(angulo,0,0,1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    /*for(i=360; i>0;i--)
    {
        theta=i*3.142/180;
        glVertex2f(10*cos(theta),10*sin(theta));
        glColor3f(r,g,b);
        r =(rand()%10)/10.0;
        g =(rand()%10)/10.0;
        b =(rand()%10)/10.0;
    }
    glEnd();*/

    glBegin(GL_LINES); // L

    glVertex2f(-9,7);
    glVertex2f(-9,-3);
    glVertex2f(-9,-3);
    glVertex2f(-7,-3);

    glEnd();

    glBegin(GL_LINES);// U

    glVertex2f(-6,7);
    glVertex2f(-6,-3);
    glVertex2f(-6,-3);
    glVertex2f(-3,-3);
    glVertex2f(-3,-3);
    glVertex2f(-3,7);

    glEnd();

    glBegin(GL_LINES); // I

    glVertex2f(-1,7);
    glVertex2f(-1,-3);
    glVertex2f(0,7);
    glVertex2f(0,-3);
    glVertex2f(-1,7);
    glVertex2f(0,7);
    glVertex2f(-1,-3);
    glVertex2f(0,-3);

    glEnd();

    glBegin(GL_LINES);// Z

    glVertex2f(1,7);
    glVertex2f(5,7);
    glVertex2f(5,7);
    glVertex2f(1,-3);
    glVertex2f(1,-3);
    glVertex2f(5,-3);
    glEnd();

    glFlush();
}

void listeningKey (unsigned char tecla,
                   GLint x, GLint y)
    {
        switch(tecla)
        {
            case '+': escala += 0.01;
                break;
            case '-': escala -= 0.01;
                break;
            case 'a': tx -= 0.1;
                break;
            case 'd': tx += 0.1;
                break;
            case 'w': ty += 0.1;
                break;
            case 's': ty -= 0.1;
                break;
            case 'e': angulo -= 0.1;
                break;
            case 'q': angulo += 0.1;
                break;
        }
        desenha();
    }

int main(int argc, char* argv[])
{
    glutInit(&argc,  argv);
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(800,600);
    //glutInitWindowSize(800,600);
    glutCreateWindow("Meu nome na freeglut");
    glutKeyboardFunc(listeningKey);
    glutDisplayFunc(desenha);
    srand(time(NULL));
    glClearColor( 0, 0, 1, 0);
    glutMainLoop();
    return 0;


}
