#pragma once

#include <string>
#include <vector>
#include "Habitacao.h"
#include "Exececao.h"

using namespace std;

class Vivenda :public Habitacao
{
public:
	/**
	* Constructor da class Vivenda, cria uma vivenda com as expecificacoes dadas
	*/
	Vivenda(/**Morada (Habitacao::Morada) */string morada,/**Area da Habitacao (Habitacao::Area_Habitacional)*/ unsigned int area_hab,/**Mensalidade (Habitacao::Mensalidade)*/ float mensalidade,/**Area exterior (Vivenda::Area_Exterior)*/ unsigned int area_ext,/**Se tem piscina ou nao (Vivenda::Piscina)*/ bool piscina); //feito
	/**
	* Destrutor da class Vivenda
	*/
	~Vivenda();
	/**
	* Devolve a informacao sobre a Vivenda
	*/
	void info();
	/**
	* Calcula a mensalidade (Habitacao::Mensalidade) da vivenda
	*/
	void calcMensalidade();
	/**
	* Devolve a area exterior (Vivenda::Area_Exterior) da vivenda
	*/
	unsigned int getAreaExterior();
	/**
	* Adiciona uma piscina a vivenda
	*/
	void adicionaPiscina();
	/**
	* Remove piscina da vivenda
	*/
	void removePiscina();
	/**
	* Modifica a area exterior (Vivenda::Area_Exterior) da vivenda para a area pretendida
	*/
	void modificaArea_Exterior(/**Area exterior pretendida*/unsigned int areaExt);	//feito
	/**
	* Guarda a informacao 
	*/
	string save();


private:
	/**
	* Area exterior da vivenda
	*/
	unsigned int Area_Exterior;
	/**
	*  Piscina da vivenda (true = Tem piscina / false = Nao tem piscina)
	*/
	bool Piscina;

};
