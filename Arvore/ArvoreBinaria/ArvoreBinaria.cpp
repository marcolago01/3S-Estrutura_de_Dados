// ArvoreBinaria.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ArvoreBinaria.h"


int main()
{
	ABB teste;
	inicializarABB(teste);
	inserirABB_it(teste, 10, "teste");
	inserirABB_it(teste, 5, "2");
	inserirABB_it(teste, 13, "3");
	inserirABB_it(teste, 8, "4");
	inserirABB_it(teste, 11, "5");
	system("pause");
}

