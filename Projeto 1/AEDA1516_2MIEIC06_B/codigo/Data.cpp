#include "Data.h"
#include <fstream> 
#include <sstream>

#include <iostream>
#include <Windows.h>

using namespace std;

template<class T>
T string_to_int(string intStr)
{
	T n;
	istringstream intStream(intStr);
	intStream >> n;
	return n;
}


Condomino* Data::getCondomino(int nif)
{
	for (size_t i = 0; i < Condominos.size(); i++)
	{
		if (nif == Condominos[i]->getNif())
			return Condominos[i];
	}
	return NULL;
}

Servico * Data::getServico(int serv)
{
	return Servicos[serv];
}

bool Data::inicialize(){

	ifstream servico;

	servico.open("Servicos.txt");

	vector<string> aux_servico;
	while (!servico.eof()){
		string aux;
		getline(servico, aux);
		if (aux != "")
			aux_servico.push_back(aux);
	}

	vector<vector<string>> servico_data;

	for (size_t i = 0; i < aux_servico.size(); i++)
	{

		string aux = aux_servico[i];
		istringstream intra(aux);
		vector<string> data;
		while (intra)
		{
			string auxx;
			if (!getline(intra, auxx, ','))
				break;
			data.push_back(auxx);
		}
		servico_data.push_back(data);
	}

	/*
	servico_data[i][0] = nome;
	servico_data[i][1] = numero;
	*/
	for (size_t i = 0; i < servico_data.size(); i++)
	{
		Servicos.push_back(new Servico(servico_data[i][0], string_to_int<int>(servico_data[i][1]), i));
	}

	servico.close();



	servico.open("Condominos.txt");

	vector<string> aux_condomino;
	while (!servico.eof()){
		string aux;
		getline(servico, aux);
		if (aux != "")
			aux_condomino.push_back(aux);
	}

	vector<vector<string>> condominos_data;

	for (size_t i = 0; i < aux_condomino.size(); i++)
	{

		string aux = aux_condomino[i];
		istringstream intra(aux);
		vector<string> data;
		while (intra)
		{
			string auxx;
			if (!getline(intra, auxx, ','))
				break;
			data.push_back(auxx);
		}
		condominos_data.push_back(data);
	}

	/*
	condominos_data[i][0]=nome;
	condominos_data[i][1]=NIF;
	*/
	for (size_t i = 0; i < condominos_data.size(); i++)
	{
		Condominos.push_back(new Condomino(condominos_data[i][0], string_to_int<unsigned int>(condominos_data[i][1])));
	}

	servico.close();



	servico.open("Data.txt");

	vector<string> aux_condominio;
	while (!servico.eof()){
		string aux;
		getline(servico, aux);
		if (aux != "")
			aux_condominio.push_back(aux);
	}

	servico.close();



	for (size_t i = 0; i < aux_condominio.size(); i++)
	{
		servico.open(aux_condominio[i] + ".txt");

		vector<string> aux_condominios;
		while (!servico.eof()){
			string aux;
			getline(servico, aux);
			if (aux != "")
				aux_condominios.push_back(aux);
		}

		servico.close();

		vector<vector<string>> condominios_data;

		for (size_t k = 0; k < aux_condominios.size(); k++)
		{

			string aux = aux_condominios[k];
			istringstream intra(aux);
			vector<string> data;
			while (intra)
			{
				string auxx;
				if (!getline(intra, auxx, ','))
					break;
				data.push_back(auxx);
			}
			condominios_data.push_back(data);
		}

		/*
		0-apartamento
		1-vivenda

		rua

		area habitacional

		mensalidade

		0-tipologia
		1-area exterior

		0-piso
		1-piscina

		nif do condomino

		servico que quer
		*/

		Condominio * condominio = new Condominio(aux_condominio[i]);

		for (size_t m = 0; m < condominios_data[0].size(); m++)
			condominio->addServico(getServico(string_to_int<int>(condominios_data[0][m])));


		for (size_t l = 1; l < condominios_data.size(); l++)
		{
			Habitacao * habi;
			if (condominios_data[l][0] == "0")
				habi = new Apartamento(condominios_data[l][1], string_to_int<unsigned int>(condominios_data[l][2]), string_to_int<int>(condominios_data[l][3]), condominios_data[l][4], string_to_int<int>(condominios_data[l][5]));
			else
				habi = new Vivenda(condominios_data[l][1], string_to_int<unsigned int>(condominios_data[l][2]), string_to_int<int>(condominios_data[l][3]), string_to_int<unsigned int>(condominios_data[l][4]), condominios_data[l][5] == "0" ? false : true);

			habi->addCondomino(getCondomino(string_to_int<int>(condominios_data[l][6])));

			for (size_t j = 7; j < condominios_data[l].size(); j++)
			{
				habi->addServico(getServico(string_to_int<int>(condominios_data[l][j])));
			}
			condominio->addHabitacao(habi);
		}
		Condominios.push_back(condominio);
	}


	return true;

}

bool Data::save()
{
	ofstream aux;
	string nome;

	aux.open("Servicos.txt");
	for (size_t i = 0; i < Servicos.size(); i++)
	{
		if (i == Servicos.size() - 1)
			aux << Servicos[i]->save();
		else
			aux << Servicos[i]->save() << endl;
	}
	aux.close();

	aux.open("Condomino.txt");
	for (size_t i = 0; i < Condominos.size(); i++)
	{
		if (i == Condominos.size() - 1)
			aux << Condominos[i]->save();
		else
			aux << Condominos[i]->save() << endl;
	}
	aux.close();

	aux.open("Data.txt");
	for (size_t i = 0; i < Condominios.size(); i++)
	{
		if (i == Condominios.size() - 1)
			aux << Condominios[i]->getNome();
		else
			aux << Condominios[i]->getNome() << endl;
	}
	aux.close();

	for (size_t i = 0; i < Condominios.size(); i++)
	{
		aux.open(Condominios[i]->getNome() + ".txt");
		string serv;

		for (size_t j = 0; j < Servicos.size(); j++)
		{
			if (j == Servicos.size() - 1)
				serv += to_string(Servicos[j]->getId());
			else serv = serv + to_string(Servicos[j]->getId()) + ",";
		}
		aux << serv << endl;
		for (size_t j = 0; j < Condominios[i]->getHabitacoes().size(); j++)
		{
			if (j == Condominios[i]->getHabitacoes().size() - 1)
				aux << Condominios[i]->getHabitacoes()[j]->save();
			else aux << Condominios[i]->getHabitacoes()[j]->save() << endl;
		}
		aux.close();

	}
	return true;
}

void Data::info()
{
	cout << "N de Condominios: " << Condominios.size() << "\n";
	for (size_t i = 0; i < Condominios.size(); i++)
		cout << Condominios[i]->getNome() << "\n";
	
	cout << "\n";
	cout << "N de Servicos: " << Servicos.size() << "\n";
	for (size_t i = 0; i < Servicos.size(); i++)
		cout << Servicos[i]->getNome() << "\n";

	cout << "\n";
	cout << "N de Condominos: " << Condominos.size() << "\n";
	for (size_t i = 0; i < Condominos.size(); i++)
		cout << Condominos[i]->getNome() << "\n";

}

Condominio *Data::getCondominio(string nome)
{
	for (size_t i = 0; i < Condominios.size(); i++)
	{
		if (nome == Condominios[i]->getNome())
			return Condominios[i];
	}
	return NULL;
}

void Data::remCondominio(string nome) 
{
	for (size_t i = 0; i < Condominios.size(); i++)
	{
		if (nome == Condominios[i]->getNome())
		{
			Condominios.erase(Condominios.begin() + i);
			return;
		}
	}
	throw ValorInvalido();
}

void Data::remServico(string nome)
{
	for (size_t i = 0; i < Servicos.size(); i++)
	{
		if (nome == Servicos[i]->getNome())
		{
			Servicos.erase(Servicos.begin() + i);
			return;
		}
	}
	throw ValorInvalido();
}

void Data::addCond(string nome)
{
	for (int i = 0; i < Condominios.size(); i++)
	{
		if (Condominios[i]->getNome() == nome)
			throw ValorInvalido();
	}


	Condominios.push_back(new Condominio(nome));
}


//limpa o ecra estava a dar erro de multiplo include e nao estava a conseguir por a funcioanr ...
void clrscr2() {
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
bool verificaOPi(string opcao)
{
	if ((opcao != "0") && (opcao != "1") && (opcao != "2") && (opcao != "3") && (opcao != "4") && (opcao != "5") && (opcao != "6") && (opcao != "7") && (opcao != "8"))
	{
		return true;
	}
	else return false;
}
bool verificaHab(string opcao)
{
	if ((opcao != "1") && (opcao != "2"))
	{
		return true;
	}
	else return false;
}
bool verificaTip(string opcao)
{
	if ((opcao != "T0") && (opcao != "T1") && (opcao != "T2") && (opcao != "T3") && (opcao != "T4") && (opcao != "T5") && (opcao != "T6") && (opcao != "T7") && (opcao != "T8") && (opcao != "T9") && (opcao != "T10"))
	{
		return true;
	}
	else return false;
}
bool verificaOp2(string opcao)
{
	if ((opcao != "0") && (opcao != "1") && (opcao != "2") && (opcao != "3") && (opcao != "4"))
	{
		return true;
	}
	else return false;
}

bool Data::run()
{
	/*
	antigo testes sem o menu


	//Inicial
	info();

	Condominio * Condaux;
	Condaux = getCondominio("cd1");

	cout << "\n\n";
	Condaux->info(); //XXX
	//---------------------------------
	
	//Calcula as mensalidades com base nos atributos
	vector <Habitacao*> habitacoes;
	habitacoes=Condaux->getHabitacoes();

	for (size_t i = 0; i < habitacoes.size(); i++)
		habitacoes[i]->calcMensalidade();

	Condaux->info(); //XXX
	//---------------------------------

	//Aderir a servicos
	vector <Servico *> ServicosCond;
	ServicosCond = Condaux->getServicos();

	habitacoes[0]->addServico(ServicosCond[0]);
	Condaux->info(); //XXX
	//---------------------------------

	//Terminar servicos
	habitacoes[0]->removeServico(ServicosCond[0]);

	Condaux->info(); //XXX
	//---------------------------------
	
	//Adicionar habitacoes
	Habitacao *hab;
	Condomino *c = new Condomino("ze", 133756904);

	hab = new Apartamento("rua aqui perto", 281, 1000, "T10", 100);
	hab->addCondomino(c);
	hab->calcMensalidade();
	Condaux->addHabitacao(hab);
	
	Condaux->info(); //XXX
	//---------------------------------

	//Adicionar servicos
	Servico *s = new Servico("eletricista", 2);

	Condaux->addServico(s);

	Condaux->info(); //XXX
	//---------------------------------

	*/
	
	string nome;
	cout << "Insira o nome do Condominio: ";
	cin >> nome;

	Condominio * Condaux;
	Condaux = getCondominio(nome);


	clrscr2();

	string opcao;

	cout << "1: Ver info sobre Condominio \n";
	cout << "2: Ver info sobre Servicos do Condominio \n";
	cout << "3: Adicionar Habitacao \n";
	cout << "4: Remover Habitacao \n";
	cout << "5: Modificar Habitacao \n";
	cout << "6: Adicionar Servico \n";
	cout << "7: Remover Servico \n";
	cout << "8: Modificar Servicos \n";
	cout << "0: Voltar...\n";
	cin >> opcao;

	//verificação
	while (verificaOPi(opcao))
	{
		cout << "\n Opcao invalida! Introduza uma opcao valida: " << endl;
		cin.ignore();
		cin >> opcao;
	}
	//////////////

	if (opcao == "0")
		return true;
	else if (opcao == "1")
	{
		Condaux->verHab();
		cin.get();	//para conseguir ver
	}
	else if (opcao == "2")
	{
		Condaux->verSerCond();
		cin.get(); //para conseguir ver
	}
	else if (opcao == "3")
	{ 
		try{
		////inicio opcao3///////////////////////////////////////////
		clrscr2();
		cout << "Vivenda: 1 \n";
		cout << "Apartamento: 2 \n";
		string op, n;
		unsigned int nif;
		cin >> op;

		//verificação
		while (verificaHab(op))
		{
			cout << "\n Opcao invalida! Introduza uma opcao valida: " << endl;
			cin.ignore();
			cin >> op;
		}
		/////////////

		Habitacao *hab;
		Condomino *c;
		if (op == "1")
		{
			////subopcao 1///////////////////////////////
			cout << "Nome do condomino: ";
			cin.ignore();
			getline(cin,n);
			cout << "NIF: ";
			cin >> nif;

			string m, r;
			unsigned int aH, aE;
			bool p;
			float men;


			c= new Condomino(n, nif);
			clrscr2();
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
			Condaux->addHabitacao(hab);
			////FIM subopcao 1///////////////////////////////
		}
		else if (op == "2")
		{
			////subopcao 2///////////////////////////////
			cout << "Nome do condomino: ";
			cin.ignore(); //por causa dos cin>> anteriores e  o getline a seguir
			getline(cin,n);
			cout << "NIF: ";
			cin >> nif;

			string m, t;
			unsigned int aH;
			int p;
			float men;


			c = new Condomino(n, nif);
			clrscr2();
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
			while (verificaTip(t))
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
			Condaux->addHabitacao(hab);
			////FIM subopcao 2///////////////////////////////
		}
		}
		catch (ValorInvalido &e)
		{		cout << "\n erro opcao 2-3 \n";	}
		/////fim opcao 3//////////////////////////////////////////////////////////////////////////
		Condaux->verHab();
		cin.get();	//para conseguir ver ja que o save() ou o inicialize() nao funciona totalmente bem
	}
	else if (opcao == "4")
	{
		unsigned int nif;
		clrscr2();
		Condaux->verHab();
		cout << "\n\n";
		cout << "Insira o nif do condomino a que a habitacao pertence: ";
		cin >> nif;
		try{
			Condaux->remHab(nif);
		}
		catch (ValorInvalido &e)
		{
			cout << "\n erro opcao 2-4\n";
		}
		cout << "\n\n\n";
		/////////////////////////////////
		Condaux->verHab();
		cin.get();	//para conseguir ver ja que o save() ou o inicialize() nao funciona totalmente bem
	}
	else if (opcao == "5")
	{
		//selecionar a habitação
		unsigned int nif;
		string n;
		clrscr2();
		Condaux->verHab();

		cout << "\n\n Nome do Condomino: ";
		cin.ignore();//por causa dos cin>> anteriores e  o getline a seguir
		getline(cin, n);
		cout << "NIF: ";
		cin >> nif;

		Habitacao *hab;
		Condomino *c = new Condomino(n, nif);
		try{
			hab = Condaux->getHabitacao(c);
			delete c; //porque nao precisamos mais dele

			//as modificações
			clrscr2();
			//Pode-se por mais, não sei bem se os professores querem exemplos, ou mesmo poder alterar já tudo
			string op;
			float men;
			unsigned int area;

			cout << "1: Modificar Mensalidade\n";
			cout << "2: Modificar A Habitacional\n";
			cout << "3: Aderir a Servico \n";
			cout << "4: Terminar Servico \n";
			cout << "0: Voltar...\n";
			cin >> op;
			//verificacao
			while (verificaOp2(op))
			{
				cout << "\n Opcao invalida! Introduza uma opcao valida: " << endl;
				cin.ignore();
				cin >> op;
			}

			//////////////////////////
			if (op == "0")
				return true;
			else if (op == "1")
			{
				cout << "Valor: ";
				cin >> men;
				hab->modificaMensalidade(men);
			}
			else if (op == "2")
			{
				cout << "Valor: ";
				cin >> area;
				hab->modificaArea_Habitacional(area);
			}
			else if (op == "3")
			{
				int numS;
				clrscr2();
				Condaux->verSerCond();

				cout << "\n Insira o n do Servico a aderir (0...n)";
				cin >> numS;

				hab->addServico(Condaux->getServ(Servicos[numS]->getNome()));

			}
			else if (op == "4")
			{
				int numS;
				clrscr2();
				hab->verServicosAderidos();

				cout << "\n Insira o n do Servico a terminar (0...n)";
				cin >> numS;

				hab->removeServico( Condaux->getServ(Servicos[numS]->getNome()) );

			}

		}
		catch (ValorInvalido &e)
		{
			cout << "\n erro opcao 2-5 \n";
		}
		////////////////////////////////////////
		Condaux->verHab();
		cin.get();	//para conseguir ver ja que o save() ou o inicialize() nao funciona totalmente bem
		////////////////////////////////////////////
	}
	else if (opcao == "6")
	{
		Condaux->verSerCond();
		cout << "\n\n";


		string nm;
		unsigned int n;
		cout << "Nome do Servico: ";
		cin >> nm;
		cout << "N prestadores de Servico: ";
		cin >> n;
		Servico *s = new Servico(nm, n);
		try{
			Condaux->addServico(s);
		} catch (ValorInvalido &e)
		{
			cout << "\n erro opcao 2-6";
		}


		/////////////////////////////////
		Condaux->verSerCond();
		cin.get(); //para conseguir ver
		///////////////////////////////

	}
	else if (opcao == "7")
	{
		Condaux->verSerCond();
		cout << "\n\n";

		string nm;
		cout << "Nome do Servico: ";
		cin >> nm;

		try{
			Condaux->remServico(nm);
		}
		catch (ValorInvalido &e)
		{cout << "\n erro opcao 2-7";	}

		/////////////////////////////////
		Condaux->verSerCond();
		cin.get(); //para conseguir ver
		///////////////////////////////


	}
	else if (opcao == "8")
	{
		Condaux->verSerCond();
		cout << "\n\n";

		Servico *s;
		string nm;
		unsigned int num;
		cout << "Nome Servico:";
		cin >> nm;
		try{
			s = Condaux->getServ(nm);
		
		cout << "Novo nome: ";
		cin >> nm;
		s->modificaNome(nm);
		cout << "Num Prestadores de servico: ";
		cin >>num;
		s->modificaNPS(num);
		}
		catch (ValorInvalido &e)
		{
			cout <<"\n erro 2-8\n";
		}


		/////////////////////////////////
		Condaux->verSerCond();
		cin.get(); //para conseguir ver
		///////////////////////////////
	}
	//save();
	
	return true;
}

