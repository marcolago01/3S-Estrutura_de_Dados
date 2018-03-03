#pragma once
#ifndef LISTAESTATICA_H
#define LISTAESTATICA_H

#include <iostream>
using namespace std;

struct TCarta
{
	int valor;
	int naipe;
};

const int MAX = 52;

struct ListaEstatica
{
	TCarta elementos[MAX];
	int qtd;
};

void inicializarListaEst(ListaEstatica &l) {
	l.qtd = 0;
}

bool inserirFimLEst(ListaEstatica &l, TCarta c) {
	if (l.qtd == MAX) {
		return false;
	}
	l.elementos[l.qtd] = c;
	l.qtd++;
	return true;
}

bool inserirInicioLest(ListaEstatica &l, TCarta c) {
	if (l.qtd == MAX) {
		return false;
	}
	for (int i = l.qtd;i > 0;i--) {
		l.elementos[i] = l.elementos[i - 1];
	}
	l.elementos[0] = c;
	l.qtd++;
	return true;
}

bool inserirPosLEst(ListaEstatica &l, TCarta c, int pos) {
	if (l.qtd == MAX || pos > l.qtd || pos <0) {
		return false;
	}
	for (int i = l.qtd;i > pos; i--) {
		l.elementos[i] = l.elementos[i - 1];
	}
	l.elementos[pos] = c;
	l.qtd++;
	return true;
}

bool removeFimLEst(ListaEstatica &l) {
	if (l.qtd > 0) {
		l.qtd--;
		return true;
	}
	else {
		return false;
	}

}

bool removeInicioLEst(ListaEstatica &l) {
	if (l.qtd > 0) {
		l.qtd--;
		for (int i = 0;i < l.qtd;i++) {
			l.elementos[i] = l.elementos[i + 1];
		}
		return true;
	}
	else {
		return false;
	}
	
}

bool removePosLEst(ListaEstatica &l, int pos) {
	if (l.qtd <= 0 || pos < 0 || pos >= l.qtd) {
		return false;
	}
	else {
		l.qtd--;
		for (int i = pos;i < l.qtd-1;i++) {
			l.elementos[i] = l.elementos[i + 1];
		}
		return true;
	}


}

void imprimirLEst(ListaEstatica l) {
	for (int i = 0;i < l.qtd;i++) {
		cout << l.elementos[i].valor << " - " << l.elementos[i].naipe << endl;
	}
}

#endif
