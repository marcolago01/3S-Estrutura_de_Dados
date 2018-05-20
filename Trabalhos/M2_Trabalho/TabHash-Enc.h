#pragma once

#include "ListaEnc.h"
using namespace std;

const int MAX = 1000;

struct TabHashEnc
{
	ListaEnc<int> tabHash[MAX];
	int qtd;
};

void inicializarTabHashEnc(TabHashEnc &tabela) {
	tabela.qtd = 0;
	for (int i = 0; i < MAX; i++) {
		 inicializarListaEnc(tabela.tabHash[i]);
	}
}

bool inserirTabHashEnc(TabHashEnc &tabela, int chave,int instrucao) {
	int posicao = chave % MAX;
	if (inserirFimListaEnc(tabela.tabHash[posicao],chave)) {
		instrucao++;
		tabela.qtd++;
		return true;
	}
	return false;
	
}

bool pesquisarTabHashEnc(TabHashEnc &tabela, int chave, int &instrucao) {
	int posicao = chave % MAX;

	if (tabela.tabHash[posicao].qtd != 0) {
		Elemento<int> *nav = tabela.tabHash[posicao].inicio;
		while (nav != NULL)
		{
			if (nav->elemento == chave) {
				return true;
			}
			instrucao++;
			nav = nav->proximo;
		}
		return false;
	}else{
		return false;
	}

}


