#include <GL/gl.h>
#include <GL/glut.h>
#include <Math.h>

GLfloat escala=1;
GLfloat rotacao=0;
GLfloat movex = 0, movey = 0;

void quadrado(){
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
        glVertex2f(35,-20);
        glVertex2f(35,-18);
        glVertex2f(37,-18);
        glVertex2f(37,-20);
    glEnd();
}

void grama(){
glColor3f(0.49,0.99,0);
    glBegin(GL_QUADS);
        glVertex2f(-50,-50);
        glVertex2f(-50,50);
        glVertex2f(50,50);
        glVertex2f(50,-50);
    glEnd();
}

void rua1 (){

glColor3f(0,0,0);
    glBegin(GL_QUADS);
        glVertex2f(-48,20);
        glVertex2f(-48,40);
        glVertex2f(48,40);
        glVertex2f(48,20);
    glEnd();

}

void rua2 (){

glColor3f(0,0,0);
    glBegin(GL_QUADS);
        glVertex2f(28,-40);
        glVertex2f(28,40);
        glVertex2f(48,40);
        glVertex2f(48,-40);
    glEnd();

}


void desenhaObjeto(void){
    glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50,50,-50,50);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
        grama();
    glPopMatrix();

    glPushMatrix();
        rua1();
    glPopMatrix();

    glPushMatrix();
        rua2();
    glPopMatrix();

    glPushMatrix();
        glScalef(escala, escala, 0);
        glRotatef(rotacao, 0,0,1);
        glTranslatef(movex, movey,0);
        quadrado();
    glPopMatrix();

	glFlush();
}


void teclas(unsigned char tecla, GLint x, GLint y){
    switch(tecla){
        case '1': rotacao-=10;
        break;
        case '2': rotacao+=10;
        break;
    }
    glutPostRedisplay();
}


void setasDirecionais(GLint tecla, GLint x, GLint y){
    switch(tecla){
        case GLUT_KEY_LEFT: movex--;
        break;
        case GLUT_KEY_RIGHT: movex++;
        break;
        case GLUT_KEY_UP: movey++;
        break;
        case GLUT_KEY_DOWN: movey--;
        break;
    }
    glutPostRedisplay();
}

int main(void){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
     glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,
                           (glutGet(GLUT_SCREEN_HEIGHT)-540)/2);
	glutCreateWindow("Exemplo - Teclado");
    glutDisplayFunc(desenhaObjeto);
    glutKeyboardFunc(teclas);
    glutSpecialFunc(setasDirecionais);
    glClearColor(1,1,1,0);
    glutMainLoop();
    return 0;
}
