/*
#include <GL/gl.h>
#include <GL/glut.h>
#include <Math.h>

GLint movePontoY = 0; //para mover o ponto em incrementais (1 em 1)
GLint movePontoX = 0;   // para saber a direção do ponto no eixo y (+ ou -)
GLint direcaoY = 1;   // para saber a direção do ponto no eixo y (+ ou -)
GLint direcaoX = 0;   // para saber a direção do ponto no eixo y (+ ou -)

void timerPonto(int passo)
{
    if (direcaoY == 1)
    {
        movePontoY += 1;
        if (movePontoY == 9)
        {
            direcaoY = 0;
            direcaoX = 1;
        }
    }
    else if (direcaoY == -1)
    {
        movePontoY -= 1;
        if (movePontoY == 1)
        {
            direcaoY = 0;
            direcaoX = -1;
        }
    }
    else if (direcaoX == 1)
    {
        movePontoX += 1;
        if (movePontoX == 5)
        {
            direcaoY = -1;
            direcaoX = 0;
        }
    }
    else if (direcaoX == -1)
    {
        movePontoX -= 1;
        if (movePontoX == 0)
        {
            direcaoY = 1;
            direcaoX = 0;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(60, timerPonto, 1);
}


void pontoY()
{
    glPointSize(20);                   //adiciona espessura do ponto
    glBegin(GL_POINTS);                //glBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
    glColor3f(0, 1, 0);              //adiciona cor
    glVertex2f(movePontoX, movePontoY);       //desenha um ponto na coordenada x, y, onde y vai ser a variável que criamos para deslocar o ponto neste eixo
    glEnd();
}


void linhas()
{
    glLineWidth(5);
    glColor3f(1, 1, 0);

    glBegin(GL_LINE_STRIP);
    glVertex2f(0, 9);

    glVertex2f(1, 9);
    glVertex2f(2, 9);
    glVertex2f(3, 9);
    glVertex2f(5, 9);
    glVertex2f(5, 5);
    glVertex2f(5, 1);
    glVertex2f(5, 0);

    glEnd();
}


void rua2()
{
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(4, 8);
    glVertex2f(4, 0);
    glVertex2f(6, 0);
    glVertex2f(6, 8);
    glEnd();
}

void rua1()
{
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(0, 10);
    glVertex2f(6, 10);
    glVertex2f(6, 8);
    glVertex2f(0, 8);
    glEnd();
}

void desenhaObjetos(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,10,0,10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();



    glPushMatrix();
    rua1();
    glPopMatrix();
    glPushMatrix();
    rua2();
    glPopMatrix();

    glPushMatrix();
    linhas();
    glPopMatrix();

     glPushMatrix();
    pontoY();
    glPopMatrix();

    glFlush();

}

int main(void)
{

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,(glutGet(GLUT_SCREEN_HEIGHT)-540)/2);
    glutCreateWindow("Introdução ao OpenGL");
    glutDisplayFunc(desenhaObjetos);
    glutTimerFunc(10, timerPonto, 1);
    glClearColor(0, 0.39, 0, 0);
    glutMainLoop();
    return 0;
}
*/
#include <GL/gl.h>
#include <GL/glut.h>
#include <Math.h>

GLint movePontoY = 0; //para mover o ponto em incrementais (1 em 1)
GLint movePontoX = 0;   // para saber a direção do ponto no eixo y (+ ou -)
GLint direcaoY = 1;   // para saber a direção do ponto no eixo y (+ ou -)
GLint direcaoX = 0;   // para saber a direção do ponto no eixo y (+ ou -)

void timerPonto(int passo)                  //função timerPonto, que verifica o local do ponto para saber quando deve parar de subir (ou descer) o ponto no eixo y
{
    if (direcaoY == 1)                       //se a direção for 1, o ponto sobre, se for -1 ele desce
    {
        movePontoY += 1;
        if (movePontoY == 9)                 //se move ponto for igual ao nosso limite superior máximo no eixo y+
        {
            direcaoY = 0;                  // começa a descer no eixo y, quando chegar no limite de 90y
            direcaoX = 1;
        }
    }
    else if (direcaoY == -1)
    {
        movePontoY -= 1;                     //decrementa nosso moveponto até o limite estipulado
        if (movePontoY == -9)               //se move ponto for igual ao nosso limite inferior máximo no eixo y-
        {
            direcaoY = 0;                  //começa a subir no eixo y, quando chegar no limite de -90y
            direcaoX = -1;
        }
    }
    else if (direcaoX == 1)
    {
        movePontoX += 1;
        if (movePontoX == 5)
        {
            direcaoY = -1;
            direcaoX = 0;
        }
    }
    else if (direcaoX == -1)
    {
        movePontoX -= 1;
        if (movePontoX == -5)
        {
            direcaoY = 1;
            direcaoX = 0;
        }
    }
    glutPostRedisplay();                 //chama a função desenha toda vez que for necessária
    glutTimerFunc(60, timerPonto, 1);      //precisamos chamar a função timer toda vez, Ele executa essa função timer e entra aqui novamente. Até eu querer sair da função timer (neste caso, não queremos sair)
}


void pontoY()
{
    glPointSize(20);                   //adiciona espessura do ponto
    glBegin(GL_POINTS);                //glBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
    glColor3f(0, 1, 0);              //adiciona cor
    glVertex2f(movePontoX, movePontoY);       //desenha um ponto na coordenada x, y, onde y vai ser a variável que criamos para deslocar o ponto neste eixo
    glEnd();
}


void linhas()
{
    glLineWidth(5);
    glColor3f(1, 1, 0);

    glBegin(GL_LINE_STRIP);
    glVertex2f(0, 9);

    glVertex2f(1, 9);
    glVertex2f(2, 9);
    glVertex2f(3, 9);
    glVertex2f(5, 9);
    glVertex2f(5, 5);
    glVertex2f(5, 1);
    glVertex2f(5, 0);

    glEnd();
}


void rua2()
{
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(4, 8);
    glVertex2f(4, 0);
    glVertex2f(6, 0);
    glVertex2f(6, 8);
    glEnd();
}

void rua1()
{
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(0, 10);
    glVertex2f(6, 10);
    glVertex2f(6, 8);
    glVertex2f(0, 8);
    glEnd();
}

void desenhaObjetos(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,10,0,10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();



    glPushMatrix();
    rua1();
    glPopMatrix();
    glPushMatrix();
    rua2();
    glPopMatrix();

    glPushMatrix();
    linhas();
    glPopMatrix();

     glPushMatrix();
    pontoY();
    glPopMatrix();

    glFlush();

}

int main(void)
{

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,(glutGet(GLUT_SCREEN_HEIGHT)-540)/2);
    glutCreateWindow("Introdução ao OpenGL");
    glutDisplayFunc(desenhaObjetos);
    glutTimerFunc(10, timerPonto, 1);
    glClearColor(0, 0.39, 0, 0);
    glutMainLoop();
    return 0;
}
