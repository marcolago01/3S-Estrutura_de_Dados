// ListaGenerica.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "lista_estatica_gen.h"
#include "listaEstatica.h"
#include <iostream>
using namespace std;

void imprimirCartas(TLEstG<TCarta, 52> l) {
	for (int i = 0; i < l.qtd; i++)
	{
		cout << l.elementos[i].valor << " - " << l.elementos[i].naipe << endl;
	}
}


int main()
{
	TLEstG <float,100> numero;
	TLEstG <TCarta, 52> cartas;

	inicializarLEstG(numero);
	inicializarLEstG(cartas);

	inserirFimLEstG(numero,(float)32.1);

	TCarta a;
	a.valor = 12;a.naipe = 3;
	inserirFimLEstG(cartas, a);

	TCarta b;
	b.valor = 10;b.naipe = 2;
	inserirInicioLEstG(cartas, b);

	imprimirCartas(cartas);

	
    return 0;
}

