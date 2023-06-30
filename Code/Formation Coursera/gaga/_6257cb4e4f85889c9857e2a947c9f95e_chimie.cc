#include <iostream>
#include <string>
#include <cmath>
#define BONUS
using namespace std;

class Flacon
{
private:
  string nom;
  double volume;
  double pH;
 
public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
Flacon& operator+=(Flacon const f) {
	nom+=" + "+f.nom;
	pH=-log10(((volume*pow(10.,-pH)+f.volume*pow(10.,-f.pH))/(volume+f.volume)));
	volume+=f.volume;
	return *this;
	}

Flacon(string n, double v, double pH)
:nom(n), volume(v), pH(pH) {}

ostream& etiquette(ostream& sortie) const {
return	sortie<<nom<<" : "<<volume<<" ml, pH "<<pH;
	}

friend ostream& operator<<(ostream& sortie, Flacon f){
	return f.etiquette(sortie);
	}
	
	
Flacon operator+(Flacon const& f2) const{
	return (Flacon(*this)+=f2);
	}
};

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void afficher_melange(Flacon const& f1, Flacon const& f2)
{
  cout << "Si je mélange " << endl;
  cout << "\t\"" << f1 << "\"" << endl;
  cout << "avec" << endl;
  cout << "\t\"" << f2 << "\"" << endl;
  cout << "j'obtiens :" << endl;
  cout << "\t\"" << (f1 + f2) << "\"" << endl;
}

int main()
{
  Flacon flacon1("Eau", 600.0, 7.0);
  Flacon flacon2("Acide chlorhydrique", 500.0, 2.0);
  Flacon flacon3("Acide perchlorique",  800.0, 1.5);

  afficher_melange(flacon1, flacon2);
  afficher_melange(flacon2, flacon3);

  return 0;

}
