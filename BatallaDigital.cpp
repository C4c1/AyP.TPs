/*
 * BatallaDigital.cpp
 *
 *  Created on: 21 may 2023
 *      Author: David
 */
#include"BatallaDigital.h"
using namespace std;

BatallaDigital::BatallaDigital(){

	this->tablero = new Tablero(1,1,1);
	this->cantidadJugadores = 0;
	this->cantidadSoldados = 2;
	this->jugadores = new Lista<Jugador*>();

	//this->mazoDeCartas = new Pila<Carta*>();
	//this->crearMazoDeCartas();

}

BatallaDigital::BatallaDigital(int limiteX,int limiteY,int limiteZ,int cantidadJugadores,int cantidadSoldados){

	this->tablero = new Tablero(limiteX,limiteY,limiteZ);
	this->cantidadJugadores = cantidadJugadores;
	this->cantidadSoldados = cantidadSoldados;
	this->jugadores = new Lista<Jugador*>();

	//this->mazoDeCartas = new Pila<Carta*>();
	//this->crearMazoDeCartas();

}

void BatallaDigital::mostrarTablero(){

	this->tablero->getTablero()->reiniciarCursor();
	int numeroCapa  = 1;
	while(this->tablero->getTablero()->avanzarCursor()){

		cout<<"Capa"<<numeroCapa<<endl;
		cout<<endl;
		this->tablero->getTablero()->getCursor()->reiniciarCursor();

		while(this->tablero->getTablero()->getCursor()->avanzarCursor()){

			this->tablero->getTablero()->getCursor()->getCursor()->reiniciarCursor();

			while(this->tablero->getTablero()->getCursor()->getCursor()->avanzarCursor()){
				Casillero* casillero = this->tablero->getTablero()->getCursor()->getCursor()->getCursor();
				if(casillero->getFicha() != NULL){

					char simbolo = casillero->getFicha()->getSimbolo();
					cout<<" "<<simbolo;

				}else{

					char simbolo = this->tablero->getTablero()->getCursor()->getCursor()->getCursor()->getSimbolo();
					cout<<" "<<simbolo;

				}

			}
			cout<<endl;
		}
		numeroCapa++;
		cout<<endl;
	}

}

Tablero* BatallaDigital::getTablero(){
	return this->tablero;
}

void BatallaDigital::cargarMapa(){
	Lista<Lista<Lista<Casillero*>*>*>* tablero = this->tablero->getTablero();

	tablero->reiniciarCursor();
	while(tablero->avanzarCursor()){

		Lista<Lista<Casillero*>*>* nivelUno = tablero->getCursor();
		nivelUno->reiniciarCursor();
		while(nivelUno->avanzarCursor()){

			Lista<Casillero*>* nivelDos = nivelUno->getCursor();
			nivelDos->reiniciarCursor();
			while(nivelDos->avanzarCursor()){

				Casillero* casilla = nivelDos->getCursor();
				if(casilla->getCoordenada()->getPosicionZ() < 5){
					if(casilla->getCoordenada()->getPosicionY() < (this->tablero->getLimiteY()/2)){
						casilla->setSimbolo('A');
						casilla->setTerrono(agua);
					}else{
						casilla->setSimbolo('T');
						casilla->setTerrono(tierra);
					}
				}
			}
		}

	}
}

void BatallaDigital::agregarJugadores(int cantidad){

	for(int i = 0 ; i < cantidad ; i++){

		Jugador* nuevoJugador = new Jugador(this->cantidadSoldados, (char)(i + 1));
		this->jugadores->add(nuevoJugador);

	}


}

bool BatallaDigital::colocarFicha(Ficha* ficha,int posicionX, int posicionY, int posicionZ){

	Casillero* casillero = this->tablero->getTablero()->get(posicionZ)->get(posicionY)->get(posicionX);

	if(casillero->getEstado() == libre){
		casillero->setFicha(ficha);
		casillero->setEstado(ocupado);
		return true;
	}else{
		return false;
	}

}

int BatallaDigital::getCantidadJugadores(){
	return this->cantidadJugadores;
}

void BatallaDigital::aniadirSoldadosAJugador(int cantidad){

	this->jugadores->reiniciarCursor();
	while(this->jugadores->avanzarCursor()){
		for(int i = 0 ; i < cantidad ; i++){
			Ficha* nuevoSoldado = new Ficha(soldado);

			this->jugadores->getCursor()->getFichasDisponibles()->add(nuevoSoldado);
		}
	}
}

int BatallaDigital::getCantidadSoldados(){
	return this->cantidadSoldados;
}

Lista<Jugador*>* BatallaDigital::getJugadores(){
	return this->jugadores;
}

/*
void BatallaDigital::crearMazoDeCartas(){
	int contadorCartas = 0;
	do{

		Carta* cartaAtaqueQuimico = new Carta(CartaAtaqueQuimico);
		contadorCartas++;
		this->mazoDeCartas->apilar(cartaAtaqueQuimico);
		Carta* cartaBarco = new Carta(cartaDeBarco);
		contadorCartas++;
		this->mazoDeCartas->apilar(cartaBarco);
		Carta* cartaAvion = new Carta(cartaDeAvionRadar);
		contadorCartas++;
		this->mazoDeCartas->apilar(cartaAvion);

	}while(contadorCartas < 20);

}

Pila<Carta*>* BatallaDigital::getMazoDeCartas(){
	return this->mazoDeCartas;
}
*/


