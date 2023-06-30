#include"BatallaDigital.h"
#include<string>
#include"Carta.h"
#include<cstdlib>
#include"Menu.h"
using namespace std;

int main(){

	Menu* menu = new Menu();
	menu->iniciarJuego();
	delete menu;

	return 0;
}


