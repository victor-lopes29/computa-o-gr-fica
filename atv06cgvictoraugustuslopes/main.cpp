#include <GL/gl.h>
#include <GL/glut.h>
#include <conio.h>
#include <stdio.h>


int movex = 0, movey = 0;

int forma = 0;

void ponto(){
    glPointSize(10);
    glBegin(GL_POINTS);
        glColor3f(1,0,0);
        glVertex2f(movex,movey);
    glEnd();
}

void triangulos(){
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1, 0, 0);
        glVertex2f(movex,movey);
        glVertex2f(movex+20,movey-25);
        glVertex2f(movex,movey-40);

    glEnd();
}

void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,800,600,0);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
        if (forma == 0)
            ponto();
        if (forma == 1)
            triangulos();

    glPopMatrix();
	glutSwapBuffers();
}

void movimentaMouse(int x, int y){
    movex = x;
    movey = y;

    glutPostRedisplay();
}

void gerenciaMouse(int botao, int estado, int x, int y){
    if (botao == GLUT_RIGHT_BUTTON)
        if(estado == GLUT_UP){
            forma = 0;
            movex = x;
            movey = y;
            printf("%d, %d\n", movex, movey);
        }
    if (botao == GLUT_LEFT_BUTTON)
        if(estado == GLUT_DOWN){
            forma = 0;
            movex = x;
            movey = y;
            printf("%d, %d\n", movex, movey);
        }
    if (botao == GLUT_MIDDLE_BUTTON)
        if(estado == GLUT_DOWN){
            forma = 1;
            movex = x;
            movey = y;
            printf("%d, %d\n", movex, movey);
        }
    glutPostRedisplay();
}

int main(void){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(320,150);
	glutCreateWindow("Atividade 06 - Victor Augustus Lopes Costa");
    glutDisplayFunc(desenhaObjetos);
    glutMouseFunc(gerenciaMouse);
    glClearColor(1,1,1,0);
    glutMainLoop();
    return 0;
}
