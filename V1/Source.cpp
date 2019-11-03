#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int mostrarMenu();
void MostrarCabeceraMenu();
void MostrarOpcionesMenu();
string fichaToString(short int izq, short int dcha);
void mostrarTablero(short int fichaN1, short int fichaN2, string tablero, int numColocadas, int numRobadas);
void mostrarCabeceraTablero();
short int aleat();
bool puedoPonerIzq(string tablero, short int fichaN1, short int fichaN2);
bool puedoPonerDcha(string tablero, short int fichaN1, short int fichaN2);
string ponerIzq(string tablero, short int fichaN1, short int fichaN2);
string ponerDcha(string tablero, short int fichaN1, short int fichaN2);

int main() {

	srand(time(NULL));

	int eleccion; 
	int fichasRobadas = 0; 
	int fichasColocadas = 0; 
	int n1; 
	int n2; 
	string fichaActual; 
	string tablero; 

	tablero = fichaToString(aleat(), aleat());
	eleccion = mostrarMenu();

	while (eleccion != 0) {

		if (eleccion == 1) {
			if (puedoPonerIzq(tablero, n1, n2)) {
				tablero = ponerIzq(tablero, n1, n2);
				fichasColocadas++;
			}
		}
		else if (eleccion == 2) {
			if (puedoPonerDcha(tablero, n1, n2)) {
				tablero = ponerDcha(tablero, n1, n2);
				fichasColocadas++; 
				
			}
		}
		else if (eleccion == 3) {
			n1 = aleat();
			n2 = aleat();
			fichaActual = fichaToString(n1, n2);
			fichasRobadas++; 
		}
		mostrarTablero(n1, n2, tablero, fichasColocadas, fichasRobadas);
		eleccion = mostrarMenu(); 
	}
	
	return 0;
}

int mostrarMenu() {

	int opcion;

	MostrarCabeceraMenu(); 
	MostrarOpcionesMenu();

	cout<<"Elija opcion: "; 
	cin >> opcion; 

	if (opcion < 0 || opcion > 3) {
	
		mostrarMenu(); 	
	}
	


	return opcion;
}

void MostrarCabeceraMenu() {
	cout << "  ------------------------- " << endl;
	cout << " | ";
	cout << "    MENU OPCIONES   " << "    | " << endl;

	cout << "  ------------------------- " << endl;
}

void MostrarOpcionesMenu() {
	cout << "1. Poner ficha por la izquierda" << endl; 
	cout << "2. Poner ficha por la derecha" << endl; 
	cout << "3. Robar ficha nueva" << endl; 
	cout << "0. Salir" << endl;
}

string toStr(int n) {

	string numero; 

	numero = char(int('0') + n);

	return numero;
}


string fichaToString(short int izq, short int dcha) {
	return   "|"  + toStr(izq) +"-" + toStr(dcha) + "|";
}

void mostrarTablero(short int fichaN1, short int fichaN2, string tablero, int numColocadas, int numRobadas) {
	mostrarCabeceraTablero(); 
	cout << tablero<<endl;
	cout << "Fichas colocadas: " << numColocadas << " - Fichas robadas: " << numRobadas << endl; 
	cout<<"Ficha jugador: " << fichaToString(fichaN1, fichaN2) << endl;
	

}

void mostrarCabeceraTablero() {
	cout << "  ------------------------- " << endl;
	cout << " | ";
	cout << "   TABLERO           " << "    | " << endl;

	cout << "  ------------------------- " << endl;
	cout << endl;
}

short int aleat() {
	return 0 + rand() % (6 + 1 - 0); 
}

bool puedoPonerIzq(string tablero, short int fichaN1, short int fichaN2) {
	
	return  (int(tablero[1]) - int('0')) == fichaN2;
}

bool puedoPonerDcha(string tablero, short int fichaN1, short int fichaN2) {
	
	return (int(tablero[tablero.size() - 2]) - int('0'))== fichaN1;
}

string ponerIzq(string tablero, short int fichaN1, short int fichaN2) {

	return fichaToString(fichaN1, fichaN2) + tablero; 

}
string ponerDcha(string tablero, short int fichaN1, short int fichaN2) {
	return tablero + fichaToString(fichaN1, fichaN2);
}

