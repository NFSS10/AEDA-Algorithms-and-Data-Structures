#pragma once

#include <string>
#include <vector>
#include "Apartamento.h"
#include "Habitacao.h"
#include "Vivenda.h"
#include "Exececao.h"
#include "Servicos.h"

using namespace std;

/*
A vivenda e o apartamento possuem valores base mensal de condomínio diferentes.
O valor do condomínio de uma vivenda varia também com o tamanho da área exterior e a existência de piscina.
O valor do condomínio de um apartamento varia de acordo com a tipologia e piso.
*/


class Condominio
{
public:
	/**
	* Construtor da class Condominio, cria um Condominio com as especificacoes dadas
	*/
	Condominio(/**Nome (Condominio::Nome)*/string nome);	//feito
	/**
	* Destrutor da class Condominio
	*/
	~Condominio();
	/**
	* Adiciona a Habitacao pretendida ao vector de Habitacoes do Condominio (Condominio::Habitacoes)
	*/
	void addHabitacao(/**Habitacao pretendida*/Habitacao *hab);	//feito
	/**
	* Adiciona o Servico pretendido ao vector de servicos do Condominio (Condominio::Servico_Condominio)
	*/
	void addServico(Servico * ser);	//feito
	/**
	* Modifica o Nome (Condominio::Nome) do Condominio para o nome pretendido
	*/
	void modificaNome(/**Nome pretendido*/string nome); //feito
	/**
	* Devolve a informacao sobre o Condominio
	*/
	void info();	//feito
	/**
	* Devolve o Nome (Condominio::Nome) do Condominio
	*/
	string getNome();	//feito
	/**
	* Devolve a Habitacao cujo Condominio e o pretendido
	*/
	Habitacao* getHabitacao(/**Condominio pretendido*/Condomino *cond); //feito /retorna Habitacao do condomino "cond"
	/**
	* Devolve o vector de habitacoes (Condominio::Habitacoes) do Condominio
	*/
	vector <Habitacao*> &getHabitacoes(); //feito /retorna o vetor Habitacoes
	/**
	* Devolve o vector de servicos (Condominio::Servico_Condominio) usados pelo Condominio
	*/
	vector <Servico *> &getServicos(); //feito /retorna o vetor dos servicos
	/**
	* Ordena o vector de Habitacoes (Condominio::Habitacoes) por valor de Area (Habitacao::Area_Habitacional) (Crescente)
	*/
	void OrdenarHabArea();
	/**
	* Ordena o vector de Habitacoes (Condominio::Habitacoes) por ordem alfabetica da Morada (Habitacao::Morada) (Crescente)
	*/
	void OrdenarHabMorada();
	/**
	* Ordena o vector de Habitacoes (Condominio::Habitacoes) por valor da mensalidade (Habitacao::Mensalidade) (Crescente)
	*/
	void OrdenarHabMensalidade();
	/**
	* Ordena o vector de servicos do Condominio (Condominio::Servico_Condominio) por ordem alfabetica do nome (Servico::Nome) (Crescente)
	*/
	void OrdenarServicoCondNome();
	/**
	* Mostra as informacoes das habitacões ordenadas consoante um numero de input; 1-Area , 2-Morada , 3-Mensalidade
	*/
	void verHab();	//feito  
	/**
	* Mostras os nomes (Servico::Nome) dos servicos de condominio (Condominio::Servico_Condominio) ordenados por ordem alfabetica
	*/
	void verSerCond();	//feito /novo
	/**
	* Remove o Servico cujo nome (Servico::Nome) e o pretendido do vector de servicos de condominio (Condominio::Servico_Condominio)
	*/
	void remServico(/**Nome pretendido*/string nome); //feito 
	/**
	* Remove a Habitacao cujo NIF (Condomino::NIF) do Condomino é o pretendido
	*/
	void remHab(/**NIF pretendido*/unsigned int nif); //feito 
	/**
	* Devolve o Servico do condominio cujo nome é o pretendido
	*/
	Servico* getServ(/**Nome pretendido*/string nome); // feito  

private:
	/**
	* Nome do Condominio
	*/
	string Nome;
	/**
	* Vector de Habitacoes do Condominio
	*/
	vector <Habitacao*> Habitacoes;
	/**
	* Vector de Servicos do Condominio
	*/
	vector <Servico *> Servico_Condominio;	//Servicos existentes
};



