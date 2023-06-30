#include"Tablero.h"


Tablero::Tablero(int limiteX,int limiteY,int limiteZ){

	this->limiteX = limiteX;
	this->limiteY = limiteY;
	this->limiteZ = limiteZ;
	this->tablero = new Lista<Lista<Lista<Casillero*>*>*>();
	//this->crearTablero();
}

Lista<Lista<Lista<Casillero*>*>*>* Tablero::getTablero(){
	return this->tablero;
}

void Tablero::crearTablero(){
	for(int posicionZ = 0;posicionZ<this->limiteZ;posicionZ++){

		Lista<Lista<Casillero*>*>* nivelUno = new Lista<Lista<Casillero*>*>();

		for(int posicionY = 0;posicionY<this->limiteY;posicionY++){

			Lista<Casillero*>* nivelDos = new Lista<Casillero*>();

			for(int posicionX = 0;posicionX<this->limiteX;posicionX++){

				Casillero* nuevaCasilla = new Casillero(posicionX+1,posicionY+1,posicionZ+1);
				nivelDos->add(nuevaCasilla);
				//delete nuevaCasilla;

			}

			nivelUno->add(nivelDos);

		}

		this->tablero->add(nivelUno);

	}
}

int Tablero::getLimiteX(){
	return this->limiteX;
}

int Tablero::getLimiteY(){
	return this->limiteY;
}

int Tablero::getLimiteZ(){
	return this->limiteZ;
}

void Tablero::setLimiteX(int nuevoLimite){
	this->limiteX = nuevoLimite;
}

void Tablero::setLimiteY(int nuevoLimite){
	this->limiteY = nuevoLimite;
}

void Tablero::setLimiteZ(int nuevoLimite){
	this->limiteZ = nuevoLimite;
}

Tablero::~Tablero(){
	Lista<Lista<Lista<Casillero*>*>*>* nivelUno = this->tablero;
	nivelUno->reiniciarCursor();
	while(nivelUno->avanzarCursor()){
		Lista<Lista<Casillero*>*>* nivelDos = nivelUno->getCursor();
		nivelDos->reiniciarCursor();
		while(nivelDos->avanzarCursor()){

			Lista<Casillero*>* nivelTres = nivelDos->getCursor();

			nivelTres->reiniciarCursor();
			while(nivelTres->avanzarCursor()){
				Casillero* aRemover = nivelTres->getCursor();
				delete aRemover;
			}
			delete nivelTres;
		}
		delete nivelDos;
	}
	delete nivelUno;
}

void Tablero::imprimirTablero() {
    RGBApixel lightGray;
    lightGray.Red = 192;
    lightGray.Green = 192;
    lightGray.Blue = 192;


	int cursorI = 25;
	int cursorJ = 30;
	int fontHeight = 10;
	int largoX = this->getLimiteX();
	int largoY = this->getLimiteY();
	int largoZ = this->getLimiteZ();

    BMP window;
    window.SetSize((largoX * 33) + 50, (((largoY * 2 * (fontHeight + 2)) + 18) * largoZ) + 30 );
    for (int j = 0 ; j < window.TellHeight() ; j++) {
        for (int i = 0 ; i < window.TellWidth() ; i++) {
            *window(i, j) = lightGray;
        }
    }

    RGBApixel fontColor;
    fontColor.Red = 0;
    fontColor.Green = 0;
    fontColor.Blue = 0;

    char tituloTablero [20] = "Tablero INICIAL";
    PrintString( window, tituloTablero, cursorI + 50 , cursorJ - 20, fontHeight, fontColor );

	Lista<Lista<Lista<Casillero*>*>*>* auxiliar1 = this->getTablero();
	auxiliar1->reiniciarCursor();

    while(cursorJ + 2 * fontHeight + 2 < window.TellHeight() && auxiliar1->avanzarCursor()){

		int y = 1;
		Lista<Lista<Casillero*>*>* auxiliar2 = auxiliar1->getCursor();
		auxiliar2->reiniciarCursor();

		while(auxiliar2->avanzarCursor()){

			int x = 1;
			char auxCharText [5];
			strcpy( auxCharText , "   |");
			char lineText [5];
			strcpy( lineText , "---|");



			Lista<Casillero*>* auxiliar3 = auxiliar2->getCursor();
			auxiliar3->reiniciarCursor();

			int advancedCursorI = cursorI;
            while(auxiliar3->avanzarCursor()){
            	Casillero* auxiliar4 = auxiliar3->getCursor();

                auxCharText[1] = auxiliar4->getSimbolo()[0];
				if (x == largoX) {
					auxCharText[3] = ' ';
				}
				PrintString( window, auxCharText, advancedCursorI, cursorJ, fontHeight, fontColor );
				advancedCursorI = advancedCursorI + 33;

				x++;
            }
            cursorJ += (fontHeight + 2);

			advancedCursorI = cursorI;
			if (y != largoY) {
				for (int i = 1; i <= largoX; i++) {
					if (i == largoX) {
						lineText[3] = ' ';
					}
	                PrintString( window, lineText, advancedCursorI, cursorJ, fontHeight, fontColor );
					advancedCursorI = advancedCursorI + 33;
	            }
				cursorJ += (fontHeight + 2);
			}

			y++;
		}

		cursorJ += (fontHeight + 20);
	}


	window.WriteToFile( "TableroJugador.bmp");
}

void Tablero::imprimirTablero(string simboloJugador) {
    RGBApixel lightGray;
    lightGray.Red = 192;
    lightGray.Green = 192;
    lightGray.Blue = 192;


	int cursorI = 25;
	int cursorJ = 30;
	int fontHeight = 10;
	int largoX = this->getLimiteX();
	int largoY = this->getLimiteY();
	int largoZ = this->getLimiteZ();

    BMP window;
    window.SetSize((largoX * 33) + 50, (((largoY * 2 * (fontHeight + 2)) + 18) * largoZ) + 30 );

    for (int j = 0 ; j < window.TellHeight() ; j++) {
        for (int i = 0 ; i < window.TellWidth() ; i++) {
            *window(i, j) = lightGray;
        }
    }

    RGBApixel fontColor;
    fontColor.Red = 0;
    fontColor.Green = 0;
    fontColor.Blue = 0;

    RGBApixel fichaColor;
    fichaColor.Red = 150;
    fichaColor.Green = 0;
    fichaColor.Blue = 0;

    char tituloTablero [20] = "Tablero Jugador ";
    strcat(tituloTablero, simboloJugador.c_str());
    PrintString( window, tituloTablero, cursorI + 50 , cursorJ - 20, fontHeight, fontColor );

	Lista<Lista<Lista<Casillero*>*>*>* auxiliar1 = this->getTablero();
	auxiliar1->reiniciarCursor();


    while(cursorJ + 2 * fontHeight + 2 < window.TellHeight() && auxiliar1->avanzarCursor()){

		int y = 1;
		int filaActual = 1;

		Lista<Lista<Casillero*>*>* auxiliar2 = auxiliar1->getCursor();
		auxiliar2->reiniciarCursor();

		while(auxiliar2->avanzarCursor()){

			int x = 1;
			char auxCharText [5];
			strcpy( auxCharText , "   |");
			char lineText [5];
			strcpy( lineText , "---|");

			Lista<Casillero*>* auxiliar3 = auxiliar2->getCursor();
			auxiliar3->reiniciarCursor();

			int advancedCursorI = cursorI;


			/*string simbolo;
			stringstream ss;
			int numeroFila = filaActual;
			char numeroReferencia[0];
			ss << numeroFila;
			ss >> simbolo;
			strcpy(numeroReferencia,simbolo.c_str());
			PrintString( window, numeroReferencia, cursorI - 3 , cursorJ , fontHeight, fontColor );
			filaActual++;
			*/

			if(filaActual > largoY ){
				filaActual = 1;
			}


			//imprime en pantalla la hilera en eje X
            while(auxiliar3->avanzarCursor()){
            	Casillero* auxiliar4 = auxiliar3->getCursor();

            	if(auxiliar4->getFicha() != NULL  ){
            		if(auxiliar4->getFicha()->getNombreJugador() == simboloJugador){
            			auxCharText[1] = auxiliar4->getFicha()->getSimbolo()[0];
            			PrintString( window, auxCharText, advancedCursorI, cursorJ, fontHeight, fichaColor );

            		}else{
            			auxCharText[1] = auxiliar4->getSimbolo()[0];
            			PrintString( window, auxCharText, advancedCursorI, cursorJ, fontHeight, fontColor );
            		}

            		if (x == largoX) {
            		    auxCharText[3] = ' ';
            		    PrintString( window, auxCharText, advancedCursorI, cursorJ, fontHeight, fontColor );
            		}



            	}else{
            		auxCharText[1] = auxiliar4->getSimbolo()[0];

            		if (x == largoX) {
            		    auxCharText[3] = ' ';
            		}

            		PrintString( window, auxCharText, advancedCursorI, cursorJ, fontHeight, fontColor );
            	}


            	advancedCursorI = advancedCursorI + 33;

				x++;

            }


            cursorJ += (fontHeight + 2);


			advancedCursorI = cursorI;
			if (y != largoY) {
				for (int i = 1; i <= largoX; i++) {
					if (i == largoX) {
						lineText[3] = ' ';
					}
	                PrintString( window, lineText, advancedCursorI, cursorJ, fontHeight, fontColor );
					advancedCursorI = advancedCursorI + 33;
	            }
				cursorJ += (fontHeight + 2);
			}

			y++;
		}

		cursorJ += (fontHeight + 20);
	}


	window.WriteToFile( "TableroJugador.bmp");
}



