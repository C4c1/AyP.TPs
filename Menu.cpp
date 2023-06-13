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
	this->estado = finalizado;
	this->saltarTurno = false;
}

void Menu::iniciarJuego(){
	this->estado = enJuego;

	cout<<"--BATALLA DIGITAL--"<<endl;

	this->juego->getTablero()->setLimiteX(6);
	this->juego->getTablero()->setLimiteY(6);
	this->juego->getTablero()->setLimiteZ(6);
	this->juego->getTablero()->crearTablero();
	this->juego->cargarMapa();
	this->juego->mostrarTablero();
	this->ingresarJugadores();
	cout<<"cantidad: "<<this->juego->getCantidadSoldados()<<endl;
	this->juego->aniadirSoldadosAJugador(this->juego->getCantidadSoldados());

	this->aniadirSoldadosEnTablero(this->juego->getTablero(),this->juego->getJugadores());


	Carta* c1 = new Carta(cartaDeAvionRadar);
	Carta* c2 = new Carta(cartaDeAvionRadar);
	this->juego->getJugadores()->get(1)->getCartas()->add(c1);
	this->juego->getJugadores()->get(1)->getCartas()->add(c2);

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
		string nombreJugador = jugadores->getCursor()->getSimbolo();

		this->juego->mostrarTableroParaJugador(jugadores->getCursor(),nombreJugador);

		fichas->reiniciarCursor();
		while(fichas->avanzarCursor()){
			Ficha* soldado = fichas->getCursor();

			cout<<"	Jugador "<<jugadores->getCursor()->getSimbolo()<<" || "<<"Soldado N°: "<<contadorSoldado<<endl;

			this->juego->colocarFicha(soldado,this->validarCasilla("S","A"));
			this->juego->mostrarTableroParaJugador(jugadores->getCursor(),nombreJugador);
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
		cout<<"Simbolo A comparar: "<<simboloAComparar<<"Estado: "<<casillero->getEstado()<<"Terreno: "<<casillero->getTipoTerreno()<<endl;
		if(simboloAComparar == "S" && casillero->getEstado() == libre && casillero->getTipoTerreno() == tierra ){
			valido = true;
			coordenadaValida = casillero->getCoordenada();
		}else if(simboloAComparar == "B" && casillero->getEstado() == libre && casillero->getTipoTerreno() == agua ){
			valido = true;
			coordenadaValida = casillero->getCoordenada();
		}else if(simboloAComparar == "+" && casillero->getEstado() == libre && casillero->getTipoTerreno() == aire ){
			valido = true;
			coordenadaValida = casillero->getCoordenada();
		}else{
			cout<<"Casillero ocupada, eliga otro"<<endl;
		}

	}while(valido == false);
	return coordenadaValida;
}

Ficha* Menu::seleccionarFicha(Jugador* jugador){

	int posicionDeFicha;
	int contador = 1;;
	Lista<Ficha*>* disponibles = new Lista<Ficha*>();
	jugador->getFichasDisponibles()->reiniciarCursor();
	while(jugador->getFichasDisponibles()->avanzarCursor()){


		Ficha* ficha = jugador->getFichasDisponibles()->getCursor();


		if(ficha->getTipoFicha() == soldado){

			cout<<contador<<" - Soldado     | Posicion: "<<"("<<ficha->getCoordenada()->getPosicionX()<<","<<ficha->getCoordenada()->getPosicionY()<<","<<ficha->getCoordenada()->getPosicionZ()<<")"<<endl;
			contador++;
			disponibles->add(ficha);
		}else if(ficha->getTipoFicha() == barco){

			cout<<contador<<" - Barco       | Posicion: "<<"("<<ficha->getCoordenada()->getPosicionX()<<","<<ficha->getCoordenada()->getPosicionY()<<","<<ficha->getCoordenada()->getPosicionZ()<<")"<<endl;
			contador++;
			disponibles->add(ficha);

		}else if(ficha->getTipoFicha() == avionRadar){

			cout<<contador<<" - Avion radar | Posicion: "<<"("<<ficha->getCoordenada()->getPosicionX()<<","<<ficha->getCoordenada()->getPosicionY()<<","<<ficha->getCoordenada()->getPosicionZ()<<")"<<endl;
			contador++;
			disponibles->add(ficha);

		}

	}

	posicionDeFicha = this->validarPosicion(0,disponibles->contarElementos(),"Ingrese el numero de ficha a mover: ");

	return disponibles->get(posicionDeFicha);
}

void Menu::iniciarPartida(){

	do{

		this->juego->getJugadores()->reiniciarCursor();

		while(this->juego->getJugadores()->avanzarCursor()){

			Jugador* jugador = this->juego->getJugadores()->getCursor();
			if(this->juego->tieneSoldados(jugador) == true && this->saltarTurno == false){
				this->juego->detectarMinasCOnAvionRadarAlIncioDeTurno(jugador);
				cout<<"El jugador: "<<jugador->getSimbolo()<<" tomo una carta "<<endl;
				this->juego->tomarCarta(jugador);
				this->juego->mostrarTableroParaJugador(jugador,jugador->getSimbolo());
				this->aniadirMinaEnTablero(jugador);
				this->juego->mostrarTableroParaJugador(jugador,jugador->getSimbolo());
				this->jugarTurno(jugador);
				this->juego->mostrarTableroParaJugador(jugador,jugador->getSimbolo());

				this->disparaConBarcosDisponibles(jugador);
				this->juego->mostrarTableroParaJugador(jugador,jugador->getSimbolo());

				this->SeleccionarCartaAJugar(jugador);
				this->juego->mostrarTableroParaJugador(jugador,jugador->getSimbolo());

			}else{
				//cout<<" CAMBIAR A VERDADERO "<<endl;
				this->saltarTurno = false;
			}
			//cout<<" QUE PASA "<<endl;
		}
		//cout<<" - A - "<<endl;
		if(this->saltarTurno == false){
			this->estado = this->revisarEstadoDeJuego();
		}
		//cout<<" - B - "<<endl;
	}while(this->estado == enJuego);

	if(this->estado == empate){
		cout<<" - EMPATE, NINGUN JUGADOR TIENE SOLDADOS - "<<endl;
	}else if(this->estado == existeGanador){
		cout<<" - HAY UN GANADOR - "<<endl;
		Jugador* ganador = this->juego->buscarGanador();
		if(ganador != NULL){
			cout<<" JUGADOR N°: "<<ganador->getSimbolo()<<endl;
		}
	}
}

void Menu::jugarTurno(Jugador* jugador){
	cout<<endl;
	cout<<"Turno jugador N°: "<<jugador->getSimbolo()<<endl;
	cout<<" - Mover Ficha - "<<endl;

	Ficha* fichaAMover = this->seleccionarFicha(jugador);
	Casillero* actual = this->juego->buscarCasillero(fichaAMover->getCoordenada());
	Casillero* destino = this->seleccionarDireccionAMoverSoldado(fichaAMover);
	this->juego->moverFicha(actual,destino,fichaAMover);

}

Casillero* Menu::seleccionarDireccionAMoverSoldado(Ficha* ficha){

	int contador = 0;
	Lista<Casillero*>* casilleros = new Lista<Casillero*>();

	casilleros = this->generarListaDeCasilleroDisponibles(ficha);

	cout<<"TAMANIO DE LA LISTA DE CASILLERO = "<<casilleros->contarElementos()<<" || Simbolo De Ficha = "<<ficha->getSimbolo()<<" POSICION = "<<ficha->getCoordenada()->verCoordenada()<<endl;

	casilleros->reiniciarCursor();
	int indice = 1;
	while(casilleros->avanzarCursor()){
		Casillero* aMostrar = casilleros->getCursor();

		cout<<indice<< " - Mover a: "<<"("<<aMostrar->getCoordenada()->getPosicionX()<<","<<aMostrar->getCoordenada()->getPosicionY()<<","<<aMostrar->getCoordenada()->getPosicionZ()<<")"<<endl;
		indice++;
		contador++;

	}

	int opcion = this->validarPosicion(0,contador,"Seleccione una opcion: ");

	return casilleros->get(opcion);
}

Lista<Casillero*>* Menu::generarListaDeCasilleroDisponibles(Ficha* ficha){
	Lista<Casillero*>* casilleros = new Lista<Casillero*>();
	int centroX = ficha->getCoordenada()->getPosicionX();
	int centroY = ficha->getCoordenada()->getPosicionY();
	int centroZ = ficha->getCoordenada()->getPosicionZ();
	int inicioX ;
	int inicioY ;
	int inicioZ = 5;
	int finalX ;
	int finalY ;
	int finalZ = 5;


	inicioX = this->validarNumero(centroX,1,this->juego->getTablero()->getLimiteX(),1);
	inicioY = this->validarNumero(centroY,1,this->juego->getTablero()->getLimiteY(),1);;

	finalX = this->validarNumero(centroX,1,this->juego->getTablero()->getLimiteX(),0);
	finalY = this->validarNumero(centroY,1,this->juego->getTablero()->getLimiteY(),0);

	if(ficha->getTipoFicha() == avionRadar){
		inicioZ = this->validarNumero(centroZ,6,this->juego->getTablero()->getLimiteZ(),0);
		finalZ = this->validarNumero(centroZ,6,this->juego->getTablero()->getLimiteY(),0);
	}

	for(int z = inicioZ ; z <= finalZ ; z++){
		for(int y = inicioY ; y <= finalY ; y++){
			for(int x = inicioX ; x <= finalX ; x++){

				Casillero* casillero = this->juego->buscarCasillero(x,y,z);

				if(ficha->getTipoFicha() == soldado && casillero->getTipoTerreno() != agua && this->tieneFichaDeMisomoJUgador(ficha,casillero) == false){

					casilleros->add(casillero);

				}
				if(ficha->getTipoFicha() == barco && casillero->getTipoTerreno() != tierra && this->tieneFichaDeMisomoJUgador(ficha,casillero) == false){

					casilleros->add(casillero);

				}
				if(ficha->getTipoFicha() == avionRadar && this->tieneFichaDeMisomoJUgador(ficha,casillero) == false){

					casilleros->add(casillero);

				}

			}
		}
	}

	return casilleros;

}

int Menu::validarNumero(int numero, int minimo , int maximo, int opcion){
	if(opcion == 1){
		if(numero > minimo){
			return numero - 1;
		}else{
			return numero;
		}
	}

	if(opcion == 0){
		if(numero < maximo){
			return numero + 1;
		}else{
			return numero;
		}
	}

	return -1;
}

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


EstadoDelJUego Menu::revisarEmpate(){
	bool esEmpate = true;

	this->juego->getJugadores()->reiniciarCursor();

	while(this->juego->getJugadores()->avanzarCursor() && esEmpate == false){
		Jugador* jugador = this->juego->getJugadores()->getCursor();
		if(this->juego->tieneSoldados(jugador) == true ){
			esEmpate = false;
		}
	}

	if(esEmpate == true){
		return empate;
	}else{
		return enJuego;
	}

}

EstadoDelJUego Menu::revisarEstadoDeJuego(){
	int contador = 0;

	this->juego->getJugadores()->reiniciarCursor();

	while(this->juego->getJugadores()->avanzarCursor()){
		Jugador* jugador = this->juego->getJugadores()->getCursor();
		if(this->juego->tieneSoldados(jugador) == true ){
			contador ++;
		}
	}
	if(contador == 0){
		return empate;
	}else if(contador == 1){
		return existeGanador;
	}else{
		return enJuego;
	}

}

void Menu::aniadirMinaEnTablero(Jugador* jugador){
	Coordenada* posicion = new Coordenada(0,0,0);
	bool seMino = false;
	do{
		cout<<endl;
		cout<<"Turno jugador N°: "<<jugador->getSimbolo()<<endl;
		cout<<" - Colocar Mina - "<<endl;
		cout<<"Ingrese coordenadas para colocar mina"<<endl;
		posicion->setPosicionX(this->validarPosicion(0,this->juego->getTablero()->getLimiteX(),"Coordenada X: "));
		posicion->setPosicionY(this->validarPosicion(0,this->juego->getTablero()->getLimiteY(),"Coordenada Y: "));
		posicion->setPosicionZ(this->validarPosicion(0,5,"Coordenada Z: "));
		if(this->juego->colocarMina(jugador,posicion) == true){
			seMino = true;
		}else{
			cout<<" Posicion no disponible, Ingrese otra "<<endl;
		}

	}while(seMino == false);

}

void Menu::SeleccionarCartaAJugar(Jugador* jugador){

	Lista<Carta*>* cartas = jugador->getCartas();
	cartas->reiniciarCursor();
	cout<<"Cantidad de cartas del jugador: "<<cartas->contarElementos()<<endl;
	int indice = 1;
	while(cartas->avanzarCursor()){
		Carta* carta = cartas->getCursor();
		if(carta->getTipoCarta() == cartaDeBarco){
			cout<<indice<<" - Barco "<<endl;
		}
		if(carta->getTipoCarta() == CartaAtaqueQuimico){
			cout<<indice<<" - Ataque quimico "<<endl;
		}
		if(carta->getTipoCarta() == cartaDeAvionRadar){
			cout<<indice<<" - Avion radar "<<endl;
		}
		if(carta->getTipoCarta() == cartaSaltarTurno){
			cout<<indice<<" - Saltar turno del siguiente Jugador "<<endl;
		}
		if(carta->getTipoCarta() == cartaAntiAereo){
			cout<<indice<<" - Antiaereo "<<endl;
		}
		indice++;
	}

	int opcion;
	cout<<endl;
	cout<<"Turno jugador N°: "<<jugador->getSimbolo()<<endl;
	cout<<"¿Quiere jugar una carta?"<<endl;
	cout<<"1 - Si"<<endl;
	cout<<"2 - No"<<endl;
	opcion = this->validarPosicion(0,2,"Ingrese la opcion: ");

	if(opcion == 1){

		int numeroDeCarta;
		numeroDeCarta = this->validarPosicion(0,cartas->contarElementos(),"Ingrese numero de carta a jugar: ");
		Carta* cartaAJugar = cartas->get(numeroDeCarta);

		//cout<<"Ingrese la Pocion dende va a jugar la carta"<<endl;
		Coordenada* posicion ;
		Ficha* ficha = NULL;
		if(cartaAJugar->getTipoCarta() == cartaDeBarco){
			ficha = new Ficha(barco,jugador->getSimbolo());
			jugador->getFichasDisponibles()->add(ficha);
		}else if(cartaAJugar->getTipoCarta() == cartaDeAvionRadar){
			ficha = new Ficha(avionRadar,jugador->getSimbolo());
			jugador->getFichasDisponibles()->add(ficha);
		}else if(cartaAJugar->getTipoCarta() == cartaSaltarTurno){
			this->saltarTurno = true;
		}else if(cartaAJugar->getTipoCarta() == cartaAntiAereo){
			int poscion = this->validarPosicion(0, this->juego->getJugadores()->contarElementos(), "Ingrese el numero de Jugador: ")
			this->juego->usarAntiaereo(poscion);
		}else if(cartaAJugar->getTipoCarta() == cartaAntiAereo){

		}
		//cout<<"Simbolo Ficha: "<<ficha->getSimbolo()<<" || Limite Z: "<<this->juego->getTablero()->getLimiteZ()<<endl;

		if(ficha != NULL){
			posicion = this->validarCasilla(ficha->getSimbolo(),ficha->getNombreJugador());
			this->juego->colocarFicha(ficha, posicion);
		}


		if(ficha != NULL && ficha->getTipoFicha() == avionRadar){
			this->juego->detectarMinasConAvionRadar(jugador, posicion);

			this->verListaDeMinasDetectadas(jugador);


		}

		cartas->remover(numeroDeCarta);

	}
}

void Menu::disparaConBarcosDisponibles(Jugador* jugador){

	Lista<Ficha*>* barcos = this->buscarFichas(jugador,barco);

	if(!barcos->vacia()){
		cout<<endl;
		cout<<"Turno jugador N°: "<<jugador->getSimbolo()<<endl;
		cout<<" - Disparar con barcos - "<<endl;
		barcos->reiniciarCursor();
		while(barcos->avanzarCursor()){
			Ficha* barco = barcos->getCursor();
			cout<<"Dispara barco en posicion : "<<barco->getCoordenada()->verCoordenada()<<endl;
			cout<<"Ingrese coordenada de disparo"<<endl;
			Coordenada* aDisparar = new Coordenada(this->validarPosicion(0,this->juego->getTablero()->getLimiteX(),"Ingrese posicion X: "),
																		this->validarPosicion(0,this->juego->getTablero()->getLimiteY(),"Ingrese posicion Y: "),
																		this->validarPosicion(4,this->juego->getTablero()->getLimiteZ(),"Ingrese posicion Z: "));

			this->juego->dispararConBarcoA(this->juego->buscarCasillero(aDisparar));

		}
	}

}

Lista<Ficha*>* Menu::buscarFichas(Jugador* jugador,TipoFicha tipo){

	Lista<Ficha*>* fichas = new Lista<Ficha*>();

	jugador->getFichasDisponibles()->reiniciarCursor();

	while(jugador->getFichasDisponibles()->avanzarCursor()){
		Ficha* ficha = jugador->getFichasDisponibles()->getCursor();
		if(ficha->getTipoFicha() == tipo){
			fichas->add(ficha);
		}

	}
	return fichas;

}

