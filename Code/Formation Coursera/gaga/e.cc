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
	
	int pos() {return position_;}
	bool vivant() const {
		if (points_de_vie_>0) return true; else return false;}
		
	int points_attaque() {
		return force_*niveau_;}
		
	void deplacer(int n) {
		position_+=n;}
		
	void adieux() { cout<<nom_<<" n’est plus!"; }
	
    void faiblir(int n) {
		if(vivant()) {points_de_vie_-=n;} if (not vivant()) points_de_vie_=0;}
		
    ostream& afficher(ostream& s) {
         s<<nom_<< ", niveau: ";
         s<<niveau_<< ", points de vie: ";
         s<<points_de_vie_<< ", force: ";
         s<<force_ <<", points d'attaque: ";
       return  s<<points_attaque()<< ", position: ";

	 }

};

class Dragon:public Creature {
	int portee_flamme_;
	bool combat(Creature const & bete,int n) const {
		if (Creature::combat(bete)and(n<portee_flamme_)) return true; else return false;}
	
	public:
	Dragon(string n, int niv, int p, int f, int portee_flamme_, int pos=0)
	:Creature(n,niv,p,f ,pos),  portee_flamme_( portee_flamme_){}
	
	void voler(int pos) {
		position_=pos;
		}
	void souffle_sur(Creature& bete) {
		int d(distance(position_,bete.pos()));
		if (combat(bete,d)) {
		bete.faiblir(points_attaque()) ;
		faiblir(d); }
		levelup();
		}
	
	};
	
class Hydre:public Creature {
	int longueur_cou_;
	int dose_poison_;
	
	bool combat(Creature const& bete,int n) {
		if (Creature::combat(bete)and(n<longueur_cou_)) return true; else return false;}
	
	public:
	Hydre(string n, int niv, int p, int f, int longueur_cou_, int dose_poison_, int pos=0)
	:Creature(n,niv,p,f ,pos), longueur_cou_(longueur_cou_), dose_poison_(dose_poison_){}
   
    void empoisonne(Creature& bete) {
		int d(distance(position_,bete.pos()));
		if (combat(bete,d)) bete.faiblir(points_attaque()+dose_poison_);
		levelup();
		}
	};
	
	void combat(Dragon d, Hydre h) {
		h.empoisonne(d);
		d.souffle_sur(h);
		}
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
int main()
{
 
}
