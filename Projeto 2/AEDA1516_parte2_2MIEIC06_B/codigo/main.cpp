#pragma once;

#include <iostream>

#include "Data.h"
#include "Condominios.h"
#include "Condomino.h"
#include <Windows.h>


#include "Menu.h"

using namespace std;



int main()
{	
	Data data;
	Menu Menu;


	data.inicialize();
	Menu.Iniciar(data);

	Menu.save();
	


	
	//TESTE PONTO 3
	/*
	Condominio* cond=new Condominio("cond1");

	Servico limpeza("limpeza",2);
	Servico limpezaa("limpeza", 3);
	Servico can("canalizacao", 2);
	Servico m("ma", 3);


	cond->addServico_Cond(limpeza);
	cond->addServico_Cond(limpezaa);
	cond->addServico_Cond(can);
	cond->addServico_Cond(m);
	cond->addServico_Cond(m);


	cond->procurarServicos("limpeza"); //procura por nome, retorna o servico e o num de prestadores de servico, retorna nao existe se nao existir
	cout << "\n\n\n";
	cond->procurarServicos("aaaa"); //procura por nome, retorna o servico e o num de prestadores de servico, retorna nao existe se nao existir
	cout << "\n\n\n";
	cond->listarServicos(); //lista os servicos

	cout << "\n\n\n\n";
	cond->remServico_Cond("ma");
	cond->listarServicos();
	*/
	
	/*
	//TEste ponto 2
	//   tipo,     destino,    ponto_paragem,    dist_ponto_paragem
	Transporte metro("metro", "Porto", "Penafiel", 10);
	Transporte autocarro("autocarro", "Porto", "Paredes", 500);
	Transporte comboio("comboio", "Lisboa", "Caide", 200);
	Transporte teste("teste", "Lisboa", "Caide", 200);

	Condominio* cond = new Condominio("cond1");

	cond->addTransporte(metro);
	cond->addTransporte(autocarro);
	cond->addTransporte(comboio);
	cond->addTransporte(teste);

	cond->listarTransportes();


	cond->remTransporte("teste");
	cout << "\n\n\n\n";
	cond->listarTransportes();

	cout << cond->getPontoParagemMaisProx();
	cout << "\n";
	cout << cond->getPontoParagemMaisProx("Lisboa");
	cout << "\n";
	cout << cond->getPontoParagemMaisProx("eeee");

	cond->toogle_Ativ_PontoParagem("metro");
	cond->toogle_Ativ_PontoParagem("autocarro");
	cond->toogle_Ativ_PontoParagem("comboio");
	cond->toogle_Ativ_PontoParagem("metro");
	cout << "\n\n\n\n\n\n\n\n";

	cond->listarTransportes();
	*/
	



	return 0;

}