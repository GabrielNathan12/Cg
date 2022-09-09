#include <GL/glut.h>
#include <iostream>
#include "./lib/terceiros/jitter.h"
//#define STB_IMAGE_IMPLEMENTATION
#include "./lib/terceiros/stb_image.h"
#include "./lib/texturas.h"
#include "Main.cpp"
#include "lobisomen.cpp"
#include "esqueleto.cpp"
#include "zumbi.cpp"

Humano personagem;
Lobisomen lobinho;
Zumbi zumbi;
Esqueleto esqueleto;

float opacidadeCubo = 1.0;
GLfloat cube_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat coresTronco[] = { 0.5, 0.4414, 0.3242, 1.0 };

GLfloat coresPerso[] = { 0.5, 0.4414, 0.3242, 1.0 };

GLfloat angle = 10.0f;
int count = 0;

GLuint texIDMapa;
GLuint texIDFolha;

float animacao = 0;
float const cam_pers = 0.2; // constante para manter a sincronia de movimento do personagem com a camera 

float x = 0.0, y = 0.0; // coordenadas da camera
float xC = 0.0, zC = 0.0;


GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };

GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat no_shininess[] = { 0.0 };
GLfloat low_shininess[] = { 5.0 };
GLfloat high_shininess[] = { 100.0 };
GLfloat mat_emission[] = {0.3, 0.2, 0.2, 0.0};

struct vet3{
	float x, y, z;
	vet3() : x(0.0), y(0.0), z(0.0){}
	vet3(float _x, float _y, float _z) : x(_x), y(_y), z (_z){}
	vet3 operator + (const vet3 & v) const {
		return vet3(x + v.x, y + v.y, z + v.z);
	}
	vet3 operator * (float k) const {
		return vet3(x * k, y * k, z * k);
	}
};

vet3 m_pos = vet3(0, 0, -1);
vet3 m_dir = vet3(0, 0, -1);
vet3 m_left = vet3(-1, 0, 0);
vet3 m_up = vet3(0, 1, 0);
vet3 m_veloc = vet3(0, 0, 0); //velocidade da camera
float m_scl = cam_pers;



void ativarCamera(){
	//vet3 look = m_pos + m_dir;
	vet3 look = m_pos + m_dir;
	gluLookAt(m_pos.x, m_pos.y, m_pos.z, look.x, look.y, look.z, m_up.x, m_up.y, m_up.z);
}

void posicaoCamera(){
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	glTranslatef(0.0f,0.0f,-3.0f);
	glRotatef(30.0f,1.0f,0.0f,0.0f);
	glRotatef(angle,0.0f,0.0f,0.0f);
}

void desenhaMapa(){

	glBindTexture(GL_TEXTURE_2D, texIDMapa);
		glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); 
		glVertex3f(-100.0, 0.0, -100.0);
		glTexCoord2f(0.0, 100.0);
		glVertex3f(-100.0, 0.0, 100.0);
		glTexCoord2f(100.0, 100.0);
		glVertex3f(100.0, 0.0, 100.0);
		glTexCoord2f(100.0, 0.0);
		//glColor3f(0.60f,1.0f,1.0f);
		glVertex3f(100.0, 0.0, -100.0);
	glEnd();
}

void desenhaArvore(){
	float Base = 0.1;
	float height = 2.0;
	GLUquadricObj *qobj;
	qobj = gluNewQuadric();
	
	
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, 0);
		glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		//glColor3f(0.0,1.0,0.0);
		glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glRotatef(-90, 1.0f, 0.0f, 0.0f);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, coresTronco);
		gluCylinder(qobj, Base, Base - (0.2 * Base), height, 20, 20);
	glPopMatrix();
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, texIDFolha);
		glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glColor4f(0.0, 0.0, 0.0, 0.2);
		glTranslatef (0.0, 2.0, 0.09);
		glRotatef(-90, 1.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
			//glRotatef(-110, 15.0f, 0.0f, 0.0f);
			
			glTexCoord2f(0.0, 0.0); 
			glVertex3f(-1.0, 0.0, -1.0);
			glTexCoord2f(0.0, 1.0);

			glVertex3f(-1.0, 0.0, 1.0);
			glTexCoord2f(1.0, 1.0);

			glVertex3f(1.0, 0.0, 1.0);
			glTexCoord2f(1.0, 0.0);

			glVertex3f(1.0, 0.0, -1.0);           
     		glEnd();
     	glPopMatrix();
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texIDFolha);
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glColor4f(0.0, 0.0, 0.0, 0.2);
	glTranslatef (0.0, 2.0, 0.09);
	glRotatef(-180, 1.0, 0.0f, 0.0f);
	glBegin(GL_QUADS);
		//glRotatef(-110, 15.0f, 0.0f, 0.0f);
		
		glTexCoord2f(0.0, 0.0); 
		glVertex3f(-1.0, 0.0, -1.0);
		glTexCoord2f(0.0, 1.0);

		glVertex3f(-1.0, 0.0, 1.0);
		glTexCoord2f(1.0, 1.0);

		glVertex3f(1.0, 0.0, 1.0);
		glTexCoord2f(1.0, 0.0);

		glVertex3f(1.0, 0.0, -1.0);           
	glEnd();
glPopMatrix();
}

void desenhaPersonagem(){
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();

	glPushMatrix();
   		glBindTexture(GL_TEXTURE_2D, 0);
  		glTranslatef(xC , 1.0 , zC);
  		glScalef(0.01 , 0.01, 0.01);
		glRotatef(animacao, 0.0f, 1.0f, 0.0f);
   		glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
		glColor3f(1.0f , 1.0f, 0.0f);

   	personagem.DesenhaTudo();
	
	glTranslatef(5.0f,0.0f,15.0f);
	   //glTranslatef (xC, 0.0, zC);
	   //glRotatef (45.0, 0.0, 0.0, 1.0);
	   //glRotatef (45.0, 1.0, 0.0, 0.0);
	   //glMaterialfv(GL_FRONT, GL_DIFFUSE, cube_diffuse);
	   //glutSolidCube (0.7);
	glPopMatrix();
   glutSwapBuffers();
	
}

float posLuz = 0.0;

void configLuz(){
   GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
   GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat position[] = { posLuz, posLuz, 2.0, 0.0 };
   GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
   GLfloat local_view[] = { 0.0 };

   glEnable(GL_DEPTH_TEST);
   glShadeModel(GL_SMOOTH);

   glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
   glLightfv(GL_LIGHT0, GL_POSITION, position);
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
   glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
}

void init(){

	glEnable( GL_DEPTH_TEST );
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glGenTextures(1, &texIDMapa);
	glGenTextures(1, &texIDFolha);
	carregaTextura( "gramaPixelArt.png",texIDMapa);
	carregaTextura( "1.png",texIDFolha);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	configLuz();

	personagem.criarListPontos();
	//Aqui vai continuar instanciando os pontos

	
}

void RenderScene(void) {
  	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	ativarCamera();
	desenhaMapa();
	desenhaArvore();
	
	desenhaPersonagem();
	glFlush();
}

void ChangeSize(GLsizei width,GLsizei height) {
  glViewport(0,0,width,height);
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  gluPerspective(45.0,width/height,0.1,500.0);
  glMatrixMode( GL_MODELVIEW );
}

void IdleFunction(void) {
  if (angle == -360) angle = 0;
  posicaoCamera();
  RenderScene();
}

void KeyboardFunc ( unsigned char key, int x, int y )
{	
	
	if (key == 'p'){
		std::cout << key << std::endl << count << std::endl;
		count += 1;
		
		ChangeSize(777,777);
	}
	switch(key){
		case 'w':
		case 'W':
			zC = zC - cam_pers;
			m_veloc = m_dir * m_scl;
			m_pos = m_pos + m_veloc;
			animacao += 20;

			if(animacao > 180){
				animacao = 180;
			}
			ChangeSize(777,777);
		break;
		case 'a':
		case 'A':
			xC = xC - cam_pers;
			m_veloc = m_left * m_scl;
			m_pos = m_pos + m_veloc;

			animacao += 20;

			if(animacao > 270){
				animacao = 270;
			}
			ChangeSize(777,777);

		break;
		case 's':
		case 'S':
			zC = zC + cam_pers;
			m_veloc = m_dir * (-m_scl);
			m_pos = m_pos + m_veloc;
			animacao = 0;
			ChangeSize(777,777);
		break;
		case 'd':
		case 'D':
			xC = xC + cam_pers;
			m_veloc = m_left * (-m_scl);
			m_pos = m_pos + m_veloc;
			animacao += 20;

			if(animacao > 90){
				animacao = 90;
			}
			ChangeSize(777,777);
		break;

		case 't':
		case 'T':
			//frente
			m_veloc = m_dir * m_scl;
			m_pos = m_pos + m_veloc;
			ChangeSize(777,777);
		break;
		case 'g':
		case 'G':
			//traz
			m_veloc = m_dir * (-m_scl);
			m_pos = m_pos + m_veloc;
			ChangeSize(777,777);
		break;
		case 'f':
		case 'F':
			
			m_veloc = m_left * m_scl;
			m_pos = m_pos + m_veloc;
			ChangeSize(777,777);
		break;
		case 'h':
		case 'H':
			m_veloc = m_left * (-m_scl);
				
			m_pos = m_pos + m_veloc;
			ChangeSize(777,777);
		break;
		case 'u':
		case 'U':
			m_veloc = m_up *  m_scl;
			m_pos = m_pos + m_veloc;
			ChangeSize(777,777);
		break;
		case 'j':
		case 'J':
			m_veloc = m_up *  (-m_scl);
			m_pos = m_pos + m_veloc;
			ChangeSize(777,777);
		break;
		case 'l':
		case 'L':
			posLuz = posLuz + 1.0;
			configLuz();
			ChangeSize(777,777);
		break;
	}
		std::cout << "pos - "<< "X: " << m_pos.x  << "Y: " << m_pos.y  << "Z: "  << m_pos.z << std::endl;
	std::cout<<"pressionou a tecla [" << key << "]\n";
}

int main(int argc, char* argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize (777, 777);
  glutInitWindowPosition (100, 100);
  glutCreateWindow("MAPA");
  init();
  glutDisplayFunc(RenderScene);
  glutReshapeFunc(ChangeSize);
  glutIdleFunc(IdleFunction);
  glutReshapeFunc(ChangeSize);
  glutKeyboardFunc(KeyboardFunc); 
  std::cout <<"EXECUTANDO... "<<std::endl;
  glutMainLoop();
  glDisable(GL_TEXTURE_2D);
  glDeleteTextures(1, &texIDMapa);
  return 0;
}
