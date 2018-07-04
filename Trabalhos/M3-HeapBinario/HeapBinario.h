#pragma once
#ifndef HEAPBINARIO_H
#define HEAPBINARIO_H

#include <algorithm>
#include <string>
using namespace std;

struct Dado
{
	int chave;
	string dado;
};

struct HB
{
	Dado heap[1000];
	int qtd;
};

void inicializarHB(HB &hb) {
	for (int i = 0; i < 1000; i++)
	{
		hb.heap[i].chave = NULL;
	}
	hb.qtd = 0;
}

bool verificarMenorHm(Dado heap[], int pos) {
	if (heap[pos].chave == NULL) {
		return false;
	}

	int pai = (pos - 1) / 2;
	return heap[pos].chave < heap[pai].chave;
}

bool verificarMaiorHm(Dado heap[], int pos) {
	if (heap[pos].chave == NULL) {
		return false;
	}

	int filhoEsq = (2 * pos) + 1;
	int filhoDir = (2 * pos) + 2;
	if (heap[filhoEsq].chave == NULL) {
		return false;
	}
	if (heap[filhoDir].chave == NULL) {
		return false;
	}
	return heap[pos].chave > heap[filhoEsq].chave || heap[pos].chave > heap[filhoDir].chave;
}

void trocarHmMenor(Dado heap[], int pos) {
	int pai = (pos - 1) / 2;
	swap(heap[pos], heap[pai]);
}

void trocarHmMaior(Dado heap[], int pos,int filho) {
	swap(heap[pos], heap[filho]);
}

void inserirHm(HB &hb,Dado chave) {
	if (hb.qtd == 1000) {
		return;
	}
	hb.heap[hb.qtd] = chave;
	hb.qtd++;

	int i = hb.qtd - 1;
	while(i > 0)
	{
		if (verificarMenorHm(hb.heap, i)) {
			trocarHmMenor(hb.heap, i);
			int pai = (i - 1) / 2;
			i = pai;
		}
		else {
			i--;
		}

	}
}

void removerHm(HB &hb,bool remover,int pos=0) {
	int filhoEsq = (2 * pos) + 1;
	int filhoDir = (2 * pos) + 2;
	if (remover) {
		hb.heap[pos] = hb.heap[hb.qtd - 1];
		hb.qtd--;
	}
	if (verificarMenorHm(hb.heap, filhoEsq)) {
		trocarHmMenor(hb.heap, filhoEsq);
		return removerHm(hb, false, filhoEsq);
	}
	else if (verificarMenorHm(hb.heap, filhoDir)) {
		trocarHmMenor(hb.heap, filhoDir);
		return removerHm(hb, false, filhoDir);
	}
}

void atualizarPeloDado(HB &hb, Dado valor) {
	if (hb.qtd == 0) {
		return;
	}

	for (int i = 0; i < 1000; i++)
	{
		if (hb.heap[i].dado == valor.dado) {
			hb.heap[i].chave == valor.chave;

			int f = i;
			while(f > 0 && f < hb.qtd)
			{
				if (verificarMenorHm(hb.heap, f)) {
					trocarHmMenor(hb.heap, f);
					int pai = (f - 1) / 2;
					f = pai;
				}
				else if (verificarMaiorHm(hb.heap, f)) {
					int filhoEsq = (2 * f) + 1;
					int filhoDir = (2 * f) + 2;
					
					if (hb.heap[filhoEsq].chave < hb.heap[filhoDir].chave) {
						trocarHmMaior(hb.heap, f, filhoEsq);
						f = filhoEsq;
					}
					else {
						trocarHmMaior(hb.heap, f, filhoDir);
						f = filhoDir;
					}
				}
				else {
					f = 0;
					i = 1000;
				}
			}
		}
		if (hb.heap[i].chave == NULL) {
			i = 1000;
		}
	}
}


#endif // !HEAPBINARIO_H

