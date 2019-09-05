#include "Servicos.h"

Servico::Servico(string nome, unsigned int nPressServ) :Nome(nome), numPrestServ(nPressServ)
{}

string Servico::getNome()
{
	return Nome;
}

unsigned int Servico::getNumPrestServ()
{
	return numPrestServ;
}

void Servico::modificaNome(string nome)
{
	Nome = nome;
}

void Servico::addNserv()
{
	numPrestServ = numPrestServ + 1;
}

void Servico::decNserv()
{
	numPrestServ = numPrestServ - 1;
	if (numPrestServ < 0)               //se num prestacoes for negativo;
		throw ValorInvalido();
}

void Servico::modificaNPS(unsigned int num)
{
	numPrestServ = num;
	if (numPrestServ < 0)               //se num prestacoes for negativo é um unsigned int, nunca vai ser 0
		throw ValorInvalido();
}

int Servico::getId()
{
	return id;
}

string Servico::save()
{
	return Nome + "," + to_string(numPrestServ);
}


Servico::Servico(string nome, unsigned int nPressServ, int ident) :Nome(nome), numPrestServ(nPressServ), id(ident)
{}

