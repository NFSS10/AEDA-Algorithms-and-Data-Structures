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
	string res = "";

	res = res + "vivenda";
	res = res + " ";
	//Habitacao geral------------------------------------
	res = res + to_string(getA_Habitacional());
	res = res + " ";
	res = res + to_string(getMensalidade());
	res = res + " ";

	//condomino
	res = res + getCondomino()->getNome();
	res = res + " ";
	res = res + to_string(getCondomino()->getNif());
	res = res + " ";
	//----------------------------------------------------
	//vivenda
	res = res + to_string(Area_Exterior);
	res = res + " ";
	res = res + to_string(Piscina);
	res = res + " ";

	//rua--------------------------------
	res = res + "\n";

	res = res + getMorada();
	res = res + "\n";
	//-------------------------------------

	//Servicos---------------------------------------------
	res = res + "serv: ";
	for (size_t i = 0; i < getServicos().size(); i++)
	{
		res = res + getServicos()[i]->getNome(); //nome nome2 nome3 nome4
		res = res + " ";
	}
	//---------------------------------------------
	//nomecondominio / vivenda info
	//rua
	//servicos


	return res;
}
