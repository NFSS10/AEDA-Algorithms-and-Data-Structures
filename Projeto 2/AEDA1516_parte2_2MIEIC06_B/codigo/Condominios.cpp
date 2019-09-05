#include "Condominios.h"

#include <iostream>

using namespace std;

Condominio::Condominio(string nome) :Nome(nome), num_hab(0), num_vivendas(0)
{}
Condominio::Condominio(string nome, string localizacao) : Nome(nome), Localizacao(localizacao), num_hab(0), num_vivendas(0)
{}

void Condominio::addHabitacao(Habitacao *hab)
{
	if (hab->getCondomino() == NULL) //se nao tiver condominio;
	{
		throw ValorInvalido();
	}
	Habitacoes.push_back(hab);
	num_hab++;
	if (dynamic_cast<Vivenda*>(hab) != NULL)
	{
		num_vivendas++;
	}
}

void Condominio::addServico(Servico * ser)
{
	for (int i = 0; i < Servico_Condominio.size(); i++)
	{
		if (Servico_Condominio[i]->getNome() == ser->getNome()) //servico com o mesmo nome(ja existente);
			Servico_Condominio[i]->modificaNPS(Servico_Condominio[i]->getNumPrestServ() + ser->getNumPrestServ());
	}
	Servico_Condominio.push_back(ser);
}

void Condominio::modificaNome(string nome)
{
	Nome = nome;
}

void Condominio::info()
{
	cout << "__________  Condominio __________\n";
	cout << "Nome: " << Nome <<"\n";
	cout << "Habitacoes: \n";
	for (size_t i = 0; i < Habitacoes.size(); i++)
	{
		Habitacoes[i]->info();
		cout << "\n";
	}
	cout << "\n Servicos do Condominio: \n";
	for (size_t i = 0; i < Servico_Condominio.size(); i++)
	{
		cout << Servico_Condominio[i]->getNome() << ", " << Servico_Condominio[i]->getNumPrestServ() << "\n";
	}

	cout << "________________________________ \n";
}

string Condominio::getNome()
{
	return Nome;
}

Habitacao *Condominio::getHabitacao(Condomino *cond)
{
	for (size_t i = 0; i < Habitacoes.size(); i++)
		if ((Habitacoes[i]->getCondomino()->getNome() == cond->getNome()) && (Habitacoes[i]->getCondomino()->getNif() == cond->getNif()) )
			return Habitacoes[i];


	throw ValorInvalido();
	return NULL;
}

vector <Habitacao*> &Condominio::getHabitacoes()
{
	return Habitacoes;
}

vector <Servico *> &Condominio::getServicos()
{
	return Servico_Condominio;
}

bool ordhabarea(Habitacao* a, Habitacao* b)
{
	if (a->getA_Habitacional() < b->getA_Habitacional())
		return true;
	return false;
}

bool ordhabmorada(Habitacao* a, Habitacao* b)
{
	if (a->getMorada() < b->getMorada())
		return true;
	return false;
}

bool ordhabmensalidade(Habitacao* a, Habitacao* b)
{
	if (a->getMensalidade() < b->getMensalidade())
		return true;
	return false;
}

void Condominio::OrdenarHabArea() //ordena por area;
{
	sort(Habitacoes.begin(), Habitacoes.end(), ordhabarea);
	return;
}
void Condominio::OrdenarHabMorada() //ordena por morada
{
	sort(Habitacoes.begin(), Habitacoes.end(), ordhabmorada);
	return;
}
void Condominio::OrdenarHabMensalidade() //ordena por mensalidade
{
	sort(Habitacoes.begin(), Habitacoes.end(), ordhabmensalidade);
	return;
}
void Condominio::OrdenarServicoCondNome() //ordena sericos de condominio por nome;
{
	sort(Servico_Condominio.begin(), Servico_Condominio.end());
	return;
}
#include <windows.h>
void limpa()
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

void Condominio::verHab() //falta excepçao
{
	string op;
	cout << "Ordenadas por: \n";
	cout << "Area: 1 \n";
	cout << "Morada: 2 \n";
	cout << "Mensalidade: 3 \n";
	cin >> op;

	//excepção se nao for "1" "2" "3" "0"
	limpa();


	cout << "N de Habitacoes: " << num_hab << "\n";
	cout << "N de Vivendas: " << num_vivendas << "\n";
	cout << "\n";

	if (op == "0")
		return;
	else if (op == "1")
	{
		OrdenarHabArea();
		for (size_t i = 0; i < Habitacoes.size(); i++)
		{
			Habitacoes[i]->info();
			cout << "\n";
		}
	}
	else if (op == "2")
	{
		OrdenarHabMorada();
		for (size_t i = 0; i < Habitacoes.size(); i++)
		{
			Habitacoes[i]->info();
			cout << "\n";
		}
	}
	else if (op == "3")
	{
		OrdenarHabMensalidade();
		for (size_t i = 0; i < Habitacoes.size(); i++)
		{
			Habitacoes[i]->info();
			cout << "\n";
		}
	}
	else
		throw ValorInvalido();
}

void Condominio::verSerCond()
{
	OrdenarServicoCondNome();
	for (size_t i = 0; i < Servico_Condominio.size(); i++)
	{
		cout << " " << Servico_Condominio[i]->getNome() << ", N " << Servico_Condominio[i]->getNumPrestServ()<<"  ";
	}
}

void Condominio::remServico(string nome) //falta excepção
{
	for (size_t i = 0; i < Servico_Condominio.size(); i++)
	{
		if (Servico_Condominio[i]->getNome() == nome)
		{
			Servico_Condominio.erase(Servico_Condominio.begin() + i);
			return;
		}
	}
	throw ValorInvalido();
	return;
}

void Condominio::remHab(unsigned int nif) // falta excepção
{
	//vector <Habitacao*> hab;
	//hab = getHabitacoes();
	

	for (size_t i = 0; i < Habitacoes.size(); i++)
	{
		if (Habitacoes[i]->getCondomino()->getNif() == nif)
		{
			if (dynamic_cast<Vivenda*>(Habitacoes[i]) != NULL)
			{
				num_vivendas--;
			}
			Habitacoes.erase(Habitacoes.begin() + i);
			num_hab--;
		
			return;
		}
	}
	throw ValorInvalido();
	return;

}

Servico* Condominio::getServ(string nome)
{
	for (size_t i = 0; i < Servico_Condominio.size(); i++)
		if (Servico_Condominio[i]->getNome() == nome)
			return Servico_Condominio[i];
	
	throw ValorInvalido();
	return NULL;
}



//_________________________________________________________________________________________________________________________________________________________
//_________________________________________________________________________________________________________________________________________________________




void Condominio::addServico_Cond(Servico &servico)
{
	hashServicos::iterator it;
	pair<hashServicos::iterator, bool> res;

	res = Servicos_Cond.insert(servico);

	//nao inseriu, existia, logo add mais 1 ao nprestadores servico. 
	// se == true, entao nao existia, inseriu e termina
	if (res.second == false)
	{
		unsigned int n = 0;
		it = res.first;
		Servico saux = *it;
		Servicos_Cond.erase(it);

		n = saux.getNumPrestServ();// n servicos dos que ja estava inserido
		n = n + servico.getNumPrestServ(); //soma o do servico em colisao
		saux.modificaNPS(n); //n prestadores de servico atualizado
		Servicos_Cond.insert(saux);

	}

}
void Condominio::procurarServicos(string nomeServico)
{
	hashServicos::iterator it;
	it = Servicos_Cond.begin();

	while (it != Servicos_Cond.end())
	{
		//encontrou
		if (it->getNome() == nomeServico)
		{
			cout << "Encontrado. \n\n";
			cout << nomeServico << "\n";
			cout << "N prestadores de servico: " << it->getNumPrestServ();
			cout << "\n";

			return;
		}

		it++;
	}
	//nao encontrou
	cout << "Nao encontrou. \n\n";
}
void Condominio::listarServicos()
{
	hashServicos::iterator it;
	it = Servicos_Cond.begin();

	while (it != Servicos_Cond.end())
	{
		cout << it->getNome();
		cout << "\n";
		cout << "N prestadores de servico: " << it->getNumPrestServ();
		cout << "\n\n";

		it++;
	}

}

void Condominio::remServico_Cond(string nomeServico)
{

	hashServicos::iterator it;
	it = Servicos_Cond.begin();

	while (it != Servicos_Cond.end())
	{
		//encontrou
		if (it->getNome() == nomeServico)
		{
			Servicos_Cond.erase(it);
			return;
		}

		it++;
	}
	//nao encontrou

}


string Condominio::saveServicos()
{
	string res="";
	hashServicos::iterator it;
	it = Servicos_Cond.begin();

	while (it != Servicos_Cond.end())
	{
		res = res + it->getNome();
		res = res + " ";
		res = res + to_string(it->getNumPrestServ());
		res = res + " ";

		it++;
	}
	res = res + "xxxxx";
	return res;
}




//_________________________________________________________________________________________________________________________________________________________
//_________________________________________________________________________________________________________________________________________________________





void Condominio::addTransporte(Transporte &transporte)
{
	TransportesPublicos.push(transporte);
}


string Condominio::getPontoParagemMaisProx()
{
	string res;
	priority_queue<Transporte> aux;

	aux = TransportesPublicos;

	while (!aux.empty())
	{
		if (aux.top().getEstado() == false) //destivado
		{
			aux.pop();
		}
		else //nao desativado
		{
			res = aux.top().getPontoParagem();
			return res; //e retorna
		}
	}
	// se esta aqui e porque nao tinha nenhum ponto de paragem ou estavam desativados

	res = "Nao ha pontos de paragem acessiveis. \n";

	return res;
}

string Condominio::getPontoParagemMaisProx(string dest)
{
	string res;
	priority_queue<Transporte> aux;

	aux = TransportesPublicos;

	while (!aux.empty())
	{
		if (aux.top().getEstado() == false) //destivado
		{
			aux.pop();
		}
		else //nao desativado
		{
			if (aux.top().getDestino() == dest)
			{
				res = aux.top().getPontoParagem();
				return res; //e retorna
			}
			aux.pop(); // nao tem o destino, por isso avança
		}
	}
	// se esta aqui e porque nao tinha nenhum ponto de paragem ou estavam desativados

	res = "Nao ha pontos de paragem acessiveis. \n";

	return res;

}


bool Condominio::remTransporte(string tipo)
{
	bool res = false;
	vector<Transporte> aux;

	while (!TransportesPublicos.empty())
	{
		aux.push_back(TransportesPublicos.top());

		TransportesPublicos.pop();
	}


	for (size_t i = 0; i < aux.size(); i++)
	{
		if (aux[i].getTipo() == tipo)
		{
			aux.erase(aux.begin() + i);
			res = true;
			i--;
		}
	}

	for (size_t i = 0; i < aux.size(); i++)
	{
		TransportesPublicos.push(aux[i]);
	}
	return res;
}


void Condominio::listarTransportes()
{
	priority_queue<Transporte> auxh;
	vector<Transporte> aux;

	auxh = TransportesPublicos;

	while (!auxh.empty())
	{
		aux.push_back(auxh.top());
		auxh.pop();
	}

	for (size_t i = 0; i < aux.size(); i++)
	{
		cout << "Tipo: " << aux[i].getTipo();
		cout << "\n";
		cout << "Ponto de Paragem: " << aux[i].getPontoParagem() << "   Distancia: " << aux[i].getDistancia() << "   Ativado ?: ";
		if (aux[i].getEstado() == true)
			cout << "Sim";
		else if (aux[i].getEstado() == false)
			cout << "Nao";

		cout << "\n";
		cout << "Destino: " << aux[i].getDestino();
		cout << "\n\n";
	}

}

void Condominio::toogle_Ativ_PontoParagem(string tipo)
{
	vector<Transporte> aux;

	while (!TransportesPublicos.empty())
	{
		aux.push_back(TransportesPublicos.top());

		TransportesPublicos.pop();
	}


	for (size_t i = 0; i < aux.size(); i++)
	{
		if (aux[i].getTipo() == tipo)
			aux[i].ativ_ou_desativ_PontoParagem();
	}

	for (size_t i = 0; i < aux.size(); i++)
	{
		TransportesPublicos.push(aux[i]);
	}
}

string Condominio::saveTransportes()
{
	string res = "";
	
	priority_queue<Transporte> auxh;
	vector<Transporte> aux;

	auxh = TransportesPublicos;

	while (!auxh.empty())
	{
		aux.push_back(auxh.top());
		auxh.pop();
	}

	for (size_t i = 0; i < aux.size(); i++)
	{
		res = res + aux[i].getTipo();
		res = res + " ";
		res = res + aux[i].getPontoParagem();
		res = res + " ";
		res = res + aux[i].getDestino();
		res = res + " ";
		res = res + to_string(aux[i].getDistancia());
		res = res + " ";
		res = res + to_string(aux[i].getEstado());
		res = res + " ";
	}


	res = res + "xxxxx";
	return res;
}


//======================================================================

int Condominio::getNumHab() const
{
	return num_hab;
}

int Condominio::getNumVivendas() const
{

		return num_vivendas;

}



bool Condominio::operator < (const Condominio &dir) const
{
	if (getNumHab() == dir.getNumHab())
	{
		return (getNumVivendas() <= dir.getNumVivendas());
	}
	return (getNumHab() < dir.getNumHab());
}


string Condominio::getLocalizacao() const
{
	return Localizacao;
}

string Condominio::saveHabitacoes()
{
	string res;
	res = "";
	for (size_t i = 0; i < Habitacoes.size(); i++)
	{
		if (i == 0)
			res = res + Habitacoes[i]->save();
		if (i > 0)
		{
			res = res + "\n";
			res = res + Habitacoes[i]->save();
		}
	}

	return res;
}











