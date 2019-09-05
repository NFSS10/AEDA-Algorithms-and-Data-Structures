#pragma once

#include <string>

using namespace std;

class Transporte
{
public:
	Transporte(); //feito
	~Transporte(); //feito
	Transporte(string tipo, string destino, string ponto_paragem, unsigned int dist_ponto_paragem); //feito
	Transporte(string tipo, string destino, string ponto_paragem, unsigned int dist_ponto_paragem, bool estado); //feito
	bool operator < (const Transporte & transporte) const; //retorna a comparaçao > em vez do suposto < para ficar no topo o mais proximo //feito
	void setPontoParagem(string novoPontoParagem); //feito
	void setDestino(string novoDestino); //feito
	void ativ_ou_desativ_PontoParagem();	// desativado significa que Estado=false


	string getTipo() const; //feito
	string getDestino() const; //feito
	string getPontoParagem() const; //feito
	unsigned int getDistancia() const; //feito
	bool getEstado() const; //feito
private:
	string Tipo;
	string Destino;
	string PontoParagem;
	unsigned int dist_PontoParagem;
	bool Estado;

};




