#pragma once
#ifndef LISTAEST_H
#define LISTAEST_H

template<typename T, int MAX>
struct ListaEstGen
{
	T elementos[MAX];
	int qtd;
};

template<typename T, int MAX>
void inicializarListaEstGen(ListaEstGen <T, MAX> &lista) {
	lista.qtd = 0;
}

template<typename T,int MAX>
bool inserirInicioListaEstGen(ListaEstGen <T, MAX> &lista, T item) {
	if (lista.qtd == MAX){
		return false;
	}
	
	for (int i = lista.qtd; i > 0; i--)
	{
		lista.elementos[i] = lista.elementos[i - 1];
	}

	lista.elementos[0] = item;
	lista.qtd++;
	return true;
}

template<typename T,int MAX>
bool inserirFimListaEstGen(ListaEstGen < T, MAX> &lista, T item) {
	if (lista.qtd == MAX) {
		return false;
	}
	lista.elementos[lista.qtd] = item;
	lista.qtd++;
	return true;
}

template<typename T,int MAX>
bool inserirPosicaoListaEstGen(ListaEstGen <T, MAX> &lista, T item,int posicao) {
	if (lista.qtd == MAX || posicao < 0 || posicao>=lista.qtd) { 
	}

	for (int i = lista.qtd; i > posicao; i--)
	{
		lista.elementos[i] = lista.elementos[i - 1];
	}
	lista.elementos[posicao] = item;
	lista.qtd++;
	return true;
}

template<typename T,int MAX>
bool removerInicioListaEstGen(ListaEstGen <T, MAX> &lista) {
	if (lista.qtd == 0) {
		return false;
	}

	lista.qtd--;
	for (int i = 0; i < lista.qtd; i++) {
		lista.elementos[i] = lista.elementos[i+1];
	}
	return true;
}

template<typename T,int MAX>
bool removerFimListaEstGen(ListaEstGen <T, MAX> &lista) {
	if (lista.qtd == 0) {
		return false;
	}
	lista.qtd--;
	return true;
}

template<typename T,int MAX>
bool removerPosicaoListaEstGen(ListaEstGen <T, MAX> &lista,int posicao) {
	if (lista.qtd == 0) {
		return false;
	}
	lista.qtd--;
	for (int i = posicao; i < lista.qtd; i++)
	{
		lista.elementos[i] = lista.elementos[i + 1];
	}
	return true;
}

template<typename T,int MAX>
bool bubbleSortListaEstGen(ListaEstGen <T, MAX> &lista) {
	if (lista.qtd < 2) {
		return false;
	}

	T aux;
	for (int i = 0; i < lista.qtd-1; i++) {
		for (int j = 0; j < lista.qtd-1; j++) {
			if (lista.elementos[j] > lista.elementos[j + 1]) {
				aux = lista.elementos[j];
				lista.elementos[j] = lista.elementos[j + 1];
				lista.elementos[j + 1] = aux;
			}
		}
	}
	return true;
}


#endif 
