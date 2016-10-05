/*
 * main.cpp
 *
 *  Created on: 2016-09-24
 *      Author: etudiant
 */

#include <iostream>
#include <algorithm>

#include "auxiliaires.h"
#include "ligne.h"
#include "station.h"
#include "voyage.h"
#include "arret.h"

using namespace std;

const string EMPLACEMENT_FICHIERS_RTC = "~\\RTC\\";
const char delimiteur { ',' };



/* Construction de VOYAGE */
/*
void initVoyages() {

	for (unsigned int i = 0; i < fichier_voyages.size(); i++) {
		for(size_t n = 0; n < fichier_lignes.size(); ++n) {
			auto index = find(fichier_lignes[n].begin(), fichier_lignes[n].end(), fichier_voyages[i][0]);

			if (fichier_lignes[n].end() != index) {
				Ligne ligne(fichier_lignes[i]);
				Voyage voyage(fichier_voyages[i], &ligne);
			}
			else {
				throw logic_error("Aucune ligne trouvée pour le voyage");
			}
		}
	}
}*/

int main() {

	vector<vector<string>> fichier_voyages;
	vector<vector<string>> fichier_lignes;
	vector<vector<string>> fichier_stations;
	vector<vector<string>> fichier_arrets;

	vector<Ligne*> lignes;
	vector<Station> stations;
	vector<Arret> arrets;
	vector<Voyage> voyages;

	lireFichier("RTC/trips.txt", fichier_voyages, delimiteur, true);
	lireFichier("RTC/stops.txt", fichier_stations, delimiteur, true);
	lireFichier("RTC/routes.txt", fichier_lignes, delimiteur, true);
	lireFichier("RTC/stop_times.txt", fichier_arrets, delimiteur, true);


	for(int i = 0; i < fichier_lignes.size(); i++) {
		Ligne uneLigne = Ligne(fichier_lignes[i]);
		lignes.push_back(&uneLigne);
	}

	for(int i = 0; i < fichier_stations.size(); i++) {
		Station uneStation = Station(fichier_stations[i]);
		stations.push_back(uneStation);
	}

	for(int i = 0; i < fichier_arrets.size(); i++) {
		Arret unArret = Arret(fichier_arrets[i]);
		arrets.push_back(unArret);
	}

	for(int i = 0; i < fichier_voyages.size(); i++) {
		unsigned int ligne_id = stoul(fichier_voyages[i][0]);

		Ligne* laLigne;
		for(int j = 0; j < lignes.size(); j++) {
			if(ligne_id == lignes[j]->getId()) {
				laLigne = lignes[j];
			}
		}

		Voyage unVoyage = Voyage(fichier_voyages[i], laLigne);
		voyages.push_back(unVoyage);
	}


	//initVoyages();
	return 0;
}











