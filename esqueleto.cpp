#include <GL/glut.h>
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <iostream>

using namespace std;


#ifndef ESQUELETO_H
#define ESQUELETO_H


class Esqueleto {
    private :
        void criarCabecaList();
        void criarPescocoList();
        void criarTorsoList();
        void criarBracoDirList();
        void criarBracoEsqList();
        void criarQuadrilList();
        void criarPernaDirList();
        void criarPernaEsqList();
    
    public:
        float cabeca_x , cabeca_y , cabeca_z;  
        float pescoco_x , pescoco_y , pescoco_z; 
        float torso_x , torso_y , torso_z;  
        float bracoE_x , bracoE_y , bracoE_z; 
        float bracoD_x , bracoD_y , bracoD_z; 
        float ombroE , ombroD; 
        float quadril_x , quadril_y , quadril_z; 
        float moverQuadril_x , moverQuadril_y , moverQuadril_z;  
        float pernaE_x , pernaE_y , pernaE_z;
        float pernaD_x , pernaD_y , pernaD_z; 
        float pernaE , pernaD; 
 
        GLuint cabecaList;
        GLuint perscoList;
        GLuint torsoList;
        GLuint bracoDList; 
        GLuint bracoEList; 
        GLuint quadrilList;
        GLuint pernaEList; 
        GLuint pernaDList;

        void criarListPontos();
        void DesenhaTudo();
        void reset();
        Esqueleto();
        ~Esqueleto();

};

#endif

Esqueleto :: Esqueleto(){

    cabeca_x = 0.0f;
    cabeca_y = 0.0f;
    cabeca_z = 0.0f;

    pescoco_x = 0.0f;
    pescoco_y = 0.0f;
    pescoco_z = 0.0f;

    torso_x = 0.0f;
    torso_y = 0.0f;
    torso_z = 0.0f;
    
    bracoE_x = 0.0f; 
    bracoE_y = 0.0f; 
    bracoE_z = -10.0f;
    
    bracoD_x = 0.0f;
    bracoD_y = 0.0f, 
    bracoD_z = 10.0f;

    ombroE = -10.0f;
    ombroD = -50.0f;

    quadril_x = 0.0f;
    quadril_y = 0.0f;
    quadril_z = 0.0f;

    moverQuadril_x = 0.0f; 
    moverQuadril_y = 0.0f; 
    moverQuadril_z = 0.0f;
    
    pernaE_x = 0.0f;
    pernaE_y = 0.0f; 
    pernaE_z = -5.0f;

    pernaD_x =  0.0f; 
    pernaD_y = 0.0f; 
    pernaD_z = 5.0f;

    pernaE = 0.0f;
    pernaD = 0.0f;


}

Esqueleto :: ~Esqueleto(){

}

void Esqueleto :: criarCabecaList(){
    cabecaList = glGenLists(1);
    glNewList(cabecaList , GL_COMPILE);

    glPushMatrix();
        glScalef(0.9f , 1.0f , 1.0f);
        glColor3f(1.0f, 0.0f, 0.2f); 
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

void Esqueleto :: criarPescocoList(){
    perscoList = glGenLists(1);
    glNewList(perscoList , GL_COMPILE);
    glColor3f(0.8f, 0.8f, 0.8f); 
    GLUquadricObj *quadratico;
    quadratico = gluNewQuadric();
    glScalef(0.9f , 1.0f , 1.0f);
    glRotatef(90.0f , 1.0f , 0.0f , 0.0f);
    gluCylinder(quadratico ,  2.5f , 2.0f , 5.0f , 32 , 32);
    gluDisk(quadratico , 0.0f , 0.6f , 32 , 32);
    glRotatef(-90.0f , 1.0f , 0.0f , 0.0f);

    glEndList();
}

void Esqueleto :: criarTorsoList(){
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    //glGenTextures(1, &texID);
    torsoList = glGenLists(1);

    glNewList(torsoList , GL_COMPILE);
    glColor3f(0.8f, 0.8f, 0.8f); 
    GLUquadricObj *quadratico;
    quadratico = gluNewQuadric();
    glScalef(0.9f , 1.0f , 1.0f);
    glRotatef(90.0f , 1.0f , 0.0f , 0.0f);
    //gluQuadricTexture(quadratico , 1);
    //glBindTexture(GL_TEXTURE_2D , texID);
    glTexCoord2f(0.0, 0.0);
    glTexCoord2f(100.0, 100.0);
    glTexCoord2f(100.0, 0.0);
    gluCylinder(quadratico , 2.5f , 2.0f , 5.0f , 32 , 32);
    gluDisk(quadratico , 0.0f , 2.5f , 32 , 32);

    glPushMatrix();
        glTranslatef(0.0f , 0.0f , 5.0f);
        gluDisk(quadratico , 0.0f , 2.0f , 32 , 32);
    glPopMatrix();
    glRotatef(-90.0f , 1.0f , 0.0f , 0.0f);
    glEndList();
    glDisable(GL_TEXTURE_2D);

}

void Esqueleto :: criarBracoDirList(){
    bracoDList = glGenLists(1);
    
    glNewList(bracoDList , GL_COMPILE);
    glColor3f(0.8f, 0.8f, 0.8f); 
    GLUquadricObj *quadratico;
    quadratico = gluNewQuadric();
    glScalef(0.9f , 1.0f , 1.0f);
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

void Esqueleto :: criarBracoEsqList(){
    bracoEList = glGenLists (1);
	
    glNewList(bracoEList , GL_COMPILE);
    glColor3f(0.8f, 0.8f, 0.8f);     
    GLUquadricObj *quadratico;
    quadratico = gluNewQuadric();
    glScalef(0.9f , 1.0f , 1.0f);
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

void Esqueleto :: criarQuadrilList(){
    quadrilList = glGenLists (1);
	
    glNewList(quadrilList, GL_COMPILE);
		//Texture tex;
		//humanTexture = tex.loadBMP_custom("./images/belt.bmp");
        glColor3f(0.8f, 0.8f, 0.8f);  
		GLUquadricObj *quadratico;
		quadratico = gluNewQuadric();
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        glScalef(0.9f , 1.0f , 1.0f);
		//gluQuadricTexture(quadratic,1);
		gluCylinder(quadratico,2.1f,2.1f,1.0f,32,32);

		glPushMatrix();
			glTranslatef(0.0,0.0,1.0f);
			gluDisk(quadratico,0.0f,2.1f,32,32);
		glPopMatrix();

		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glEndList();
}

void Esqueleto :: criarPernaDirList(){
    pernaDList = glGenLists (1);
	glNewList(pernaDList, GL_COMPILE);
		//Texture tex;
		//humanTexture = tex.loadBMP_custom("./images/trouser.bmp");
		glColor3f(0.8f, 0.8f, 0.8f);   
		GLUquadricObj *quadratico;
		quadratico = gluNewQuadric();
        glScalef(0.9f , 1.0f , 1.0f);
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		//gluQuadricTexture(quadratico,1);
		gluCylinder(quadratico,1.0f,1.0f,4.0f,32,32);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glEndList();
}

void Esqueleto :: criarPernaEsqList(){
    pernaEList = glGenLists (1);
	
    glNewList(pernaEList, GL_COMPILE);
		//Texture tex;
		//humanTexture = tex.loadBMP_custom("./images/trouser.bmp");
		glColor3f(0.8f, 0.8f, 0.8f);     
		GLUquadricObj *quadratico;
		quadratico = gluNewQuadric();
        glScalef(0.9f , 1.0f , 1.0f);
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		//gluQuadricTexture(quadratico,1);
		gluCylinder(quadratico,1.0f,0.8f,6.0f,32,32);

		glPushMatrix();
			glTranslatef(0.0,0.0,6.0f);
			gluDisk(quadratico,0.0f,0.8f,32,32);
		glPopMatrix();

		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glEndList();
}

void Esqueleto :: criarListPontos(){
    criarCabecaList();
    criarPescocoList();
    criarTorsoList();
    criarBracoDirList();
    criarBracoEsqList();
    criarQuadrilList();
    criarPernaDirList();
    criarPernaEsqList();
}

void Esqueleto :: DesenhaTudo(){
    
    // Quadril
    glPushMatrix();
		glTranslatef(moverQuadril_x,moverQuadril_y,moverQuadril_z);
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
			glCallList(bracoDList);

			glTranslatef(0.0,-3.0f,0.0f);
			glRotatef(ombroD,1.0,0.0,0.0f);
			glCallList(bracoEList);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-2.5f,-0.0f,0.0f);
			glRotatef(bracoE_x,1.0,0.0,0.0);
			glRotatef(bracoE_z,0.0,0.0,1.0);
			glRotatef(bracoE_y,0.0,1.0,0.0);
			glCallList(bracoDList);

			glTranslatef(0.0,-3.0f,0.0f);
			glRotatef(ombroE,1.0,0.0,0.0f);
			glCallList(bracoEList);
		glPopMatrix();

		
		glRotatef(pescoco_x,1.0,0.0,0.0);
		glRotatef(pescoco_z,0.0,0.0,1.0);
		glRotatef(pescoco_y,0.0,1.0,0.0);
		glTranslatef(0.0f,0.6f,0.0f);
		glCallList(perscoList);

		glRotatef(cabeca_x,1.0,0.0,0.0);
		glRotatef(cabeca_z,0.0,0.0,1.0);
		glRotatef(cabeca_y,0.0,1.0,0.0);
		glTranslatef(0.0f,1.3f,0.0f);
		glCallList(cabecaList);


	glPopMatrix();
}


void Esqueleto :: reset(){
	cabeca_x = 0.0f;
    cabeca_y = 0.0f;
    cabeca_z = 0.0f;

    pescoco_x = 0.0f;
    pescoco_y = 0.0f;
    pescoco_z = 0.0f;

    torso_x = 0.0f;
    torso_y = 0.0f;
    torso_z = 0.0f;
    
    bracoE_x = 0.0f; 
    bracoE_y = 0.0f; 
    bracoE_z = -10.0f;
    
    bracoD_x = 0.0f;
    bracoD_y = 0.0f, 
    bracoD_z = 10.0f;

    ombroE = -10.0f;
    ombroD = -50.0f;

    quadril_x = 0.0f;
    quadril_y = 0.0f;
    quadril_z = 0.0f;

    moverQuadril_x = 0.0f; 
    moverQuadril_y = 0.0f; 
    moverQuadril_z = 0.0f;
    
    pernaE_x = 0.0f;
    pernaE_y = 0.0f; 
    pernaE_z = -5.0f;

    pernaD_x =  0.0f; 
    pernaD_y = 0.0f; 
    pernaD_z = 5.0f;

    pernaE = 0.0f;
    pernaD = 0.0f;

}


