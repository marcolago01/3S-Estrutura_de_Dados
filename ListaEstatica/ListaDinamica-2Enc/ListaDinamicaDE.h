#pragma once
#ifndef LISTADINAMICADE_H
#define LISTADINAMICADE_H

#include "string"
using namespace std;

struct TMusica
{
	string titulo;
	string artista;

};

struct TElementoDE
{
	TMusica m;
	TElementoDE * prox;
	TElementoDE * ant;

};

struct TListaDE
{
	TElementoDE * inicio;
	TElementoDE * fim;
	int qtd;
};

void inicializarTListaDE(TListaDE &l) {
	l.inicio = NULL;
	l.fim = NULL;
	l.qtd = 0;
}

bool inserirInicioLDE(TListaDE &l, TMusica m) {

	TElementoDE * novo = new TElementoDE;

	if (novo==NULL)
	{
		return false;
	}

	novo->m = m;
	novo->ant = NULL;

	novo->prox = l.inicio;
	l.inicio = novo;
	if (l.qtd==0)
	{
		l.fim = novo;
	}
	else
	{
		l.inicio->prox->ant = l.inicio;
	}
	l.qtd++;

	return true;
}

bool inserirFimLDE(TListaDE &l, TMusica m) {
	TElementoDE * novo = new TElementoDE;
	if (novo == NULL) {
		return false;
	}

	if (l.qtd == 0) {
		return inserirInicioLDE(l, m);
	}
	else
	{
		novo->m = m;
		novo->prox = NULL;
		novo->ant = l.fim;
		l.fim->prox = novo;
		l.fim = novo;
		l.qtd++;

		return true;
	}
	
}

bool removeInicioLDE(TListaDE &l) {
	if (l.qtd == 0) {
		return false;
	}

	TElementoDE * save = new TElementoDE;

	save = l.inicio;
	l.inicio = l.inicio->prox;
	delete save;
	if (l.qtd > 1) {
		l.inicio->ant = NULL;
	}
	else
	{
		l.fim = NULL;
	}
	
	l.qtd--;
	return true;
}

bool removeFimLDE(TListaDE &l) {
	if (l.qtd == 0) {
		return false;
	}

	if (l.qtd == 1) {
		return removeInicioLDE(l);
	}

	TElementoDE * save = new TElementoDE;
	save = l.fim;
	l.fim->ant->prox = NULL;
	l.fim = l.fim->ant;
	l.qtd--;

	delete save;

	return true;
}

#endif
