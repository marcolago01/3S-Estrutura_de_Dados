// AC2-TabelaHash.cpp : define o ponto de entrada para o aplicativo do console.
//
#include "stdafx.h"
#include "TabelaHash-Aberto.h"
#include "TabHash-Enc.h"
#include <fstream>
#include <string>
#include <time.h>

void gravar(string th, string op, int ocup, int inst) {
	ofstream arq("saida.csv", ofstream::app);

	arq << th << ","
		<< op << ","
		<< ocup << ","
		<< inst << "\n";
}


int main()
{
	srand(time(NULL));
	
	TabHashA thA;
	inicializarTabHashA(thA);

	for (int i = 0; i < 2000; i++)
	{
		int chave = rand() % 32000 + 1;
		int instr = 1;
		inserirTabHashA(thA, chave, instr);
		if (i == 90 || i == 240 || i == 740 || i == 990 || i == 1990) {
			for (int k = 0; k < 10; k++)
			{
				int chave = rand() % 32000 + 1;
				instr = 1;
				inserirTabHashA(thA, chave, instr);
				gravar("thA", "ins", (i + 10) / 10, instr);
			}
			for (int k = 0; k < 10; k++)
			{
				int chave = rand() % 32000 + 1;
				instr = 1;
				pesquisarTabHashA(thA, chave, instr);
				gravar("thA", "pesq", (i + 10) / 10, instr);
			}
			i += 10;
		}
	}

	TabHashEnc thEnc;
	inicializarTabHashEnc(thEnc);

	for (int i = 0; i < 2000; i++)
	{
		int chave = rand() % 32000 + 1;
		int instr = 1;
		inserirTabHashEnc(thEnc, chave, instr);
		if (i == 90 || i == 240 || i == 740 || i == 990 || i == 1990) {
			for (int k = 0; k < 10; k++)
			{
				int chave = rand() % 32000 + 1;
				instr = 1;
				inserirTabHashEnc(thEnc, chave, instr);
				gravar("thEnc", "ins", (i + 10) / 10,instr);
			}
			for (int k = 0; k < 10; k++)
			{
				int chave = rand() % 32000 + 1;
				instr = 1;
				pesquisarTabHashEnc(thEnc, chave, instr);
				gravar("thEnc", "pesq", (i + 10) / 10,instr);
			}
			i += 10;
		}
	}
	


}

