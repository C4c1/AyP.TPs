/*
 * main.cpp
 *
 *  Created on: 21 may 2023
 *      Author: David
 */
#include"BatallaDigital.h"
#include<string>
#include"Carta.h"
#include"Pila.h"
#include"Menu.h"
using namespace std;
int main(){
	/*
	BatallaDigital* batallaDigital = new BatallaDigital(6,4,7,2,2);
	Ficha* ficha = new Ficha(soldado);
	batallaDigital->colocarFicha(ficha,1,3,5);
	batallaDigital->cargarMapa();
	batallaDigital->mostrarTablero();
	*/

	Menu* menu = new Menu();
	menu->iniciarJuego();


	return 0;
}


