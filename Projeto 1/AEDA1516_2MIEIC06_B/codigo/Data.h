#pragma once
#include "Exececao.h"
#include "Condominios.h"
#include "Condomino.h"





class Data{
private:
	/**
	* Vector de Condominio (s)
	*/
	vector <Condominio *> Condominios;
	/**
	* Vector de Servico (s)
	*/
	vector <Servico *> Servicos;
	/**
	* Vector de Condomino (s)
	*/
	vector <Condomino *> Condominos;

public:
	/**
	* Recolhe dos ficheiros de texto a informacao necessaria
	*/
	bool inicialize();
	/**
	* Guarda nos ficheiros de texto a informacao
	*/
	bool save();
	/**
	* Metodo para gerir todos os condominios
	*/
	bool run();
	/**
	* Devolve o condomino cujo NIF (Condomino::NIF) é o pretendido
	*/
	Condomino * getCondomino(/**NIF pretendido*/int nif);
	/**
	* Devolve o Servico que se encontra na posicao pretendida no vector de servicos (Data::Servico)
	*/
	Servico * getServico(/**Posicao pretendida*/int serv);
	/**
	* Devolve o Condominio com o nome (Condominio::Nome) pretendido
	*/
	Condominio *getCondominio(/**Nome pretendido*/string nome);
	/**
	* Devolve a informacao sobre os condominio, servicos, e condominos existentes
	*/
	void info();
	/**
	* Remove Condominio de nome (Condominio::Nome) pretendido do vector de condominios (Data::Condominios)
	*/
	void remCondominio(/**Nome pretendido*/string nome);
	/**
	* Remove Servico de nome (Servico::Nome) pretendido do vector de servicos (Data::Servicos)
	*/
	void remServico(string nome);
	/**
	* Adiciona Condominio de nome (Condominio::Nome) pretendido ao vector de condominios (Data::Condominios)
	*/
	void addCond(/**Nome pretendido*/string nome);

};