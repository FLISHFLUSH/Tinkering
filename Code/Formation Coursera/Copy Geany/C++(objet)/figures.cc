#include <cmath>
#include <iostream>
using namespace std;
class Figure {
	protected:
	double x, y;
	
	public:
	Figure(double x=0, double y=0)
	:x(x), y(y) {}
	
void getCentre(double& abscisse, double& ordonnee) const {
    abscisse = x;
    ordonnee = y;
  }
void setCentre(double abscisse, double ordonnee) {
    x = abscisse;
    y = ordonnee;
  }
ostream& affiche(ostream& s) 
	{ return s<<endl<<"centre: ("<<x<<","<<y<<")"; }
	
	
	};
// ----------------------------------------------------------------------
class Rectangle : public Figure {
private:
  double largeur;
  double longueur;
public:
Rectangle(double larg, double L,double x, double y) 
:Figure(x,y), largeur(larg), longueur(L) {}
Rectangle(double larg, double L) 
: largeur(larg), longueur(L) {}
  
  ostream& affiche(ostream& s) {
     Figure::affiche(s);
  return s<<endl<<"de largeur: "<<largeur<<" et de longueur "<<longueur<<".";}
  double surface () const { return largeur * longueur; }
  double getLongueur() const { return longueur; }
  double getLargeur()  const { return largeur;  }
  void setLargeur(double l)  { largeur  = l; }
  void setLongueur(double l) { longueur = l; }
};
// ----------------------------------------------------------------------
class Cercle : public Figure {
public:
Cercle(double x, double y,double rayon=0) 
:Figure(x,y), rayon(rayon) {}
Cercle(double rayon=0)
: rayon(rayon) {}

ostream& affiche(ostream& s) {
     Figure::affiche(s);
  return s<<endl<<"de rayon "<<rayon<<".";}
  double surface() const { return M_PI * rayon * rayon; }
  double getRayon() const { return rayon; }
  void setRayon(double r) {
    if (r < 0.0) r = 0.0;
    rayon = r;
  }
private:
  double rayon;
};
class RectangleColore : public Rectangle {
protected:
  unsigned int couleur;
public:
  RectangleColore(double larg, double L, unsigned int c)
   : Rectangle(larg, L), couleur(c) {}
};


int main() {
  RectangleColore r(4.3, 12.5, 4);
  cout << r.getLargeur() << endl;
  // 2 affiche donc choisis l'affiche le plus proche
r.Figure::affiche(cout);
r.affiche(cout);
  cout << endl;
  Cercle c;
c.setCentre(2.3, 4.5);
  c.setRayon(12.2);
c.affiche(cout);
  cout << endl;
  return 0;
}
