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

void BatallaDigital::mostrarTableroParaJugador(std::string nombre){

	this->tablero->getTablero()->reiniciarCursor();
	int numeroCapa  = 1;

	cout<<" - TABLERO JUGADOR: "<<nombre<<" - "<<endl;
	cout<<endl;


	while(this->tablero->getTablero()->avanzarCursor()){

		cout<<"Capa"<<numeroCapa<<endl;
		cout<<endl;
		this->tablero->getTablero()->getCursor()->reiniciarCursor();
		//cout<<" hola 1"<<endl;
		while(this->tablero->getTablero()->getCursor()->avanzarCursor()){
			//cout<<" hola 2"<<endl;
			this->tablero->getTablero()->getCursor()->getCursor()->reiniciarCursor();
			//cout<<" hola 3"<<endl;
			while(this->tablero->getTablero()->getCursor()->getCursor()->avanzarCursor()){
				Casillero* casillero = this->tablero->getTablero()->getCursor()->getCursor()->getCursor();
				//cout<<" hola 4"<<endl;
				if(casillero->getFicha() != NULL){
					//cout<<" hola 5"<<endl;

					if(casillero->getFicha()->getNombreJugador() == nombre){
						string simbolo = casillero->getFicha()->getSimbolo();
						cout<<" "<<simbolo;
					}else{
						string simbolo = casillero->getSimbolo();
						cout<<" "<<simbolo;
					}


				}else{
					//cout<<" hola 6"<<endl;
					string simbolo1 = casillero->getSimbolo();
					cout<<" "<<simbolo1;

				}

			}
			cout<<endl;
			//cout<<"hola?"<<endl;
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

	/*
	jugadores->reiniciarCursor();
	while(jugadores->avanzarCursor() && fichas == NULL){
		if(jugadores->getCursor()->getSimbolo() == nombre){
			fichas = jugadores->getCursor()->getFichasDisponibles();
		}
	}
	*/
	//cout<<"posicionN: "<<posicion<<" | "<<posicion+1<<endl;
	fichas = jugadores->get(posicion)->getFichasDisponibles();
	//cout<<"Tamanio de Lista : "<<fichas->contarElementos()<<endl;
	return fichas;
}

void BatallaDigital::removerFichaDeLista(Coordenada* posicion,Lista<Ficha*>* lista){
	int contarPosiciones = 1;
	int posicionABorrar = 0;

	//cout<<" Tamanio De ListaR: "<<lista->contarElementos()<<endl;
	//cout<<"Coordenada: "<<posicion->getPosicionX()<<posicion->getPosicionY()<<posicion->getPosicionZ()<<endl;
	//cout<<"1- simbolo: "<<lista->get(1)->getSimbolo()<<endl;
	//cout<<"2- simbolo: "<<lista->get(2)->getSimbolo()<<endl;
	//cout<<"1- coordenda: "<<lista->get(1)->getCoordenada()->getPosicionX()<<lista->get(1)->getCoordenada()->getPosicionY()<<lista->get(1)->getCoordenada()->getPosicionZ()<<endl;
	//cout<<"1- coordenda: "<<lista->get(2)->getCoordenada()->getPosicionX()<<lista->get(2)->getCoordenada()->getPosicionY()<<lista->get(2)->getCoordenada()->getPosicionZ()<<endl;

	lista->reiniciarCursor();
	while(lista->avanzarCursor()){
		//cout<<" ENTRO "<<endl;
		Ficha* ficha = lista->getCursor();

		if(posicion->getPosicionX() == ficha->getCoordenada()->getPosicionX() &&
				posicion->getPosicionY() == ficha->getCoordenada()->getPosicionY() &&
				posicion->getPosicionZ() == ficha->getCoordenada()->getPosicionZ()){
			//cout<<" ENTRO en if "<<endl;
			posicionABorrar = contarPosiciones;
		}
		contarPosiciones++;
		//cout<<"posicion a Borrar: "<<posicionABorrar<<endl;
		//cout<<"contador posicion: "<<contarPosiciones<<endl;
	}
	//cout<<" salio de while | posicion a Borrar: "<<posicionABorrar<<endl;
	int tamanioLista = lista->contarElementos();
	//cout<<" salio de while abajo "<<endl;
	//cout<<"Posicion A Borrar: "<<posicionABorrar<<" Tamanio De Lista: "<<tamanioLista<<endl;

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

	//cout<<" uno "<<endl;
	if(casillero->getEstado() != bloqueado){
		//cout<<" dos "<<endl;
		if(casillero->getEstado() == libre){
			//cout<<" tres "<<endl;
			Ficha* ficha = new Ficha(mina,jugador->getSimbolo());
			casillero->setFicha(ficha);
			ficha->setCoordenada(posicion);
			jugador->getFichasDisponibles()->add(ficha);
			seMino = true;
		}else if(casillero->getEstado() == ocupado){
			//cout<<" cuatro "<<endl;
			Lista<Ficha*>fichas;
			//cout<<" a "<<endl;
			this->removerFichaDeLista(casillero->getCoordenada(),this->buscarDuenioDeFicha(casillero->getFicha()->getNombreJugador()));
			//cout<<" ab "<<endl;
			casillero->setEstado(bloqueado);
			casillero->setFicha(NULL);
			seMino = true;

		}
	}else{
		cout<<" cinco "<<endl;
		seMino = false;
	}

	return seMino;
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


