#include "Apartamento.h"
#include <iostream>

Apartamento::Apartamento(string morada, unsigned int area_hab, float mensalidade, string tipo, int piso) :Tipologia(tipo), Piso(piso), Habitacao(morada, area_hab, mensalidade)
{}

void Apartamento::info()
{
	vector<Servico *> servicos;
	servicos = getServicos();

	cout << "-------Apartamento-------\n";
	cout << "Propriet�rio: " << getCondomino()->getNome() << "   NIF: " << getCondomino()->getNif() << "\n";
	cout << "Morada: " << getMorada() << "\n";
	cout << "Area Habitacional: " << getA_Habitacional() << "\n";
	cout << "Tipo: " << getTipologia() << "   Piso: " << getPiso()<<"\n";
	cout << "Mensalidade: " << getMensalidade() << "\n";
	cout << "Servicos: \n   ";
	for (int i = 0; i < servicos.size(); i++)
		cout << servicos[i]->getNome() << "   N Prestadores de servico: " << servicos[i]->getNumPrestServ() << "\n   ";
}

void Apartamento::calcMensalidade()
{
	float modificador = 1, aux, mensa;
	int piso = getPiso();
	string tipo = getTipologia();
	
	if (tipo == "T0")
		modificador -= 0.2;
	else if (tipo == "T1")
		modificador += 0;
	else if (tipo == "T2")
		modificador += 0.2;
	else if (tipo == "T3")
		modificador += 0.4;
	else if (tipo == "T4")
		modificador += 0.6;
	else if (tipo == "T5")
		modificador += 1;
	else if (tipo == "T6")
		modificador += 1.3;
	else if (tipo == "T7")
		modificador += 1.6;
	else if (tipo == "T8")
		modificador += 1.9;
	else if (tipo == "T9")
		modificador += 2.3;
	else if (tipo == "T10")
		modificador += 2.5;

	aux = getA_Habitacional() / 10;
	modificador += aux*0.1;

	aux = piso*0.02;
	modificador += aux;

	mensa = getMensalidade();
	mensa = mensa*modificador;

	modificaMensalidade(mensa);
}

string Apartamento::getTipologia()
{
	return Tipologia;
}

int Apartamento::getPiso()
{
	return Piso;
}

void Apartamento::modificaTipologia(string tipo)
{
	Tipologia = tipo;
}

void Apartamento::modificaPiso(int piso)
{
	Piso = piso;
}

string Apartamento::save()
{
	string aux;
	for (size_t i = 0; i < this->getServicos().size(); i++)
	{
		if (i == this->getServicos().size() - 1)
			aux += to_string(this->getServicos()[i]->getId());
		else aux = aux + to_string(this->getServicos()[i]->getId()) + ",";
	}
	return "0," + this->getMorada() + "," + to_string(this->getA_Habitacional()) + "," + to_string(this->getMensalidade()) + "," + this->getTipologia() + "," + to_string(this->getPiso()) + "," + to_string(this->getCondomino()->getNif()) + "," + aux;
}



