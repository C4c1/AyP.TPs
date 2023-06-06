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
	this->juego->getTablero()->setLimiteY(6);
	this->juego->getTablero()->setLimiteZ(6);
	this->juego->getTablero()->crearTablero();
	this->juego->cargarMapa();
	this->juego->mostrarTablero();
	//this->juego->mostrarTableroConCoordenadas();
	this->ingresarJugadores();
	cout<<"cantidad: "<<this->juego->getCantidadSoldados()<<endl;
	this->juego->aniadirSoldadosAJugador(this->juego->getCantidadSoldados());

	this->aniadirSoldadosEnTablero(juego->getTablero(),juego->getJugadores());

	this->juego->mostrarTablero();
	this->juego->mostrarTablerocasilleroBloqueados();
/*
	//cout<<this->seleccionarFicha(juego->getJugadores()->get(1))->getSimbolo()<<endl;
	Casillero* c =this->seleccionarDireccionAMoverSoldado(this->seleccionarFicha(juego->getJugadores()->get(1)));

	cout<<c->getCoordenada()->getPosicionX()<<c->getCoordenada()->getPosicionY()<<c->getCoordenada()->getPosicionZ()<<endl;
*/
	this->iniciarPartida();

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


void Menu::aniadirSoldadosEnTablero(Tablero* tablero, Lista<Jugador*>* jugadores){

	cout<<"Colocar Soldados en el Tablero"<<endl;
	jugadores->reiniciarCursor();
	while(jugadores->avanzarCursor()){

		int contadorSoldado = 1;

		Lista<Ficha*> * fichas = jugadores->getCursor()->getFichasDisponibles();
		fichas->reiniciarCursor();
		while(fichas->avanzarCursor()){
			Ficha* soldado = fichas->getCursor();

			cout<<"	Jugador "<<jugadores->getCursor()->getSimbolo()<<" || "<<"Soldado N°: "<<contadorSoldado<<endl;

			this->juego->colocarFicha(soldado,this->validarCasilla("S","A"));
			this->juego->mostrarTablero();
			contadorSoldado++;
		}

	}

}

int Menu::validarPosicion(int valorMinimo, int valorMaximo, string texto){
	bool valido = false;
	int numero;
	while(valido == false){
		cout<<texto;
		cin>>numero;
		if(numero > valorMinimo && numero <= valorMaximo){
			valido = true;
		}else{
			cout<<"Valor no valido, ingres uno nuevo"<<endl;
		}
	}
	return numero;
}

Coordenada* Menu::validarCasilla(string simboloAComparar,string simbolo){
	int posicionX;
	int posicionY;
	int posicionZ;
	bool valido = false;
	Coordenada* coordenadaValida;
	do{
		posicionX = this->validarPosicion(0,this->juego->getTablero()->getLimiteX(),"Ingrese posicion X: ");
		posicionY = this->validarPosicion(0,this->juego->getTablero()->getLimiteY(),"Ingrese posicion Y: ");

		if(simboloAComparar == "S" || simboloAComparar == "B"){
			posicionZ = 5;//los soldados van si o si sobre tierra
		}else{
			posicionZ = this->validarPosicion(5,this->juego->getTablero()->getLimiteZ(),"Ingrese posicion Z: ");
		}

		Casillero* casillero = this->juego->getTablero()->getTablero()->get(posicionZ)->get(posicionY)->get(posicionX);

		if(simboloAComparar == "S" && casillero->getEstado() == libre && casillero->getTipoTerreno() == tierra ){
			valido = true;
			//casillero->setEstado(ocupado);
			coordenadaValida = casillero->getCoordenada();
			cout<<"Casillero valido"<<endl;
		}else if(simboloAComparar == "B" && casillero->getEstado() == libre && casillero->getTipoTerreno() == agua ){
			valido = true;
			//casillero->setEstado(ocupado);
			coordenadaValida = casillero->getCoordenada();
			cout<<"Casillero valido"<<endl;
		}else{
			cout<<"Casillero ocupada, eliga otro"<<endl;
		}

	}while(valido == false);
	cout<<"regreso coordenada de casillero valido "<< coordenadaValida->getPosicionX()<<coordenadaValida->getPosicionY()<<coordenadaValida->getPosicionZ()<<endl;
	return coordenadaValida;
}

Ficha* Menu::seleccionarFicha(Jugador* jugador){

	int posicionDeFicha;
	int contador = 1;;

	jugador->getFichasDisponibles()->reiniciarCursor();
	while(jugador->getFichasDisponibles()->avanzarCursor()){


		Ficha* ficha = jugador->getFichasDisponibles()->getCursor();


		if(ficha->getTipoFicha() == soldado){

			cout<<contador<<" - Soldado     | Posicion: "<<"("<<ficha->getCoordenada()->getPosicionX()<<","<<ficha->getCoordenada()->getPosicionY()<<","<<ficha->getCoordenada()->getPosicionZ()<<")"<<endl;
			contador++;

		}else if(ficha->getTipoFicha() == barco){

			cout<<contador<<" - Barco       | Posicion: "<<"("<<ficha->getCoordenada()->getPosicionX()<<","<<ficha->getCoordenada()->getPosicionY()<<","<<ficha->getCoordenada()->getPosicionZ()<<")"<<endl;
			contador++;

		}else if(ficha->getTipoFicha() == avionRadar){

			cout<<contador<<" - Avion radar | Posicion: "<<"("<<ficha->getCoordenada()->getPosicionX()<<","<<ficha->getCoordenada()->getPosicionY()<<","<<ficha->getCoordenada()->getPosicionZ()<<")"<<endl;
			contador++;

		}

	}


	posicionDeFicha = this->validarPosicion(0,jugador->getFichasDisponibles()->contarElementos(),"Ingrese el numero de ficha a mover: ");

	return jugador->getFichasDisponibles()->get(posicionDeFicha);
}

void Menu::iniciarPartida(){

	do{

		this->juego->getJugadores()->reiniciarCursor();

		while(this->juego->getJugadores()->avanzarCursor()){


			Jugador* jugador = this->juego->getJugadores()->getCursor();
			cout<<"al principio JUGADOR: "<<jugador->getSimbolo()<<endl;
			this->jugarTurno(jugador);
			cout<<"1 al final JUGADOR: "<<this->juego->getJugadores()->getCursor()->getSimbolo()<<endl;
			this->juego->mostrarTablero();
			this->juego->mostrarTablerocasilleroBloqueados();
			cout<<"2 al final JUGADOR: "<<this->juego->getJugadores()->getCursor()->getSimbolo()<<endl;
		}

	}while(2>1);
}

void Menu::jugarTurno(Jugador* jugador){

	cout<<"Turno jugador N°: "<<jugador->getSimbolo()<<endl;
	cout<<" - Mover Ficha - "<<endl;
	Ficha* fichaAMover = this->seleccionarFicha(jugador);
	Casillero* actual = this->juego->buscarCasillero(fichaAMover->getCoordenada());
	Casillero* destino = this->seleccionarDireccionAMoverSoldado(fichaAMover);
	this->juego->moverFicha(actual,destino,fichaAMover);

}

Casillero* Menu::seleccionarDireccionAMoverSoldado(Ficha* ficha){
	Casillero* nuevaPosicion;
	bool seleccionValida = false;
	int contador = 1;
	Lista<Casillero*>* casilleros = new Lista<Casillero*>();

		//cout<<"HOLA "<<(ficha->getCoordenada()->getPosicionX() - 1)<<endl;

		if((ficha->getCoordenada()->getPosicionX() - 1) >= 1){

			Casillero* casillero = this->juego->buscarCasillero(ficha->getCoordenada()->getPosicionX() - 1,ficha->getCoordenada()->getPosicionY(),ficha->getCoordenada()->getPosicionZ());
			cout<<"HOLA, si es mayor "<<endl;
			cout<<"nombre de "<<endl;
			if(casillero->getTipoTerreno() != agua && this->tieneFichaDeMisomoJUgador(ficha,casillero) == false){

				//cout<<contador<< " - Mover a: "<<"("<<ficha->getCoordenada()->getPosicionX() - 1<<","<<ficha->getCoordenada()->getPosicionY()<<","<<ficha->getCoordenada()->getPosicionZ()<<")"<<endl;
				casilleros->add(casillero);
				contador++;
			}

		}

		if((ficha->getCoordenada()->getPosicionX() + 1) <= this->juego->getTablero()->getLimiteX()){

			Casillero* casillero = this->juego->buscarCasillero(ficha->getCoordenada()->getPosicionX() + 1,ficha->getCoordenada()->getPosicionY(),ficha->getCoordenada()->getPosicionZ());
			if(casillero->getTipoTerreno() != agua && this->tieneFichaDeMisomoJUgador(ficha,casillero) == false){

				//cout<<contador<< " - Mover a: "<<"("<<ficha->getCoordenada()->getPosicionX() + 1<<","<<ficha->getCoordenada()->getPosicionY()<<","<<ficha->getCoordenada()->getPosicionZ()<<")"<<endl;
				casilleros->add(casillero);
				contador++;
			}

		}

		if((ficha->getCoordenada()->getPosicionY() - 1) >= 1){

			Casillero* casillero = this->juego->buscarCasillero(ficha->getCoordenada()->getPosicionX(),ficha->getCoordenada()->getPosicionY() - 1,ficha->getCoordenada()->getPosicionZ());
			if(casillero->getTipoTerreno() != agua && this->tieneFichaDeMisomoJUgador(ficha,casillero) == false){

				//cout<<contador<< " - Mover a: "<<"("<<ficha->getCoordenada()->getPosicionX()<<","<<ficha->getCoordenada()->getPosicionY() - 1 <<","<<ficha->getCoordenada()->getPosicionZ()<<")"<<endl;
				casilleros->add(casillero);
				contador++;
			}

		}

		if((ficha->getCoordenada()->getPosicionY() + 1) <= this->juego->getTablero()->getLimiteY()){

			Casillero* casillero = this->juego->buscarCasillero(ficha->getCoordenada()->getPosicionX(),ficha->getCoordenada()->getPosicionY() + 1,ficha->getCoordenada()->getPosicionZ());
			if(casillero->getTipoTerreno() != agua && this->tieneFichaDeMisomoJUgador(ficha,casillero) == false){

				//cout<<contador<< " - Mover a: "<<"("<<ficha->getCoordenada()->getPosicionX()<<","<<ficha->getCoordenada()->getPosicionY() + 1 <<","<<ficha->getCoordenada()->getPosicionZ()<<")"<<endl;
				casilleros->add(casillero);
				contador++;
			}

		}

		if((ficha->getCoordenada()->getPosicionX() - 1) >= 1 && (ficha->getCoordenada()->getPosicionY() - 1) >= 1 ){

			Casillero* casillero = this->juego->buscarCasillero(ficha->getCoordenada()->getPosicionX() - 1,ficha->getCoordenada()->getPosicionY() - 1,ficha->getCoordenada()->getPosicionZ());
			if(casillero->getTipoTerreno() != agua && this->tieneFichaDeMisomoJUgador(ficha,casillero) == false){

				//cout<<contador<< " - Mover a: "<<"("<<ficha->getCoordenada()->getPosicionX() - 1 <<","<<ficha->getCoordenada()->getPosicionY() - 1 <<","<<ficha->getCoordenada()->getPosicionZ()<<")"<<endl;
				casilleros->add(casillero);
				contador++;
			}

		}

		if((ficha->getCoordenada()->getPosicionX() - 1) >= 1 && (ficha->getCoordenada()->getPosicionY() + 1) <= this->juego->getTablero()->getLimiteY() ){

			Casillero* casillero = this->juego->buscarCasillero(ficha->getCoordenada()->getPosicionX() - 1,ficha->getCoordenada()->getPosicionY() + 1,ficha->getCoordenada()->getPosicionZ());
			if(casillero->getTipoTerreno() != agua && this->tieneFichaDeMisomoJUgador(ficha,casillero) == false){

				//cout<<contador<< " - Mover a: "<<"("<<ficha->getCoordenada()->getPosicionX() - 1 <<","<<ficha->getCoordenada()->getPosicionY() + 1 <<","<<ficha->getCoordenada()->getPosicionZ()<<")"<<endl;
				casilleros->add(casillero);
				contador++;
			}

		}

		if((ficha->getCoordenada()->getPosicionX() + 1) <= this->juego->getTablero()->getLimiteX() && (ficha->getCoordenada()->getPosicionY() - 1) >= 1){

			Casillero* casillero = this->juego->buscarCasillero(ficha->getCoordenada()->getPosicionX() + 1,ficha->getCoordenada()->getPosicionY() - 1,ficha->getCoordenada()->getPosicionZ());
			if(casillero->getTipoTerreno() != agua && this->tieneFichaDeMisomoJUgador(ficha,casillero) == false){

				//cout<<contador<< " - Mover a: "<<"("<<ficha->getCoordenada()->getPosicionX() + 1 <<","<<ficha->getCoordenada()->getPosicionY() - 1 <<","<<ficha->getCoordenada()->getPosicionZ()<<")"<<endl;
				casilleros->add(casillero);
				contador++;
			}

		}

		if((ficha->getCoordenada()->getPosicionX() + 1) <= this->juego->getTablero()->getLimiteX() && (ficha->getCoordenada()->getPosicionY() + 1) <= this->juego->getTablero()->getLimiteY() ){

			Casillero* casillero = this->juego->buscarCasillero(ficha->getCoordenada()->getPosicionX() + 1,ficha->getCoordenada()->getPosicionY() + 1,ficha->getCoordenada()->getPosicionZ());
			if(casillero->getTipoTerreno() != agua && this->tieneFichaDeMisomoJUgador(ficha,casillero) == false){

				//cout<<contador<< " - Mover a: "<<"("<<ficha->getCoordenada()->getPosicionX() + 1 <<","<<ficha->getCoordenada()->getPosicionY() + 1 <<","<<ficha->getCoordenada()->getPosicionZ()<<")"<<endl;
				casilleros->add(casillero);
				contador++;
			}

		}

		casilleros->reiniciarCursor();
		int indice = 1;
		while(casilleros->avanzarCursor()){
			Casillero* aMostrar = casilleros->getCursor();

			cout<<indice<< " - Mover a: "<<"("<<aMostrar->getCoordenada()->getPosicionX()<<","<<aMostrar->getCoordenada()->getPosicionY()<<","<<aMostrar->getCoordenada()->getPosicionZ()<<")"<<endl;
			indice++;

		}

		int opcion = this->validarPosicion(0,contador,"Seleccione una opcion: ");

		return casilleros->get(opcion);
}

/*
void Menu::agregarDireccionVlidaDeMovimiento(Ficha* ficha, Lista<Casillero*>* casilleros, int posicionX,int posicionY,int posicionZ){

	if((ficha->getCoordenada()->getPosicionX() + 1) <= this->juego->getTablero()->getLimiteX() && (ficha->getCoordenada()->getPosicionY() + 1) <= this->juego->getTablero()->getLimiteY() ){

		Casillero* casillero = this->juego->buscarCasillero(ficha->getCoordenada()->getPosicionX() + 1,ficha->getCoordenada()->getPosicionY() + 1,ficha->getCoordenada()->getPosicionZ());
		if(casillero->getTipoTerreno() != agua){

			//cout<<contador<< " - Mover a: "<<"("<<ficha->getCoordenada()->getPosicionX() + 1 <<","<<ficha->getCoordenada()->getPosicionY() + 1 <<","<<ficha->getCoordenada()->getPosicionZ()<<")"<<endl;
			casilleros->add(casillero);
			//contador++;
		}

	}

}
*/

bool Menu::tieneFichaDeMisomoJUgador(Ficha* ficha, Casillero* aRevisar){

	if(aRevisar->getFicha() == NULL){
		return false;
	}else{
		if(ficha->getNombreJugador() == aRevisar->getFicha()->getNombreJugador()){
			return true;
		}else{
			return false;
		}
	}

}





