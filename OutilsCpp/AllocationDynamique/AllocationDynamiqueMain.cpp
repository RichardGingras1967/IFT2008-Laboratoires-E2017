#include <iostream>

using namespace std;

int main() {
	// Allocation dynamique d'un entier
	int *x = new int;
	*x = 42;
	cout << "Valeur de x : " << *x << endl;

	// Allocation dynamique d'un tableau d'entier
	int *tableau = new int[10];

	// Allocation dynamique d'un tableau à deux dimensions
	int tailleDim1 = 10;
	int tailleDim2 = 5;
	int **tableau2D = new int*[tailleDim1];
	for (auto i = 0; i < tailleDim1; i++) {
		tableau2D[i] = new int[tailleDim2];
	}
	// tableau2D[ligne][colonne]

	// Désallouer la mémoire
	delete x;
	delete[] tableau;
	for (auto i = 0; i < tailleDim1; i++) {
		delete[] tableau2D[i];
	}
	delete[] tableau2D;
}

