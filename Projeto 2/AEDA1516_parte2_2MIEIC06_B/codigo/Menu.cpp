#include "Menu.h"
#include <iostream>
#include <conio.h>
#include <windows.h>



using namespace std;

//Cores
#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15

// Limpa o ecrã

void clrscr()
{
	COORD coordScreen = { 0, 0 };
	DWORD cCharsWritten;
	DWORD dwConSize;
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO  csbi;
	GetConsoleScreenBufferInfo(hCon, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(hCon, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
	GetConsoleScreenBufferInfo(hCon, &csbi);
	FillConsoleOutputAttribute(hCon, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
	SetConsoleCursorPosition(hCon, coordScreen);
}

void setcolor(unsigned int color, unsigned int background_color)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	if (background_color == BLACK)
		SetConsoleTextAttribute(hCon, color);
	else
		SetConsoleTextAttribute(hCon, color | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
}


Menu::Menu()
{
	//Nopcao_M = 1;
	//NumOpcoes_M = 5;
}

Menu::~Menu()
{
}

void Menu::DrawnMenuI()
{
	clrscr();
	cout << "Info inicial (n condominios, condominos e servicos totais) \n";
	cout << "Gerir condominios \n";
	cout << "Adicionar condominios \n";
	cout << "Remover Condominios \n";
	cout << "Sair \n";
}

void Menu::navMenus(int tecla, unsigned int Num_de_Opcoes, unsigned int &op)
{
	if (tecla == 224) //setas
	{
		tecla = _getch();
		if (tecla == 72) // cima
			if (op > 1)
				op--;
		if (tecla == 80) // baixo
			if (op < Num_de_Opcoes)
				op++;
	}
}

/////////////////////////////// feito
void Menu::DrawnM_op1()
{
	clrscr();
	setcolor(WHITE, LIGHTGRAY);
	cout << "Info inicial (n condominios, condominos e servicos totais) \n";
	setcolor(WHITE, BLACK);
	cout << "Gerir condominios \n";
	cout << "Adicionar condominios \n";
	cout << "Remover Condominios \n";
	cout << "Listagens \n";
	cout << "Sair \n";
}
void Menu::DrawnM_op2()
{
	clrscr();
	cout << "Info inicial (n condominios, condominos e servicos totais) \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Gerir condominios \n";
	setcolor(WHITE, BLACK);
	cout << "Adicionar condominios \n";
	cout << "Remover Condominios \n";
	cout << "Listagens \n";
	cout << "Sair \n";
}
void Menu::DrawnM_op3()
{
	clrscr();
	cout << "Info inicial (n condominios, condominos e servicos totais) \n";
	cout << "Gerir condominios \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Adicionar condominios \n";
	setcolor(WHITE, BLACK);
	cout << "Remover Condominios \n";
	cout << "Listagens \n";
	cout << "Sair \n";
}
void Menu::DrawnM_op4()
{
	clrscr();
	cout << "Info inicial (n condominios, condominos e servicos totais) \n";
	cout << "Gerir condominios \n";
	cout << "Adicionar condominios \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Remover Condominios \n";
	setcolor(WHITE, BLACK);
	cout << "Listagens \n";
	cout << "Sair \n";
}
void Menu::DrawnM_op5()
{
	clrscr();
	cout << "Info inicial (n condominios, condominos e servicos totais) \n";
	cout << "Gerir condominios \n";
	cout << "Adicionar condominios \n";
	cout << "Remover Condominios \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Listagens \n";
	setcolor(WHITE, BLACK);
	cout << "Sair \n";
}
void Menu::DrawnM_op6()
{
	clrscr();
	cout << "Info inicial (n condominios, condominos e servicos totais) \n";
	cout << "Gerir condominios \n";
	cout << "Adicionar condominios \n";
	cout << "Remover Condominios \n";
	cout << "Listagens \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Sair \n";
	setcolor(WHITE, BLACK);
}

int Menu::M_op1()
{
	clrscr();
	data.info();
	cin.get();
	return 0;
}
int Menu::M_op2()
{
	clrscr();
	S1_iniciar();
	return 0;
}
int Menu::M_op3()
{
	clrscr();
	string nome, loc;
	cout << "Nome de condominio: ";
	cin >> nome;

	cout << "\n" << "Localizacao: ";
	cin >> loc;

	data.addCond(nome, loc);
	return 0;
}
int Menu::M_op4()
{
	clrscr();
	string nome;
	cout << "Nome de condominio: ";
	cin >> nome;
	data.remCondominio(nome);
	return 0;
}
////////////////////////////////////////////////

//////////a gerir condominio/////////////////////feito
void Menu::S1_iniciar()
{
	string nome;
	cout << "Insira o nome do Condominio: ";
	cin >> nome;

	condAgerir = nome;
	CondaGerir = data.getCondominio(nome);


	DrawnS1_op1();

	int tecla;
	while (tecla = _getch())
	{
		if (tecla == ENTER) //enter
		{
			switch (Nopcao_S1)
			{
			case 1:
				S1_op1();
				break;
			case 2:
				S1_op2();
				break;
			case 3:
				S1_op3();
				break;
			case 4:
				S1_op4();
				break;
			case 5:
				S1_op5();
				break;
			case 6:
				return;
				break;
			default:
				break;
			}
		}
		//Le tecla
		navMenus(tecla, NumOpcoes_S1, Nopcao_S1);

		if (tecla == ESC) //esc
			return;
		//Op
		switch (Nopcao_S1)
		{
		case 1:
			DrawnS1_op1();
			break;
		case 2:
			DrawnS1_op2();
			break;
		case 3:
			DrawnS1_op3();
			break;
		case 4:
			DrawnS1_op4();
			break;
		case 5:
			DrawnS1_op5();
			break;
		case 6:
			DrawnS1_op6();
			break;
		default:
			break;
		}

	}
}
int Menu::S1_op1()
{
	clrscr();
	CondaGerir->verHab();

	cout << "\n\n";
	cout << "Transportes: \n";
	CondaGerir->listarTransportes();

	cin.get();
	cin.get();
	return 0;
}
int Menu::S1_op2()
{
	clrscr();
	CondaGerir->verSerCond();
	cout << "\n\n\n";

	//parte 2, tabela
	cout << "Total Servicos (tabela)\n";
	CondaGerir->listarServicos();

	cin.get();
	cin.get();
	return 0;
}
int Menu::S1_op3()
{
	S1_Hab_Iniciar();
	return 0;
}
int Menu::S1_op4()
{
	S1_Ser_Iniciar();
	return 0;
}
int Menu::S1_op5()
{
	Transportes_iniciar();
	return 0;
}
void Menu::DrawnS1_op1()
{
	clrscr();
	cout << "-----A gerir condominio \"" << condAgerir << " \" ------\n\n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Ver info sobre Condominio \n";
	setcolor(WHITE, BLACK);
	cout << "Ver info sobre Servicos do Condominio \n";
	cout << "Habitacoes >>>> \n";
	cout << "Servivos >>>> \n";
	cout << "Transportes >>>> \n";
	cout << "Voltar \n";
}
void Menu::DrawnS1_op2()
{
	clrscr();
	cout << "-----A gerir condominio \"" << condAgerir << " \" ------\n\n";
	cout << "Ver info sobre Condominio \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Ver info sobre Servicos do Condominio \n";
	setcolor(WHITE, BLACK);
	cout << "Habitacoes >>>> \n";
	cout << "Servivos >>>> \n";
	cout << "Transportes >>>> \n";
	cout << "Voltar \n";
}
void Menu::DrawnS1_op3()
{
	clrscr();
	cout << "-----A gerir condominio \"" << condAgerir << " \" ------\n\n";
	cout << "Ver info sobre Condominio \n";
	cout << "Ver info sobre Servicos do Condominio \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Habitacoes >>>> \n";
	setcolor(WHITE, BLACK);
	cout << "Servivos >>>> \n";
	cout << "Transportes >>>> \n";
	cout << "Voltar \n";
}
void Menu::DrawnS1_op4()
{
	clrscr();
	cout << "-----A gerir condominio \"" << condAgerir << " \" ------\n\n";
	cout << "Ver info sobre Condominio \n";
	cout << "Ver info sobre Servicos do Condominio \n";
	cout << "Habitacoes >>>> \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Servivos >>>> \n";
	setcolor(WHITE, BLACK);
	cout << "Transportes >>>> \n";
	cout << "Voltar \n";
}
void Menu::DrawnS1_op5()
{
	clrscr();
	cout << "-----A gerir condominio \"" << condAgerir << " \" ------\n\n";
	cout << "Ver info sobre Condominio \n";
	cout << "Ver info sobre Servicos do Condominio \n";
	cout << "Habitacoes >>>> \n";
	cout << "Servivos >>>> \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Transportes >>>> \n";
	setcolor(WHITE, BLACK);
	cout << "Voltar \n";
}
void Menu::DrawnS1_op6()
{
	clrscr();
	cout << "-----A gerir condominio \"" << condAgerir << " \" ------\n\n";
	cout << "Ver info sobre Condominio \n";
	cout << "Ver info sobre Servicos do Condominio \n";
	cout << "Habitacoes >>>> \n";
	cout << "Servivos >>>> \n";
	cout << "Transportes >>>> \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Voltar \n";
	setcolor(WHITE, BLACK);
}


//////////////////////////////////////////
//Submenu1 habitacoes--feito--------------------------------------------------------------------------------------------------------
void Menu::S1_Hab_Iniciar()
{
	DrawnS1_Hab_op1();

	int tecla;
	while (tecla = _getch())
	{
		if (tecla == ENTER) //enter
		{
			switch (Nopcao_S1_H)
			{
			case 1:
				S1_Hab_op1();
				break;
			case 2:
				S1_Hab_op2();
				break;
			case 3:
				S1_Hab_op3();
				break;
			case 4:
				return;
				break;
			default:
				break;
			}
		}
		//Le tecla
		navMenus(tecla, NumOpcoes_S1_H, Nopcao_S1_H);

		if (tecla == ESC) //esc
			return;
		//Op
		switch (Nopcao_S1_H)
		{
		case 1:
			DrawnS1_Hab_op1();
			break;
		case 2:
			DrawnS1_Hab_op2();
			break;
		case 3:
			DrawnS1_Hab_op3();
			break;
		case 4:
			DrawnS1_Hab_op4();
			break;
		default:
			break;
		}

	}
}
int Menu::S1_Hab_op1()
{
	Hab_op1_iniciar();
	return 0;
}
int Menu::S1_Hab_op2()
{
	unsigned int nif;
	clrscr();
	CondaGerir->verHab();
	cout << "\n\n";
	cout << "Insira o nif do condomino a que a habitacao pertence: ";
	cin >> nif;
	CondaGerir->remHab(nif);
	return 0;
}
int Menu::S1_Hab_op3()
{
	Hab_op3_iniciar();
	return 0;
}
void Menu::DrawnS1_Hab_op1()
{
	clrscr();
	setcolor(WHITE, LIGHTGRAY);
	cout << "Adicionar Habitacao >>>> \n";
	setcolor(WHITE, BLACK);
	cout << "Remover Habitacao \n";
	cout << "Modificar Habitacao >>>> \n";
	cout << "Voltar \n";
}
void Menu::DrawnS1_Hab_op2()
{
	clrscr();
	cout << "Adicionar Habitacao >>>> \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Remover Habitacao \n";
	setcolor(WHITE, BLACK);
	cout << "Modificar Habitacao >>>> \n";
	cout << "Voltar \n";
}
void Menu::DrawnS1_Hab_op3()
{
	clrscr();
	cout << "Adicionar Habitacao >>>> \n";
	cout << "Remover Habitacao \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Modificar Habitacao >>>> \n";
	setcolor(WHITE, BLACK);
	cout << "Voltar \n";
}
void Menu::DrawnS1_Hab_op4()
{
	clrscr();
	cout << "Adicionar Habitacao >>>> \n";
	cout << "Remover Habitacao \n";
	cout << "Modificar Habitacao >>>> \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Voltar \n";
	setcolor(WHITE, BLACK);
}
//______SubMenu1 op1: adicionar //feito
void Menu::Hab_op1_iniciar()
{
	DrawnS1_Hab_op1_vivenda();

	int tecla;
	while (tecla = _getch())
	{
		if (tecla == ENTER) //enter
		{
			switch (Nopcao_S1_H_A)
			{
			case 1:
				Hab_op1_vivenda();
				break;
			case 2:
				Hab_op1_apartamento();
				break;
			case 3:
				return;
				break;
			default:
				break;
			}
		}
		//Le tecla
		navMenus(tecla, NumOpcoes_S1_H_A, Nopcao_S1_H_A);

		if (tecla == ESC) //esc
			return;
		//Op
		switch (Nopcao_S1_H_A)
		{
		case 1:
			DrawnS1_Hab_op1_vivenda();
			break;
		case 2:
			DrawnS1_Hab_op1_apartamento();
			break;
		case 3:
			DrawnS1_Hab_op1_voltar();
			break;
		default:
			break;
		}

	}
}
int Menu::Hab_op1_vivenda()
{
	unsigned int nif;
	string n;
	Habitacao *hab;
	Condomino *c;
	cout << "Nome do condomino: ";
	cin.ignore();
	getline(cin, n);
	cout << "NIF: ";
	cin >> nif;

	string m, r;
	unsigned int aH, aE;
	bool p;
	float men;


	c = new Condomino(n, nif);
	clrscr();
	cout << "Morada: ";
	cin.ignore(); //por causa dos cin>> anteriores e o getline a seguir
	getline(cin, m);
	cout << "Area Habitacional: ";
	cin >> aH;
	cout << "Area Exterior: ";
	cin >> aE;
	cout << "Mensalidade Base: ";
	cin >> men;
	cout << "Piscina (s ou n) ?:";
	cin >> r;
	if (r == "s")
		p = true;
	else if (r == "n")
		p = false;

	hab = new Vivenda(m, aH, men, aE, p);

	hab->addCondomino(c);
	hab->calcMensalidade();
	CondaGerir->addHabitacao(hab);
	return 0;
}
bool verificaTipo(string opcao)
{
	if ((opcao != "T0") && (opcao != "T1") && (opcao != "T2") && (opcao != "T3") && (opcao != "T4") && (opcao != "T5") && (opcao != "T6") && (opcao != "T7") && (opcao != "T8") && (opcao != "T9") && (opcao != "T10"))
	{
		return true;
	}
	else return false;
}
int Menu::Hab_op1_apartamento()
{
	unsigned int nif;
	string n;
	Habitacao *hab;
	Condomino *c;
	cout << "Nome do condomino: ";
	cin.ignore(); //por causa dos cin>> anteriores e  o getline a seguir
	getline(cin, n);
	cout << "NIF: ";
	cin >> nif;

	string m, t;
	unsigned int aH;
	int p;
	float men;


	c = new Condomino(n, nif);
	clrscr();
	cout << "Morada: ";
	cin.ignore(); //por causa dos cin>> anteriores e  o getline a seguir
	getline(cin, m);
	cout << "Area Habitacional: ";
	cin >> aH;
	cout << "Mensalidade Base: ";
	cin >> men;
	cout << "Tipologia (T0...T10): ";
	cin >> t;
	//verificacao tipologia
	while (verificaTipo(t))
	{
		cout << "\n Tipologia invalida! Introduza uma tipologia valida (T0...T10): " << endl;
		cin.ignore();
		cin >> t;
	}
	/////////////////////////////
	cout << "Piso: ";
	cin >> p;

	hab = new Apartamento(m, aH, men, t, p);
	hab->addCondomino(c);
	hab->calcMensalidade();
	CondaGerir->addHabitacao(hab);
	return 0;
}
void Menu::DrawnS1_Hab_op1_vivenda()
{
	clrscr();
	cout << "Habitacoes >>>> Adicionar Habitacao: \n\n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Vivenda \n";
	setcolor(WHITE, BLACK);
	cout << "Apartamento: \n";
	cout << "Voltar \n";
}
void Menu::DrawnS1_Hab_op1_apartamento()
{
	clrscr();
	cout << "Habitacoes >>>> Adicionar Habitacao: \n\n";
	cout << "Vivenda \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Apartamento: \n";
	setcolor(WHITE, BLACK);
	cout << "Voltar \n";
}
void Menu::DrawnS1_Hab_op1_voltar()
{
	clrscr();
	cout << "Habitacoes >>>> Adicionar Habitacao: \n\n";
	cout << "Vivenda \n";
	cout << "Apartamento: \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Voltar \n";
	setcolor(WHITE, BLACK);
}
//______SubMenu1 op3: modificar__________________________A FAZER_______________________
void Menu::Hab_op3_iniciar()
{
	DrawnS1_Hab_op3_Mod_Mensalidade();

	int tecla;
	while (tecla = _getch())
	{
		if (tecla == ENTER) //enter
		{
			switch (Nopcao_S1_H_M)
			{
			case 1:
				Hab_op3_Mod_Mensalidade();
				break;
			case 2:
				Hab_op3_Mod_AreaHabitacional();
				break;
			case 3:
				Hab_op3_Aderir_Servico();
				break;
			case 4:
				Hab_op3_Terminar_Servico();
				break;
			case 5:
				return;
				break;
			default:
				break;
			}
		}
		//Le tecla
		navMenus(tecla, NumOpcoes_S1_H_M, Nopcao_S1_H_M);

		if (tecla == ESC) //esc
			return;
		//Op
		switch (Nopcao_S1_H_M)
		{
		case 1:
			DrawnS1_Hab_op3_Mod_Mensalidade();
			break;
		case 2:
			DrawnS1_Hab_op3_Mod_AreaHabitacional();
			break;
		case 3:
			DrawnS1_Hab_op3_Aderir_Servico();
			break;
		case 4:
			DrawnS1_Hab_op3_Terminar_Servico();
			break;
		case 5:
			DrawnS1_Hab_op3_Voltar();
			break;
		default:
			break;
		}

	}
}
int Menu::Hab_op3_Mod_Mensalidade()
{//selecionar a habitação
	unsigned int nif;
	string n;
	clrscr();
	CondaGerir->verHab();

	cout << "\n\n Nome do Condomino: ";
	cin.ignore();//por causa dos cin>> anteriores e  o getline a seguir
	getline(cin, n);
	cout << "NIF: ";
	cin >> nif;

	Habitacao *hab;
	Condomino *c = new Condomino(n, nif);
	hab = CondaGerir->getHabitacao(c);
	delete c; //porque nao precisamos mais dele


	float men;
	cout << "Valor: ";
	cin >> men;
	hab->modificaMensalidade(men);

	return 0;
}
int Menu::Hab_op3_Mod_AreaHabitacional()
{//selecionar a habitação
	unsigned int nif;
	string n;
	clrscr();
	CondaGerir->verHab();

	cout << "\n\n Nome do Condomino: ";
	cin.ignore();//por causa dos cin>> anteriores e  o getline a seguir
	getline(cin, n);
	cout << "NIF: ";
	cin >> nif;

	Habitacao *hab;
	Condomino *c = new Condomino(n, nif);
	hab = CondaGerir->getHabitacao(c);
	delete c; //porque nao precisamos mais dele


	unsigned int area;
	cout << "Valor: ";
	cin >> area;
	hab->modificaArea_Habitacional(area);

	return 0;
}
int Menu::Hab_op3_Aderir_Servico()
{//selecionar a habitação
	unsigned int nif;
	string n;
	clrscr();
	CondaGerir->verHab();

	cout << "\n\n Nome do Condomino: ";
	cin.ignore();//por causa dos cin>> anteriores e  o getline a seguir
	getline(cin, n);
	cout << "NIF: ";
	cin >> nif;

	Habitacao *hab;
	Condomino *c = new Condomino(n, nif);
	hab = CondaGerir->getHabitacao(c);
	delete c; //porque nao precisamos mais dele




	string nome;
	clrscr();
	CondaGerir->verSerCond();

	cout << "\n Insira o nome do Servico a aderir";
	cin >> nome;

	hab->addServico(CondaGerir->getServ(nome));

	return 0;
}
int Menu::Hab_op3_Terminar_Servico()
{
	//selecionar a habitação
	unsigned int nif;
	string n;
	clrscr();
	CondaGerir->verHab();

	cout << "\n\n Nome do Condomino: ";
	cin.ignore();//por causa dos cin>> anteriores e  o getline a seguir
	getline(cin, n);
	cout << "NIF: ";
	cin >> nif;

	Habitacao *hab;
	Condomino *c = new Condomino(n, nif);
	hab = CondaGerir->getHabitacao(c);
	delete c; //porque nao precisamos mais dele


	string numS;
	clrscr();
	hab->verServicosAderidos();

	cout << "\n Insira o nome do Servico a terminar";
	cin >> numS;

	hab->removeServico(CondaGerir->getServ(numS));
	return 0;
}
void Menu::DrawnS1_Hab_op3_Mod_Mensalidade()
{
	clrscr();
	cout << "Habitacoes >>>> Modificar Habitacao: \n\n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Modificar Mensalidade\n";
	setcolor(WHITE, BLACK);
	cout << "Modificar A Habitacional\n";
	cout << "Aderir a Servico \n";
	cout << "Terminar Servico \n";
	cout << "Voltar \n";
}
void Menu::DrawnS1_Hab_op3_Mod_AreaHabitacional()
{
	clrscr();
	cout << "Habitacoes >>>> Modificar Habitacao: \n\n";
	cout << "Modificar Mensalidade\n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Modificar A Habitacional\n";
	setcolor(WHITE, BLACK);
	cout << "Aderir a Servico \n";
	cout << "Terminar Servico \n";
	cout << "Voltar \n";
}
void Menu::DrawnS1_Hab_op3_Aderir_Servico()
{
	clrscr();
	cout << "Habitacoes >>>> Modificar Habitacao: \n\n";
	cout << "Modificar Mensalidade\n";
	cout << "Modificar A Habitacional\n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Aderir a Servico \n";
	setcolor(WHITE, BLACK);
	cout << "Terminar Servico \n";
	cout << "Voltar \n";
}
void Menu::DrawnS1_Hab_op3_Terminar_Servico()
{
	clrscr();
	cout << "Habitacoes >>>> Modificar Habitacao: \n\n";
	cout << "Modificar Mensalidade\n";
	cout << "Modificar A Habitacional\n";
	cout << "Aderir a Servico \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Terminar Servico \n";
	setcolor(WHITE, BLACK);
	cout << "Voltar \n";
}
void Menu::DrawnS1_Hab_op3_Voltar()
{
	clrscr();
	cout << "Habitacoes >>>> Modificar Habitacao: \n\n";
	cout << "Modificar Mensalidade\n";
	cout << "Modificar A Habitacional\n";
	cout << "Aderir a Servico \n";
	cout << "Terminar Servico \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Voltar \n";
	setcolor(WHITE, BLACK);
}
//_______________________________________________________________________________
//------------------------------------------------------------------------------------------------------------------------------------


//Submenu1 servicos
void Menu::S1_Ser_Iniciar()
{
	DrawnS1_Ser_op1();

	int tecla;
	while (tecla = _getch())
	{
		if (tecla == ENTER) //enter
		{
			switch (Nopcao_S1_S)
			{
			case 1:
				S1_Ser_op1();
				break;
			case 2:
				S1_Ser_op2();
				break;
			case 3:
				S1_Ser_op3();
				break;
			case 4:
				return;
				break;
			default:
				break;
			}
		}
		//Le tecla
		navMenus(tecla, NumOpcoes_S1_S, Nopcao_S1_S);

		if (tecla == ESC) //esc
			return;
		//Op
		switch (Nopcao_S1_S)
		{
		case 1:
			DrawnS1_Ser_op1();
			break;
		case 2:
			DrawnS1_Ser_op2();
			break;
		case 3:
			DrawnS1_Ser_op3();
			break;
		case 4:
			DrawnS1_Ser_op4();
			break;
		default:
			break;
		}
	}
}
int Menu::S1_Ser_op1()
{
	CondaGerir->verSerCond();
	cout << "\n\n";


	string nm;
	unsigned int n;
	cout << "Nome do Servico: ";
	cin >> nm;
	cout << "N prestadores de Servico: ";
	cin >> n;
	Servico *s = new Servico(nm, n);
	CondaGerir->addServico(s);


	//parte 2 tabela.... adiciona a tabela
	Servico aux(nm, n);
	CondaGerir->addServico_Cond(aux);

	return 0;
}
int Menu::S1_Ser_op2()
{
	CondaGerir->verSerCond();
	cout << "\n\n";

	string nm;
	cout << "Nome do Servico: ";
	cin >> nm;

	CondaGerir->remServico(nm);

	//parte 2 tabela.... apaga da tabela
	CondaGerir->remServico_Cond(nm);

	return 0;
}	//remover
int Menu::S1_Ser_op3()
{
	clrscr();
	CondaGerir->verSerCond();
	cout << "\n\n\n";

	//parte 2, tabela
	cout << "Total Servicos (tabela)\n";
	CondaGerir->listarServicos();
	///////////////////////////////////
	cout << "\n\n\n";

	Servico *s;
	string nm;
	unsigned int num;
	cout << "Nome Servico:";
	cin >> nm;
	s = CondaGerir->getServ(nm);
	
	CondaGerir->remServico_Cond(nm); /////////////////apaga da tabela

	cout << "Novo nome: ";
	cin >> nm;
	s->modificaNome(nm);
	cout << "Num Prestadores de servico: ";
	cin >> num;
	s->modificaNPS(num);



	//parte 2 - tabela.... modifica o existente na tabela
	Servico aux(nm, num);
	CondaGerir->addServico_Cond(aux);



	return 0;
}
void Menu::DrawnS1_Ser_op1()
{
	clrscr();
	setcolor(WHITE, LIGHTGRAY);
	cout << "Adicionar Servico \n";
	setcolor(WHITE, BLACK);
	cout << "Remover Servico \n";
	cout << "Modificar Servicos \n";
	cout << "Voltar\n";
}
void Menu::DrawnS1_Ser_op2()
{
	clrscr();
	cout << "Adicionar Servico \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Remover Servico \n";
	setcolor(WHITE, BLACK);
	cout << "Modificar Servicos \n";
	cout << "Voltar\n";
}
void Menu::DrawnS1_Ser_op3()
{
	clrscr();
	cout << "Adicionar Servico \n";
	cout << "Remover Servico \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Modificar Servicos \n";
	setcolor(WHITE, BLACK);
	cout << "Voltar\n";
}
void Menu::DrawnS1_Ser_op4()
{
	clrscr();
	cout << "Adicionar Servico \n";
	cout << "Remover Servico \n";
	cout << "Modificar Servicos \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Voltar\n";
	setcolor(WHITE, BLACK);
}



//addTransporte
//Remtransporte
//desativar ponto paragem
//getpontoparagem

//Sbmenu Transportes
void Menu::Transportes_iniciar()
{
	DrawnTop1();

	int tecla;
	while (tecla = _getch())
	{
		if (tecla == ENTER) //enter
		{
			switch (Nopcao_T)
			{
			case 1:
				Tra_op1();
				break;
			case 2:
				Tra_op2();
				break;
			case 3:
				Tra_op3();
				break;
			case 4:
				Tra_op4();
				break;
			case 5:
				return;
				break;
			default:
				break;
			}
		}
		//Le tecla
		navMenus(tecla, NumOpcoes_T, Nopcao_T);

		if (tecla == ESC) //esc
			return;
		//Op
		switch (Nopcao_T)
		{
		case 1:
			DrawnTop1();
			break;
		case 2:
			DrawnTop2();
			break;
		case 3:
			DrawnTop3();
			break;
		case 4:
			DrawnTop4();
			break;
		case 5:
			DrawnTop5();
			break;
		default:
			break;
		}
	}
}
int Menu::Tra_op1()
{
	string tipo, destino, ponto_paragem;
	unsigned int dist;

	clrscr();
	cout << "Insira o tipo: ";
	cin >> tipo;
	cout << "Insira o destino: ";
	cin >> destino;
	cout << "Insira o ponto_paragem: ";
	cin >> ponto_paragem;
	cout << "Insira a distancia: ";
	cin >> dist;

	Transporte aux(tipo, destino,  ponto_paragem, dist);
	CondaGerir->addTransporte(aux);

	return 0;
}
int Menu::Tra_op2()
{
	clrscr();
	CondaGerir->listarTransportes();
	cout << "\n\n";

	string tipo;
	cout << "Insira o tipo: ";
	cin >> tipo;

	CondaGerir->remTransporte(tipo);

	return 0;
}
int Menu::Tra_op3()
{
	clrscr();
	CondaGerir->listarTransportes();
	cout << "\n\n";

	string tipo;
	cout << "Insira o tipo: ";
	cin >> tipo;

	CondaGerir->toogle_Ativ_PontoParagem(tipo);
	return 0;
}
int Menu::Tra_op4()
{
	clrscr();
	string r, destino;
	cout << "Especificar destino (s ou n): ";
	cin >> r;
	if (r == "s")
	{
		clrscr();
		cout << "Insira o destino: ";
		cin >> destino;
		cout << "\n";
		CondaGerir->getPontoParagemMaisProx(destino);
	}
	else
	{
		CondaGerir->getPontoParagemMaisProx();
	}
	return 0;
}
void Menu::DrawnTop1()
{
	clrscr();
	cout << "Transportes >>>> \n\n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Adicionar Transporte \n";
	setcolor(WHITE, BLACK);
	cout << "Remover Transporte \n";
	cout << "Toogle Ponto de Paragem \n";
	cout << "Ponto de Paragem mais proximo \n";
	cout << "Voltar\n";
}
void Menu::DrawnTop2()
{
	clrscr();
	cout << "Transportes >>>> \n\n";
	
	cout << "Adicionar Transporte \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Remover Transporte \n";
	setcolor(WHITE, BLACK);
	cout << "Toogle Ponto de Paragem \n";
	cout << "Ponto de Paragem mais proximo \n";
	cout << "Voltar\n";
}
void Menu::DrawnTop3()
{
	clrscr();
	cout << "Transportes >>>> \n\n";

	cout << "Adicionar Transporte \n";
	cout << "Remover Transporte \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Toogle Ponto de Paragem \n";
	setcolor(WHITE, BLACK);
	cout << "Ponto de Paragem mais proximo \n";
	cout << "Voltar\n";
}
void Menu::DrawnTop4()
{
	clrscr();
	cout << "Transportes >>>> \n\n";
	cout << "Adicionar Transporte \n";
	cout << "Remover Transporte \n";
	cout << "Toogle Ponto de Paragem \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Ponto de Paragem mais proximo \n";
	setcolor(WHITE, BLACK);
	cout << "Voltar\n";
}
void Menu::DrawnTop5()
{
	clrscr();
	cout << "Transportes >>>> \n\n";
	cout << "Adicionar Transporte \n";
	cout << "Remover Transporte \n";
	cout << "Toogle Ponto de Paragem \n";
	cout << "Ponto de Paragem mais proximo \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Voltar\n";
	setcolor(WHITE, BLACK);
}


int Menu::Iniciar(Data &data)
{
	this->data=data;

	DrawnM_op1();
	//DrawnMenuI();
	//72
	//80

	int tecla;
	while (tecla = _getch())
	{
		if (tecla == ENTER) //enter
		{
			switch (Nopcao_M)
			{
			case 1:
				M_op1();
				break;
			case 2:
				M_op2();
				break;
			case 3:
				M_op3();
				break;
			case 4:
				M_op4();
				break;
			case 5:
				cond_arv_iniciar();
				break;
			case 6:
				return 0;
				break;
			default:
				break;
			}
		}
		//Le tecla
		navMenus(tecla, NumOpcoes_M, Nopcao_M);

		if (tecla == ESC) //esc
			return 0;
		//Op
		switch (Nopcao_M)
		{
		case 1:
			DrawnM_op1();
			break;
		case 2:
			DrawnM_op2();
			break;
		case 3:
			DrawnM_op3();
			break;
		case 4:
			DrawnM_op4();
			break;
		case 5:
			DrawnM_op5();
			break;
		case 6:
			DrawnM_op6();
			break;
		default:
			break;
		}

	}

	return 0;
}

void Menu::save()
{
//Condominios
	data.savecond();

//Servicos
	data.saveServicos();

//Transportes
	data.saveTransportes();

//Habitacoes
	data.saveHabitacoes();

}






//condominios arvores
void Menu::cond_arv_iniciar()
{
	Drawn_cond_arv_1();

	int tecla;
	while (tecla = _getch())
	{
		if (tecla == ENTER) //enter
		{
			switch (Nopcao_condARV)
			{
			case 1:
				cond_arv_op1();
				break;
			case 2:
				return;
				break;
			default:
				break;
			}
		}
		//Le tecla
		navMenus(tecla, NumOpcoes_condARV, Nopcao_condARV);

		if (tecla == ESC) //esc
			return;
		//Op
		switch (Nopcao_condARV)
		{
		case 1:
			Drawn_cond_arv_1();
			break;
		case 2:
			Drawn_cond_arv_2();
			break;
		default:
			break;
		}
	}
}

int Menu::cond_arv_op1()
{
	mais_op_iniciar();
	return 0;
}
void Menu::Drawn_cond_arv_1()
{
	clrscr();
	setcolor(WHITE, LIGHTGRAY);
	cout << "Mais opcoes >>>>\n";
	setcolor(WHITE, BLACK);
	cout << "Voltar \n";
}
void Menu::Drawn_cond_arv_2()
{
	clrscr();
	cout << "Mais opcoes >>>>\n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Voltar \n";
	setcolor(WHITE, BLACK);
}

//Mais opcoes
void Menu::mais_op_iniciar()
{
	Drawn_mais_op_1();

	int tecla;
	while (tecla = _getch())
	{
		if (tecla == ENTER) //enter
		{
			switch (Nopcao_MaisOP)
			{
			case 1:
				mais_op_1();
				break;
			case 2:
				mais_op_2();
				break;
			case 3:
				mais_op_3();
				break;
			case 4:
				mais_op_4();
				break;
			case 5:
				mais_op_5();
				break;
			case 6:
				return;
				break;
			default:
				break;
			}
		}
		//Le tecla
		navMenus(tecla, NumOpcoes_MaisOP, Nopcao_MaisOP);

		if (tecla == ESC) //esc
			return;
		//Op
		switch (Nopcao_MaisOP)
		{
		case 1:
			Drawn_mais_op_1();
			break;
		case 2:
			Drawn_mais_op_2();
			break;
		case 3:
			Drawn_mais_op_3();
			break;
		case 4:
			Drawn_mais_op_4();
			break;
		case 5:
			Drawn_mais_op_5();
			break;
		case 6:
			Drawn_mais_op_6();
			break;
		default:
			break;
		}
	}
}

int Menu::mais_op_1()
{
	int x;
	cout << "insira numero de habitaçoes: ";
	cin >> x;
	for (int i = 0; i < data.condXHab(x).size(); i++)
	{
		cout << data.condXHab(x)[i].getNome() << " localizacao: " << data.condXHab(x)[i].getLocalizacao() << endl;
	}
	cin.get();
	cin.get();

	return 0;
}
int Menu::mais_op_2()
{
	int x, y;
	cout << "insira x ";
	cin >> x;
	cout << "insira y ";
	cin >> y;
	for (int i = 0; i < data.condEntreHab(x, y).size(); i++)
	{
		cout << data.condEntreHab(x, y)[i].getNome() << " localizacao: " << data.condEntreHab(x, y)[i].getLocalizacao() << " N.Habitacoes: " << data.condEntreHab(x, y)[i].getNumHab() << endl;
	}
	cin.get();
	cin.get();
	return 0;
}
int Menu::mais_op_3()
{
	string local;
	cout << "insira local: ";
	cin >> local;
	for (int i = 0; i < data.condLocal(local).size(); i++)
	{
		cout << data.condLocal(local)[i].getNome() << " localizacao: " << data.condLocal(local)[i].getLocalizacao() << " N.Habitacoes: " << data.condLocal(local)[i].getNumHab() << endl;
	}
	cin.get();
	cin.get();
	return 0;
}
int Menu::mais_op_4()
{
	int x;
	cout << "insira numero de vivendas: ";
	cin >> x;
	for (int i = 0; i < data.condXVivendas(x).size(); i++)
	{
		cout << data.condXVivendas(x)[i].getNome() << " localizacao: " << data.condXVivendas(x)[i].getLocalizacao() << " N.Habitacoes: " << data.condXVivendas(x)[i].getNumHab() << endl;
	}
	cin.get();
	cin.get();
	return 0;
}
int Menu::mais_op_5()
{
	int x;
	cout << "insira numero de apartamentos: ";
	cin >> x;
	for (int i = 0; i < data.condXApartamentos(x).size(); i++)
	{
		cout << data.condXApartamentos(x)[i].getNome() << " localizacao: " << data.condXApartamentos(x)[i].getLocalizacao() << " N.Habitacoes: " << data.condXApartamentos(x)[i].getNumHab() << endl;
	}
	cin.get();
	cin.get();
	return 0;
}
void Menu::Drawn_mais_op_1()
{
	clrscr();
	cout << "Mais opcoes >>>>\n\n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Procurar condominios por numero de habitaçoes \n";
	setcolor(WHITE, BLACK);
	cout << "Procurar condominios entre x e y habitaçoes \n";
	cout << "Procurar condominios por local \n";
	cout << "Procurar condominios por numero de vivendas \n";
	cout << "Procurar condominios por numero de apartamentos \n";
	cout << "Voltar \n";

}
void Menu::Drawn_mais_op_2()
{
	clrscr();
	cout << "Mais opcoes >>>>\n\n";
	cout << "Procurar condominios por numero de habitaçoes \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Procurar condominios entre x e y habitaçoes \n";
	setcolor(WHITE, BLACK);
	cout << "Procurar condominios por local \n";
	cout << "Procurar condominios por numero de vivendas \n";
	cout << "Procurar condominios por numero de apartamentos \n";
	cout << "Voltar \n";

}
void Menu::Drawn_mais_op_3()
{
	clrscr();
	cout << "Mais opcoes >>>>\n\n";
	cout << "Procurar condominios por numero de habitaçoes \n";
	cout << "Procurar condominios entre x e y habitaçoes \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Procurar condominios por local \n";
	setcolor(WHITE, BLACK);
	cout << "Procurar condominios por numero de vivendas \n";
	cout << "Procurar condominios por numero de apartamentos \n";
	cout << "Voltar \n";

}
void Menu::Drawn_mais_op_4()
{
	clrscr();
	cout << "Mais opcoes >>>>\n\n";
	cout << "Procurar condominios por numero de habitaçoes \n";
	cout << "Procurar condominios entre x e y habitaçoes \n";
	cout << "Procurar condominios por local \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Procurar condominios por numero de vivendas \n";
	setcolor(WHITE, BLACK);
	cout << "Procurar condominios por numero de apartamentos \n";
	cout << "Voltar \n";

}
void Menu::Drawn_mais_op_5()
{
	clrscr();
	cout << "Mais opcoes >>>>\n\n";
	cout << "Procurar condominios por numero de habitaçoes \n";
	cout << "Procurar condominios entre x e y habitaçoes \n";
	cout << "Procurar condominios por local \n";
	cout << "Procurar condominios por numero de vivendas \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Procurar condominios por numero de apartamentos \n";
	setcolor(WHITE, BLACK);
	cout << "Voltar \n";

}
void Menu::Drawn_mais_op_6()
{
	clrscr();
	cout << "Mais opcoes >>>>\n\n";
	cout << "Procurar condominios por numero de habitaçoes \n";
	cout << "Procurar condominios entre x e y habitaçoes \n";
	cout << "Procurar condominios por local \n";
	cout << "Procurar condominios por numero de vivendas \n";
	cout << "Procurar condominios por numero de apartamentos \n";
	setcolor(WHITE, LIGHTGRAY);
	cout << "Voltar \n";
	setcolor(WHITE, BLACK);

}







