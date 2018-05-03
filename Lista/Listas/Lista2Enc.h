#pragma once
#ifndef LISTA2ENC_H
#define LISTA2ENC_H

#include <iostream>
using namespace std;

template<typename T>
struct Elemento2Enc {
	T elemento;
	Elemento2Enc *proximo;
	Elemento2Enc *anterior;
};

template<typename T>
struct Lista2Enc {
	Elemento2Enc<T> *inicio;
	Elemento2Enc<T> *fim;
	int qtd;
};

template<typename T>
void inicializarLista2Enc(Lista2Enc<T> &lista) {
	lista.inicio = NULL;
	lista.fim = NULL;
	lista.qtd = 0;
}

template<typename T>
bool inserirInicioLista2Enc(Lista2Enc<T> &lista, T elemento) {
	Elemento2Enc<T> *novo = new Elemento2Enc<T>;
	if (novo == NULL) {
		return false;
	}

	novo->elemento = elemento;
	novo->anterior = NULL;
	novo->proximo = lista.inicio;
	lista.inicio = novo;
	if (lista.qtd == 0) {
		lista.fim = novo;
	}
	else {
		lista.inicio->proximo->anterior = novo;
	}
	lista.qtd++;
	return true;
}

template<typename T>
bool inserirFimLista2Enc(Lista2Enc<T> &lista, T elemento) {
	Elemento2Enc<T> *novo = new Elemento2Enc<T>;
	if (novo == NULL) {
		return false;
	}

	if (lista.qtd == 0) {
		return inserirInicioLista2Enc(lista, elemento);
	}

	novo->elemento = elemento;
	novo->proximo = NULL;
	novo->anterior = lista.fim;
	lista.fim->proximo = novo;
	lista.fim = novo;
	lista.qtd++;
	return true;
}

template<typename T>
bool inserirPosLista2Enc(Lista2Enc<T> &lista, T elemento, int posicao) {
	if (posicao < 0 || posicao > lista.qtd) {
		return false;
	}

	if (posicao == lista.qtd) {
		return inserirFimLista2Enc(lista, elemento); //adicionar inserir Fim
	}

	if (lista.qtd > 1) {
		Elemento2Enc<T> *novo = new Elemento2Enc<T>;
		if (novo == NULL) {
			return false;
		}

		Elemento2Enc<T> *nav = lista.inicio;
		for (int i = 0; i < posicao - 1; i++) {
			nav = nav->proximo;
		}

		nav->proximo->anterior = novo;
		nav->proximo = novo;
		lista.qtd++;
		return true;
	}
	else {
		return inserirInicioLista2Enc(lista, elemento); //adicionar Inserir Inicio
	}
}

template<typename T>
bool removerInicioLista2Enc(Lista2Enc<T> &lista) {
	if (lista.qtd == 0) {
		return false;
	}
	Elemento2Enc<T> *save = lista.inicio;
	lista.inicio = lista.inicio->proximo;
	delete save;
	if (lista.qtd > 1) {
		lista.inicio->anterior = NULL;
	}
	else {
		lista.fim = NULL;
	}
	lista.qtd--;
	return true;
}

template<typename T>
bool removerFimLista2Enc(Lista2Enc<T> &lista) {
	if (lista.qtd == 0) {
		return false;
	}
	Elemento2Enc<T> *save = lista.fim;
	lista.fim = lista.fim->anterior;
	delete save;
	if (lista.qtd > 1) {
		lista.fim->proximo = NULL;
	}
	else {
		lista.inicio = NULL;
	}
	lista.qtd--;
	return true;
}

template<typename T>
bool removerPosicaoLista2Enc(Lista2Enc<T> &lista, int posicao) {
	if (posicao < 0 || posicao >= lista.qtd || lista.qtd == 0) {
		return false;
	}

	Elemento2Enc<T> *apagar = lista.inicio;
	for (int i = 0; i < posicao; i++)
	{
		apagar = apagar->proximo;
	}

	if (posicao == 0) {
		return removerInicioLista2Enc(lista);
	}
	else if (posicao == lista.qtd - 1) {
		return removerFimLista2Enc(lista);
	}

	apagar->anterior->proximo = apagar->proximo;
	apagar->proximo->anterior = apagar->anterior;
	delete apagar;
	lista.qtd--;
	return true;
}


template<typename T>
bool bubbleSortLista2Enc(Lista2Enc<T> &lista) {
	if (lista.qtd < 2) {
		return false;
	}

	T aux;
	Elemento2Enc<T> *navegador = lista.inicio;
	for (int i = 0; i < lista.qtd - 1; i++) {
		for (int j = 0; j < lista.qtd - 1; j++)
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
#endif // !LISTA2ENC_H

