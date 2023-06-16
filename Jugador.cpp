using namespace std;
#include"Jugador.h"

Jugador::Jugador(int solodadoDisponibles, string simbolo){
	this->cartas = new Lista<Carta*>();
	this->simbolo = simbolo;
	this->numeroSoldadosDisponibles = solodadoDisponibles;
	this->FichasDisponibles = new Lista<Ficha*>();
	this->posicionDeMinasDetectadasPorRadar = new Lista<Coordenada*>();
}

Lista<Carta*>* Jugador::getCartas(){
	return this->cartas;
}

string Jugador::getSimbolo(){
	return this->simbolo;
}

int Jugador::getSoldadosDisponibles(){
	return this->numeroSoldadosDisponibles;
}

Lista<Ficha*>* Jugador::getFichasDisponibles(){
	return this->FichasDisponibles;
}

Lista<Coordenada*>* Jugador::getPosicionDeMinasDetectadasPorRadar(){
	return this->posicionDeMinasDetectadasPorRadar;
}

Jugador::~Jugador(){

	this->cartas->reiniciarCursor();
	while(this->cartas->avanzarCursor()){
		Carta* aRemover = this->cartas->getCursor();
		delete aRemover;
	}
	delete this->cartas;

	this->FichasDisponibles->reiniciarCursor();
	while(this->FichasDisponibles->avanzarCursor()){
		Ficha* aRemover = this->FichasDisponibles->getCursor();
		delete aRemover;
	}
	delete this->FichasDisponibles;

	this->posicionDeMinasDetectadasPorRadar->reiniciarCursor();
	while(this->posicionDeMinasDetectadasPorRadar->avanzarCursor()){
		Coordenada* aRemover = this->posicionDeMinasDetectadasPorRadar->getCursor();
		delete aRemover;
	}
	delete this->posicionDeMinasDetectadasPorRadar;
}

