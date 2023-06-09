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
	this->jugadores = new Lista<Jugador*>();
    this->cantidadSoldados = 0;

}

BatallaDigital::BatallaDigital(int limiteX,int limiteY,int limiteZ,int cantidadJugadores,int cantidadSoldados){

	this->tablero = new Tablero(limiteX,limiteY,limiteZ);
	this->jugadores = new Lista<Jugador*>();
    this->cantidadSoldados = cantidadSoldados;

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

void BatallaDigital::mostrarTableroParaJugador(std::string nombre){

	this->tablero->getTablero()->reiniciarCursor();
	int numeroCapa  = 1;

	cout<<" - TABLERO JUGADOR: "<<nombre<<" - "<<endl;
	cout<<endl;


	while(this->tablero->getTablero()->avanzarCursor()){

		cout<<"Capa"<<numeroCapa<<endl;
		cout<<endl;
		this->tablero->getTablero()->getCursor()->reiniciarCursor();
		while(this->tablero->getTablero()->getCursor()->avanzarCursor()){
			this->tablero->getTablero()->getCursor()->getCursor()->reiniciarCursor();
			while(this->tablero->getTablero()->getCursor()->getCursor()->avanzarCursor()){
				Casillero* casillero = this->tablero->getTablero()->getCursor()->getCursor()->getCursor();
				if(casillero->getFicha() != NULL){

					if(casillero->getFicha()->getNombreJugador() == nombre){
						string simbolo = casillero->getFicha()->getSimbolo();
						cout<<" "<<simbolo;
					}else{
						string simbolo = casillero->getSimbolo();
						cout<<" "<<simbolo;
					}


				}else{
					string simbolo1 = casillero->getSimbolo();
					cout<<" "<<simbolo1;

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

		Jugador* nuevoJugador = new Jugador(this->cantidadSoldados, simbolo);
		this->jugadores->add(nuevoJugador);

	}


}

bool BatallaDigital::colocarFicha(Ficha* ficha, Coordenada* coordenada){

	Casillero* casillero = this->tablero->getTablero()->get(coordenada->getPosicionZ())->get(coordenada->getPosicionY())->get(coordenada->getPosicionX());

	if(casillero->getEstado() == libre && casillero->getFicha() == NULL){

		casillero->setFicha(ficha);
		ficha->setCoordenada(coordenada);

		casillero->setEstado(ocupado);
		return true;
	}

	if(casillero->getEstado() == libre && casillero->getFicha() != NULL){
		if(casillero->getFicha()->getTipoFicha() == mina ){
			stringstream convertirAEntero;
			ficha->setCoordenada(coordenada);
			int numeroJugador;
			convertirAEntero << ficha->getNombreJugador();
			convertirAEntero  >> numeroJugador;
			this->removerFichaDeLista(coordenada, this->jugadores->get(numeroJugador)->getFichasDisponibles());
			casillero->setEstado(bloqueado);
			casillero->setFicha(NULL);
			return true;
		}
	}

	return false;

}

/*int BatallaDigital::getCantidadJugadores(){
	return this->cantidadJugadores;
}*/

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

		this->removerFichaDeLista(destino->getCoordenada(),this->buscarDuenioDeFicha(destino->getFicha()->getNombreJugador()));
		destino->setFicha(NULL);
		this->removerFichaDeLista(aMover->getCoordenada(),this->buscarDuenioDeFicha(aMover->getNombreJugador()));
		actual->setFicha(NULL);
		actual->setEstado(libre);
		destino->setEstado(libre);

	}else if(destino->getFicha()->getSimbolo() == "M"){

		this->removerFichaDeLista(aMover->getCoordenada(),this->buscarDuenioDeFicha(aMover->getNombreJugador()));
		actual->setFicha(NULL);
		destino->setFicha(NULL);
		actual->setEstado(libre);
		destino->setEstado(bloqueado);

	}
	return true;
}

Lista<Ficha*>* BatallaDigital::buscarDuenioDeFicha(string nombre){
	Lista<Ficha*>* fichas = NULL;
	Lista<Jugador*>* jugadores = this->jugadores;

	stringstream convertiAEntero;
	int posicion;

	convertiAEntero<<nombre;
	convertiAEntero>>posicion;

	fichas = jugadores->get(posicion)->getFichasDisponibles();

	return fichas;
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

	int tamanioLista = lista->contarElementos();

	if(posicionABorrar >= 1 && posicionABorrar <= tamanioLista){
		lista->remover(posicionABorrar);
	}

}

bool BatallaDigital::tieneSoldados(Jugador* jugador){
	int contadorSoldados = 0;

	Lista<Ficha*>* fichas = jugador->getFichasDisponibles();
	fichas->reiniciarCursor();
	while(fichas->avanzarCursor()){
		if(fichas->getCursor()->getSimbolo() == "S" ){
			contadorSoldados++;
		}
	}

	if(contadorSoldados == 0){
		return false;
	}else{
		return true;
	}
}

bool BatallaDigital::colocarMina(Jugador* jugador,Coordenada* posicion){
	bool seMino = false;

	Casillero* casillero = this->buscarCasillero(posicion);

	if(casillero->getEstado() != bloqueado){
		if(casillero->getEstado() == libre){
			if(casillero->getFicha() == NULL){

				Ficha* ficha = new Ficha(mina,jugador->getSimbolo());
				casillero->setFicha(ficha);
				ficha->setCoordenada(posicion);
				jugador->getFichasDisponibles()->add(ficha);
				seMino = true;

			}else{
				if(casillero->getFicha()->getSimbolo() != "M"){
					Ficha* ficha = new Ficha(mina,jugador->getSimbolo());
					casillero->setFicha(ficha);
					ficha->setCoordenada(posicion);
					jugador->getFichasDisponibles()->add(ficha);
					seMino = true;
				}
			}

		}else if(casillero->getEstado() == ocupado){
			Lista<Ficha*>fichas;
			this->removerFichaDeLista(casillero->getCoordenada(),this->buscarDuenioDeFicha(casillero->getFicha()->getNombreJugador()));
			casillero->setEstado(bloqueado);
			casillero->setFicha(NULL);
			seMino = true;

		}
	}else{
		seMino = false;
	}

	return seMino;
}

Jugador* BatallaDigital::buscarGanador(){
	Jugador* jugador = NULL;
	bool encontrado = false;
	this->jugadores->reiniciarCursor();
	while(this->jugadores->avanzarCursor() && encontrado == false){

		if(this->tieneSoldados(this->jugadores->getCursor()) == true){

			jugador = this->jugadores->getCursor();
			encontrado = true;

		}

	}

	return jugador;
}

void BatallaDigital::tomarCarta(Jugador* jugador){

	int numeroRandom = 1; //1 + rand() % 3;

	if(numeroRandom == 1){
		Carta* carta = new Carta(cartaDeBarco);
		jugador->getCartas()->add(carta);
	}else if(numeroRandom == 2){
		Carta* carta = new Carta(CartaAtaqueQuimico);
		jugador->getCartas()->add(carta);
	}else{
		Carta* carta = new Carta(cartaDeAvionRadar);
		jugador->getCartas()->add(carta);
	}


}

void BatallaDigital::dispararConBarcoA(Casillero* casillero){
	if(casillero->getFicha() != NULL){
		if(casillero->getFicha()->getTipoFicha() == mina){

			this->removerFichaDeLista(casillero->getFicha()->getCoordenada(),this->buscarDuenioDeFicha(casillero->getFicha()->getNombreJugador()));
			casillero->setFicha(NULL);
			casillero->setEstado(bloqueado);

		}else{
			this->removerFichaDeLista(casillero->getFicha()->getCoordenada(),this->buscarDuenioDeFicha(casillero->getFicha()->getNombreJugador()));
			casillero->setFicha(NULL);
			casillero->setEstado(libre);
		}

	}
}



















