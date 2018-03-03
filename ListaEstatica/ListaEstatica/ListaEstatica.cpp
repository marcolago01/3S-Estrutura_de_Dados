// ListaEstatica.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "listaEstatica.h"
#include <iostream>
using namespace std;


int main()
{
	ListaEstatica jog1, jog2;

	inicializarListaEst(jog1);
	inicializarListaEst(jog2);

	TCarta a, b, c, d;
	a.valor = 10;a.naipe = 3;
	b.valor = 2;b.valor = 1;
	c.valor = 12, c.naipe = 2;
	d.valor = 8;d.naipe = 4;

	inserirInicioLest(jog1, a);
	inserirPosLEst(jog2, b, 3);
	inserirFimLEst(jog1, c);
	inserirInicioLest(jog1, d);

	removePosLEst(jog1, 2);

	cout << "Imprimindo jog1:" << endl;
	imprimirLEst(jog1);
	cout << "Imprimindo jog2" << endl;
	imprimirLEst(jog2);
	return 0;
}

