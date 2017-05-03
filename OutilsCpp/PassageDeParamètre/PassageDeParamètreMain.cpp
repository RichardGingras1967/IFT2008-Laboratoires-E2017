#include <iostream>
#include <string>

using namespace std;

string MettreEnMajuscule_valeur(string texte);
string MettreEnMajuscule_pointeur(string *texte);
string MettreEnMajuscule_reference(string &texte);
string MettreEnMajuscule_referenceConstante(const string &texte);

int main() {
	// Passage par valeur:
	string nom_original = "programmation";
	string nom_valeurResultat = MettreEnMajuscule_valeur(nom_original);
	cout << "Le passage par valeur fait une copie temporaire des paramètres." << endl;
	cout << "La variable originale reste inchangée." << endl;
	cout << "Variable originale : " << nom_original << endl;
	cout << "Valeur retournée : " << nom_valeurResultat << endl;

	cout << endl;

	// Passage par adresse:
	nom_original = "programmation";
	nom_valeurResultat = MettreEnMajuscule_pointeur(&nom_original);
	cout << "Le passage par adresse (pointeur) transmet l'adresse à la fonction." << endl;
	cout << "Une modification sur le contenu du pointeur dans la fonction modifiera la variable originale." << endl;
	cout << "Variable originale : " << nom_original << endl;
	cout << "Valeur retournée : " << nom_valeurResultat << endl;

	cout << endl;

	// Passage par référence:
	nom_original = "programmation";
	nom_valeurResultat = MettreEnMajuscule_reference(nom_original);
	cout << "Le passage par référence envoie un alias à la fonction." << endl;
	cout << "Une modification à cette alias modifiera la valeur de la variable originale." << endl;
	cout << "Variable originale : " << nom_original << endl;
	cout << "Valeur retournée : " << nom_valeurResultat << endl;

	cout << endl;

	// Passage par référence constante:
	nom_original = "programmation";
	nom_valeurResultat = MettreEnMajuscule_referenceConstante(nom_original);
	cout << "Le passage par référence constante permet de protéger les données de la variables originale." << endl;
	cout << "Il est donc impossible de modifier la valeur de l'alias à l'intéieur de la fonction." << endl;
	cout << "Variable originale : " << nom_original << endl;
	cout << "Valeur retournée : " << nom_valeurResultat << endl;

	cout << endl;

	cout << "Questions :" << endl;
	cout << "Quand utiliser le passage par valeur?" << endl;
	cout << "Quelle technique est la plus coûteuse?" << endl;
	cout << "Quelle technique devrait-on prévilégier?" << endl;

	return 0;
}

string MettreEnMajuscule_valeur(string texte) {
	for (size_t i = 0; i < texte.size(); i++) {
		texte[i] = toupper(texte[i]);
	}
	return texte;
}

string MettreEnMajuscule_pointeur(string *texte) {
	for (size_t i = 0; i < texte->size(); i++) {
		(*texte)[i] = toupper((*texte)[i]);
	}
	return *texte;
}

string MettreEnMajuscule_reference(string &texte) {
	for (size_t i = 0; i < texte.size(); i++) {
		texte[i] = toupper(texte[i]);
	}
	return texte;
}

string MettreEnMajuscule_referenceConstante(const string &texte) {
	string copieTexte = texte;
	for (size_t i = 0; i < texte.size(); i++) {
		copieTexte[i] = toupper(texte[i]);
	}

	return copieTexte;
}
