#pragma once
#ifndef ARVORESBB_H
#define ARVORESBB_H

#include <string>
using namespace std;

struct NodoSBB
{
	int chave;
	string dado;

	NodoSBB *menor;
	NodoSBB *maior;

	char orientMenor;	//'v' = vertical
	char orientMaior;	//'h' = horizontal
};

struct ArvoreSBB
{
	NodoSBB *raiz;
	int qtd;
};

void inicializarArvoreSBB(ArvoreSBB &arvore) {
	arvore.raiz = NULL;
	arvore.qtd = 0;
}

void diresqSBB(NodoSBB *a, NodoSBB *b, NodoSBB *c);
void dirdirSBB(NodoSBB *a, NodoSBB *b, NodoSBB *c);
void esqesqSBB(NodoSBB *a, NodoSBB *b, NodoSBB *c);
void esqdirSBB(NodoSBB *a, NodoSBB *b, NodoSBB *c);

int inserirSBB(NodoSBB *&nodo, int chave, string dado) {
	if (nodo == NULL) {
		nodo = new NodoSBB;
		nodo->chave = chave;
		nodo->dado = dado;
		nodo->maior = NULL;
		nodo->menor = NULL;
		//nodo->orientMaior = 'h';
		//nodo->orientMenor = 'h';
		return 1;
	}
	else {
		if (chave > nodo->chave) {
			int r = 0; 
			r += inserirSBB(nodo->maior, chave, dado);
			
			if (r == 1) {
				nodo->orientMaior = 'h';
				r++;
			}

			if (r == 2 && nodo->orientMaior=='h') {
				if (chave > nodo->maior->chave) {
					dirdirSBB(nodo, nodo->maior, nodo->maior->maior);
				}
				else {
					diresqSBB(nodo, nodo->maior, nodo->maior->menor);
				}
				r = 1;
				return r;
			}
		}
	}
	return 0;
}

#endif // !ARVORESBB_H

