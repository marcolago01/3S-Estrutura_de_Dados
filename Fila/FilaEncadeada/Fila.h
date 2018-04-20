#pragma once
#ifndef LISTA_H
#define LISTA_H

template<typename T>
struct ElementoF
{
	T dado;
	ElementoF<T> *prox;
};

template<typename T>
struct Fila
{
	ElementoF<T> *inicio;
	ElementoF<T> *ultimo;
	int qtd;
};

template<typename T>
void inicializarFila(Fila<T> &fila) {
	fila.inicio = NULL;
	fila.ultimo = NULL;
	fila.qtd = 0;
}

template<typename T>
bool enfileirar(Fila<T> &fila, T dado) {
	ElementoF<T> *novo = new ElementoF<T>;
	if (novo == NULL) {
		return false;
	}
	novo->dado = dado;
	novo->prox = NULL;
	if (fila.qtd == 0) {
		fila.inicio = novo;
	}
	else {
		fila.ultimo->prox = novo;
	}
	fila.ultimo = novo;
	fila.qtd++;
	return true;
}

template<typename T>
bool desenfileirar(Fila<T> &fila) {
	if (fila.qtd == 0) {
		return false;
	}
	ElementoF<T> *apagar;
	apagar = fila.inicio;
	fila.inicio = fila.inicio->prox;
	if (fila.qtd == 1) {
		fila.ultimo = fila.ultimo->prox;
	}

	delete apagar;
	fila.qtd--;
	return true;

}

#endif // !LISTA_H

