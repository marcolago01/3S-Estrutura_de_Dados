// ArvoreDeExpressao.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include "ArvoreExpressao.h"


int main()
{
	AExp teste("(3-(9+7)*4)*8+1+1");
	teste.inicializarAExp();
	montarAExp(teste.raiz);
	int teste2;
	teste2 = executarAExp(teste.raiz);
	teste.pause();

}

