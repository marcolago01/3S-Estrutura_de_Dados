#pragma once
#ifndef ARVOREAVL_H
#define ARVOREAVL_H

#include <string>
using namespace std;

struct NodoAVL
{
	int chave;
	string dado;
	NodoAVL * maior;
	NodoAVL * menor;
	int bal;
};

struct AVL
{
	NodoAVL * raiz;
	int qtd;
};

void inicializarAVL(AVL &arvore) {
	arvore.raiz = NULL;
	arvore.qtd = 0;
}

int inserirAVL(NodoAVL *& nodo, int chave, string dado) {

	if (nodo == NULL) {
		nodo = new NodoAVL;
		nodo->chave = chave;
		nodo->dado = dado;
		nodo->maior = NULL;
		nodo->menor = NULL;
		nodo->bal = 0;
	}
	
	return 1;
}

void dirdir(NodoAVL *a, NodoAVL *b, NodoAVL *c) {
	a->maior = b->menor;
	b->menor = a;
	
	b->bal = 0;
	b->bal = 0;
	
	a = b;
}
void diresq(NodoAVL *a, NodoAVL *b, NodoAVL *c);
void esqesq(NodoAVL *a, NodoAVL *b, NodoAVL *c);
void esqdir(NodoAVL *a, NodoAVL *b, NodoAVL *c);

int buscaAVL(NodoAVL *& nodo, int chave, string dado) {


	if (chave > nodo->chave) {
		int b = inserirAVL(nodo->maior, chave, dado);
		nodo->bal += b;
		if (nodo->bal == 2) {
			if (chave > nodo->maior->chave) {
				dirdir(nodo, nodo->maior, nodo->maior->maior);
			}
			else {
				diresq(nodo, nodo->maior, nodo->maior->menor);
			}
			b = 0;
		}
		if (nodo->bal == 0) {
			b = 0;
		}
		return b;
	}
	else {
		int b = inserirAVL(nodo->menor, chave, dado);
		nodo->bal -= b;
		if (nodo->bal == -2) {
			if (chave < nodo->menor->chave) {
				esqesq(nodo, nodo->menor, nodo->menor->menor);
			}
			else {
				esqdir(nodo, nodo->menor, nodo->menor->maior);
			}
			b = 0;
		}
		if (nodo->bal == 0) {
			b = 0;
		}
		return b;
	}
}
#endif // !ARVOREAVL_H

