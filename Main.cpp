#include <GL/glut.h>
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <iostream>

using namespace std;

float rx = 0, rz = 0;

float abertura = 40.0, znear = 1, zfar = 20, aspect = 1;
GLUquadricObj *quadrado;

void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(abertura, aspect, znear, zfar);
    glMatrixMode(GL_MODELVIEW);

    glClearColor(0, 0, 0, 1);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glEnable(GL_DEPTH_TEST);
    quadrado = gluNewQuadric();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity( );

    gluPerspective(abertura, aspect, znear, zfar);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    gluLookAt(0, 0, 15,  //from. Posicao onde a camera esta posicionada
              0, 0, 0,  //to. Posicao absoluta onde a camera esta vendo
              0, 1, 0); //up. Vetor Up.

    glRotatef((GLfloat) rx, 0.0f, 1.0f, 0.0f);
    glRotatef((GLfloat) 90, 1.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //Tronco
    glPushMatrix();
        glColor3f(0,1,0);
        //parametro o objeto quadric, raio em z, raio em zheight , altura , fatias , pilhas
        glTranslatef(0.0 , 0.0 , 0.0);  
        gluCylinder(quadrado, 1.0, 1, 3, 30, 30);
    glPopMatrix();

    //Braco direito
    glPushMatrix();
        glColor3f(1,0,0);
        //parametro o objeto quadric, raio em z, raio em zheight , altura , fatias , pilhas
        glTranslatef(1.0 , 1.0 , 0.0);  
        gluCylinder(quadrado, 1.0, 1, 1, 30, 30);
    glPopMatrix();

    //Braco esquerdo
    glPushMatrix();
        glColor3f(1,0,0);
        //parametro o objeto quadric, raio em z, raio em zheight , altura , fatias , pilhas
        glTranslatef(-1.0 , 1.0 , 0.0);  
        gluCylinder(quadrado, 1.0, 1, 1, 30, 30);
    glPopMatrix();

    //Perna direita 
    glPushMatrix();
        glColor3f(1,0,0);
        //parametro o objeto quadric, raio em z, raio em zheight , altura , fatias , pilhas
        glTranslatef(1.0 , 0.4 , 0.0);  
        gluCylinder(quadrado, 1.0, 1, 1, 30, 30);
    glPopMatrix();

    //Perna esquerda
    glPushMatrix();
        glColor3f(1,0,0);
        //parametro o objeto quadric, raio em z, raio em zheight , altura , fatias , pilhas
        glTranslatef(-1.0 , -1.0 , 0.0);  
        gluCylinder(quadrado, 1.0, 1, 1, 30, 30);
    glPopMatrix();

    glutSwapBuffers();
    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    key = tolower(key);
    switch (key) {
        case 27:
            exit(0);
        case '+':
            abertura += 1;

    }
}



int main(int argc, char **argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize (777, 777);
    glutInitWindowPosition(100, 10);
    glutCreateWindow("Personagens");

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutKeyboardFunc(keyboard);

    init();

    glutMainLoop();
    return 0;
}