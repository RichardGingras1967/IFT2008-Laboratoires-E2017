#include <iostream>
#include "Date.h"
using namespace std;

struct sDate {
	// passe a la structure un objet Date dans le constructeur
	// Dans le fond une structure fonctionne comme une classe

	util::Date m_date;
	sDate(util::Date &date) :
			m_date(date) {

	}

	void ajouteUneJournee(long nbJour) {
		m_date.ajouteNbJour(nbJour);
		//cout << "passage par copie" << endl;
		//cout << m_date.reqDateFormatee() << endl;
	}

	void ajouteUneJournee(long &nbJour) {
		m_date.ajouteNbJour(nbJour);
		//cout << "passage par reference" << endl;
		//cout << m_date.reqDateFormatee() << endl;
	}

	void ajouteUneJournee(long *nbJour) {
		m_date.ajouteNbJour(*nbJour);
		//cout << "passage par pointeur" << endl;
		//cout << m_date.reqDateFormatee() << endl;
	}
};

string fctRecevantLaStructure(const sDate &sd) {
	cout << "la structure est passe a la fonction par reference" << endl;

	string d = sd.m_date.reqDateFormatee();

	return d;

}

string fctRecevantLaStructure(sDate *sd) {
	cout << "la structure est passe a la fonction par pointeur" << endl;
	cout << "la date + 3 jour est retourne " << endl;
	sd->ajouteUneJournee(3);
	string d = sd->m_date.reqDateFormatee();

	return d;

}
int main() {
	util::Date dateNaissance(20, 01, 1972);
	sDate sdate(dateNaissance);
	//sdate.ajouteUneJournee(15);
	//long i = 30;
	sDate *ptr(0);
	//long *iptr(0);
	//iptr = &i;
	ptr = &sdate;
	//ptr->ajouteUneJournee(iptr);
	//ptr->ajouteUneJournee(&i);

	cout << fctRecevantLaStructure(sdate) << endl;
	cout << fctRecevantLaStructure(ptr);
	return 0;
}

