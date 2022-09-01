/*
w,a,s,d - movimenta o quadrado
t,g,f,h - movimenta apenas a camera


*/

#include <GL/glut.h>
#include <iostream>
#include "jitter.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
float opacidadeCubo = 1.0;
GLfloat cube_diffuse[] = { 0.7, 1.0, 0.0, opacidadeCubo };

GLfloat angle = 10.0f;
int count = 0;

GLuint texID;

float const cam_pers = 0.2; // constante para manter a sincronia de movimento do personagem com a camera 

float x = 0.0, y = 0.0; // coordenadas da camera
float xC = 0.0, zC = 0.0;

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

void carregaTextura(std::string dirTextura, GLuint id){
	unsigned char * imgData;
	int largura, altura, canais;
	imgData = stbi_load(dirTextura.c_str(), &largura, &altura, &canais, 4);
	if(imgData){
		glBindTexture(GL_TEXTURE_2D, id);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, largura, altura, 0, GL_RGBA, GL_UNSIGNED_BYTE, imgData);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		
		stbi_image_free(imgData);
	}else{
		std::cout << "Deu ruim a textura irmão :(\n";
	}

}

void RenderScene(void) {
  glClearColor(0.0f,0.0f,0.0f,0.0f);
  glEnable( GL_DEPTH_TEST );
  glEnable(GL_TEXTURE_2D);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glGenTextures(1, &texID);
  carregaTextura( "gramaPixelArt.png",texID);
  
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  ativarCamera();
  glBindTexture(GL_TEXTURE_2D, texID);
  glBegin(GL_QUADS);
   glColor3f(0.60f,1.0f,0.0f);
   glTexCoord2f(0.0, 0.0); 
   glVertex3f(-100.0, 0.0, -100.0);
   glTexCoord2f(0.0, 100.0);
   //glColor3f(0.60f,5.0f,0.0f);
   glVertex3f(-100.0, 0.0, 100.0);
   glTexCoord2f(100.0, 100.0);
   //glColor3f(0.60f,0.0f,0.0f);
   glVertex3f(100.0, 0.0, 100.0);
   glTexCoord2f(100.0, 0.0);
   //glColor3f(0.60f,1.0f,1.0f);
   glVertex3f(100.0, 0.0, -100.0);
  glEnd();
  glDisable(GL_TEXTURE_2D);
  glBegin( GL_LINES );
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.7f,0.0f,0.0f);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.5f,0.0f);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.7f);
  glEnd();
  glBegin( GL_POLYGON );
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.2f,0.0f);
    glVertex3f(0.2f,0.3f,0.0f);
    glVertex3f(0.4f,0.2f,0.0f);
    glVertex3f(0.4f,0.0f,0.0f);
  glEnd();
  glBegin( GL_QUADS );
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.4f);
    glVertex3f(0.0f,0.2f,0.4f);
    glVertex3f(0.0f,0.2f,0.0f);
  glEnd();
  glBegin( GL_QUAD_STRIP );
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(0.0f,0.2f,0.0f);
    glVertex3f(0.0f,0.2f,0.4f);
    glVertex3f(0.2f,0.3f,0.0f);
    glVertex3f(0.2f,0.3f,0.4f);
    glVertex3f(0.4f,0.2f,0.0f);
    glVertex3f(0.4f,0.2f,0.4f);
  glEnd();
  glColor3f(1.0f,1.0f,1.0f);
  glBegin( GL_LINE_STRIP );
    glVertex3f(0.0f,0.0f,0.4f);
    glVertex3f(0.4f,0.0f,0.4f);
    glVertex3f(0.4f,0.0f,0.0f);
  glEnd();
  glBegin( GL_LINES );
    glVertex3f(0.4f,0.0f,0.4f);
    glVertex3f(0.4f,0.2f,0.4f);
  glEnd();
  
   glPushMatrix ();
	   glTranslatef (xC, 0.0, zC);
	   //glRotatef (45.0, 0.0, 0.0, 1.0);
	   //glRotatef (45.0, 1.0, 0.0, 0.0);
	   glMaterialfv(GL_FRONT, GL_DIFFUSE, cube_diffuse);
	   glutSolidCube (0.5);
   glPopMatrix ();
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
  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity();
  glTranslatef(0.0f,0.0f,-3.0f);
  glRotatef(30.0f,1.0f,0.0f,0.0f);
  glRotatef(angle,0.0f,0.0f,0.0f);
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
			ChangeSize(777,777);
		break;
		case 'a':
		case 'A':
			xC = xC - cam_pers;
			m_veloc = m_left * m_scl;
			m_pos = m_pos + m_veloc;
			ChangeSize(777,777);

		break;
		case 's':
		case 'S':
			zC = zC + cam_pers;
			m_veloc = m_dir * (-m_scl);
			m_pos = m_pos + m_veloc;
			ChangeSize(777,777);
		break;
		case 'd':
		case 'D':
			xC = xC + cam_pers;
			m_veloc = m_left * (-m_scl);
			m_pos = m_pos + m_veloc;
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
	}
		std::cout << "pos - "<< "X: " << m_pos.x  << "Y: " << m_pos.y  << "Z: "  << m_pos.z << std::endl;
	std::cout<<"pressionou a tecla [" << key << "]\n";
}

int main(int argc, char* argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (777, 777);
  glutInitWindowPosition (100, 100);
  glutCreateWindow("MAPA");
  glutDisplayFunc(RenderScene);
  glutReshapeFunc(ChangeSize);
  glutIdleFunc(IdleFunction);
  glutReshapeFunc(ChangeSize);
  glutKeyboardFunc(KeyboardFunc); 
  std::cout <<"EXECUTANDO... "<<std::endl;
  glutMainLoop();
  glDeleteTextures(1, &texID);
  return 0;
}
