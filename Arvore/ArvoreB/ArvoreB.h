#pragma once
#ifndef ARVOREB_H
#define ARVOREB_H

#include <string>
using namespace std;

const int m = 2;

struct Pagina
{
	int regs[2*m];
	string dados[2*m];
	int qtd;
	Pagina *filhos[2*m+1];

};

int imparesAB(Pagina *raiz) {
	int cont = 0;
	if (raiz== NULL) {
		return cont;
	}

	if (raiz->filhos[0] == NULL) {
		for (int i = 0; i < raiz->qtd; i++)
		{
			if (raiz->regs[i] % 2 != 0) {
				cont++;
			}
		}
		return cont;
	}
	else
	{
		for (int i = 0; i < (raiz->qtd+1); i++)
		{
			cont += imparesAB(raiz->filhos[i]);
		
		}
	}
	return cont;
}

int qtdRegNivelK(Pagina *raiz, int k,int nivel = 0) {
	int cont = 0;
	if (raiz == NULL) {
		return cont;
	}
	if (nivel == k) {
		cont += raiz->qtd;
		return cont;
	}
	else {
		for (int i = 0; i < raiz->qtd+1; i++)
		{
			cont += qtdRegNivelK(raiz->filhos[i], k, nivel+1);
		}
	}
	return cont;
}

#endif
