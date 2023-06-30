#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
/*struct Date {
	unsigned int jour, mois, annee;
	}; */

class Vehicule {
	protected:
	string marque;
	unsigned int date;
	double prix;
	
	public:
	Vehicule(string marque, unsigned int date, double prix)
	:marque(marque), date(date), prix(prix) {}
	
	void affiche(ostream&) const;
	void calculePrix();
	};
	

class Voiture: public Vehicule {
double cylindree;
double porte;
double puissance;
double kilometrage;
	
	public:
	Voiture(string marque, unsigned int date, double prix, double cylindree, double porte, double puissance, double kilometrage)
	:Vehicule(marque, date, prix), cylindree(cylindree), porte(porte), puissance(puissance), kilometrage(kilometrage) {}
	
	void calculePrix();
	void affiche(ostream& s) {
		Vehicule::affiche(s); 
		s<<"litres: " << cylindree<<endl<<"nb de portes: "<<porte<<endl<<"Puissance: "<< puissance<<endl;
		s<<"kilometrage: "<<kilometrage<<endl<<endl;}
	};

class Avion: public Vehicule {
string type;
double heure;
	
	public:
	Avion(string marque, unsigned int date, double prix, string type, double heure)
	:Vehicule(marque, date, prix), type(type), heure(heure) {}
	
	void calculePrix();
	void affiche(ostream& s) {Vehicule::affiche(s); s<<"type: " << type<<endl<<"heures de vol: "<<heure<<endl<<endl;}
	};

int main()
{
  vector<Voiture> garage;
  vector<Avion>   hangar;
  garage.push_back(Voiture("Peugeot", 1998, 147325.79, 2.5, 5, 180.0,
                           12000));
  garage.push_back(Voiture("Porsche", 1985, 250000.00, 6.5, 2, 280.0,
                           81320));
  garage.push_back(Voiture("Fiat",    2001,   7327.30, 1.6, 3,  65.0, 
                           3000));
  hangar.push_back(Avion("Cessna",      1972, 1230673.90, "HELICES",  
                         250));
  hangar.push_back(Avion("Nain Connu", 1992, 4321098.00, "REACTION",
                         1300));
  for (auto voiture : garage) {
    voiture.calculePrix();
    voiture.affiche(cout);
  }
  for (auto avion : hangar) {
    avion.calculePrix();
    avion.affiche(cout);
  }
  return 0;
}

	
void Vehicule::affiche(ostream& s) const {
	//on purrait faire mumuse avec % pour améliorer l'affichage
s<<"Marque: "<<marque<<endl<<"Date d'achat: "<<date<<endl<<"Prix: "<< prix<<" Frcs"<<endl;
}
void Vehicule::calculePrix(){
	for(size_t i(date); i<2018;++i)
	prix*=0.99;
	}
	
void Voiture::calculePrix(){
	for(size_t i(date); i<2018;++i)
	prix*=0.98; //cout <<prix<<endl;
	for (size_t i(0); i<kilometrage/10000;i++)
	prix*=0.95; //cout <<prix<<endl;
	if ((marque=="Fiat") or(marque=="Renault")) prix*=0.9;
	if ((marque=="Ferrari") or(marque=="Porsche")) prix*=0.8;
	}
	
void Avion::calculePrix(){
	for(size_t i(date); i<2018;++i)
	prix*=0.99;
	if (type=="REACTION")
	for (size_t i(0); i<heure/1000;i++)
	prix*=0.9;
	if (type=="HELICES")
	for (size_t i(0); i<heure/100;i++)
	prix*=0.9;
	}
	
