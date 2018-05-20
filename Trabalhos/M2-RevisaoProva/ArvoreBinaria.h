#pragma once
#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

#include <string>
#include <iostream>
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

void inFixa(NodoABB *&nodo) {

	if (nodo != NULL) {
		inFixa(nodo->menor);
		cout << nodo->chave << ", ";
		inFixa(nodo->maior);
	}
}

string buscaString(NodoABB *nodo, int chave) {
	if (nodo == NULL) {
		return "nao encontrado";
	}
	if (nodo->chave == chave) {
		return nodo->dado;
	}
	else {
		if (chave < nodo->chave) {
			return buscaString(nodo->menor,chave);
		}
		else {
			return buscaString(nodo->maior,chave);
		}
	}
	
}

int busca(NodoABB *nodo, string dado) {
	if (nodo != NULL) {
		if (nodo->dado == dado) {
			return nodo->chave;
		}
		
		int res = busca(nodo->menor, dado);
		if (res == NULL) {
			return busca(nodo->maior, dado);
		}
		else {
			return res;
		}
	}
	return NULL;
}

void removeNodo(NodoABB *&nodo) {

	NodoABB *mm = nodo->menor;
	NodoABB *pai = NULL;

	if (mm == NULL) {
		NodoABB * rem = nodo;
		nodo = nodo->maior;
		delete rem;
		return;
	}

	while (nodo->maior != NULL) {
		pai = mm;
		mm = mm->maior;
	}

	mm->maior = nodo->maior;
	if (pai != NULL) {
		pai->maior = mm->menor;
		mm->menor = nodo->menor;
	}
	delete nodo;
	nodo = mm;
}

bool encontrarRemoverNodo(NodoABB *nodo, int chave) {
	if (nodo == NULL) {
		return false;
	}
	if (nodo->chave == chave) {
		removeNodo(nodo);
		return true;
	}
	else {
		if (chave < nodo->chave) {
			return encontrarRemoverNodo(nodo->menor, chave);
		}
		else {
			return encontrarRemoverNodo(nodo->maior, chave);
		}
	}
}
#endif // !ARVOREBINARIA_H

