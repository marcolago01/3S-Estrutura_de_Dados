#pragma once
#ifndef LISTA_ESTATICA_GEN_H
#define LISTA_ESTATICA_GEN_H

template<typename T,int MAX>
struct TLEstG
{
	T elementos[MAX];
	int qtd;
};

template <typename T,int MAX>
void inicializarLEstG(TLEstG <T, MAX> &l) {
	l.qtd = 0;
}

template <typename T,int MAX>
bool inserirFimLEstG(TLEstG <T, MAX> &l, T dado) {
	if (l.qtd == MAX) {
		return false;
	}

	l.elementos[l.qtd] = dado;
	l.qtd++;
	return true;
}

template <typename T,int MAX>
bool inserirInicioLEstG(TLEstG <T, MAX> &l, T dado) {
	if (l.qtd == MAX) {
		return false;
	}

	for (int i = l.qtd; i > 0; i--)
	{
		l.elementos[i] = l.elementos[i - 1];
	}

	l.elementos[0] = dado;
	l.qtd++;
	return true;
}

#endif // !LISTA_ESTATICA_GEN_H

