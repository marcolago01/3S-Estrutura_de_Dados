#pragma once
#ifndef CLIENT_H
#define CLIENT_H

struct Cliente
{
	int tempo;

	Cliente(int tempo) {
		this->tempo = tempo;
	}
};

template<typename T>
void chegadaDeClientes(Fila<T> *caixa, int filas) {
	int c1t = 2;
	int c2t = 3;
	int c3t = 5;

	for (int i = 0; i < 10; i++)
	{
		if (c1t != 0) {

		}
	}
}


#endif // !CLIENT_H

