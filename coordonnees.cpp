/*
 * coordonnees.cpp
 *
 *  Created on: 2016-09-24
 *      Author: etudiant
 */

#include <cmath>
#include "coordonnees.h"

const int RAYON_TERRE = 6371;

Coordonnees::Coordonnees(double latitude, double longitude) {
	m_latitude = latitude;
	m_longitude = longitude;
}

double Coordonnees::getLatitude() const {
	return m_latitude;
}

void Coordonnees::setLatitude(double latitude) {
	m_latitude = latitude;
}

double Coordonnees::getLongitude() const {
	return m_longitude;
}

void Coordonnees::setLongitude(double longitude) {
	m_longitude = longitude;
}

bool Coordonnees::is_valide_coord(double p_latitude, double p_longitude) {
	return abs(p_latitude) <= 90 &&
		   abs(p_longitude) <= 180;
}

double Coordonnees::operator -(const Coordonnees& other) const {
	double varLatitude = other.getLatitude() - this->getLatitude();
	double varLongitude = other.getLongitude() - this->getLongitude();

	double partieGauche = pow(sin(varLatitude/2), 2);
	double partieDroite = cos(this->getLongitude()) * cos(other.getLongitude()) * pow(sin(varLongitude/2), 2);


	return 2 * RAYON_TERRE * asin(sqrt(partieGauche + partieDroite));
}


std::ostream & operator<<(std::ostream & flux, const Coordonnees & p_coord) {
	return flux << p_coord.getLatitude() << ", " << p_coord.getLongitude();
}



