#include "Vivenda.h"
#include "Servicos.h"
#include <iostream>

using namespace std;

Vivenda::Vivenda(string morada, unsigned int area_hab, float mensalidade, unsigned int area_ext, bool piscina) :Area_Exterior(area_ext),Piscina(piscina), Habitacao(morada, area_hab, mensalidade)
{}

unsigned int Vivenda::getAreaExterior()
{
	return Area_Exterior;
}

void Vivenda::adicionaPiscina()
{
	Piscina = true;
}

void Vivenda::removePiscina()
{
	Piscina = false;
}

void Vivenda::info()
{
	vector<Servico *> servicos;
	servicos = getServicos();

	cout << "-------Vivenda-------\n";
	cout << "Proprietario: " << getCondomino()->getNome() << "   NIF: " << getCondomino()->getNif() << "\n";
	cout << "Morada: " << getMorada() << "\n";
	cout << "Area Habitacional: " << getA_Habitacional() << "   Area Exterior: " << getAreaExterior() << "\n";
	cout << "Tem piscina ?: ";
	if (Piscina)
		cout << "Sim \n";
	else
		cout << "Nao \n";
	cout << "Mensalidade: " << getMensalidade() << "\n";
	cout << "Servicos: \n   ";
	for (int i = 0; i < servicos.size(); i++)
		cout << servicos[i]->getNome() << "   N Prestadores de servico: " << servicos[i]->getNumPrestServ() << "   \n";

}

void Vivenda::calcMensalidade()	//Coloquei desta forma, se acham que devia elevar mais o preco ou baixar digam
{
	float modificador = 1, aux, mensa;

	if (Piscina)
		modificador += 0.5;
	
	aux = Area_Exterior/10;
	modificador += aux*0.2;

	aux = getA_Habitacional() / 10;
	modificador += aux*0.1;

	mensa = getMensalidade();
	mensa = mensa*modificador;

	modificaMensalidade(mensa);
}

void Vivenda::modificaArea_Exterior(unsigned int areaExt)
{
	Area_Exterior = areaExt;
}

string Vivenda::save()
{
	string aux;
	for (size_t i = 0; i < this->getServicos().size(); i++)
	{
		if (this->getServicos().size() - 1 == i)
			aux += to_string(this->getServicos()[i]->getId());
		else aux = aux + to_string(this->getServicos()[i]->getId()) + ",";
	}
	string aux2;
	if (Piscina)
		aux2 = "1";
	else aux2 = "0";

	return "1," + this->getMorada() + "," + to_string(this->getA_Habitacional()) + "," + to_string(this->getMensalidade()) + "," + to_string(this->getAreaExterior()) + "," + aux2 + "," + to_string(this->getCondomino()->getNif()) + "," + aux;
}

