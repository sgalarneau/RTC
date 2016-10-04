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

vector<vector<string>> fichier_voyages;
vector<vector<string>> fichier_lignes;
vector<vector<string>> fichier_stations;
vector<vector<string>> fichier_arrets;

/* Construction de VOYAGE */
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
}

int main() {

	const vector<Voyage> voyages;

	lireFichier("RTC/trips.txt", fichier_voyages, delimiteur, true);
	lireFichier("RTC/stops.txt", fichier_stations, delimiteur, true);
	lireFichier("RTC/routes.txt", fichier_lignes, delimiteur, true);
	lireFichier("RTC/stop_times.txt", fichier_arrets, delimiteur, true);

	initVoyages();
	return 0;
}
