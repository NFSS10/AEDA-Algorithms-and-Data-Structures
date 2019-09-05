#include "Transporte.h"


Transporte::Transporte()
{
}


Transporte::~Transporte()
{
}


string Transporte::getTipo() const
{
	return Tipo;
}
string Transporte::getDestino() const
{
	return Destino;
}
string Transporte::getPontoParagem() const
{
	return PontoParagem;
}
unsigned int Transporte::getDistancia() const

{
	return dist_PontoParagem;
}
bool Transporte::getEstado() const
{
	return Estado;
}


Transporte::Transporte(string tipo, string destino, string ponto_paragem, unsigned int dist_ponto_paragem) :Tipo(tipo), Destino(destino), PontoParagem(ponto_paragem), dist_PontoParagem(dist_ponto_paragem), Estado(true)
{}

Transporte::Transporte(string tipo, string destino, string ponto_paragem, unsigned int dist_ponto_paragem, bool estado) : Tipo(tipo), Destino(destino), PontoParagem(ponto_paragem), dist_PontoParagem(dist_ponto_paragem), Estado(estado)
{}
bool Transporte::operator < (const Transporte & transporte) const
{
	return  dist_PontoParagem > transporte.getDistancia();
}

void Transporte::setPontoParagem(string novoPontoParagem)
{
	PontoParagem = novoPontoParagem;
}

void Transporte::setDestino(string novoDestino)
{
	Destino = novoDestino;
}

void Transporte::ativ_ou_desativ_PontoParagem()
{
	if (Estado == true)
		Estado = false;

	else
		Estado = true;

}



