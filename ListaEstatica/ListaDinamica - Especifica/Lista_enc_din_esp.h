#pragma once
#ifndef LISTA_ENC_DIN_ESP_H
#define LISTA_ENC_DIN_ESP_H

#include <string>
using namespace std;

struct TMusica
{
	string titulo;
	string artista;
};

struct TElemento
{
	TMusica m;
	TElemento * proximo;
};

struct TLista
{
	TElemento * inicio;
	int qtd;
};

void inicializarLEnc(TLista &l) {
	l.inicio = NULL;
	l.qtd = 0;
}

bool inserirInicioLEnc(TLista &l, TMusica m) {
	TElemento * novo = new TElemento;
	if (novo == NULL) {
		return false;
	}
	novo->m = m;
	novo->proximo = l.inicio;
	l.inicio = novo;
	l.qtd++;
	return true;
}

bool inserirFimLEnc(TLista &l, TMusica m) {
	//Solução caso lista vazia.
	if (l.qtd == 0) {
		return inserirInicioLEnc(l, m);
	}

	TElemento * novo = new TElemento;
	if (novo == NULL) {
		return false;
	}

	novo->m = m;
	novo->proximo = NULL;

	TElemento * pontAux;
	pontAux = l.inicio;
	
	//Solução do Professor
	while (pontAux->proximo != NULL) {
		pontAux = pontAux->proximo;
	}

	l.qtd++;
	return true;

	/* Minha solução
	bool ultimoElemento = false;
	do {
		if (pontAux->proximo == NULL) {
			pontAux->proximo = novo;
			ultimoElemento = true;
		}
		pontAux = pontAux->proximo;
	} while (!ultimoElemento);*/
}

bool removerInicioLEnc(TLista &l) {
	if (l.qtd == 0) {
		return false;
	}

	TElemento * save;
	save = l.inicio;
	l.inicio = l.inicio->proximo;
	delete save;

	l.qtd--;
	return true;
}


#endif
