#pragma once
#ifndef MERGESORT_H
#define MERGESORT_H

void merge(int vetor[], int inicio, int meio, int fim, int vetorAux[]) {
	int p1, p2, tamanho;
	int fim1 = 0, fim2 = 0;
	tamanho = fim - inicio + 1;
	p1 = inicio;
	p2 = meio + 1;
	
	for (int i = 0; i < tamanho; i++) {
		if (!fim1 && !fim2) {
			if (vetor[p1] < vetor[p2]) {
				vetorAux[i] = vetor[p1++];
			}
			else {
				vetorAux[i] = vetor[p2++];
			}

			if (p1 > meio) fim1 = 1;
			if (p2 > fim) fim2 = 1;
		}
		else {
			if (!fim1) {
				vetorAux[i] = vetor[p1++];
			}
			else {
				vetorAux[i] = vetor[p2++];
			}
		}

		for (int j = 0; int k = inicio; j < tamanho; j++; k++) {
			vetor[k] = vetorAux[j];
		}
	}
}

void mergeSort(int vetor[], int inicio, int fim, int vetorAux[]) {
	int meio;
	if (inicio < fim) {
		meio = ((inicio + fim) / 2);
		mergeSort(vetor, inicio, meio, vetorAux);
		mergeSort(vetor, meio + 1, fim, vetorAux);
		merge(vetor, inicio, meio, fim, vetorAux);
	}
}

void mergeSort(int vetor[], int tamanho) {
	int vetorAux[tamanho];
	mergeSort(vetor, 0, tamanho, vetorAux);
}

#endif // !MERGESORT_H
