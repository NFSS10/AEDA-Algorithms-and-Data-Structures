#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include "Exececao.h"
#include "Condomino.h"
#include "Servicos.h"
#include <iostream>

using namespace std;

/*Damos um preco base a habitacao (podemos distinguir por zona, etc) e depois com o calcMensalidade, damos o valor e mudado
consoante as areas, piso, piscina, etc*/

class Habitacao
{
public:
	/**
	* Construtor da class Habitacao, cria uma habitacao com as expecificacoes dadas
	*/
	Habitacao(/**Morada (Habitacao::Morada)*/string morada,/**Area da Habitacao (Habitacao::Area_Habitacional)*/ unsigned int area_hab, /**Mensalidade (Habitacao::Mensalidade)*/float mensalidade); //feito
	/**
	* Modifica o valor da mensalidade (Habitacao::Mensalidade) para o valor pretendido
	*/
	void modificaMensalidade(/**Mensalidade pretendida*/ float mensalidade);
	/**
	* Devolve a Morada (Habitacao::Morada) da Habitacao
	*/
	string getMorada();	//feito
	/**
	* Devolve a Area Habitacional (Habitacao::Area_Habitacional) da Habitacao
	*/
	unsigned int getA_Habitacional();
	/**
	* Devolve a Mensalidade (Habitacao::Mensalidade) da Habitacao
	*/
	float getMensalidade();	//feito
	/**
	* Devolve o condomino (Habitacao::condomino) da Habitacao
	*/
	Condomino *getCondomino();	//feito
	/**
	* Devolve um vector com os servicos (Habitacao::servico) da Habitacao
	*/
	vector<Servico *> getServicos();
	/**
	*  Modifica a Morada (Habitacao::Morada) para o valor pretendido
	*/
	void modificaMorada(/**Valor pretendido da Morada (Habitacao::Morada)*/string morada);	//feito
	/**
	*  Modifica a Area Habitacional (Habitacao::Area_Habitacional) para o valor pretendido
	*/
	void modificaArea_Habitacional(/**Valor pretendido da Area Habitacional (Habitacao::Area_Habitacional)*/unsigned int areaHab);	//feito
	/**
	* Ordena o vector com os servicos (Habitacao::servico) da Habitacao por ordem alfabetica do nome (Servico::Nome)
	*/
	void ordenaServicosNome();
	/**
	* Metodo virtual para ser modificado pelas sub-classes (Vivenda e Apartamento) que devolve a sua informacao
	*/
	virtual void info() = 0;	//feito
	/**
	* Metodo virtual para ser modificado pelas sub-classes (Vivenda e Apartamento) que calcula a sua mensalidade
	*/
	virtual void calcMensalidade() = 0;	//feito
	/**
	* Modifica o condomino (Habitacao::condomino) da Habitacao para o Condomino pretendido;
	*/
	void addCondomino(/**Condomino pretendido*/Condomino * cond);	//feito
	/**
	* Adiciona um Servico ao vector de servicos (Habitacao::servico) da Habitacao
	*/
	void addServico(/**Servico a ser adicionado*/Servico * ser);	//feito
	/**
	* Remove o Servico pretendido do vector de servicos (Habitacao::servico) da Habitacao
	*/
	void removeServico(/**Servico a ser removido*/ Servico * ser); //feito menos excepcao
	/**
	* Funcao Virual para ser modificada por Apartamento e Vivenda
	*/
	virtual string save() { return ""; };	
	/**
	* Mostra todos os servicos aderidos pela habitacao
	*/
	void verServicosAderidos(); 


private:
	/**
	* Morada da Habitacao
	*/
	string Morada;
	/**
	* Area Habitacional da Habitacao
	*/
	unsigned int Area_Habitacional;
	/**
	* Mensalidade da Habitacao
	*/
	float Mensalidade;
	/**
	* Condomino da Habitacao
	*/
	Condomino *condomino;
	/**
	* Vector de Servicos  da Habitacao
	*/
	vector<Servico *> servico; //Servico aderidos

};