#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int distance(int x, int y)
{
  return abs(x - y);
}

class Creature
{
  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
    protected:
 string nom_;
	int niveau_;
	int points_de_vie_;
	int force_;
	int position_;
	
	bool combat(Creature const & bete) const {
	if (vivant() and bete.vivant()) return true; else return false; }
	
	void levelup() { if (vivant()) ++ niveau_;}
	
	public:
	Creature(string n, int niv, int p, int f, int pos=0)
	:nom_(n), niveau_(niv), points_de_vie_(p), force_(f), position_(pos) {}
	
	int position () const { return position_;}
	
	bool vivant() const {
		if (points_de_vie_>0) return true; else return false;}
		
	int points_attaque() const {
		if (vivant())return force_*niveau_; else return 0;}
		
	void deplacer(int n) {
		if (vivant()) position_+=n;}
		
	void adieux() const { cout<<nom_<<" n'est plus !"<<endl; }
	
    void faiblir(int n) {
		if(vivant()) {points_de_vie_-=n;} if (not vivant()) { points_de_vie_=0; adieux();}}
		
    void afficher() const {
         cout<<nom_<< ", niveau: ";
         cout<<niveau_<< ", points de vie: ";
         cout<<points_de_vie_<< ", force: ";
         cout<<force_ <<", points d'attaque: ";
    cout<<points_attaque()<< ", position: "<<position_<<endl;

	 }

};

class Dragon:public Creature {
	int portee_flamme_;
	bool combat (Creature const & bete,int n) const {
		if (Creature::combat(bete)and(n<portee_flamme_)) return true; else return false;}
	
	public:
	Dragon(string n, int niv, int p, int f, int portee_flamme_, int pos=0)
	:Creature(n,niv,p,f ,pos),  portee_flamme_( portee_flamme_){}
	
	void voler(int pos) {
		if (vivant()) position_=pos;
		}
	void souffle_sur(Creature& bete) {
		int d(distance(position_,bete.position()));
		if (combat(bete,d)) {
		bete.faiblir(points_attaque()) ;
		faiblir(d); 
		if (not bete.vivant()) levelup();}
		}
	
	};
	
class Hydre:public Creature {
	int longueur_cou_;
	int dose_poison_;
	
	bool combat(Creature const& bete,int n) const {
		if (Creature::combat(bete)and(n<longueur_cou_)) return true; else return false;}
	
	public:
	Hydre(string n, int niv, int p, int f, int longueur_cou_, int dose_poison_, int pos=0)
	:Creature(n,niv,p,f ,pos), longueur_cou_(longueur_cou_), dose_poison_(dose_poison_){}
   
    void empoisonne(Creature& bete) {
		int d(distance(position_,bete.position()));
		if (combat(bete,d)){ bete.faiblir(points_attaque()+dose_poison_);
		if (not bete.vivant()) levelup(); }
		}
	};
	
	void combat(Dragon& d, Hydre& h) {
		h.empoisonne(d); 
		d.souffle_sur(h); 
		}
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
int main()
{
  Dragon dragon("Dragon rouge"   , 2, 10, 3, 20         );
  Hydre  hydre ("Hydre maléfique", 2, 10, 1, 10, 1,  42 );

  dragon.afficher();
  cout << "se prépare au combat avec :" << endl;
  hydre.afficher();

  cout << endl;
  cout << "1er combat :" << endl;
  cout << "    les créatures ne sont pas à portée, donc ne peuvent pas s'attaquer."
       << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  cout << endl;
  cout << "Le dragon vole à proximité de l'hydre :" << endl;
  dragon.voler(hydre.position() - 1);
  dragon.afficher();

  cout << endl;
  cout << "L'hydre recule d'un pas :" << endl;
  hydre.deplacer(1);
  hydre.afficher();

  cout << endl;
  cout << "2e combat :" << endl;
  cout << "\
  + l'hydre inflige au dragon une attaque de 3 points\n\
      [ niveau (2) * force (1) + poison (1) = 3 ] ;\n\
  + le dragon inflige à l'hydre une attaque de 6 points\n\
      [ niveau (2) * force (3) = 6 ] ;\n\
  + pendant son attaque, le dragon perd 2 points de vie supplémentaires\n\
       [ correspondant à la distance entre le dragon et l'hydre : 43 - 41 = 2 ].\
" << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  cout << endl;
  cout << "Le dragon avance d'un pas :" << endl;
  dragon.deplacer(1);
  dragon.afficher();

  cout << endl;
  cout << "3e combat :" << endl;
  cout << "\
  + l'hydre inflige au dragon une attaque de 3 points\n\
      [ niveau (2) * force (1) + poison (1) = 3 ] ;\n\
  + le dragon inflige à l'hydre une attaque de 6 points\n\
      [ niveau (2) * force (3) = 6 ] ;\n\
  + pendant son attaque, le dragon perd 1 point de vie supplémentaire\n\
       [ correspondant à la distance entre le dragon et l'hydre : 43 - 42 = 1 ] ;\n\
  + l'hydre est vaincue et le dragon monte au niveau 3.\
" << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  cout << endl;
  cout << "4e Combat :" << endl;
  cout << "    quand une créature est vaincue, rien ne se passe." << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  return 0;
}
