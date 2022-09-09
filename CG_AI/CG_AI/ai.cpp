#include <iostream>
#include <vector>
#include <cmath>
// O raio de alcance em que a AI percebe o Jogador.
float AI_RANGE = 5.0;

enum Move { UP, DOWN, LEFT, RIGHT, LAST};

//calcula a distancia euclidiana 2d das coordenadas
float getDistancia(float ax, float az, float bx, float bz)
{
	return sqrt(pow(ax - bx, 2) + pow(az - bz, 2));
}

std::vector<float> ai(float cx, float cz, float velocidade, float px, float pz)
{
	auto vec = std::vector<float>();
	vec = { cx, cz };
	float distancia = getDistancia(cx, cz, px, pz);
	bool face = false;
	if ((rand() % static_cast<int>(100)) > 25) face = true;//adiciona um pouco de imprevisibilidade nas ações dos inimigos
	float a = 0, b = 0;
	if (distancia<=AI_RANGE and face)
	{
		//Testa os possiveis caminhos e encontra o que coloca ele mais proximo do personagem
		for (int testar = UP; testar != LAST; testar++)
		{
			switch (testar)
			{
			case UP:
				a = cx;
				b = cz + velocidade;
				break;
			case DOWN:
				a = cx;
				b = cz - velocidade;
				break;
			case LEFT:
				a = cx - velocidade;
				b = cz;
				break;
			case RIGHT:
				a = cx + velocidade;
				b = cz;
				break;
			default:
				break;
			}
		}
		//Se a distancia for menor q a menor anterior ou a inicial recebe a coordenada
		if (getDistancia(vec[0], vec[1], px, pz) > getDistancia(a, b, px, pz)) vec = { a, b };
	}
	else//toma uma acao aleatoria
	{
		int num = (rand() % static_cast<int>(4));
		switch (num)
		{
		case UP:
			a = cx;
			b = cz + velocidade;
			break;
		case DOWN:
			a = cx;
			b = cz - velocidade;
			break;
		case LEFT:
			a = cx - velocidade;
			b = cz;
			break;
		case RIGHT:
			a = cx + velocidade;
			b = cz;
			break;
		default:
			break;
		}
		vec = { a, b };
	}
	return vec;
}

