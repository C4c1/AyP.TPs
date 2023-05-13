#include <iostream>
#include "BatallaDigital.h"


int main() {

    int jugadores,soldados,minas;
    cout <<"Ingrese un numero de jugadores, uno de soldados y otro de minas"<<endl;
    cin>> jugadores;
    cin>> soldados;
    cin>> minas;
    BatallaDigital Batalla = BatallaDigital(jugadores,soldados,minas);

    Batalla.DarInformacion();
    return 0;
}
