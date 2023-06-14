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

void BatallaDigital::mostrarTableroParaJugador(Jugador* jugador,std::string nombre){

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
					}else if(casillero->getFicha()->getNombreJugador() != nombre && casillero->getFicha()->getTipoFicha() == mina &&
							this->estaEnLaListaDeMinasDetectadas(jugador, casillero->getCoordenada())){
						string simbolo = "E";
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
				}else{
					casilla->setSimbolo("*");
					casilla->setTerrono(aire);
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
		destino->setTurnosBloqueado(2);
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
			casillero->setTurnosBloqueado(3);
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

	int numeroRandom = 1 + rand() % 6;
	//int numeroRandom = 2;

	if(numeroRandom == 1){
		Carta* carta = new Carta(cartaDeBarco);
		jugador->getCartas()->add(carta);
	}else if(numeroRandom == 2){
		Carta* carta = new Carta(CartaAtaqueQuimico);
		jugador->getCartas()->add(carta);
	}else if(numeroRandom == 3){
		Carta* carta = new Carta(cartaDeAvionRadar);
		jugador->getCartas()->add(carta);
	}else if(numeroRandom == 4){
		Carta* carta = new Carta(cartaSaltarTurno);
		jugador->getCartas()->add(carta);
	}else if(numeroRandom == 5){
		Carta* carta = new Carta(cartaAntiAereo);
		jugador->getCartas()->add(carta);
	}else if(numeroRandom == 6){
		Carta* carta = new Carta(cartaKamikaze);
		jugador->getCartas()->add(carta);
	}


}

void BatallaDigital::dispararConBarcoA(Casillero* casillero){
	if(casillero->getFicha() != NULL){
		if(casillero->getFicha()->getTipoFicha() == mina){

			this->removerFichaDeLista(casillero->getFicha()->getCoordenada(),this->buscarDuenioDeFicha(casillero->getFicha()->getNombreJugador()));
			casillero->setFicha(NULL);
			casillero->setEstado(bloqueado);
			casillero->setTurnosBloqueado(3);

		}else if(casillero->getFicha()->getTipoFicha() == avionRadar){
			stringstream convertiAEntero;
			int numeroJugador;

			convertiAEntero<<casillero->getFicha()->getNombreJugador();
			convertiAEntero>>numeroJugador;

			this->eliminarMinasDetectadas(this->jugadores->get(numeroJugador), casillero->getCoordenada());
			this->removerFichaDeLista(casillero->getFicha()->getCoordenada(),this->buscarDuenioDeFicha(casillero->getFicha()->getNombreJugador()));
			casillero->setFicha(NULL);
			casillero->setEstado(libre);

		}else{
					this->removerFichaDeLista(casillero->getFicha()->getCoordenada(),this->buscarDuenioDeFicha(casillero->getFicha()->getNombreJugador()));
					casillero->setFicha(NULL);
					casillero->setEstado(libre);
				}

	}
}

void BatallaDigital::detectarMinasConAvionRadar(Jugador* jugador, Coordenada* posicionDelAvionRadar){

	Lista<Coordenada*>* posicionesDeMInasEnemigas = jugador->getPosicionDeMinasDetectadasPorRadar();
	int centroX = posicionDelAvionRadar->getPosicionX();
	int centroY = posicionDelAvionRadar->getPosicionY();
	int centroZ = posicionDelAvionRadar->getPosicionZ();
	int inicioX ;
	int inicioY ;
	int inicioZ = 1;
	int finalX ;
	int finalY ;
	int finalZ = 5;


	inicioX = this->validarNumero(centroX,1,this->getTablero()->getLimiteX(),1);
	inicioY = this->validarNumero(centroY,1,this->getTablero()->getLimiteY(),1);;

	finalX = this->validarNumero(centroX,1,this->getTablero()->getLimiteX(),0);
	finalY = this->validarNumero(centroY,1,this->getTablero()->getLimiteY(),0);



	for(int z = inicioZ ; z <= finalZ ; z++){
		for(int y = inicioY ; y <= finalY ; y++){
			for(int x = inicioX ; x <= finalX ; x++){
				Casillero* casillero = this->buscarCasillero(x, y, z);

				if(casillero->getFicha() != NULL &&
						casillero->getFicha()->getTipoFicha() == mina &&
						casillero->getFicha()->getNombreJugador() != jugador->getSimbolo()){

					Coordenada* posicionDeMInaEnemiga = new Coordenada(x,y,z);
					posicionesDeMInasEnemigas->add(posicionDeMInaEnemiga);

				}

			}
		}
	}


}

void BatallaDigital::detectarMinasCOnAvionRadarAlIncioDeTurno(Jugador* jugador){

	jugador->getFichasDisponibles()->reiniciarCursor();

	while(jugador->getFichasDisponibles()->avanzarCursor()){
		Ficha* ficha = jugador->getFichasDisponibles()->getCursor();
		if(ficha->getTipoFicha() == avionRadar){

			Coordenada* posicionDelAvionRadar = ficha->getCoordenada();

			Lista<Coordenada*>* posicionesDeMInasEnemigas = jugador->getPosicionDeMinasDetectadasPorRadar();
			int centroX = posicionDelAvionRadar->getPosicionX();
			int centroY = posicionDelAvionRadar->getPosicionY();
			int centroZ = posicionDelAvionRadar->getPosicionZ();
			int inicioX ;
			int inicioY ;
			int inicioZ = 1;
			int finalX ;
			int finalY ;
			int finalZ = 5;


			inicioX = this->validarNumero(centroX,1,this->getTablero()->getLimiteX(),1);
			inicioY = this->validarNumero(centroY,1,this->getTablero()->getLimiteY(),1);;

			finalX = this->validarNumero(centroX,1,this->getTablero()->getLimiteX(),0);
			finalY = this->validarNumero(centroY,1,this->getTablero()->getLimiteY(),0);



			for(int z = inicioZ ; z <= finalZ ; z++){
				for(int y = inicioY ; y <= finalY ; y++){
					for(int x = inicioX ; x <= finalX ; x++){
						Casillero* casillero = this->buscarCasillero(x, y, z);

						if(casillero->getFicha() != NULL &&
								casillero->getFicha()->getTipoFicha() == mina &&
								casillero->getFicha()->getNombreJugador() != jugador->getSimbolo() &&
								this->estaEnLaListaDeMinasDetectadas(jugador, casillero->getCoordenada()) == false){

							Coordenada* posicionDeMInaEnemiga = new Coordenada(x,y,z);
							posicionesDeMInasEnemigas->add(posicionDeMInaEnemiga);

						}

					}
				}
			}


		}
	}
}


int BatallaDigital::validarNumero(int numero, int minimo, int maximo, int opcion){
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


bool BatallaDigital::estaEnLaListaDeMinasDetectadas(Jugador* jugador,Coordenada* aBuscar){

	jugador->getPosicionDeMinasDetectadasPorRadar()->reiniciarCursor();

	while(jugador->getPosicionDeMinasDetectadasPorRadar()->avanzarCursor()){
		if(jugador->getPosicionDeMinasDetectadasPorRadar()->getCursor()->compararCoordenadas(aBuscar)){
			return true;
		}
	}

	return false;

}

void BatallaDigital::eliminarMinasDetectadas(Jugador* jugador,  Coordenada* posicionDelAvionRadar){

	Lista<Coordenada*>* posicionesDeMInasEnemigas = jugador->getPosicionDeMinasDetectadasPorRadar();
	Lista<int>* posiciones = new Lista<int>();
	int contador = 1;
	int centroX = posicionDelAvionRadar->getPosicionX();
	int centroY = posicionDelAvionRadar->getPosicionY();
	int centroZ = posicionDelAvionRadar->getPosicionZ();
	int inicioX ;
	int inicioY ;
	int inicioZ = 1;
	int finalX ;
	int finalY ;
	int finalZ = 5;


	inicioX = this->validarNumero(centroX,1,this->getTablero()->getLimiteX(),1);
	inicioY = this->validarNumero(centroY,1,this->getTablero()->getLimiteY(),1);;

	finalX = this->validarNumero(centroX,1,this->getTablero()->getLimiteX(),0);
	finalY = this->validarNumero(centroY,1,this->getTablero()->getLimiteY(),0);



	for(int z = inicioZ ; z <= finalZ ; z++){
		for(int y = inicioY ; y <= finalY ; y++){
			for(int x = inicioX ; x <= finalX ; x++){
				Casillero* casillero = this->buscarCasillero(x, y, z);
				bool encontrado = false;
				int contarPosiciones = 1;
				int posicionABorrar = 0;
				Lista<Coordenada*>* lista = jugador->getPosicionDeMinasDetectadasPorRadar();

				lista->reiniciarCursor();
				while(lista->avanzarCursor() && encontrado == false){

					Coordenada* posicion = lista->getCursor();

					if(posicion->compararCoordenadas(casillero->getCoordenada())){
						posicionABorrar = contarPosiciones;
						encontrado = true;
					}
					contarPosiciones++;

				}

				int tamanioLista = lista->contarElementos();

				if(posicionABorrar >= 1 && posicionABorrar <= tamanioLista){
					lista->remover(posicionABorrar);
				}

			}
		}
	}

}

void BatallaDigital::usarAntiaereo(int numeroDeJugador){

	stringstream convertirAString;
	string nombreJugador;
	convertirAString<<numeroDeJugador;
	convertirAString>>nombreJugador;

	Lista<Ficha*>* fichas = this->jugadores->get(numeroDeJugador)->getFichasDisponibles();
	Lista<Coordenada*>* posiciones = this->jugadores->get(numeroDeJugador)->getPosicionDeMinasDetectadasPorRadar();

	int cantidadFichas = fichas->contarElementos();

	for(int i = cantidadFichas; i > 0; i--){
		if(fichas->get(i)->getTipoFicha() == avionRadar){
			Coordenada* poscion = fichas->get(i)->getCoordenada();
			this->buscarCasillero(poscion)->setFicha(NULL);
			this->buscarCasillero(poscion)->setEstado(libre);
			fichas->remover(i);
		}

	}

	int cantidadPosiciones = posiciones->contarElementos();

	for(int i = cantidadPosiciones; i > 0; i--){
		posiciones->remover(i);
	}

}

bool BatallaDigital::usarKamikaze(Ficha* kamikaze , Jugador* jugadorActual, int jugadorEnemigo){

	Lista<Ficha*>* fichasEnemigas = this->jugadores->get(jugadorEnemigo)->getFichasDisponibles();
	fichasEnemigas->reiniciarCursor();
	bool barcoEncontrado = false;
	Ficha* barcoEnemigo = NULL;
	while(fichasEnemigas->avanzarCursor() && barcoEncontrado == false ){
		if(fichasEnemigas->getCursor()->getTipoFicha() == barco){
			barcoEnemigo = fichasEnemigas->getCursor();
			barcoEncontrado = true;
		}
	}

	if(barcoEnemigo != NULL){
		Casillero* delBarco = this->buscarCasillero(barcoEnemigo->getCoordenada());
		this->removerFichaDeLista(barcoEnemigo->getCoordenada(),this->jugadores->get(jugadorEnemigo)->getFichasDisponibles());
		delBarco->setEstado(libre);
		delBarco->setFicha(NULL);

		Casillero* delAvion = this->buscarCasillero(kamikaze->getCoordenada());
		this->removerFichaDeLista(kamikaze->getCoordenada(),jugadorActual->getFichasDisponibles());
		delAvion->setEstado(libre);
		delAvion->setFicha(NULL);
		return true;
	}else{
		return false;
	}

}

bool BatallaDigital::usarAtaqueQuimico(Coordenada* posicion){


	int centroX = posicion->getPosicionX();
	int centroY = posicion->getPosicionY();
	int centroZ = posicion->getPosicionZ();
	int inicioX ;
	int inicioY ;
	int inicioZ ;
	int finalX ;
	int finalY ;
	int finalZ ;


	inicioX = this->validarRangoAtaqueQuimico(centroX,1,this->getTablero()->getLimiteX(),1);
	inicioY = this->validarRangoAtaqueQuimico(centroY,1,this->getTablero()->getLimiteY(),1);
	inicioZ = this->validarRangoAtaqueQuimico(centroZ,1,this->getTablero()->getLimiteZ(),1);

	finalX = this->validarRangoAtaqueQuimico(centroX,1,this->getTablero()->getLimiteX(),0);
	finalY = this->validarRangoAtaqueQuimico(centroY,1,this->getTablero()->getLimiteY(),0);
	finalZ = this->validarRangoAtaqueQuimico(centroZ,1,this->getTablero()->getLimiteZ(),0);



	for(int z = inicioZ ; z <= finalZ ; z++){
		for(int y = inicioY ; y <= finalY ; y++){
			for(int x = inicioX ; x <= finalX ; x++){
				Casillero* casillero = this->buscarCasillero(x, y, z);

				if(centroY-y == 2 || centroY-y == -2 || centroX-x == 2 || centroX-x == -2 || centroZ-z == 2 || centroZ-z == -2){

					if(casillero->getEstado() == bloqueado && casillero->getTurnosBloqueado() > 2){
						casillero->setEstado(bloqueado);
						//casillero->setTurnosBloqueado(2);
					}else{
						casillero->setEstado(bloqueado);
						casillero->setTurnosBloqueado(2);
					}


				}else if(centroY-y == 1 || centroY-y == -1 || centroX-x == 1 || centroX-x == -1 || centroZ-z == 1 || centroZ-z == -1){

					if(casillero->getEstado() == bloqueado && casillero->getTurnosBloqueado() > 4){
						casillero->setEstado(bloqueado);
						//casillero->setTurnosBloqueado(4);
					}else{
						casillero->setEstado(bloqueado);
						casillero->setTurnosBloqueado(4);
					}

				}else if(centroY == y && centroX == x && centroZ == z){

					if(casillero->getEstado() == bloqueado && casillero->getTurnosBloqueado() > 6){
						casillero->setEstado(bloqueado);
						//casillero->setTurnosBloqueado(4);
					}else{
						casillero->setEstado(bloqueado);
						casillero->setTurnosBloqueado(6);
					}

				}else{

					casillero->setEstado(bloqueado);
					casillero->setTurnosBloqueado(2);

				}

			}
		}
	}

	return true;
}

int BatallaDigital::validarRangoAtaqueQuimico(int numero, int minimo, int maximo, int opcion){

	if(opcion == 1){
		if(numero-2 > minimo){
			return numero - 2;
		}else{
			return minimo;
		}
	}

	if(opcion == 0){
		if(numero+2 < maximo){
			return numero + 2;
		}else{
			return maximo;
		}
	}

	return -1;

}

void BatallaDigital::revisarCasilleroBloqueados(){

	this->tablero->getTablero()->reiniciarCursor();
	int numeroCapa  = 1;
	while(this->tablero->getTablero()->avanzarCursor()){

		//cout<<"Capa"<<numeroCapa<<endl;
		//cout<<endl;
		this->tablero->getTablero()->getCursor()->reiniciarCursor();

		while(this->tablero->getTablero()->getCursor()->avanzarCursor()){

			this->tablero->getTablero()->getCursor()->getCursor()->reiniciarCursor();

			while(this->tablero->getTablero()->getCursor()->getCursor()->avanzarCursor()){
				Casillero* casillero = this->tablero->getTablero()->getCursor()->getCursor()->getCursor();

				if(casillero->getEstado() == bloqueado){

					//string simbolo = casillero->getFicha()->getSimbolo();
					if(casillero->getTurnosBloqueado()-1 > 0){
						casillero->setTurnosBloqueado(casillero->getTurnosBloqueado()-1);
					}else{
						casillero->setTurnosBloqueado(0);
						if(casillero->getFicha() != NULL && casillero->getFicha()->getTipoFicha() != mina){
							casillero->setEstado(ocupado);
						}else{
							casillero->setEstado(libre);
						}
					}

				}

			}
			//cout<<endl;
		}
		numeroCapa++;
		//cout<<endl;
	}

}

bool BatallaDigital::todasLasFichasBloqueadasDe(Jugador* jugador){

	bool bloqueadas = true;
	Lista<Ficha*>* fichas = jugador->getFichasDisponibles();

	fichas->reiniciarCursor();
	while(fichas->avanzarCursor() && bloqueadas == true){
		if(fichas->getCursor()->getTipoFicha() == barco || fichas->getCursor()->getTipoFicha() == soldado ){
			if(this->buscarCasillero(fichas->getCursor()->getCoordenada())->getEstado() != bloqueado){
				bloqueadas = false;
			}


		}
	}
	return bloqueadas;
}

void BatallaDigital::setCantidadSoldados(int cantidad){
	this->cantidadSoldados = cantidad;
}
