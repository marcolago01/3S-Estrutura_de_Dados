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
	int chave;

	for (int i = 0; i < 15; i++)
	{
		//chave = rand() % 10000 + 1;
		inserirHm(teste, i+2);
	}

	teste.heap[0];

	removerHm(teste, true);

	teste.heap[0];
}

