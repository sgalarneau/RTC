/*
 * ligne.cpp
 *
 *  Created on: 2016-09-24
 *      Author: etudiant
 */


#include "ligne.h"

const std::string CATEGORIE_BUS_METRO_BUS_HEX = "97BF0D";
const std::string CATEGORIE_BUS_LEBUS_HEX = "013888";
const std::string CATEGORIE_BUS_EXPRESS_HEX = "E04503";
const std::string CATEGORIE_BUS_COUCHE_TARD_NOIR_HEX = "1A171B";
const std::string CATEGORIE_BUS_COUCHE_TARD_BLEU_HEX = "003888";

const std::string CATEGORIE_BUS_DESCRIPTIONS[] = { "METRO_BUS",
												   "LEBUS",
												   "EXPRESS",
												   "COUCHE_TARD" };

Ligne::Ligne(const std::vector<std::string>& ligne_gtfs) {
	m_id = stoul(ligne_gtfs[0]);
	m_numero = ligne_gtfs[2];
	m_description = ligne_gtfs[4];

	m_categorie = this->couleurToCategorie(ligne_gtfs[7]);

	m_voyages = std::vector<Voyage*>();
}

CategorieBus Ligne::couleurToCategorie(std::string couleur) {
	CategorieBus categorieBusCorrespondant;

	if(couleur == CATEGORIE_BUS_METRO_BUS_HEX){
		categorieBusCorrespondant = CategorieBus::METRO_BUS;
	} else if(couleur == CATEGORIE_BUS_LEBUS_HEX){
		categorieBusCorrespondant = CategorieBus::LEBUS;

	} else if(couleur == CATEGORIE_BUS_EXPRESS_HEX){
		categorieBusCorrespondant = CategorieBus::EXPRESS;

	} else if(couleur == CATEGORIE_BUS_COUCHE_TARD_NOIR_HEX ||
			couleur == CATEGORIE_BUS_COUCHE_TARD_BLEU_HEX){
		categorieBusCorrespondant = CategorieBus::COUCHE_TARD;
	} else {
		throw std::invalid_argument( "Aucune valeur ne correspond à \"" + couleur + "\"" );
	}

	return categorieBusCorrespondant;
}

std::string Ligne::categorieToString(CategorieBus c) {
	std::string couleurHexCorrespondante;

	switch(c){
		case CategorieBus::METRO_BUS:
			couleurHexCorrespondante = CATEGORIE_BUS_METRO_BUS_HEX;
			break;
		case CategorieBus::LEBUS:
			couleurHexCorrespondante = CATEGORIE_BUS_LEBUS_HEX;
			break;
		case CategorieBus::EXPRESS:
			couleurHexCorrespondante = CATEGORIE_BUS_EXPRESS_HEX;
			break;
		case CategorieBus::COUCHE_TARD:
			//On va donner la couleur noir par défaut
			couleurHexCorrespondante = CATEGORIE_BUS_COUCHE_TARD_NOIR_HEX;
			break;
	}

	return couleurHexCorrespondante;
}


CategorieBus Ligne::getCategorie() const {
	return m_categorie;
}

void Ligne::setCategorie(CategorieBus categorie) {
	m_categorie = categorie;
}

//TODO : À valider..
std::pair<std::string, std::string> Ligne::getDestinations() const {
	std::pair<std::string, std::string> destination;

	switch(this->m_categorie){
		case CategorieBus::COUCHE_TARD:
			destination = std::pair<std::string, std::string>(m_voyages[0]->getDestination(), "");
			break;
		default:
			destination = std::pair<std::string, std::string>(m_voyages[0]->getDestination(), m_voyages[1]->getDestination());
			break;
	}

	return destination;
}

unsigned int Ligne::getId() const {
	return m_id;
}

void Ligne::setId(unsigned int id) {
	m_id = id;
}

const std::string& Ligne::getNumero() const {
	return m_numero;
}

void Ligne::setNumero(const std::string& numero) {
	m_numero = numero;
}

const std::vector<Voyage*>& Ligne::getVoyages() const {
	return m_voyages;
}

void Ligne::setVoyages(const std::vector<Voyage*>& voyages) {
	m_voyages = voyages;
}

void Ligne::addVoyage(Voyage* ptr_voyage) {
	m_voyages.push_back(ptr_voyage);
}

const std::string& Ligne::getDescription() const {
	return m_description;
}

void Ligne::setDescription(const std::string& description) {
	m_description = description;
}

std::ostream& operator <<(std::ostream& f, const Ligne& p_ligne){
	return f << CATEGORIE_BUS_DESCRIPTIONS[static_cast<int>(p_ligne.m_categorie)]
			 << " " << p_ligne.m_numero << " : "
			 << p_ligne.m_description;
}





