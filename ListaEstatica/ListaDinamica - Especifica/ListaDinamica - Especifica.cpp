// ListaDinamica - Especifica.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "Lista_enc_din_esp.h"
using namespace std;


int main()
{
	TLista play;
	inicializarLEnc(play);
	TMusica a, b;
	a.titulo = "musica 1";a.artista = "João";
	b.titulo = "musica 2";b.artista = "Maria";
	inserirFimLEnc(play, a);
	inserirInicioLEnc(play, b);
	imprimirMusicasLEnc(play);
	removerInicioLEnc(play);
	removeFimLEnc(play);
	imprimirMusicasLEnc(play);
	return 0;
}

