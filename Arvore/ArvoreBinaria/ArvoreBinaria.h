#pragma once
#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

#include <string>
using namespace std;

struct NodoABB
{
	int chave;
	string dado;
	NodoABB *menor, *maior;
};

struct ABB
{
	NodoABB *raiz;
	int qtd;
};

void inicializarABB(ABB &arvore) {
	arvore.raiz = NULL;
	arvore.qtd = 0;
}

bool inserirABB_it(ABB &arvore, int chave, string dado) {
	NodoABB *novo = new NodoABB;
	if (novo == NULL) {
		return false;
	}
	novo->chave = chave;
	novo->dado = dado;
	novo->maior = NULL;
	novo->menor = NULL;

	if (arvore.qtd == 0) {
		arvore.raiz = novo;
	}
	else {
		NodoABB *nav = arvore.raiz;
		bool naoAlocado = true;
		do {
			if (novo->chave > nav->chave) {
				if (nav->maior == NULL) {
					nav->maior = novo;
					naoAlocado = false;
				}
				else
				{
					nav = nav->maior;
				}
			}
			else if (novo->chave < nav->chave) {
				if (nav->menor == NULL) {
					nav->menor = novo;
					naoAlocado = false;
				}
				else {
					nav = nav->menor;
				}
			}
			else {
				delete novo;
				return false;
			}
		} while (naoAlocado);
	}

	arvore.qtd++;
	return true;
}

bool inserirABBRec(NodoABB *&nodo, int chave, string dado) {
	
	if (nodo == NULL) {
		nodo = new NodoABB;
		nodo->dado = dado;
		nodo->chave = chave;
		nodo->menor = NULL;
		nodo->maior = NULL;
		return true;
	}
	else {
		if (chave == nodo->chave) {
			return false;
		}
		else
		{
			if (chave > nodo->chave) {
				return inserirABBRec(nodo->maior, chave, dado);
			}
			else {
				return inserirABBRec(nodo->menor, chave, dado);
			}
		}
	}
}



#endif // !ARVOREBINARIA_H

