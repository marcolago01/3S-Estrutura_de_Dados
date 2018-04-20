// TrabalhoListas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ListaEst.h"
#include "ListaEnc.h"
#include "Lista2Enc.h"


int main()
{
	Lista2Enc<int> teste;
	inicializarLista2Enc(teste);
	inserirInicioLista2Enc(teste, 1);
	inserirFimLista2Enc(teste, 2);
	inserirPosLista2Enc(teste, 1, 1);
	bubbleSortLista2Enc(teste);
	removerPosicaoLista2Enc(teste, 1);
	removerFimLista2Enc(teste);
	removerInicioLista2Enc(teste);

	ListaEnc<int> teste2;
	inicializarListaEnc(teste2);
	inserirInicioListaEnc(teste2, 1);
	inserirFimListaEnc(teste2, 2);
	inserirPosicaoListaEnc(teste2, 3, 1);
	bubbleSortListaEnc(teste2);
	removerPosListaEnc(teste2, 1);
	removerFimListaEnc(teste2);
	removerInicioListaEnc(teste2);

	ListaEstGen<int,10> t3;
	inicializarListaEstGen(t3);
	inserirInicioListaEstGen(t3, 3);
	inserirFimListaEstGen(t3, 4);
	inserirPosicaoListaEstGen(t3, 1,5);
	bubbleSortListaEstGen(t3);
	removerPosicaoListaEstGen(t3, 1);
	removerFimListaEstGen(t3);
	removerInicioListaEstGen(t3);
	system("pause");
}

