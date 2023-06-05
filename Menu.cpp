/*
 * Menu.cpp
 *
 *  Created on: 28 may 2023
 *      Author: David
 */
#include"Menu.h"
using namespace std;

Menu::Menu(){
	this->juego = new BatallaDigital();
}

void Menu::iniciarJuego(){

	cout<<"--BATALLA DIGITAL--"<<endl;


	this->juego->getTablero()->setLimiteX(6);
	this->juego->getTablero()->setLimiteY(4);
	this->juego->getTablero()->setLimiteZ(6);
	this->juego->getTablero()->crearTablero();
	this->juego->cargarMapa();
	this->ingresarJugadores();
	cout<<"cantidad"<<this->juego->getCantidadSoldados()<<endl;
	this->juego->aniadirSoldadosAJugador(this->juego->getCantidadSoldados());

	this->aniadirSoldadosEnTablero(juego->getTablero(),juego->getJugadores());

	this->juego->mostrarTablero();


}

void Menu::ingresarJugadores(){

	bool agregar = false;
	int cantidadJugadores;

	do{

		cout<<"Ingrese el numero de jugadores: ";
		cin>>cantidadJugadores;

		if(cantidadJugadores > 1){

			this->juego->agregarJugadores((int)cantidadJugadores);
			agregar = true;
		}else{
			cout<<"Valor no valido, ingrese otro. "<<endl;
		}

	}while(!agregar);



}

bool Menu::validarCaracterJugador(char caracter){

	if(caracter != 'A' && caracter != 'T' && caracter != '*' && ((int)caracter > 32) && ((int)caracter < 127)){
		return true;
	}else{
		cout<<"Caracter no valido"<<endl;
		return false;
	}

}

void Menu::aniadirSoldadosEnTablero(Tablero* tablero, Lista<Jugador*>* jugadores){

	cout<<"Colocar Soldados en el Tablero"<<endl;
	jugadores->reiniciarCursor();
	while(jugadores->avanzarCursor()){

		int contadorSoldado = 1;
		cout<<"	Jugador "<<jugadores->getCursor()->getSimbolo()<<"Soldado N°: "<<contadorSoldado<<endl;
		Lista<Ficha*> * fichas = jugadores->getCursor()->getFichasDisponibles();
		fichas->reiniciarCursor();
		while(fichas->avanzarCursor()){
			Ficha* soldado = fichas->getCursor();
			int posicionX;
			int posicionY;
			int posicionZ;
			cout<<"Ingrese posicion X: "<<endl;
			cin>>posicionX;
			cout<<"Ingrese posicion Y: "<<endl;
			cin>>posicionY;
			cout<<"Ingrese posicion Z: "<<endl;
			cin>>posicionZ;
			this->juego->colocarFicha(soldado, posicionX, posicionY, posicionZ);
		}

	}

}

















