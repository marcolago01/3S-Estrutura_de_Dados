#pragma once
#ifndef ARVOREEXPRESSAO_H
#define ARVOREEXPRESSAO_H

#include <string>
#include <stdlib.h>
using namespace std;

struct AExpNodo
{
	string expressao;
	AExpNodo *esquerda;
	AExpNodo *direita;

	AExpNodo(string expressao) {
		this->expressao = expressao;
	}
};

struct AExp
{
	AExpNodo * raiz;

	AExp(string expressao) {
		this->raiz = new AExpNodo(expressao);
	}

	void inicializarAExp() {
		this->raiz->direita = NULL;
		this->raiz->esquerda = NULL;
	}
	
	void pause() {
		system("pause");
	}
};

int definirPrioridade(char caracter) {
	if (caracter == '+' || caracter == '-') {
		return 1;
	}
	else if (caracter == '*' || caracter == '/') {
		return 2;
	}
	else {
		return -1;
	}
}

void montarAExp(AExpNodo *&nodo) {
	int tamanhoExpressao = nodo->expressao.length();

	if (tamanhoExpressao == 1) {
		return;
	}
	else {

		int parenteses = 0;

		for (int i = 0; i < tamanhoExpressao; i++)
		{
			if (nodo->expressao[i] == '(') {
				while (nodo->expressao[i] != ')') {
					i++;
				}
				parenteses++;
			}
		}
		if ((nodo->expressao[0] == '(' && nodo->expressao[tamanhoExpressao - 1] == ')') 
			&& parenteses == 1) {

			nodo->expressao = nodo->expressao.substr(1, tamanhoExpressao - 2);
			tamanhoExpressao = nodo->expressao.length();
		}

		int menorPrioridade = -1;
		int indiceMenorPrioridade = 0;
		int prioridadeAtual = -1;
		char caracterAtual;

		for (int i = 0; i < tamanhoExpressao; i++) {
			caracterAtual = nodo->expressao[i];

			if (caracterAtual == '(') {
				while (nodo->expressao[i] != ')') {
					i++;
				}
				caracterAtual = nodo->expressao[i];
			}

			prioridadeAtual = definirPrioridade(caracterAtual);			
			if ((prioridadeAtual > 0 && prioridadeAtual < menorPrioridade) || menorPrioridade == -1) {
				indiceMenorPrioridade = i;
				menorPrioridade = prioridadeAtual;
			}
		}
		
		nodo->esquerda = new AExpNodo(nodo->expressao.substr(0, indiceMenorPrioridade));
		nodo->direita = new AExpNodo(nodo->expressao.substr(indiceMenorPrioridade+1));
		nodo->expressao = nodo->expressao[indiceMenorPrioridade];

		montarAExp(nodo->esquerda);
		montarAExp(nodo->direita);
	}
	
}

int executarAExp(AExpNodo *&nodo) {
	int cont = 0;

	if (nodo->expressao[0] == '+') {
		cont+= executarAExp(nodo->esquerda) + executarAExp(nodo->direita);
	}
	else if (nodo->expressao[0] == '-') {
		cont+= executarAExp(nodo->esquerda) - executarAExp(nodo->direita);
	}
	else if (nodo->expressao[0] == '*') {
		cont+= executarAExp(nodo->esquerda) * executarAExp(nodo->direita);
	}
	else if (nodo->expressao[0] == '/') {
		cont+= executarAExp(nodo->esquerda) / executarAExp(nodo->direita);
	}
	else {
		cont = nodo->expressao[0]-48;
		return cont;
	}
}
#endif // !ARVOREEXPRESSAO_H

