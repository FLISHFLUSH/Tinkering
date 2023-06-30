#include <iostream>
#include <string>
using namespace std;

class Timbre
{
private:
  static constexpr unsigned int ANNEE_COURANTE = 2016;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
  protected:
string nom;
unsigned int annee;
string pays;
double valeur_faciale;

  public:
Timbre(string nom, unsigned int annee, string pays="Suisse", double  valeur=1)
:nom(nom), annee(annee), pays(pays), valeur_faciale(valeur) {}

double vente() {
	unsigned int diff_annee(ANNEE_COURANTE-annee);
	 if (diff_annee<5) return valeur_faciale; else return (2.5*diff_annee)* valeur_faciale;}

double age() { return ANNEE_COURANTE-annee;}

ostream& afficher(ostream& s) {
return s<<"de nom "<<nom<<" datant de "<<annee<<" (provenance "<<pays<<") ayant pour valeur faciale "<<valeur_faciale<<" francs";
}	
 

};


class Rare:public Timbre{
	//init en (...) ne fonctionne pas à l'intérieur d'une classe
	static const unsigned int PRIX_BASE_TRES_RARE=600, PRIX_BASE_RARE=400, PRIX_BASE_PEU_RARE=50;
	private:
	unsigned int exemplaires;
	
	public:
	Rare(string nom, unsigned int annee, string pays="Suisse", double  valeur=1,unsigned int nb=100)
:Timbre(nom, annee,pays,valeur), exemplaires(nb) {}

	unsigned int nb_exemplaires() { return exemplaires; }
	double vente() { unsigned int t;
		if (exemplaires<100) t=PRIX_BASE_TRES_RARE;
		else if (exemplaires<1000) t=PRIX_BASE_RARE;
	    else t=PRIX_BASE_PEU_RARE;
return t*(age()/10);

}
  
};
	
class Commemoratif:public Timbre{
	public:
	Commemoratif(string nom, unsigned int annee, string pays="Suisse", double  valeur=1)
: Timbre(nom, annee, pays, valeur) {}
	
double vente() { return Timbre::vente()*2;}

	};

ostream& operator<<(ostream& s, Timbre t) {
	s<<"Timbre "; return t.afficher(s);
	} 
ostream& operator<<(ostream& s, Rare r) {	
s<<"Timbre rare ("<<r.nb_exemplaires()<<" ex.) "; return r.afficher(s);	}

ostream& operator<<(ostream& s, Commemoratif c) {
	s<<"Timbre commémoratif "; return c.afficher(s);	}
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
int main() 
{cout<<"s";
  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Rare t1( "Guarana-4574", 1960, "Mexique", 0.2, 98 );
  Rare t2( "Yoddle-201"  , 1916, "Suisse" , 0.8,  3 );

  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Commemoratif t3( "700eme-501"  , 2002, "Suisse", 1.5 );
  Timbre       t4( "Setchuan-302", 2004, "Chine" , 0.2 );

  /* Nous n'avons pas encore le polymorphisme :-(
   * (=> pas moyen de faire sans copie ici :-( )  */
  cout << t1 << endl;
  cout << "Prix vente : " << t1.vente() << " francs" << endl;
  cout << t2 << endl;
  cout << "Prix vente : " << t2.vente() << " francs" << endl;
  cout << t3 << endl;
  cout << "Prix vente : " << t3.vente() << " francs" << endl;
  cout << t4 << endl;
  cout << "Prix vente : " << t4.vente() << " francs" << endl;

  return 0;
}
