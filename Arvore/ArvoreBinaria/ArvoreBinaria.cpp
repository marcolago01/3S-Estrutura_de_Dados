// ArvoreBinaria.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ArvoreBinaria.h"
#include <iostream>
using namespace std;


int main()
{
	ABB teste;
	inicializarABB(teste);
	inserirABB_it(teste, 50, "primeiro");
	inserirABB_it(teste, 25, "segundo");
	inserirABB_it(teste, 75, "terceiro");
	inserirABB_it(teste, 20, "quarto");
	inserirABB_it(teste, 30, "quinto");
	inserirABB_it(teste, 70, "sexto");
	inserirABB_it(teste, 80, "setimo");
	inserirABB_it(teste, 29, "oitavo");
	inserirABB_it(teste, 85, "nono");
	int valor = buscaChave(teste.raiz, "sexto");
	cout << valor;
	system("pause");
}

