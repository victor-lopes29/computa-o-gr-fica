#include <GL/gl.h>
#include <GL/glut.h>
#include <Math.h>

void cartesiano(){
    glLineWidth(1);
    glColor3f(0,0,0);
    glBegin(GL_LINES);
        glVertex2f(-50, 0.0);
        glVertex2f(50, 0.0);
        glVertex2f(0.0, -50.0);
        glVertex2f(0, 50);
    glEnd();
}

void triangulo(){
    glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLES);
        glVertex2f(5, 1);
        glVertex2f(7, 1);
        glVertex2f(6, 3);
    glEnd();
}/*void quadrado(){
    glColor3f(0.48, 0.41, 0.93);
    glColor3f(0.49, 0.99, 0);
    glBegin(GL_POLYGON);
        glVertex2f(23, 23);
        glVertex2f(24, 23);
        glVertex2f(25, 24);
        glVertex2f(24, 25);
        glVertex2f(23, 25);
    glEnd();
}
*/

void poligono(){
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-23, -21);
        glVertex2f(-24, -21);
        glVertex2f(-25, -22);
        glVertex2f(-24, -23);
        glVertex2f(-23, -23);
        glVertex2f(-22, -22);
    glEnd();
}

void quadrado(){
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
        glVertex2f(-23, -21);
        glVertex2f(-24, -21);

    glEnd();
}
void retangulo (){
    glColor3f(0,1,0);
    glBegin(GL_QUADS);
        glVertex2f(1, 1);
        glVertex2f(4, 1);
        glVertex2f(4, 5);
        glVertex2f(1, 5);
    glEnd();
}

void escala(){
    glScalef(4, 4, 4);
    glColor3f(1, 1, 0);
    glBegin(GL_TRIANGLES);
        glVertex2f(5, 1);
        glVertex2f(7, 1);
        glVertex2f(6, 3);
    glEnd();
}

void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-60,60,-60,60);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
        cartesiano();
    glPopMatrix();

    glPushMatrix();
        poligono();
    glPopMatrix();

    glPushMatrix();
        quadrado();
    glPopMatrix();

	glFlush();

}

int main(void){

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,(glutGet(GLUT_SCREEN_HEIGHT)-540)/2);
    glutCreateWindow("Atividade - Introdução ao OpenGL");
    glutDisplayFunc(desenhaObjetos);
    glClearColor(1,1,1,0);
    glutMainLoop();
    return 0;
}
