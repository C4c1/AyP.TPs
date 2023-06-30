#include"Carta.h"

Carta::Carta(TipoCarta tipo){
	this->tipos = tipo;
}

TipoCarta Carta::getTipoCarta(){
	return this->tipos;
}

void Carta::setTipoCarta(TipoCarta nuevoTipo){
	this->tipos = nuevoTipo;
}


Carta::~Carta(){

}
