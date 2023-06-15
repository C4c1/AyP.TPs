/*
 * main.cpp
 *
 *  Created on: 21 may 2023
 *      Author: David
 */
#include"BatallaDigital.h"
#include<string>
#include"Carta.h"
#include<cstdlib>
//#include"Pila.h"
#include"Menu.h"
using namespace std;
int main(){

	Menu* menu = new Menu();
	menu->iniciarJuego();
	delete menu;

	return 0;
}


