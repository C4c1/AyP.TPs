#include "BatallaDigital.h"

void BatallaDigital::inicializarJugadores(int soldados, int minas){
    for(int i = 0; i < this->numJugadores; i++){
        this->jugadores[i].cantSoldados = soldados;
        this->jugadores[i].cantMinas = minas;
    }
}

/*
BatallaDigital::BatallaDigital() {
    this->jugadores = new Jugador[2];
    this->numJugadores = 2;
    inicializarJugadores(4, 10);
    inicializarJugadores(4,10);
}
*/

BatallaDigital::BatallaDigital(int jugadores, int soldados, int minas) {
    this->jugadores = new Jugador[jugadores];
    this->numJugadores = jugadores;
    inicializarJugadores(soldados, minas);
}

void BatallaDigital::DarInformacion() {

    cout << "Numero de jugadores: "<< numJugadores <<endl;
    cout << "Numero de soldados: "<< this->jugadores[0].cantSoldados<<endl;
    cout << "Numero de minas: "<< this->jugadores[0].cantMinas<<endl;

}

BatallaDigital::~BatallaDigital() {
    delete [] jugadores;
}