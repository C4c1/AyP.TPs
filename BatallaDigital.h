/*
 * BatallaDigital.h
 *
 *  Created on: 21 may 2023
 *      Author: David
 */

#ifndef BATALLADIGITAL_H_
#define BATALLADIGITAL_H_
#include"Tablero.h"
#include"Carta.h"
#include"Pila.h"
#include"Jugador.h"
#include<iostream>
#include<sstream>
using namespace std;

class BatallaDigital{

private:

	Tablero* tablero;
	int cantidadJugadores;
	int cantidadSoldados;
	Lista<Jugador*>* jugadores;
	//Pila<Carta*>* mazoDeCartas;

public:

	BatallaDigital();

	BatallaDigital(int limiteX,int limiteY,int limiteZ,int cantidadJugadores,int cantidadSoldados);

	int getCantidadJugadores();

	int getCantidadSoldados();

	void mostrarTablero();

	void mostrarTableroParaJugador(std::string nombre);

	void agregarJugadores(int cantidad);

	Tablero* getTablero();

	void cargarMapa();

	bool colocarFicha(Ficha* ficha, Coordenada* coorndenada);

	void aniadirSoldadosAJugador(int cantidad);

	Lista<Jugador*>* getJugadores();

	//void crearMazoDeCartas();

	//Pila<Carta*>* getMazoDeCartas();

	void mostrarTableroConCoordenadas(){

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

						string simbolo = casillero->getFicha()->getSimbolo();
						//cout<<" "<<simbolo;
						cout<<"("<<casillero->getCoordenada()->getPosicionX()<<","<<casillero->getCoordenada()->getPosicionY()<<","<<casillero->getCoordenada()->getPosicionZ()<<")  ";

					}else{

						string simbolo = this->tablero->getTablero()->getCursor()->getCursor()->getCursor()->getSimbolo();
						//cout<<" "<<simbolo;
						cout<<"("<<casillero->getCoordenada()->getPosicionX()<<","<<casillero->getCoordenada()->getPosicionY()<<","<<casillero->getCoordenada()->getPosicionZ()<<")  ";
					}

				}
				cout<<endl;
			}
			numeroCapa++;
			cout<<endl;
		}

	}

	void mostrarTablerocasilleroBloqueados(){

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
					if(casillero->getEstado() == ocupado){

						//string simbolo = casillero->getFicha()->getSimbolo();
						//cout<<" "<<simbolo;
						cout<<" OCUPADO ";

					}else{

						cout<<" LIBRE   ";
						//string simbolo = this->tablero->getTablero()->getCursor()->getCursor()->getCursor()->getSimbolo();
						//cout<<" "<<simbolo;
					}

				}
				cout<<endl;
			}
			numeroCapa++;
			cout<<endl;
		}

}

	Casillero* buscarCasillero(Coordenada* Coordenada);

	Casillero* buscarCasillero(int posicionX,int posicionY,int posicionZ);

	bool moverFicha(Casillero* actual, Casillero* destino, Ficha* aMover);

	Lista<Ficha*>* buscarDuenioDeFicha(std::string nombre);

	void removerFichaDeLista(Coordenada* posicion,Lista<Ficha*>* lista);

	bool tieneSoldados(Jugador* jugador);

	bool colocarMina(Jugador* jugador,Coordenada* posicion);



/*
void moverFicha(Ficha* ficha);

Casillero* moverSoldado(Ficha* ficha);
*/
};



#endif /* BATALLADIGITAL_H_ */
