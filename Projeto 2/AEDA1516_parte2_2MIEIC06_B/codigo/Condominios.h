#pragma once

#include <string>
#include <vector>
#include "Apartamento.h"
#include "Habitacao.h"
#include "Vivenda.h"
#include "Exececao.h"
#include "Servicos.h"


#include "Transporte.h"

#include <unordered_set>
#include <queue>


using namespace std;

/*
A vivenda e o apartamento possuem valores base mensal de condomínio diferentes.
O valor do condomínio de uma vivenda varia também com o tamanho da área exterior e a existência de piscina.
O valor do condomínio de um apartamento varia de acordo com a tipologia e piso.
*/

typedef unordered_set<Servico, hServico, eqServico> hashServicos;

class Condominio
{
public:
	/**
	* Construtor da class Condominio, cria um Condominio com as especificacoes dadas
	*/
	Condominio(/**Nome (Condominio::Nome)*/string nome);	
	
	/**
	* Destrutor da class Condominio
	*/
	//~Condominio();
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


	//parte 1
	Condominio(/**Nome (Condominio::Nome)*/string nome, string localizacao);
	bool operator < (const Condominio &dir) const;
	int getNumHab() const;
	string getLocalizacao() const;
	int getNumVivendas() const;

	//Parte 2, filas de prioridade  //feito
	void addTransporte(Transporte &transporte);
	bool remTransporte(string tipo);
	void toogle_Ativ_PontoParagem(string tipo);
	//Retorna o topo da lista que é o mais perto caso nao tenha especificado destino, se especificou destino, entao procura e devolve o mais perto do destino
	string getPontoParagemMaisProx(); //sem destino
	string getPontoParagemMaisProx(string dest); //com destino
	void listarTransportes();
	string saveTransportes();



	//Parte 3, tabelas de dispersao //feito_
	void addServico_Cond(Servico &servico); //adiciona o servico
	void procurarServicos(string nomeServico); //procura por nome, retorna o servico e o num de prestadores de servico, retorna nao existe se nao existir
	void listarServicos(); //lista os servicos
	void remServico_Cond(string nomeServico);
	string saveServicos();


	string saveHabitacoes();


private:
	/**
	* Nome do Condominio
	*/
	string Nome;
	string Localizacao;
	/**
	* Vector de Habitacoes do Condominio
	*/
	vector <Habitacao*> Habitacoes;
	/**
	* Vector de Servicos do Condominio
	*/
	vector <Servico *> Servico_Condominio;	//Servicos existentes


	hashServicos Servicos_Cond; //Servicos existentes, parte 2 trabalho, tabelas de dispercao

	priority_queue<Transporte> TransportesPublicos;

	int num_hab;
	int num_vivendas;
};



