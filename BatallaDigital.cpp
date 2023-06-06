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

					string simbolo = casillero->getFicha()->getSimbolo();
					cout<<" "<<simbolo;

				}else{

					string simbolo = this->tablero->getTablero()->getCursor()->getCursor()->getCursor()->getSimbolo();
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
				if(casilla->getCoordenada()->getPosicionZ() <= 5){
					if(casilla->getCoordenada()->getPosicionY() <= (this->tablero->getLimiteY()/2)){
						casilla->setSimbolo("A");
						casilla->setTerrono(agua);
					}else{
						casilla->setSimbolo("T");
						casilla->setTerrono(tierra);
					}
				}
			}
		}

	}
}

void BatallaDigital::agregarJugadores(int cantidad){

	for(int i = 0 ; i < cantidad ; i++){
		int numeroJugador = i + 1;
		string simbolo;
		stringstream ss;
		ss << numeroJugador;
		ss >> simbolo;

		//cout<<"SIMBOLO JUGADOR: "<<simbolo<<endl;
		Jugador* nuevoJugador = new Jugador(this->cantidadSoldados, simbolo);
		this->jugadores->add(nuevoJugador);

	}


}

bool BatallaDigital::colocarFicha(Ficha* ficha, Coordenada* coordenada){

	Casillero* casillero = this->tablero->getTablero()->get(coordenada->getPosicionZ())->get(coordenada->getPosicionY())->get(coordenada->getPosicionX());
	//cout<<coordenada->getPosicionX()<<coordenada->getPosicionY()<<coordenada->getPosicionZ()<<endl;

	if(casillero->getEstado() == libre){
		casillero->setFicha(ficha);
		ficha->setCoordenada(coordenada);

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
			Ficha* nuevoSoldado = new Ficha(soldado,this->jugadores->getCursor()->getSimbolo());

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

Casillero* BatallaDigital::buscarCasillero(Coordenada* coordenada){
	return this->tablero->getTablero()->get(coordenada->getPosicionZ())->get(coordenada->getPosicionY())->get(coordenada->getPosicionX());
}

Casillero* BatallaDigital::buscarCasillero(int posicionX,int posicionY,int posicionZ){
	return this->tablero->getTablero()->get(posicionZ)->get(posicionY)->get(posicionX);
}

bool BatallaDigital::moverFicha(Casillero* actual, Casillero* destino, Ficha* aMover){
	if(destino->getFicha() == NULL){
		destino->setFicha(aMover);
		aMover->setCoordenada(destino->getCoordenada());
		actual->setFicha(NULL);
		actual->setEstado(libre);
		destino->setEstado(ocupado);
	}else if(destino->getFicha()->getSimbolo() == aMover->getSimbolo()){

		this->removerFichaDeLista(destino->getCoordenada(),this->buscarDueñoDeFicha(destino->getFicha()->getNombreJugador()));
		destino->setFicha(NULL);
		this->removerFichaDeLista(aMover->getCoordenada(),this->buscarDueñoDeFicha(aMover->getNombreJugador()));
		actual->setFicha(NULL);
		actual->setEstado(libre);
		destino->setEstado(libre);
	}
	return true;
}

Lista<Ficha*>* BatallaDigital::buscarDueñoDeFicha(string nombre){
	Lista<Ficha*>* fichas = NULL;
	Lista<Jugador*>* jugadores = this->jugadores;

	stringstream convertiAEntero;
	int posicion;

	convertiAEntero<<nombre;
	convertiAEntero>>posicion;

	/*
	jugadores->reiniciarCursor();
	while(jugadores->avanzarCursor() && fichas == NULL){
		if(jugadores->getCursor()->getSimbolo() == nombre){
			fichas = jugadores->getCursor()->getFichasDisponibles();
		}
	}
	*/
	return fichas = jugadores->get(posicion)->getFichasDisponibles();
}

void BatallaDigital::removerFichaDeLista(Coordenada* posicion,Lista<Ficha*>* lista){
	int contarPosiciones = 1;
	int posicionABorrar = 0;

	lista->reiniciarCursor();
	while(lista->avanzarCursor()){
		Ficha* ficha = lista->getCursor();
		if(posicion->getPosicionX() == ficha->getCoordenada()->getPosicionX() &&
				posicion->getPosicionY() == ficha->getCoordenada()->getPosicionY() &&
				posicion->getPosicionZ() == ficha->getCoordenada()->getPosicionZ()){
			posicionABorrar = contarPosiciones;
		}
		contarPosiciones++;
	}

	if(posicionABorrar >= 1 && posicionABorrar <= lista->contarElementos()){
		lista->remover(posicionABorrar);
	}

}

/*
void BatallaDigital::moverFicha(Ficha* ficha){

}
*/
/*
Casillero* BatallaDigital::moverSoldado(Ficha* ficha){

	if((ficha->getCoordenada()->getPosicionX() - 1) >= 1){

		Casillero* casillero = this->buscarCasillero(ficha->getCoordenada()->getPosicionX() - 1,ficha->getCoordenada()->getPosicionY(),ficha->getCoordenada()->getPosicionZ());
		if(casillero->getTipoTerreno() != agua && casillero->getFicha()){

			cout<< "1 - Mover a: "<<"("<<ficha->getCoordenada()->getPosicionX() - 1<<","<<ficha->getCoordenada()->getPosicionY()<<","<<ficha->getCoordenada()->getPosicionZ()<<")"<<endl;
		}

	}

	if((ficha->getCoordenada()->getPosicionX() + 1) <= this->getTablero()->getLimiteX()){

		Casillero* casillero = this->buscarCasillero(ficha->getCoordenada()->getPosicionX() + 1,ficha->getCoordenada()->getPosicionY(),ficha->getCoordenada()->getPosicionZ());

		cout<< "1 - Mover a: "<<"("<<ficha->getCoordenada()->getPosicionX() + 1<<","<<ficha->getCoordenada()->getPosicionY()<<","<<ficha->getCoordenada()->getPosicionZ()<<")"<<endl;

	}

	if((ficha->getCoordenada()->getPosicionY() - 1) >= 1){

	}

	if((ficha->getCoordenada()->getPosicionX() - 1) >= 1){

	}
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


