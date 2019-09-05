#pragma once

#include "Data.h"
#include "Condominios.h"
#include "Condomino.h"

#define ENTER 13
#define ESC 27

class Menu
{
public:
	Menu();
	~Menu();
	int Iniciar(Data &data);
	void navMenus(int tecla, unsigned int Num_de_Opcoes, unsigned int &op);
	void DrawnMenuI();
	void save();


	//Menu Inicial
	int M_op1();
	int M_op2();
	int M_op3();
	int M_op4();
	void DrawnM_op1();
	void DrawnM_op2();
	void DrawnM_op3();
	void DrawnM_op4();
	void DrawnM_op5();
	void DrawnM_op6();

	//Submenu 1
	void S1_iniciar();
	int S1_op1();
	int S1_op2();
	int S1_op3();
	int S1_op4();
	int S1_op5();
	void DrawnS1_op1();
	void DrawnS1_op2();
	void DrawnS1_op3();
	void DrawnS1_op4();
	void DrawnS1_op5();
	void DrawnS1_op6();

	//Submenu1 habitacoes
	void S1_Hab_Iniciar();
	int S1_Hab_op1();	//adicionar
	int S1_Hab_op2();	//remover
	int S1_Hab_op3();	//modificar
	void DrawnS1_Hab_op1();
	void DrawnS1_Hab_op2();
	void DrawnS1_Hab_op3();
	void DrawnS1_Hab_op4();
	//______SubMenu1 op1
	void Hab_op1_iniciar();
	int Hab_op1_vivenda();
	int Hab_op1_apartamento();
	void DrawnS1_Hab_op1_vivenda();
	void DrawnS1_Hab_op1_apartamento();
	void DrawnS1_Hab_op1_voltar();
	//______SubMenu1 op3
	void Hab_op3_iniciar();
	int Hab_op3_Mod_Mensalidade();
	int Hab_op3_Mod_AreaHabitacional();
	int Hab_op3_Aderir_Servico();
	int Hab_op3_Terminar_Servico();
	void DrawnS1_Hab_op3_Mod_Mensalidade();
	void DrawnS1_Hab_op3_Mod_AreaHabitacional();
	void DrawnS1_Hab_op3_Aderir_Servico();
	void DrawnS1_Hab_op3_Terminar_Servico();
	void DrawnS1_Hab_op3_Voltar();



	//Submenu1 servicos
	void S1_Ser_Iniciar();
	int S1_Ser_op1();	//adicionar
	int S1_Ser_op2();	//remover
	int S1_Ser_op3();	//modificar
	void DrawnS1_Ser_op1();
	void DrawnS1_Ser_op2();
	void DrawnS1_Ser_op3();
	void DrawnS1_Ser_op4();



	//Transportes menu
	void Transportes_iniciar();
	int Tra_op1();
	int Tra_op2();
	int Tra_op3();
	int Tra_op4();
	void DrawnTop1();
	void DrawnTop2();
	void DrawnTop3();
	void DrawnTop4();
	void DrawnTop5();



	//condominios arvores
	void cond_arv_iniciar();

	int cond_arv_op1();
	void Drawn_cond_arv_1();
	void Drawn_cond_arv_2();

	//Mais opcoes
	void mais_op_iniciar();

	int mais_op_1();
	int mais_op_2();
	int mais_op_3();
	int mais_op_4();
	int mais_op_5();
	void Drawn_mais_op_1();
	void Drawn_mais_op_2();
	void Drawn_mais_op_3();
	void Drawn_mais_op_4();
	void Drawn_mais_op_5();
	void Drawn_mais_op_6();


private:
	Data data;
	string condAgerir;
	Condominio * CondaGerir;

	//Menu inicial
	unsigned int Nopcao_M = 1;
	unsigned int NumOpcoes_M = 6;

	//Submenu gerir condominios
	unsigned int Nopcao_S1 = 1;
	unsigned int NumOpcoes_S1 = 6;

	//Submenu gerir condominios >> habitaçoes
	unsigned int Nopcao_S1_H = 1;
	unsigned int NumOpcoes_S1_H = 4;

	//Submenu gerir condominios >> habitaçoes >> adicionar
	unsigned int Nopcao_S1_H_A = 1;
	unsigned int NumOpcoes_S1_H_A = 3;

	//Submenu gerir condominios >> habitaçoes >> modificar
	unsigned int Nopcao_S1_H_M = 1;
	unsigned int NumOpcoes_S1_H_M = 5;

	//Submenu gerir condominios >> servicos
	unsigned int Nopcao_S1_S = 1;
	unsigned int NumOpcoes_S1_S= 4;


	//Transportes
	unsigned int Nopcao_T = 1;
	unsigned int NumOpcoes_T = 5;


	//condarv
	unsigned int Nopcao_condARV = 1;
	unsigned int NumOpcoes_condARV = 2;

	//mais ops
	unsigned int Nopcao_MaisOP = 1;
	unsigned int NumOpcoes_MaisOP = 6;


};



