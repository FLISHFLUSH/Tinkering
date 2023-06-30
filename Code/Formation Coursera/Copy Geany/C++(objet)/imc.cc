#include <iostream>
using namespace std;

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/
class Patient   {
	
	double masse;
	double hauteur;
	
	public:
	void init(double const& p, double const& t){
		if ((p<0)or(t<0)) { masse=0; hauteur=0; } 
		else { masse=p; hauteur=t; }
		}
    void afficher() const{
		cout<<"Patient : "<<masse<<" kg pour "<<hauteur<<" m"<<endl;
		}
		
    double imc() {
		if (hauteur==0) return 0; return masse/hauteur/hauteur;
		}
	double poids () const { return masse; }
	double taille () const { return hauteur; }
	};

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Patient quidam;
  double poids, taille;
  do {
    cout << "Entrez un poids (kg) et une taille (m) : ";
    cin >> poids >> taille;
    quidam.init(poids, taille);
    quidam.afficher();
    cout << "IMC : " << quidam.imc() << endl;
  } while (poids * taille != 0.0);
  return 0;
}
