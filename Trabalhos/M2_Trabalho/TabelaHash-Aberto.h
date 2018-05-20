#pragma once

struct TabHashA
{
	const int TAMANHO = 1000;
	int tabela[1000];
	int qtd;
};

void inicializarTabHashA(TabHashA &tabelaHash) {
	tabelaHash.qtd = 0;
	for (int i = 0; i < tabelaHash.TAMANHO; i++)
	{
		tabelaHash.tabela[i] = NULL;
	}
}

bool inserirTabHashA(TabHashA &tabelaHash, int chave,int &inst) {
	if (tabelaHash.qtd == tabelaHash.TAMANHO) {
		return false;
	}
	int nav = chave % tabelaHash.TAMANHO;
	while (tabelaHash.tabela[nav] != NULL) {
		nav++;
		if (nav == tabelaHash.TAMANHO) {
			nav = 0;
		}
		inst++;
	}
	tabelaHash.tabela[nav] = chave;
	tabelaHash.qtd++;
	return true;
}

bool pesquisarTabHashA(TabHashA &tabelaHash, int chave, int &inst) {
	int nav = chave % tabelaHash.TAMANHO;
	for (int i = 0; i < tabelaHash.TAMANHO; i++)
	{
		if (nav == tabelaHash.TAMANHO) {
			nav = 0;
		}

		if (tabelaHash.tabela[nav] == chave) {
			return true;
		}
		else if (tabelaHash.tabela[nav] == NULL) {
			return false;
		}
		nav++;
		inst++;
	}
	return false;
}

