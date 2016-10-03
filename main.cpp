/*
 * main.cpp
 *
 *  Created on: 2016-09-24
 *      Author: etudiant
 */

#include <iostream>

#include "auxiliaires.h"
#include "ligne.h"
#include "station.h"
#include "voyage.h"
#include "arret.h"

using namespace std;

const std::string EMPLACEMENT_FICHIERS_RTC = "~\\RTC\\";
const char delimiteur { ',' };

int main() {

	const std::vector<Voyage> voyages;

	std::vector<std::vector<std::string>> fichier_voyages;
	std::vector<std::vector<std::string>> fichier_lignes;
	std::vector<std::vector<std::string>> fichier_stations;
	std::vector<std::vector<std::string>> fichier_arrets;

	lireFichier("RTC/trips.txt", fichier_voyages, delimiteur, true);
	lireFichier("RTC/stops.txt", fichier_stations, delimiteur, true);
	lireFichier("RTC/routes.txt", fichier_lignes, delimiteur, true);
	lireFichier("RTC/stop_times.txt", fichier_arrets, delimiteur, true);


	return 0;
}

/* Construction de VOYAGE */
void initVoyages(std::vector<Voyage> &voyages) {

//	for (unsigned int i = 0; i < fichier_voyages.size(); i++) {
//		Voyage voyage = new Voyage(voyages, Ligne* p_ligne);
//	}
}
