// ArvoreDeExpressao.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include "ArvoreExpressao.h"


int main()
{
	AExp teste("(((1+2)-3)*4-(3+2))");
	teste.inicializarAExp();
	montarAExp(teste.raiz);
	int teste2;
	teste2 = executarAExp(teste.raiz);
	teste.pause();

}

