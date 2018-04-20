// Simulacao_Supermecado.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Fila.h"
#include "Cliente.h"
#include <iostream>
using namespace std;


int main()
{
	int qtdFilas;
	cout << "Insira o numero de filas";
	cin >> qtdFilas;

	Fila<Cliente> *caixas = new Fila<Cliente>[qtdFilas];

	for (int i = 0; i < qtdFilas; i++)
	{
		inicializarFila(caixas[i]);
	}

	for (int ut = 0;ut < 10000;ut++) {
		//chegadaDeClient
		//AtendimentoCliente
	}
	//Calcular média;

}

