/*
 * auxiliaires.cpp
 *
 *  Created on: 2016-09-25
 *      Author: etudiant
 */

#include <ctime>
#include "auxiliaires.h"

std::vector<std::string> split(const std::string& s, char delim) {
	std::vector<std::string> resultat;
	std::stringstream ss;
	ss.str(s);
	std::string element;

	while (std::getline(ss, element, delim)) {
		resultat.push_back(element);
	}

	return resultat;
}

void lireFichier(std::string nomFichier, std::vector<std::vector<std::string> >& resultats, char delimiteur, bool rm_entete) {
	std::ifstream fichier(nomFichier);
	std::string ligne;
	std::string ligneUn;

	if (!fichier) throw std::logic_error("L'ouverture du fichier : " + nomFichier + " a echoue");

	if (rm_entete) std::getline(fichier, ligneUn);

	while (std::getline(fichier, ligne)) {
		resultats.push_back(split(ligne, delimiteur));
		//std::cout << ligne << std::endl;
	}
}

Date::Date() {
	time_t t = time(0);
	struct tm now = *localtime( & t );

	m_an = now.tm_year;
	m_mois = now.tm_mon;
	m_jour = now.tm_mday;
}

Date::Date(unsigned int an, unsigned int mois, unsigned int jour) {
	m_an = an;
	m_mois = mois;
	m_jour = jour;
}

bool Date::operator ==(const Date& other) const {
	return this->m_an == other.m_an &&
		   this->m_mois == other.m_mois &&
		   this->m_jour == other.m_jour;
}

bool Date::operator <(const Date& other) const {
	return this->m_an < other.m_an &&
		   this->m_mois < other.m_mois &&
		   this->m_jour < other.m_jour;
}

bool Date::operator >(const Date& other) const {
	return this->m_an > other.m_an &&
		   this->m_mois > other.m_mois &&
		   this->m_jour > other.m_jour;
}

Heure::Heure() {
	time_t t = time(0);
	struct tm now = *localtime( & t );

	m_heure = now.tm_hour;
	m_min = now.tm_min;
	m_sec = now.tm_sec;
}

Heure::Heure(unsigned int heure, unsigned int min, unsigned int sec) {
	m_heure = heure;
	m_min = min;
	m_sec = sec;
}

Heure Heure::add_secondes(unsigned int secs) const {
	//Dans cette méthode, étant donnée que les secs ajouté
	//seront toujours positives (unsigned) on ne gère que l'ajout positif

	unsigned int sec = this->m_sec + secs,
				 min = this->m_min,
				 heure = this->m_heure;

	if (sec >= 60){
		sec -= 60;
		min += 1;

		if (min >= 60){
			min -= 60;
			heure += 1;
		}
	}

	//on prend comme hypothèse que l'heure maximale est 29:59:59
	if(heure >= 30) {
		throw std::invalid_argument( "L'heure maximale a été dépassée." );
	}

	return Heure(heure, min, sec);
}

bool Heure::operator ==(const Heure& other) const {
	return this->m_heure == other.m_heure &&
		   this->m_min == other.m_min &&
		   this->m_sec == other.m_sec;
}

bool Heure::operator <(const Heure& other) const {
	return this->m_heure < other.m_heure &&
		   this->m_min < other.m_min &&
		   this->m_sec < other.m_sec;
}

bool Heure::operator >(const Heure& other) const {
	return this->m_heure > other.m_heure &&
		   this->m_min > other.m_min &&
		   this->m_sec > other.m_sec;
}

bool Heure::operator <=(const Heure& other) const {
	return this->m_heure <= other.m_heure &&
		   this->m_min <= other.m_min &&
		   this->m_sec <= other.m_sec;
}

bool Heure::operator >=(const Heure& other) const {
	return this->m_heure >= other.m_heure &&
		   this->m_min >= other.m_min &&
		   this->m_sec >= other.m_sec;
}

int Heure::operator -(const Heure& other) const {
	unsigned int nbSec = this->m_heure * 3600 + this->m_min * 60 + this->m_sec;
	unsigned int nbSecOther = other.m_heure * 3600 + other.m_min * 60 + other.m_sec;

	return nbSec - nbSecOther;
}
