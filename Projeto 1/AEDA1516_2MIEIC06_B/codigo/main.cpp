#pragma once;

#include <iostream>

#include "Data.h"
#include "Condominios.h"
#include "Condomino.h"
#include <Windows.h>

using namespace std;

//limpa o ecra
void clrscr() {
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

bool verificaopcao(string opcao)
{
	if ((opcao != "1") && (opcao != "2") && (opcao != "3") && (opcao != "4") && (opcao != "0"))
	{
		return true;
	}
	else return false;
}



int main()
{
	//O save est� a funcionar mal, por isso retirei o loop onde o programa continua ate o utilizador escolher fechar, agora fecha ao completar a a��o na aplica��o desejada

	Data data;
	data.inicialize();
	
	string opcao;
	string nome;

	cout << "1: Info inicial (n condominios, condominos e servicos totais) \n";
	cout << "2: Gerir condominios \n";
	cout << "3: Adicionar condominios \n";
	cout << "4: Remover Condominios \n";
	cout << "0: Sair... \n";

	cout << "Insira a opcao: ";
	cin >> opcao;

		//verifica��o
		while (verificaopcao(opcao))
		{
			cout << "\n Opcao invalida! Introduza uma opcao valida: " << endl;
			cin.ignore();
			cin >> opcao;
		}


		clrscr();

		if (opcao == "0")
			return 0;
		else if (opcao == "1")
			data.info();
		else if (opcao == "2")
			data.run();
		else if (opcao == "3")
		{
			cout << "Nome de condominio: ";
			cin>>nome;
			data.addCond(nome);
		}
		else if (opcao == "4")
		{
			cout << "Nome de condominio: ";
			cin >> nome;
			data.remCondominio(nome);
		}

	//data.save();	//o save() n�o funciona totalmente bem, est� a decrementar os servi�os e n�o devia de o fazer
					//(ao decrementar, vai chegar um ponto onde o numero de prestadores de servi�o � 0, e ao inicializar,
					//vai lan�ar excep��o e o programa n�o inicia corretamente)
					//, mas grava as habita��es e os condominios corretamente

	cin.get();

	return 0;

}