#pragma once
#include "Exececao.h"
#include <string>
#include <vector>

using namespace std;

class Condomino{
public:
	/**
	* Construtor da class Condomino , cria um Condomino com as especificacoes dadas
	*/
	Condomino(/**Nome do condomino (Condomino::Nome)*/string nome,/**NIF do condomino (Condomino::NIF) */ unsigned int nif);	//feito
	/**
	* Devolve NIF (Condomino::NIF) do Condomino
	*/
	unsigned int getNif();	//feito
	/**
	* Devolve Nome (Condomino::Nome) do Condomino
	*/
	string getNome();	//feito
	/**
	* Modifica o nome do Condomino (Condomino::Nome) para o valor pretendido
	*/
	void modificaNome(/**Nome pretendido */string nome);	//feito
	/**
	* Modifica o NIF do Condomino (Condomino::NIF) para o valor pretendido
	*/
	void modificaNIF(/**NIF pretendido */unsigned int nif);	//feito
	/**
	* Guarda a informacao
	*/
	string save(); //função auxiliar do Data::save()

private:
	/**
	* Nome do Condomino
	*/
	string Nome;
	/**
	* NIF do Condomino
	*/
	unsigned int NIF;
};