/*
 * voyage.cpp
 *
 *  Created on: 2016-09-25
 *      Author: etudiant
 */


#include "voyage.h"

Voyage::Voyage(const std::vector<std::string>& ligne_gtfs, Ligne* p_ligne) {

	m_id = stoul(ligne_gtfs[2]);
	m_service_id = stoul(ligne_gtfs[1]);
	m_destination = ligne_gtfs[3];

	m_ligne = p_ligne;

	m_arrets = std::vector<Arret>();
}

Arret& Voyage::arretDeLaStation(unsigned int p_num_station) {
	Arret* arretTrouve;

	for(int i = 0; i < m_arrets.size(); i++){
		if(m_arrets[i].getStationId() == p_num_station) {
			arretTrouve = &m_arrets[i];
		}
	}

	return *arretTrouve;
}

std::vector<Arret> Voyage::getArrets() const {
	return m_arrets;
}

const std::string& Voyage::getDestination() const {
	return m_destination;
}

void Voyage::setDestination(const std::string& p_destination) {
	m_destination = p_destination;
}

std::string Voyage::getId() const {
	return m_id;
}

void Voyage::setId(std::string p_id) {
	m_id = p_id;
}

Ligne* Voyage::getLigne() const {
	return m_ligne;
}

void Voyage::setLigne(Ligne* p_ligne) {
	m_ligne = p_ligne;
}

std::string Voyage::getServiceId() const {
	return m_service_id;
}

void Voyage::setServiceId(std::string p_service_id) {
	m_service_id = p_service_id;
}

Heure Voyage::getHeureDepart() const {
}

Heure Voyage::getHeureFin() const {
}

void Voyage::setArrets(std::vector<Arret>& resultat) {
}

bool Voyage::operator <(const Voyage& p_other) const {
}

bool Voyage::operator >(const Voyage& p_other) const {
}