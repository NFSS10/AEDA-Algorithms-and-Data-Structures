#include "Condominios.h"

#include <iostream>
using namespace std;

Condominio::Condominio(string nome) :Nome(nome)
{}

void Condominio::addHabitacao(Habitacao *hab)
{
	if (hab->getCondomino() == NULL) //se nao tiver condominio;
	{
		throw ValorInvalido();
	}
	Habitacoes.push_back(hab);
}

void Condominio::addServico(Servico * ser)
{
	for (int i = 0; i < Servico_Condominio.size(); i++)
	{
		if (Servico_Condominio[i]->getNome()==ser->getNome()) //servico com o mesmo nome(ja existente);
			throw ValorInvalido();
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


void Condominio::verHab() //falta excepçao
{
	string op;
	cout << "Ordenadas por: \n";
	cout << "Area: 1 \n";
	cout << "Morada: 2 \n";
	cout << "Mensalidade: 3 \n";
	cin >> op;

	//excepção se nao for "1" "2" "3" "0"
	
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
			Habitacoes.erase(Habitacoes.begin() + i);
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