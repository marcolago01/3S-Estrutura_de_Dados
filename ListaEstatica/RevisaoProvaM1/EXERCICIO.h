#pragma once
#ifndef EXERCICIO_H
#define EXERCICIO_H

Lista preencherListaEst(Lista a, Lista b) {
	Lista c;
	inicializarListEst(c);
	int cont;

	for (int i = 0; i < a.qtd; i++)
	{
		cont = 0;
		for (int j = 0; j < b.qtd; j++)
		{
			if (a.valores[i] == b.qtd[j]) {
				cont++;
			}
		}
		if (cont == 0) {
			inserirFimLEst(c, a.valores[i]);
		}
	}

	for (int i = 0; i < b.qtd; i++)
	{
		cont = 0;
		for (int j = 0; j < a.qtd; j++)
		{
			if (b.valores[i] == a.valores[j]) {
				cont++;
			}
		}
		if (cont == 0) {
			inserirFimLEst(c, b.valores[i]);
		}
	}

	return c;

}

void removeAtePosicaoLDEnc(Lista &l, int k) {
	Lista * nav, *apagar;
	apagar = l.inicio;
	for (int i = 0; i < k; i++)
	{
		nav = apagar;
		apagar = apagar->prox;
	}
	nav-> = NULL;
	l.qtd = k;

	Lista * aux;
	while (apagar != NULL) {
		aux = apagar;
		apagar = apagar->prox;
		delete aux;
	}
}

#endif
