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
string nom_;
	int niveau_;
	int points_de_vie_;
	int force_;
	int position_;
	
	Creature(string n, int niv, int p, int f, int pos=0)
	:nom_(n), niveau_(niv), points_de_vie_(p), force_(f), position_(pos) {}
	
	bool vivant(){
		if (points_de_vie_>0) return true; return false;}
	int points_attaque() {
		return force_*niveau;}
	void deplacer(int n) {
		position+=n;}
	void adieux() { cout<<nom<<" n’est plus!" }
    void faiblir(int n) {
		if(vivant()) points_de_vie_-=n; if (not vivant()) points_de_vie_=0}
    ostream afficher(ostream& s) {
         s<<nom<< ", niveau: "
         s<<niveau<< ", points de vie: "
         s<<points_de_vie_ ", force: "
         s<<force_ ", points d'attaque: "
       return  s<<points_attaque() ", position: ";

	 }

};
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
int main()
{
 
}
