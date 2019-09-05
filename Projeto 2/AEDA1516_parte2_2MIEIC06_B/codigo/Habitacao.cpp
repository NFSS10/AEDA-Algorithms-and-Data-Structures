#include "Habitacao.h"

Habitacao::Habitacao(string morada, unsigned int area_hab, float mensalidade) : Morada(morada), Area_Habitacional(area_hab), Mensalidade(mensalidade)
{}

void Habitacao::addCondomino(Condomino * cond)
{
	condomino = cond;
}

void Habitacao::addServico(Servico * ser)
{
	if (ser->getNumPrestServ() == 0)          // se numero de prestadores de serviço for 0;
	{
		cout << "Num prest Sevicos == 0";
		throw ValorInvalido();
	}
	for (int i = 0; i < getServicos().size(); i++)
	{
		if(getServicos()[i]->getNome()==ser->getNome())        //se já houver um serviço com o mesmo nome;
		throw ValorInvalido();
	}
	ser->decNserv();
	servico.push_back(ser);
}

void Habitacao::modificaMensalidade(float mensalidade)
{
	if (mensalidade < 0)
	{
		throw ValorInvalido();           //se mensalidade for negativa;
	}
	Mensalidade = mensalidade;
}

string Habitacao::getMorada()
{
	return Morada;
}

unsigned int Habitacao::getA_Habitacional()
{ 
	return Area_Habitacional;
}

float Habitacao::getMensalidade()
{
	return Mensalidade;
}

Condomino *Habitacao::getCondomino()
{
	return condomino;
}

vector<Servico *> Habitacao::getServicos()
{
	return servico;
}

void Habitacao::modificaMorada(string morada)
{
	Morada = morada;
}

void Habitacao::modificaArea_Habitacional(unsigned int areaHab)
{
	Area_Habitacional = areaHab;
}

void Habitacao::removeServico(Servico * ser)
{
	for (size_t i = 0; i < servico.size(); i++)
	{
		if (servico[i]->getNome() == ser->getNome())
		{
			servico.erase(servico.begin() + i);
			ser->addNserv();
			return;
		}
	}
	cout << "\n NAO ENCONTROU O SERVICO PARA ELIMINAR \n";
	throw ValorInvalido();  //se nao existir o serviço em servico;
	return;

}




void Habitacao::ordenaServicosNome()
{
	sort(servico.begin(), servico.end());  //ordena serviços por nome;
	return;
}


void Habitacao::verServicosAderidos()
{
	ordenaServicosNome();

	for (size_t i = 0; i < servico.size(); i++)
	{
		cout << servico[i]->getNome() << ",  ";
	}
}