#pragma once
#ifndef CLIENTE_H
#define CLIENTE_H

#include<iostream>
#include "Fila.h"
using namespace std;

struct Cliente
{
	int tempo;

	Cliente(){}
	Cliente(int tempo) {
		this->tempo = tempo;
	}
};


void chegadaDeClientes(Fila<Cliente> *caixa, int qtdFilas) {
	int unidadeTempo = 1; //Unidade de tempo que um cliente leva para ser atendido

	for (int i = 0; i < 10; i++)
	{
		if (i == 2) { //Os clientes 2, 3 e 4 vão demorar 2 unidades de tempo para serem atendidos
			unidadeTempo++;
		}
		if (i == 5) { //Os clientes 5, 6, 7, 8 e 9 vão demorar 3 unidades de tempo para serem atendidos
			unidadeTempo++;
		}
		Cliente cliente(unidadeTempo); //Cria o cliente e adiciona uma unidade de tempo u.t

		int filaMenor = caixa[0].qtd;
		int numeroFilaMenor = 0;

		for (int i = 0; i < qtdFilas; i++) { //Descobre qual a menor fila
			if (filaMenor > caixa[i].qtd) {
				filaMenor = caixa[i].qtd;
				numeroFilaMenor = i;
			}
		}

		enfileirar(caixa[numeroFilaMenor], cliente); //Passa o caixa com menor fila e o conteudo do ponteiro cliente para ser enfileirado

	}
}


void atendimentoDeClientes(Fila<Cliente> *caixa, int qtdFilas) {
	for (int i = 0; i < qtdFilas; i++) { //roda todas as fileiras
		if (caixa[i].qtd > 0) {
			if (caixa[i].inicio->dado.tempo > 0) {
				caixa[i].inicio->dado.tempo--; //diminui 1 u.t (unidade de tempo)
			}
			else {
				desenfileirar(caixa[i]); //Desenfileirar não precisa de T dado em fila.h, arrumar isso
			}
		}
	}
}


#endif // !CLIENTE_H
