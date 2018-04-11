#pragma once
#ifndef PILHA_H
#define PILHA_H

template<typename T>
struct TElementoP
{
	T dado;
	TElementoP<T> *deBaixo;
};

template<typename T>
struct TPilha
{
	TElementoP<T> *topo;
	int qtd;
};

template<typename T>
void inicializarPilha(TPilha<T> &pilha) {
	pilha.topo = NULL;
	pilha.qtd = 0;
}

template<typename T>
bool push(TPilha<T> &pilha,TElementoP<T> dado) {

	TElementoP<T> *novo = new TElementoP<T>;
	if (novo == NULL) {
		return false;
	}
	novo->dado = dado;
	novo->deBaixo = pilha.topo;
	pilha.topo = novo; 
	pilha.qtd++;
	return true;
}

#endif // !PILHA_H

