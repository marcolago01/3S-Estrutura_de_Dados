// Simulacao_Supermercado.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include "Fila.h"
#include "Cliente.h"
#include <locale>
#include<iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int qtdFilas = 0;
	cout << "Insira o número de filas: ";
	cin >> qtdFilas;

	Fila<Cliente> *caixas = new Fila<Cliente>[qtdFilas];

	for (int i = 0; i < qtdFilas; i++)
	{
		inicializarFila(caixas[i]);
	}

	for (int ut = 0; ut < 10000; ut++) {
		chegadaDeClientes(caixas, qtdFilas);
		atendimentoDeClientes(caixas, qtdFilas);
	}

	system("cls");
	for (int i = 0; i < qtdFilas; i++)
	{
		cout << endl << "Caixa[" << i << "]: "  << caixas[i].qtd;
	}

	//Calcular a media
	int mediaDeClientesPorFila = 0;
	for (int i = 0; i < qtdFilas; i++) {
		mediaDeClientesPorFila += caixas[i].qtd;
	}

	mediaDeClientesPorFila = mediaDeClientesPorFila / qtdFilas;
	cout << endl << "Média : " << mediaDeClientesPorFila << endl;;

}

