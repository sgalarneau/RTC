/*
 * station.cpp
 *
 *  Created on: 2016-09-24
 *      Author: etudiant
 */

#include "station.h"
#include "coordonnees.h"
#include "voyage.h"

Station::Station(const std::vector<std::string>& ligne_gtfs)
	: m_coords(stod(ligne_gtfs[3]),
			   stod(ligne_gtfs[4])) {

	m_id = stoul(ligne_gtfs[0]);
	m_nom = ligne_gtfs[1];
	m_description = ligne_gtfs[2];

	m_voyages_passants = std::vector<Voyage*>();
}


const Coordonnees& Station::getCoords() const {
	return m_coords;
}

void Station::setCoords(const Coordonnees& coords) {
	m_coords = coords;
}

const std::string& Station::getDescription() const {
	return m_description;
}

void Station::setDescription(const std::string& description) {
	m_description = description;
}

std::vector<Ligne*> Station::getLignesPassantes() const {
	std::vector<Ligne*> lignesPassantes = std::vector<Ligne*>();

	for(int i = 0; i <= m_voyages_passants.size(); i++){
		lignesPassantes.push_back(m_voyages_passants[i]->getLigne());
	}

	return lignesPassantes;
}

const std::string& Station::getNom() const {
	return m_nom;
}

void Station::setNom(const std::string& nom) {
	m_nom = nom;
}

unsigned int Station::getId() const {
	return m_id;
}

void Station::setId(unsigned int stationId) {
	m_id = stationId;
}

const std::vector<Voyage*>& Station::getVoyagesPassants() const {
	return m_voyages_passants;
}

void Station::addVoyage(Voyage* ptr_voyage) {
	m_voyages_passants.push_back(ptr_voyage);
}

double Station::distance(const Station& p_station) const {
	return this->getCoords() - p_station.getCoords();
}

std::ostream& operator<<(std::ostream& flux, const Station& p_station) {
	return flux << p_station.m_id << " - " << p_station.m_nom;
}
