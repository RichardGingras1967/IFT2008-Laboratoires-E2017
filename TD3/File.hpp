#include "ContratException.h"
#include <iostream>
#include <sstream>

namespace labPileFile {

template<typename T>
labPileFile::File<T>::File(const int constInt) :
		m_tab(new T *[constInt]), m_tete(constInt / 2), m_queue(constInt / 2), m_tailleMax(0), m_cardinalite(0) {
}

template<typename T>
labPileFile::File<T>::File(const File<T>& file) :
		m_tab(new T *[file.MAX_FILE]), m_tete(file.MAX_FILE / 2), m_queue(file.MAX_FILE / 2), m_tailleMax(0), m_cardinalite(
				0) {
	_copier(file);
}

template<typename T>
labPileFile::File<T>::~File() {
	//_detruire();
	//delete m_tab;
}

template<typename T>
const File<T>& labPileFile::File<T>::operator =(const File<T>& file) {
	if (this != &file) {
		_detruire();
		_copier(file);
	}

	return *this;
}

template<typename T>
void labPileFile::File<T>::enfiler(const T& enfile) {

	m_tab[m_tete] = new T(enfile);
	m_tete -= 1;
	m_cardinalite += 1;
}

template<typename T>
T labPileFile::File<T>::defiler() {
	T defile;
	defile = **(m_tab + m_queue);
	delete *(m_tab + m_queue);
	m_queue -= 1;
	m_cardinalite -= 1;

	return defile;
}

template<typename T>
int labPileFile::File<T>::taille() const {
	return m_cardinalite;
}

template<typename T>
bool labPileFile::File<T>::estVide() const {
	return m_cardinalite == 0;
}

template<typename T>
bool labPileFile::File<T>::estPleine() const {
	return m_cardinalite == MAX_FILE;
}

template<typename T>
const T& labPileFile::File<T>::premier() const {
	return **(m_tab + m_queue);
}

template<typename T>
const T& labPileFile::File<T>::dernier() const {
	return **(m_tab + m_tete + 1);
}

template<typename T>
T labPileFile::File<T>::operator [](const int& nb) const {
	PRECONDITION(nb >= 0);
	PRECONDITION(nb <= m_cardinalite);
	return **(m_tab + m_tete + m_cardinalite - nb);
}

template<typename T>
void labPileFile::File<T>::verifieInvariant() const {
	INVARIANT(m_cardinalite == m_queue - m_tete);
}

template<typename T>
void labPileFile::File<T>::_detruire() {

	while (*(m_tab + m_tete) != *(m_tab + m_queue)) {
		delete *(m_tab + m_tete);
		*(m_tab + m_tete) = 0;
		m_tete += 1;
	}

	m_cardinalite = 0;
}

template<typename T>
void labPileFile::File<T>::_copier(const File<T>& source) {

	for (int i = 0; i < source.taille(); ++i) {

		enfiler(**(source.m_tab + source.m_tete + source.m_cardinalite - i));
	}
}
template<typename U>
std::ostream& operator <<(std::ostream& p_out, const File<U>& p_source) {

	p_out << "[";
	for (int i = 0; i < p_source.taille(); ++i) {
		p_out << p_source[i] << ",";
	}
	p_out << "]";
	return p_out;
}

} //Fin du namespace
