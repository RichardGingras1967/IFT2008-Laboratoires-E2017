#include <iostream>

using namespace std;

class ObjetQuelconque {
};

int main() {
	// Déclaration de pointeurs et opérateur *
	char *ptChar; // pointeur sur un caractère
	float *ptFloat; // pointeur sur un réel
	ObjetQuelconque *ptObjet; // pointeur sur un objet
	int *ptInt;
	// ...

	// Opérateur &
	int x = 0;
	ptInt = &x; // ici, l'opérateur & désigne l'adresse de la variable x, on peut donc l'affecter au pointeur.
	int &y = x; // on peut aussi créer une seconde référence (alias) à un objet

	cout << "Valeur de x : " << x << endl;
	cout << "Valeur du pointeur ptInt : " << ptInt << endl;
	cout << "Valeur du pointeur ptInt déréférencé : " << *ptInt << endl;
	cout << "Valeur de y : " << y << endl;

	cout << endl << "Affectation de 14 à la variable y..." << endl << endl;
	y = 14;

	cout << "Valeur de x : " << x << endl;
	cout << "Valeur du pointeur ptInt déréférencé : " << *ptInt << endl;
	cout << "Valeur de y : " << y << endl;

	return 0;
}
