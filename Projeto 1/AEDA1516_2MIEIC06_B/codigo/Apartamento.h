#pragma once
#include "Exececao.h"
#include "Habitacao.h"


class Apartamento :public Habitacao
{
public:
	/**
	*  Constructor da class Apartamento, cria um Apartamento com as expecificacoes dadas
	*/
	Apartamento(/**Morada (Habitacao::Morada)*/std::string morada,/**Area Habitacional (Habitacao::Area_Habitacional)*/ unsigned int area_hab,/**Mensalidade (Habitacao::Mensalidade)*/ float mensalidade,/**Tipologia (Apartamento::Tipologia)*/ std::string tipo,/**Piso (Apartamento::Piso)*/ int piso);	//feito
	/**
	* Devolve a informacao sobre o Apartamento
	*/
	void info();	//feito
	/**
	* Calcula a Mensalidade (Habitacao::Mensalidade) do Apartamento
	*/
	void calcMensalidade();	//feito
	/**
	* Devolve a Tipologia (Apartamento::Tipologia) do Apartamento
	*/
	string getTipologia();	//feito
	/**
	* Devolve o Piso (Apartamento::Piso) do Apartamento
	*/
	int getPiso();	//feito
	/**
	* Modifica a Tipologia (Apartamento::Tipologia) do Apartamento para o valor pretendido
	*/
	void modificaTipologia(/**Tipologia pretendida */string tipo);	//feito
	/**
	* Modifica o Piso (Apartamento::Piso) do Apartamento para o valor pretendido
	*/
	void modificaPiso(/**Piso pretendido */int piso);	//feito
	/**
	* Guarda a informacao 
	*/
	string save(); //função auxiliar do Data::save()

	
private:
	/**
	* Tipologia do Apartamento, T0,T1,T2,T3,... maximo T10
	*/
	string Tipologia; //T0,T1,T2,T3,... maximo T10
	/**
	* Piso do Apartamento
	*/
	int Piso;	      //Piso 1,2,4,...
};