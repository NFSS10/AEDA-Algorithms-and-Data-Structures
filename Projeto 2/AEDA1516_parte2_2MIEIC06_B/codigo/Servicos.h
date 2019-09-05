#pragma once

#include <string>
#include <vector> 
#include "Exececao.h"

using namespace std;

class Servico
{
public:
	/**
	* Construtor da class Servico ,cria um Servico com as expecificacoes dadas
	*/
	Servico(/**Nome do Servico (Servico::Nome)*/string nome,/**Numero de Prestadores de Servico (Servico::numPrestServ)*/ unsigned int nPresServ);
	/**
	* Destrutor da class Servico
	*/
	~Servico();
	/**
	* Devolve o nome do Servico (Servico::Nome)
	*/
	string getNome() const;
	/**
	* Devolve o Numero de Prestadores do Servico (Servico::numPrestServ)
	*/
	unsigned int getNumPrestServ() const;	//feito
	/**
	* Altera o nome (Servico::Nome) do Servico para o nome dado
	*/
	void modificaNome(/**Nome do Servico*/ string nome);	//feito
	/**
	* Adiciona um Prestador de servico (Servico::numPrestServ)
	*/
	void addNserv(); //feito /+1
	/**
	* Retira um Prestador de servico (Servico::numPrestServ)
	*/
	void decNserv(); //feito /-1
	/**
	* Overload do operador < de forma a ordenar os servicos por ordem alfabetica do nome
	*/
	bool operator < (Servico &b)
	{
		if (getNome() < b.getNome())
			return true;
		else return false;
	}
	/**
	* Modifica numero de prestadores (Servico::numPrestServ) para o numero pretendido
	*/
	void modificaNPS(/**Numero pretendido*/unsigned int num); //feito  /novo
	
	
	
	
	/**
	* Construtor da class Servico ,cria um Servico com as expecificacoes dadas
	*/
	//Servico(/**Nome do Servico (Servico::Nome)*/string nome,/**Numero de Prestadores de Servico (Servico::numPrestServ)*/ unsigned int nPresServ, /**Identificador do Serviço*/ int ident);
	/**
	* Retorna o identificador do Servio (Servico::id)
	*/
	//int getId(); 
	
	
	/**
	* Guarda a informacao
	*/
	//string save(); 


private:
	/**
	* Nome do Servico
	*/
	string Nome;
	/**
	* Numero de prestadores desse Servico
	*/
	unsigned int numPrestServ;
};


struct hServico
{
	int operator()(const Servico& s1) const
	{
		string s;
		int index = 0;
		s = s1.getNome();
		for (int i = 0; i < s.length(); i++)
		{
			index = index * 11 + s[i] * 7;
		}
		return index;
	}
};

struct eqServico
{
	bool operator()(const Servico& s1, const Servico& s2) const
	{
		return s1.getNome() == s2.getNome();
	}
};


