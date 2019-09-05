#include "Data.h"
#include <fstream> 
#include <sstream>

#include <iostream>
#include <Windows.h>

#include <sstream>

using namespace std;


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


void Data::pointerToCond()
{
	BSTItrIn<Condominio*> it(arvCondominios);
	arvore.makeEmpty();
	while (!it.isAtEnd())
	{
		arvore.insert(*it.retrieve());
		it.advance();
	}
}
void Data::info()
{
	int x;
	pointerToCond();
	BSTItrIn<Condominio> it(arvore);
	cout << "N de Condominios: " << Condominios.size() << "\n";
	while (!it.isAtEnd())
	{
		cout << it.retrieve().getNome() << "  ->Localizacao: " << it.retrieve().getLocalizacao() << "  ->N.Habitacoes: " << it.retrieve().getNumHab() << endl;
		it.advance();
	}
	
	cout << "\n";
	cout << "N de Servicos: " << Servicos.size() << "\n";
	for (size_t i = 0; i < Servicos.size(); i++)
		cout << Servicos[i]->getNome() << "\n";

	cout << "\n";
	/*cout << "N de Condominos: " << Condominos.size() << "\n";
	for (size_t i = 0; i < Condominos.size(); i++)
		cout << Condominos[i]->getNome() << "\n";

	/*cout << "x :" << endl;
	cin >> x;
	for (int i = 0; i < condXHab(x).size(); i++)
	{
		cout << condXHab(x)[i].getNome() << "  ->Localizacao: " << condXHab(x)[i].getLocalizacao() << "  ->N.Habitacoes: " << condXHab(x)[i].getNumHab() << endl;
	}
	cin.get();*/
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
			arvCondominios.remove(Condominios[i]);
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

void Data::addCond(string nome, string localizacao)
{
	for (int i = 0; i < Condominios.size(); i++)
	{
		if (Condominios[i]->getNome() == nome)
			throw ValorInvalido();
	}


	Condominios.push_back(new Condominio(nome,localizacao));
	arvCondominios.insert(Condominios[Condominios.size() - 1]);

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
/*
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
*/

void Data::inicialize()
{
	//condominios
	
	ifstream ficheiro;

	string CondN, CondL;
	string dummy;

	ficheiro.open("Condominios.txt");
	//Verifica se abriu corretamente
	if (ficheiro.fail())
	{
		cout << "Erro a abrir o ficheiro \n";
		exit(1);
	}

	while (!ficheiro.eof())
	{
		ficheiro >> CondN >> dummy >> CondL;
		addCond(CondN, CondL);
	}

	ficheiro.close();

	//___________________________________________________________
	//servicos
	
	ifstream fSer;

	string SerN;
	string SerCond;
	unsigned int nSer;

	fSer.open("Servicos.txt");
	//Verifica se abriu corretamente
	if (fSer.fail())
	{
		cout << "Erro a abrir o ficheiro \n";
		exit(1);
	}

	while (!fSer.eof())
	{
		fSer >> SerCond >> dummy; // nome de condominio
		while((SerN != "xxxxx") && (!fSer.eof()))
		{
			fSer >> SerN; //um nome e um numero
			if (SerN == "xxxxx")
				break;
			fSer >> nSer;

			Servico* s = new Servico(SerN, nSer);
			Servicos.push_back(s);
			Servico servico(SerN, nSer);
			getCondominio(SerCond)->addServico_Cond(servico);
			getCondominio(SerCond)->addServico(s);
		}
		SerN = "aa";
	}

	fSer.close();
	
	//____________________________________________________________
	//Transportes

	ifstream fT;
	string Tcond;
	string tipo, pparagem, destino;
	unsigned int distancia;
	bool estado;

	
	fT.open("Transportes.txt");
	//Verifica se abriu corretamente
	if (fT.fail())
	{
		cout << "Erro a abrir o ficheiro \n";
		exit(1);
	}

	while (!fT.eof())
	{
		fT >> Tcond >> dummy; // nome de condominio
		while ((tipo != "xxxxx") && (!fT.eof()))
		{
			fT >> tipo; //tipo ou xxxxx caso nao tenha algum
			if (tipo == "xxxxx")
				break;
			fT >> pparagem >> destino >> distancia >> estado;

			Transporte aux(tipo, destino, pparagem, distancia, estado);
			getCondominio(Tcond)->addTransporte(aux);
		}
		tipo = "aa";
	}

	fT.close();

	//____________________________________________________________
	//Habitacoes
	
	ifstream fH;
	string CondN_H, tipo_H;
	unsigned int A_h;
	float mens;
	string nomeCondomino;
	unsigned int niff;
	string rua;
	string servicos;

	//vivenda
	unsigned int A_E;
	bool piscina;

	//apartamento
	string tipologia;
	int piso;

	bool fazer;
	fazer = true;

	fH.open("Habitacoes.txt");
	//Verifica se abriu corretamente
	if (fH.fail())
	{
		cout << "Erro a abrir o ficheiro \n";
		exit(1);
	}

	while (!fH.eof())
	{

		fH >> CondN_H >> dummy; // nome de condominio
		
		while ((CondN_H != "xxxxx") && (!fH.eof()))
		{
			if (fazer)
				fH >> tipo_H;

			if (tipo_H == "xxxxx")
				break;
			if (tipo_H.empty())
				break;

			if (tipo_H == "vivenda")
			{
				fH >> A_h >> mens >> nomeCondomino >> niff >> A_E >> piscina;
				getline(fH, dummy);
				getline(fH, rua);
				getline(fH, servicos);


				//teste
				//cout << CondN_H << " " << A_h << " " << mens << " " << nomeCondomino << " " << nif << " " << A_E << " " << piscina << "\n";
				//cout << rua << "\n";
				//cout << servicos <<"\n";
				//cout << "\n";
				///

				//adiciona habitacao
				Habitacao *hab;
				Condomino *c;
				c = new Condomino(nomeCondomino, niff);
				hab = new Vivenda(rua, A_h, mens, A_E, piscina);

				hab->addCondomino(c);
				//adiciona servicos
				stringstream ss;
				string nomeServ;
				ss << servicos;
				ss >> dummy;
				while (ss >> nomeServ)
					hab->addServico(getCondominio(CondN_H)->getServ(nomeServ));

				//------------------------------------------------------
				getCondominio(CondN_H)->addHabitacao(hab);


				fH >> tipo_H;
				if (tipo_H == "xxxxx")
				{
					fazer = true;
					break;
				}
				fazer = false;
			}
		//________________________________________________________
			if (tipo_H == "apartamento")
			{
				fH >> A_h >> mens >> nomeCondomino >> niff >> tipologia >> piso;
				getline(fH, dummy);
				getline(fH, rua);
				getline(fH, servicos);
				

				//teste
				//cout << CondN_H << " " << A_h << " " << mens << " " << nomeCondomino << " " << nif << " " << tipologia << " " << piso << "\n";
				//cout << rua << "\n";
				//cout << servicos << "\n";
				//cout << "\n";
				///
				//adiciona habitacao
				Habitacao *hab;
				Condomino *c;
				c = new Condomino(nomeCondomino, niff);
				hab = new Apartamento(rua, A_h, mens, tipologia, piso);

				hab->addCondomino(c);
				//adiciona servicos
				stringstream ss;
				string nomeServ;
				ss << servicos;
				ss >> dummy;
				while (ss >> nomeServ)
					hab->addServico(getCondominio(CondN_H)->getServ(nomeServ));

				//------------------------------------------------------
				getCondominio(CondN_H)->addHabitacao(hab);
				

				fH >> tipo_H;
				if (tipo_H == "xxxxx")
				{
					fazer = true;
					break;
				}
				fazer = false;
			}

		}
		tipo_H = "aa";
	}

	fH.close();
	

	//_____________________________________________________________

}

void Data::savecond()
{
	ofstream ficheiro;
	ficheiro.open("Condominios.txt");

	//Verifica se abriu corretamente
	if (ficheiro.fail())
	{
		cout << "Erro a abrir o ficheiro \n";
		exit(1);
	}

	for (size_t i = 0; i < Condominios.size(); i++)
	{
		if (i == 0)//primeiro
			ficheiro << Condominios[i]->getNome() << " / " <<Condominios[i]->getLocalizacao();

		if (i>0)//resto
			ficheiro << "\n" << Condominios[i]->getNome() << " / " << Condominios[i]->getLocalizacao();

	}

	ficheiro.close();
}

void Data::saveServicos()
{
	ofstream ficheiro;
	ficheiro.open("Servicos.txt");

	//Verifica se abriu corretamente
	if (ficheiro.fail())
	{
		cout << "Erro a abrir o ficheiro \n";
		exit(1);
	}

	for (size_t i = 0; i < Condominios.size(); i++)
	{
		if (i == 0)//primeiro
			ficheiro << Condominios[i]->getNome() << " / " << Condominios[i]->saveServicos();

		if (i>0)//resto
			ficheiro << "\n" << Condominios[i]->getNome() << " / " << Condominios[i]->saveServicos();

	}

	ficheiro.close();
}


void Data::saveTransportes()
{
	ofstream ficheiro;
	ficheiro.open("Transportes.txt");

	//Verifica se abriu corretamente
	if (ficheiro.fail())
	{
		cout << "Erro a abrir o ficheiro \n";
		exit(1);
	}

	for (size_t i = 0; i < Condominios.size(); i++)
	{
		if (i == 0)//primeiro
			ficheiro << Condominios[i]->getNome() << " / " << Condominios[i]->saveTransportes();

		if (i>0)//resto
			ficheiro << "\n" << Condominios[i]->getNome() << " / " << Condominios[i]->saveTransportes();

	}

	ficheiro.close();
}


void Data::saveHabitacoes()
{
	ofstream ficheiro;
	ficheiro.open("Habitacoes.txt");

	//Verifica se abriu corretamente
	if (ficheiro.fail())
	{
		cout << "Erro a abrir o ficheiro \n";
		exit(1);
	}

	for (size_t i = 0; i < Condominios.size(); i++)
	{
		if (i == 0)//primeiro
			ficheiro << Condominios[i]->getNome() << " / " << Condominios[i]->saveHabitacoes() << "\n"<<"xxxxx";

		if (i>0)//resto
			ficheiro << "\n" << Condominios[i]->getNome() << " / " << Condominios[i]->saveHabitacoes() <<"\n"<< "xxxxx";

	}

	ficheiro.close();
}



vector<Condominio*> Data::ordenaHabitacao()
{

	vector<Condominio*> res;

	BSTItrLevel<Condominio*> it(arvCondominios);

	while (!it.isAtEnd())
	{
		res.push_back(it.retrieve());
		it.advance();
	}

	return res;
}

void Data::refresharv()
{
	BST<Condominio*> res(new Condominio("", ""));
	BSTItrLevel<Condominio*> it(arvCondominios);
	while (!it.isAtEnd())
	{
		res.insert(it.retrieve());
		it.advance();
	}
	arvCondominios = res;
}

void Data::addCondArv(Condominio *cond)
{
		arvCondominios.insert(cond);
}
void Data::remCondArv(Condominio *cond)
{
		arvCondominios.remove(cond);
}


void Data::remCondominioArv(string nome)
{
		for (size_t i = 0; i < Condominios.size(); i++)
		{
			if (nome == Condominios[i]->getNome())
				{
						remCondArv(Condominios[i]);
						Condominios.erase(Condominios.begin() + i);
						return;
				}
		}
		throw ValorInvalido();
}

BST<Condominio*> Data::getArvCondominios()
{
		return arvCondominios;
}



void Data::addCondArv(string nome, string localizacao)
{
	for (int i = 0; i < Condominios.size(); i++)
	{
		if (Condominios[i]->getNome() == nome)
			throw ValorInvalido();
	}


	Condominios.push_back(new Condominio(nome, localizacao));
	addCondArv(Condominios[Condominios.size() - 1]);

}

//=====================
vector<Condominio> Data::condXHab(int x)
{
	vector<Condominio> res;
	BSTItrIn<Condominio> it(arvore);
	while (!it.isAtEnd())
	{
		if (it.retrieve().getNumHab() == x)
		{
			res.push_back(it.retrieve());
		}
		it.advance();
	}
	return res;
}

vector<Condominio> Data::condEntreHab(int x, int y)
{
	vector<Condominio> res;
	BSTItrIn<Condominio> it(arvore);
	while (!it.isAtEnd())
	{
		if (it.retrieve().getNumHab() >= x && it.retrieve().getNumHab() <= x)
		{
			res.push_back(it.retrieve());
		}
		it.advance();
	}
	return res;
}
vector<Condominio> Data::condLocal(string local)
{
	vector<Condominio> res;
	BSTItrIn<Condominio> it(arvore);
	while (!it.isAtEnd())
	{
		if (it.retrieve().getLocalizacao()==local)
		{
			res.push_back(it.retrieve());
		}
		it.advance();
	}
	return res;
}
vector<Condominio> Data::condXVivendas(int x)
{
	vector<Condominio> res;
	BSTItrIn<Condominio> it(arvore);
	while (!it.isAtEnd())
	{
		if (it.retrieve().getNumVivendas()==x)
		{
			res.push_back(it.retrieve());
		}
		it.advance();
	}
	return res;
}
vector<Condominio> Data::condXApartamentos(int x)
{
	vector<Condominio> res;
	BSTItrIn<Condominio> it(arvore);
	while (!it.isAtEnd())
	{
		if (it.retrieve().getNumHab() - it.retrieve().getNumVivendas() == x)
		{
			res.push_back(it.retrieve());
		}
		it.advance();
	}
	return res;
}
Condominio Data::condNome(string Nome)
{
	BSTItrIn<Condominio> it(arvore);
	while (!it.isAtEnd())
	{
		if (it.retrieve().getNome()==Nome)
		{
			return it.retrieve();
		}
		it.advance();
	}

}