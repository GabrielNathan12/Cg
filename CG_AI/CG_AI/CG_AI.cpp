// CG_AI.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include "ai.h"
#include <vector>

int main()
{
    std::cout << "Hello World!\n";

	for (int i = 0; i < 100; i++)
	{
		//coord criatura
		int numA = (rand() % static_cast<int>(15));
		int numB= (rand() % static_cast<int>(15));
		//cood personagem 
		int numC = (rand() % static_cast<int>(15));
		int numD = (rand() % static_cast<int>(15));

		auto vec = std::vector<float>();
		vec = ai(numA, numB, 5, numC, numD);
		std::cout << "(" << numA << ","<< numB << ") >> (" << vec[0] << ", " << vec[1] << ")\n";
		if (getDistancia(numA, numB, numC, numD) > getDistancia(vec[0], vec[0], numC, numD)) std::cout << "||||   ||||   ||||" << getDistancia(numA, numB, numC, numD) << " >> " << getDistancia(vec[0], vec[0], numC, numD);
		std::cout << "\n";
	}
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
