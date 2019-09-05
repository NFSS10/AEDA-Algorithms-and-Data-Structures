#include "Condomino.h"

Condomino::Condomino(string nome, unsigned int nif): Nome(nome), NIF(nif)
{}

unsigned int Condomino::getNif()
{
	return NIF;
}

string Condomino::getNome()
{
	return Nome;
}

void Condomino::modificaNome(string nome)
{
	Nome = nome;
}
void Condomino::modificaNIF(unsigned int nif)
{
	NIF = nif;
}


/*
string Condomino::save()
{
	return Nome + "," + to_string(NIF);
}*/