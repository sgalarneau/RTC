/*
 * arret.cpp
 *
 *  Created on: 2016-09-24
 *      Author: etudiant
 */

#include "arret.h"

Arret::Arret(const std::vector<std::string>& ligne_gtfs)
	: m_heure_arrivee(stoul(ligne_gtfs[1].substr(0, 2)),
					  stoul(ligne_gtfs[1].substr(3, 2)),
					  stoul(ligne_gtfs[1].substr(6, 2))),
	  m_heure_depart(stoul(ligne_gtfs[2].substr(0, 2)),
					 stoul(ligne_gtfs[2].substr(3, 2)),
					 stoul(ligne_gtfs[2].substr(6, 2))) {

	m_station_id = stoul(ligne_gtfs[3]);
	m_numero_sequence = stoul(ligne_gtfs[4]);

}

const Heure& Arret::getHeureArrivee() const {
	return m_heure_arrivee;
}

void Arret::setHeureArrivee(const Heure& p_heureArrivee) {
	m_heure_arrivee = p_heureArrivee;
}

const Heure& Arret::getHeureDepart() const {
	return m_heure_depart;
}

void Arret::setHeureDepart(const Heure& p_heureDepart) {
	m_heure_depart = p_heureDepart;
}

unsigned int Arret::getNumeroSequence() const {
	return m_numero_sequence;
}

void Arret::setNumeroSequence(unsigned int p_numeroSequence) {
	m_numero_sequence = p_numeroSequence;
}

unsigned int Arret::getStationId() const {
	return m_station_id;
}

void Arret::setStationId(unsigned int stationId) {
	m_station_id = stationId;
}

std::string Arret::getVoyageId() const {
	return m_voyage_id;
}

void Arret::setVoyageId(const std::string& voyageId) {
	m_voyage_id = voyageId;
}

bool Arret::operator <(const Arret& p_other) const {
	return this->m_numero_sequence < p_other.getNumeroSequence();
}

bool Arret::operator >(const Arret& p_other) const {
	return this->m_numero_sequence > p_other.getNumeroSequence();
}

std::ostream & operator<<(std::ostream & flux, const Arret & p_arret) {
	return flux << p_arret.m_heure_arrivee << " - " << p_arret.m_station_id;
}



