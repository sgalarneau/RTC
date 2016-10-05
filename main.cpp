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

	int timer_start = clock();

	for(unsigned int i = 0; i < fichier_lignes.size(); i++) {
		Ligne uneLigne = Ligne(fichier_lignes[i]);
		lignes.push_back(&uneLigne);
	}

	for(unsigned int i = 0; i < fichier_stations.size(); i++) {
		Station uneStation = Station(fichier_stations[i]);
		stations.push_back(uneStation);
	}

	for(unsigned int i = 0; i < fichier_arrets.size(); i++) {
		Arret unArret = Arret(fichier_arrets[i]);
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

		Voyage unVoyage = Voyage(fichier_voyages[i], laLigne);
		voyages.push_back(unVoyage);
	}

	int timer_stop = clock();

	cout << "Chargement des données terminé en " <<  (timer_stop - timer_start) / double(CLOCKS_PER_SEC) << " secondes" << endl;
	cout << "======================" << endl;
	cout << "LIGNES DE LA RTC" << endl;
	cout << "COMPTE = " << lignes.size() << endl;
	cout << "======================" << endl;

	for (int i = 0; i < lignes.size(); i++) {
		string categorie = lignes[i]->categorieToString(lignes[i]->getCategorie());
		string numero = lignes[i]->getNumero();
		string desc = lignes[i]->getDescription();

		cout << categorie << " " << numero << " : " <<  desc << endl;
	}

	cout << "======================" << endl;
	cout << "STATIONS DE LA RTC" << endl;
	cout << "COMPTE = " << stations.size() << endl;
	cout << "======================" << endl;

	time_t t = time(0);
	struct tm * now = localtime( & t );

	cout << "======================" << endl;
	cout << "VOYAGES DE LA JOURNÉE DU " << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-' <<  now->tm_mday << endl;
	cout << ctime (&t) << endl; //TODO: Afficher heure comme du monde
	cout << "COMPTE = " << voyages.size() << endl;
	cout << "======================" << endl;

	for (int i = 0; i < voyages.size(); i++) {
		cout << voyages[i].getId() << ": " << voyages[i].getDestination() << endl;

		for (int j = 0; j < voyages[i].getArrets().size(); j++) {
			vector<Arret> arrets = voyages[i].getArrets();

			//cout << arrets[j].getHeureArrivee() << " - " << arrets[j].getStationId() << endl; //TODO: A Fixer
		}
	}

	return 0;
}











