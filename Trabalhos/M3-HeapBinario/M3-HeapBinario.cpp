// M3-HeapBinario.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include "HeapBinario.h"

#include <time.h>
#include <stdlib.h>
using namespace std;


int main()
{
	srand(time(NULL));

	HB teste;
	inicializarHB(teste);
	Dado testeDado;

	/*for (int i = 0; i < 15; i++)
	{
		testeDado.chave = rand() % 10000 + 1;
		testeDado.dado = "123";
		inserirHm(teste, testeDado);
	}*/

	testeDado.chave = rand() % 10000 + 1;
	testeDado.dado = "a";
	inserirHm(teste, testeDado);

	testeDado.chave = rand() % 10000 + 1;
	testeDado.dado = "b";
	inserirHm(teste, testeDado);

	testeDado.chave = rand() % 10000 + 1;
	testeDado.dado = "c";
	inserirHm(teste, testeDado);

	testeDado.chave = rand() % 10000 + 1;
	testeDado.dado = "d";
	inserirHm(teste, testeDado);

	testeDado.chave = rand() % 10000 + 1;
	testeDado.dado = "e";
	inserirHm(teste, testeDado);

	teste.heap[0];

	removerHm(teste, true);

	testeDado.chave = rand() % 10000 + 1;
	testeDado.dado = "e";
	atualizarPeloDado(teste, testeDado);

	atualizarPeloDado(teste, testeDado);
}

