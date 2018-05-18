#pragma once
#ifndef PILHA_H
#define PILHA_H

#include <iostream>
#include <string>
using namespace std;

#pragma region ********** PILHA ***********

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
bool push(TPilha<T> &pilha,T dado) {

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

template<typename T>
bool pop(TPilha<T> &pilha) {
	if (pilha.qtd == 0) {
		return false;
	}
	TElementoP<T> *apagar;
	apagar = pilha.topo;
	pilha.topo = pilha.topo->deBaixo;
	pilha.qtd--;
	delete apagar;
	return true;
}

#pragma endregion

#pragma region ******* Exercicio *********
bool compativel(char topoPilha, char caracter) {
	if (topoPilha == '(' && caracter == ')') {
		return true;
	}
	else if (topoPilha == '[' && caracter == ']') {
		return true;
	}
	else if (topoPilha == '{' && caracter == '}') {
		return true;
	}
	else {
		return false;
	}
}

bool verificarExpressao() {

	TPilha<char> pilha;
	inicializarPilha(pilha);

	string expressao;
	cin >> expressao;

	for (int i = 0; i < expressao.size(); i++)
	{
		char caracter = expressao[i];
		if (caracter == '{' || caracter == '[' || caracter == '(') {
			push(pilha, caracter);
		}
		else if (caracter == '}' || caracter == ']' || caracter == ')') {
			if (pilha.qtd == 0) {
				cout << "Erro na expressão\n";
				return false;
			}
			else if (compativel(pilha.topo->dado, caracter)) {
				pop(pilha);
			}
			else {
				cout << "Erro na expressão\n";
				return false;
			}
		}
	}
	
	if (pilha.qtd == 0) {
		cout << "Expressão válida\n";
		return true;
	}
	else {
		cout << "Erro na expressão\n";
		return false;
	}
}

#pragma endregion
#endif // !PILHA_H

