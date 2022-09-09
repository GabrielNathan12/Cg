
#ifndef TEXTURAS_H // include guard
#define TEXTURAS_H

#define STB_IMAGE_IMPLEMENTATION
#include "./terceiros/stb_image.h"

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

#endif
