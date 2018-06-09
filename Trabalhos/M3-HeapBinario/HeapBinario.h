#pragma once
#ifndef HEAPBINARIO_H
#define HEAPBINARIO_H

#include <algorithm>
using namespace std;

struct HB
{
	int heap[1000];
	int qtd;
};

void inicializarHB(HB &hb) {
	for (int i = 0; i < 1000; i++)
	{
		hb.heap[i] = NULL;
	}
	hb.qtd = 0;
}

bool verificarMenorHm(int heap[], int qtd, int pos) {
	if (heap[pos] == NULL) {
		return false;
	}

	int pai = (pos - 1) / 2;
	return heap[pos] < heap[pai];
}

void trocarHm(int heap[], int pos) {
	int pai = (pos - 1) / 2;
	swap(heap[pos], heap[pai]);
}

void inserirHm(HB &hb,int chave) {
	hb.heap[hb.qtd] = chave;
	hb.qtd++;

	for (int i = hb.qtd-1; i > 0; i--)
	{
		if (verificarMenorHm(hb.heap, hb.qtd, i)) {
			trocarHm(hb.heap, i);
		}
	}
}

void removerHm(HB &hb,bool remover,int pos=0) {
	int filhoEsq = (2 * pos) + 1;
	int filhoDir = (2 * pos) + 2;
	if (remover) {
		hb.heap[0] = hb.heap[hb.qtd - 1];
		hb.qtd--;
	}
	if (verificarMenorHm(hb.heap, hb.qtd, filhoEsq)) {
		trocarHm(hb.heap, filhoEsq);
		return removerHm(hb, false, filhoEsq);
	}
	else if (verificarMenorHm(hb.heap, hb.qtd, filhoDir)) {
		trocarHm(hb.heap, filhoDir);
		return removerHm(hb, false, filhoDir);
	}
}


#endif // !HEAPBINARIO_H

