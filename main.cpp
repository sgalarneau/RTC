/*
 * main.cpp
 *
 *  Created on: 2016-09-24
 *      Author: etudiant
 */

#include <iostream>
#include <algorithm>
#include <map>
#include <ctime>

#include "auxiliaires.h"
#include "ligne.h"
#include "station.h"
#include "voyage.h"
#include "arret.h"

using namespace std;

const string EMPLACEMENT_FICHIERS_RTC = "~\\RTC\\";
const char delimiteur { ',' };

int main() {

	vector<vector<string>> fichier_voyages;
	vector<vector<string>> fichier_lignes;
	vector<vector<string>> fichier_stations;
	vector<vector<string>> fichier_arrets;

	vector<Ligne*> lignes;
	vector<Station*> stations;
	vector<Arret*> arrets;
	vector<Voyage*> voyages;

	map<string, std::vector<Arret>> arretsVoyages;

	int timer_start = clock();

	lireFichier("RTC/trips.txt", fichier_voyages, delimiteur, true);
	lireFichier("RTC/stops.txt", fichier_stations, delimiteur, true);
	lireFichier("RTC/routes.txt", fichier_lignes, delimiteur, true);
	lireFichier("RTC/stop_times.txt", fichier_arrets, delimiteur, true);

	for(unsigned int i = 0; i < fichier_lignes.size(); i++) {
		Ligne* uneLigne = new Ligne(fichier_lignes[i]);
		lignes.push_back(uneLigne);
	}

	for(unsigned int i = 0; i < fichier_stations.size(); i++) {
		Station* uneStation = new Station(fichier_stations[i]);
		stations.push_back(uneStation);
	}



	for(unsigned int i = 0; i < fichier_arrets.size(); i++) {
		Arret* unArret = new Arret(fichier_arrets[i]);
		unArret->setVoyageId(fichier_arrets[i][0]);

		arretsVoyages[unArret->getVoyageId()].push_back(*unArret);

		arrets.push_back(unArret);
	}

	for(unsigned int i = 0; i < fichier_voyages.size(); i++) {
		unsigned int ligne_id = stoul(fichier_voyages[i][0]);

		Ligne* laLigne;
		for(unsigned int j = 0; j < lignes.size(); j++) {
			if(ligne_id == lignes[j]->getId()) {
				laLigne = lignes[j];
			}
		}

		Voyage* unVoyage = new Voyage(fichier_voyages[i], laLigne);

		unVoyage->setArrets(arretsVoyages[unVoyage->getId()]);

		voyages.push_back(unVoyage);
	}

	int timer_stop = clock();


	std::ofstream fout("resume_rtc.txt");

	fout << "Chargement des données terminé en " <<  (timer_stop - timer_start) / double(CLOCKS_PER_SEC) << " secondes" << endl;
	fout << "======================" << endl;
	fout << "LIGNES DE LA RTC" << endl;
	fout << "COMPTE = " << lignes.size() << endl;
	fout << "======================" << endl;

	for (int i = 0; i < lignes.size(); i++) {
		fout << *lignes[i] << endl;
	}

	fout << "======================" << endl;
	fout << "STATIONS DE LA RTC" << endl;
	fout << "COMPTE = " << stations.size() << endl;
	fout << "======================" << endl;

	for (int i = 0; i < stations.size(); i++) {
		fout << *stations[i] << endl;
	}

	time_t t = time(0);
	struct tm * now = localtime( & t );

	fout << "======================" << endl;
	fout << "VOYAGES DE LA JOURNÉE DU " << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-' <<  now->tm_mday << endl;
	fout << ctime (&t) << endl; //TODO: Afficher heure comme du monde
	fout << "COMPTE = " << voyages.size() << endl;
	fout << "======================" << endl;

	for (int i = 0; i < voyages.size(); i++) {
		fout << *voyages[i] << endl;
	}


	for (std::vector<Ligne*>::iterator it = lignes.begin() ; it != lignes.end(); ++it) {
		delete (*it);
    }
	lignes.clear();

	for (std::vector<Station*>::iterator it = stations.begin() ; it != stations.end(); ++it) {
		delete (*it);
    }
	stations.clear();

	for (std::vector<Voyage*>::iterator it = voyages.begin() ; it != voyages.end(); ++it) {
		delete (*it);
    }
	voyages.clear();

	for (std::vector<Arret*>::iterator it = arrets.begin() ; it != arrets.end(); ++it) {
		delete (*it);
    }
	arrets.clear();

	return 0;
}











