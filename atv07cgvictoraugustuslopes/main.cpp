#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
GLint direcao = 1;
GLint x = 70;
GLint y = -90 ;

void rua(){
    glScalef(8,8,0);
    glBegin(GL_POLYGON);
        glColor3f(0,0,0);
        glVertex2f(4,2);
        glVertex2f(4,-20);
        glVertex2f(10,-20);
        glVertex2f(10,9);
        glVertex2f(-20,9);
        glVertex2f(-20,2);
    glEnd();
}

void faixa(){
    glLineWidth(5);
    glColor3f(1,1,0);
    glEnable(GL_LINE_STIPPLE);
	glLineStipple(3,0X00FF);
    glBegin(GL_LINES);
        glVertex2f(57, -85);
        glVertex2f(57,45);
        glVertex2f(57, 45);
        glVertex2f(-85,45);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
}

void carro(){
    glPointSize(20);
    glBegin(GL_POINTS);
        glColor3f(1,1,1);
        glVertex2f(x,y);
    glEnd();
}

void timerPonto(int passo){
    if (direcao == 1){
        y+=1;
        if(y == 60){
            direcao = 2;
        }
    } else if (direcao == 2){
        x-=1;
        if(x == -90){
            direcao = 3;
        }
    }else if (direcao == 3){
        y-=1;
        if(y == 27){
            direcao = 4;
        }
    }else if (direcao == 4){
        x+=1;
        if(x == 45){
            direcao = 5;
        }
    }else if (direcao == 5){
        y-=1;
        if(y == -90){
            direcao = 6;
        }
    }else if (direcao == 6){
        x+=1;
        if(x == 70){
            direcao = 1;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(10,timerPonto,1);
}

void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
        rua();
    glPopMatrix();

    glPushMatrix();
        carro();
    glPopMatrix();

    glPushMatrix();
        faixa();
    glPopMatrix();

	glutSwapBuffers();
}

int main(void){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,
                           (glutGet(GLUT_SCREEN_HEIGHT)-540)/2);
	glutCreateWindow("Exemplo Timer");
    glutDisplayFunc(desenhaObjetos);
    glutTimerFunc(10,timerPonto,1);
    glClearColor(0.13,0.55,0.13,0);
    glutMainLoop();
    return 0;
}
