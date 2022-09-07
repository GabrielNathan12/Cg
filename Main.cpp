#include <GL/glut.h>
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <iostream>

using namespace std;

float rx = 0, rz = 0;

float abertura = 40.0, znear = 1, zfar = 20, aspect = 1;
GLUquadricObj *quadrado;

#ifndef HUMANO_H
#define HUMANO_H

class Humano {
    private :
        void criarCabecaList();
        void criarPescocoList();
        void criarTorsoList();
        void criarBraco1List();
        void criarBraco2List();
        void criarQuadrilList();
        void criarPerna1List();
        void criarPerna2List();
    
    public:
        float cabeca_x , cabeca_y , cabeca_z;
        float pescoco_x , pescoco_y , pescoco_z;
        float torso_x , torco_y , torco_z;
        float bracoE_x , bracoE_y , bracoE_z;
        float bracoD_x , bracoD_y , bracoD_z;
        float ombroE , ombroD;
        float quadril_x , quadril_y , quadril_z;
        float moverQuadril_x , moverQualdril_y , moverQuadril_z;
        float pernaE_x , pernaE_y , pernaE_z;
        float pernaD_x , pernaD_y , pernaD_z;
        float pernaE , pernaD;

        GLuint cabecaList;
        GLuint perscoList;
        GLuint torsoList;
        GLuint bracoEList;
        GLuint bracoDList;
        GLuint quadrilList;
        GLuint pernaEList;
        GLuint pernaDList;

        void criarListPontos();
        void DesenhaTudo();
        void reset();
        Humano();

};

#endif

void Humano :: criarCabecaList(){
    cabecaList = glGenLists(1);
    glNewList(cabecaList , GL_COMPILE);

    glPushMatrix();
        glScalef(0.9f , 1.0f , 1.0f);
        GLUquadricObj *quadratico;
        quadratico = gluNewQuadric();
        //gluQuadricTexture(quadratico ,1);
        gluSphere(quadratico , 1.3f , 32 , 32);
        glTranslatef(0.0f , 0.9f , 0.0f);
        GLUquadricObj * quadratico1;
        quadratico1 = gluNewQuadric();
        glRotatef(90.0f , 1.0f , 0.0f , 0.0f);
        gluCylinder(quadratico1 , 1.6f , 1.6f , 0.6f , 32 ,32);
        gluDisk(quadratico1 , 0.0f , 1.6f , 32 , 32);
        glRotatef(-90.0f , 1.0f , 0.0f , 0.0f);
        glTranslatef(0.0f , 0.6f , 0.0f);
        glRotatef(90.0f , 1.0f , 0.0f , 0.0f);
        gluCylinder(quadratico1 , 1.0f , 1.0f , 0.7f , 32 , 32);
        gluDisk(quadratico1 , 0.0f , 1.0f , 32 , 32);
    glPopMatrix();
    glEndList();
}

void Humano :: criarPescocoList(){
    perscoList = glGenLists(1);
    glNewList(perscoList , GL_COMPILE);

    //TexturaHimano = tex.loadBMP_custom("Passa o caminho da imagem");
    glColor2f(1.0f , 0.8f , 0.2f);
    GLUquadricObj *quadratico;
    quadratico = gluNewQuadric();
    glRotatef(90.0f , 1.0f , 0.0f , 0.0f);
    //gluQuadrictTexture(quadratico , 1);
    gluCylinder(quadratico , 1);
    gluDisk(quadratico , 0.0f , 0.6f , 32 , 32);
    glRotatef(-90.0f , 1.0f , 0.0f , 0.0f);

    glEndList();
}

void Humano :: criarTorsoList(){
    //Aplicar textura aqui
    torsoList = glGenLists(1);
    
    glNewList(torsoList , GL_COMPILE);
    GLUquadricObj *quadratico;
    quadratico = gluNewQuadric();
    glRotatef(90.0f , 1.0f , 0.0f , 0.0f);
    //gluQuadricTexture(quadratico , 1);
    gluCylinder(quadratico , 2.5f , 2.0f , 5.0f , 32 , 32);
    gluDisk(quadratico , 0.0f , 2.5f , 32 , 32);

    glPushMatrix();
        glTranslatef(0.0f , 0.0f , 5.0f);
        gluDisk(quadratico , 0.0f , 2.0f , 32 , 32);
    glPopMatrix();
    glRotatef(-90.0f , 1.0f , 0.0f , 0.0f);
    glEndList();
}

void Humano :: criarBraco1List(){
    bracoDList = glGenLists(1);
    
    glNewList(bracoDList , GL_COMPILE);
    glColor3f(0,0f , 1.0f , 0.2f);
    GLUquadricObj *quadratico;
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		//gluQuadricTexture(quadratico,1);
	gluCylinder(quadratico,0.6f,0.6f,3.0f,32,32);
	gluDisk(quadratico,0.0f,0.6f,32,32);
		
    glPushMatrix();
		glTranslatef(0.0,0.0,3.0f);
		gluDisk(quadratico,0.0f,0.6f,32,32);
	glPopMatrix();
		
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glEndList();
    
}

void Humano :: criarBraco2List(){
    bracoEList = glGenLists (1);
	
    glNewList(bracoEList , GL_COMPILE);
    glColor3f(0.0f, 1.0f, 0.8f);    
    GLUquadricObj *quadratico;
    quadratico = gluNewQuadric();
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    //gluQuadricTexture(quadratic,1);
    gluCylinder(quadratico,0.6f,0.4f,4.0f,32,32);
    gluDisk(quadratico,0.0f,0.4f,32,32);
    
    glPushMatrix();
        glTranslatef(0.0,0.0,4.0f);
        gluDisk(quadratico,0.0f,0.4f,32,32);
    glPopMatrix();
    
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glEndList();
}

void Humano :: criarQuadrilList(){
    quadrilList = glGenLists (1);
	
    glNewList(quadrilList, GL_COMPILE);
		//Texture tex;
		//humanTexture = tex.loadBMP_custom("./images/belt.bmp");
		GLUquadricObj *quadratico;
		quadratico = gluNewQuadric();
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		//gluQuadricTexture(quadratic,1);
		gluCylinder(quadratico,2.1f,2.1f,1.0f,32,32);

		glPushMatrix();
			glTranslatef(0.0,0.0,1.0f);
			gluDisk(quadratico,0.0f,2.1f,32,32);
		glPopMatrix();

		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glEndList();
}

void Humano :: criarPerna1List(){
    pernaDList = glGenLists (1);
	glNewList(pernaDList, GL_COMPILE);
		//Texture tex;
		//humanTexture = tex.loadBMP_custom("./images/trouser.bmp");
		glColor3f(1.0f, 1.0f, 0.0f);    
		GLUquadricObj *quadratico;
		quadratico = gluNewQuadric();
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		gluQuadricTexture(quadratico,1);
		gluCylinder(quadratico,1.0f,1.0f,4.0f,32,32);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glEndList();
}

void Humano :: criarPerna2List(){
    pernaEList = glGenLists (1);
	
    glNewList(pernaEList, GL_COMPILE);
		//Texture tex;
		//humanTexture = tex.loadBMP_custom("./images/trouser.bmp");
		glColor3f(0.0f, 1.0f, 0.8f);    
		GLUquadricObj *quadratico;
		quadratico = gluNewQuadric();
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		gluQuadricTexture(quadratico,1);
		gluCylinder(quadratico,1.0f,0.8f,6.0f,32,32);

		glPushMatrix();
			glTranslatef(0.0,0.0,6.0f);
			gluDisk(quadratico,0.0f,0.8f,32,32);
		glPopMatrix();

		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glEndList();
}

void Humano :: criarListPontos(){
    criarCabecaList();
    criarPescocoList();
    criarTorsoList();
    criarBraco1List();
    criarBraco2List();
    criarQuadrilList();
    criarPerna1List();
    criarPerna2List();
}
//Arrumar daqui para baixo
void Humano :: DesenhaTudo(){
    
    // Quadril
    glPushMatrix();
		glTranslatef(moverQuadril_x,moverQualdril_y,moverQualdril_z);
		glTranslatef(0.0f, -1.0f, 0.0f);
		glRotatef(quadril_x,1.0,0.0,0.0);
		glRotatef(quadril_z,0.0,0.0,1.0);
		glRotatef(quadril_y,0.0,1.0,0.0);
		glTranslatef(0.0f, 1.0f, 0.0f);
		glCallList(quadrilList);
	//Perna Esquerda
    glPushMatrix();
			glTranslatef(-1.1f,-1.0f,0.0f);
			glRotatef(pernaE_x,1.0,0.0,0.0);
			glRotatef(pernaE_z,0.0,0.0,1.0);
			glRotatef(pernaE_y,0.0,1.0,0.0);
			glCallList(pernaEList);															
			glTranslatef(0.0f,-4.0f,0.0f);
			glRotatef(pernaE,1.0,0.0,0.0);
			glCallList(pernaDList);
	glPopMatrix();

    //Perna Direita
    glPushMatrix();
        glTranslatef(1.1f,-1.0f,0.0f);
        glRotatef(pernaD_x,1.0,0.0,0.0);
        glRotatef(pernaD_z,0.0,0.0,1.0);
        glRotatef(pernaD_y,0.0,1.0,0.0);
        glCallList(pernaEList);
        glTranslatef(0.0f,-4.0f,0.0f);
        glRotatef(pernaD,1.0,0.0,0.0);
        glCallList(pernaDList);
    glPopMatrix();
		
        //Torso
        glRotatef(torso_x,1.0,0.0,0.0);
		glRotatef(torso_z,0.0,0.0,1.0);
		glRotatef(torso_y,0.0,1.0,0.0);
		glTranslatef(0.0f, 5.0f, 0.0f);
		glCallList(torsoList);

        //Braco direito
		glPushMatrix();
			glTranslatef(2.5f,-0.0f,0.0f);
			glRotatef(bracoD_x,1.0,0.0,0.0);
			glRotatef(bracoD_z,0.0,0.0,1.0);
			glRotatef(bracoD_y,0.0,1.0,0.0);
			glCallList(ombroD);

			glTranslatef(0.0,-3.0f,0.0f);
			glRotatef(rightLowerArmx,1.0,0.0,0.0f);
			glCallList(lowerArmList);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-2.5f,-0.0f,0.0f);
			glRotatef(leftUpperArmx,1.0,0.0,0.0);
			glRotatef(leftUpperArmz,0.0,0.0,1.0);
			glRotatef(leftUpperArmy,0.0,1.0,0.0);
			glCallList(upperArmList);

			glTranslatef(0.0,-3.0f,0.0f);
			glRotatef(leftLowerArmx,1.0,0.0,0.0f);
			glCallList(lowerArmList);
		glPopMatrix();

		
		glRotatef(neckx,1.0,0.0,0.0);
		glRotatef(neckz,0.0,0.0,1.0);
		glRotatef(necky,0.0,1.0,0.0);
		glTranslatef(0.0f,0.6f,0.0f);
		glCallList(neckList);

		glRotatef(headx,1.0,0.0,0.0);
		glRotatef(headz,0.0,0.0,1.0);
		glRotatef(heady,0.0,1.0,0.0);
		glTranslatef(0.0f,1.3f,0.0f);
		glCallList(headList);


	glPopMatrix();
}

Human::Human(){
	headx=0.0f;
	heady=0.0f;
	headz=0.0f;

	neckx=0.0f;
	necky=0.0f;
	neckz=0.0f;

	torsox=0.0f;
	torsoy=0.0f;
	torsoz=0.0f;

	leftUpperArmx=0.0f;
	leftUpperArmy=0.0f;
	leftUpperArmz=-10.0f;

	rightUpperArmx=0.0f;
	rightUpperArmy=0.0f;
	rightUpperArmz=10.0f;

	leftLowerArmx=-10.0f;
	rightLowerArmx=-50.0f;

	hipx=0.0f;
	hipy=0.0f;
	hipz=0.0f;
	hipTranslatex=0.0f;
	hipTranslatey=0.0f;
	hipTranslatez=0.0f;

	leftUpperLegx=0.0f;
	leftUpperLegy=0.0f;
	leftUpperLegz=-5.0f;

	rightUpperLegx=0.0f;
	rightUpperLegy=0.0f;
	rightUpperLegz=5.0f;

	leftLowerLegx=0.0f;
	rightLowerLegx=0.0f;
}

void Human::reset(){
	headx=0.0f;
	heady=0.0f;
	headz=0.0f;

	neckx=0.0f;
	necky=0.0f;
	neckz=0.0f;

	torsox=0.0f;
	torsoy=0.0f;
	torsoz=0.0f;

	leftUpperArmx=0.0f;
	leftUpperArmy=0.0f;
	leftUpperArmz=-10.0f;

	rightUpperArmx=0.0f;
	rightUpperArmy=0.0f;
	rightUpperArmz=10.0f;

	leftLowerArmx=-10.0f;
	rightLowerArmx=-50.0f;

	hipx=0.0f;
	hipy=0.0f;
	hipz=0.0f;
	hipTranslatex=0.0f;
	hipTranslatey=0.0f;
	hipTranslatez=0.0f;

	leftUpperLegx=0.0f;
	leftUpperLegy=0.0f;
	leftUpperLegz=-5.0f;

	rightUpperLegx=0.0f;
	rightUpperLegy=0.0f;
	rightUpperLegz=5.0f;

	leftLowerLegx=0.0f;
	rightLowerLegx=0.0f;
}
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