#pragma once
#ifndef LISTAENC_H
#define LISTAENC_H

#include <iostream>
using namespace std;

template<typename T>
struct Elemento {
	T elemento;
	Elemento *proximo;

};

template<typename T>
struct ListaEnc {
	Elemento<T> *inicio;
	int qtd;
};

template<typename T>
void inicializarListaEnc(ListaEnc<T> &lista) {
	lista.inicio = NULL;
	lista.qtd = 0;
}

template<typename T>
bool inserirInicioListaEnc(ListaEnc<T> &lista, T elemento) {
	Elemento<T> *novo = new Elemento<T>;
	if (novo == NULL) {
		return false;
	}

	novo->elemento = elemento;
	novo->proximo = lista.inicio;
	lista.inicio = novo;
	lista.qtd++;
	return true;
}

template<typename T>
bool inserirFimListaEnc(ListaEnc<T> &lista, T elemento) {
	if (lista.qtd == 0) {
		return inserirInicioListaEnc(lista, elemento);
	}

	Elemento<T> *novo = new Elemento<T>;
	if (novo == NULL) {
		return false;
	}

	novo->elemento = elemento;
	novo->proximo = NULL;
	Elemento<T> *nav = lista.inicio;

	while (nav->proximo != NULL) {
		nav = nav->proximo;
	}
	nav->proximo = novo;
	lista.qtd++;
	return true;
}
template<typename T>
bool inserirPosicaoListaEnc(ListaEnc<T> &lista, T elemento,int posicao) {
	Elemento <T> *novo = new Elemento<T>;
	novo->elemento = elemento;

	if (novo == NULL || posicao < 0 || posicao >= lista.qtd) {
		return false;
	}
	
	Elemento <T> *navegador = lista.inicio;
	for (int i = 0; i < posicao-1; i++) {
		navegador = navegador->proximo;
	}

	novo->proximo = navegador->proximo;
	navegador->proximo = novo;
	lista.qtd++;
	return true;
}

template<typename T>
bool removerInicioListaEnc(ListaEnc<T> &lista) {
	if (lista.qtd == 0) {
		return false;
	}

	Elemento<T> *apagar = lista.inicio;
	lista.inicio = lista.inicio->proximo;
	delete apagar;
	lista.qtd--;
	return true;
}

template<typename T>
bool removerFimListaEnc(ListaEnc<T> &lista) {
	if (lista.qtd == 0) {
		return false;
	}
	
	if (lista.qtd == 1) {
		return removerInicioListaEnc(lista);
	}

	Elemento<T> *navegador = lista.inicio;

	while (navegador->proximo->proximo != NULL) {
		navegador = navegador->proximo;
	}

	delete navegador->proximo;
	navegador->proximo = NULL;

	lista.qtd--;
	return true;
}

template<typename T>
bool removerPosListaEnc(ListaEnc<T> &lista, int posicao) {
	if (lista.qtd == 0 || posicao < 0 || posicao >= lista.qtd) {
		return false;
	}

	if (posicao == (lista.qtd - 1)) {
		return removerFimListaEnc(lista);	//adicionar remover fim
	}

	if (lista.qtd > 1) {
		Elemento<T> *save = lista.inicio;
		for (int i = 0; i < posicao - 1; i++) {
			save = save->proximo;
		}

		Elemento<T> *aux = save;
		save = save->proximo;
		aux->proximo = save->proximo;
		delete save;
		lista.qtd--;
		return true;
	}
	else {
		return removerInicioListaEnc(lista); //adicionar remover inicio;
	}
}

template<typename T>
bool bubbleSortListaEnc(ListaEnc<T> &lista) {
	if (lista.qtd < 2) {
		return false;
	}

	T aux;
	Elemento<T> *navegador = lista.inicio;
	for (int i = 0; i < lista.qtd-1; i++) {
		for (int j = 0; j < lista.qtd-1; j++)
		{
			if (navegador->elemento > navegador->proximo->elemento) {
				aux = navegador->elemento;
				navegador->elemento = navegador->proximo->elemento;
				navegador->proximo->elemento = aux;
			}
		}
		navegador = navegador->proximo;
	}
	return true;
}
#endif // !LISTAENC_H
