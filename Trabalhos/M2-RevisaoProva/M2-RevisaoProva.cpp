// M2-RevisaoProva.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include "ArvoreBinaria.h"
#include "Fila.h"
#include "PILHA.h"
#include <iostream>
#include <string>
using namespace std;

bool palindroma(string texto);

int main()
{
	TPilha<char> teste;

	if (palindroma("amo")) {
		cout << "blz";
	}
}

bool palindroma(string texto) {
	TPilha<char> pilha;
	inicializarPilha(pilha);
	int meio = texto.length()/2;
	int i = 0;
	for (int i = 0; i < meio; i++)
	{
		push(pilha, texto[i]);
	}
	if (texto.length() % 2 == 1)
		i++;
	while (i<texto.length())
	{
		if (pilha.topo->dado == texto[i]) {
			pop(pilha);
		}else {
			return false;
		}
		i++;
	}
	return true;
	
}

struct Paciente
{
	int prioridade;
	string nome;
};

void prioridadePaciente(Fila<Paciente> &A, Fila<Paciente> &B, Paciente vp[100]) {
	for (int p = 1; p <= 2; p++)
	{
		for (int i = 0; i < 100; i++)
		{
			if (vp[i].prioridade == p) {
				enfileirar(A, vp[i]);
			}
		}
	}

	int total = A.qtd;
	int p = 3;

	while (total < 100)
	{
		for (int i = 0; i < 100; i++)
		{
			if (vp[i].prioridade == p) {
				enfileirar(B, vp[i]);
				total++;
			}
		}
		p++;
	}
}

void arvoreBB(NodoABB *nodo, int k) {
	if (nodo == NULL) {
		return;
	}
	if (k == 1) {
		cout << nodo->chave<<",";
	}
	else
	{
		arvoreBB(nodo->menor, k - 1);
		arvoreBB(nodo->maior, k - 1);
	}
}

