
#include <iostream>
#include <vector>
using namespace std;
typedef size_t Degre;
//idée intéressante: faire du polynome nul un booleen qu'on inclut dans les attributs de la classe.
class Polynome {
public:
  // constructeurs
  Polynome(double coef = 0.0, Degre degre = 0); // monome coef * X^deg
  // méthodes publiques
  Degre degre() const { return p.size()-1; }
  void affiche_coef(ostream& out, Degre puissance, 
  bool signe = true) const;
  Polynome& simplifie(bool=true);
  double top();
  // opérateurs internes
  Polynome& operator*=(const Polynome& q);
  Polynome& operator*=(double);  
  Polynome& operator+=(const Polynome& q);
  Polynome& operator+=(double);
  bool operator==(Polynome const&);
  bool operator!=(Polynome const&);
  
private:
  // attributs privés
  vector<double> p;
  // la multiplication aura besoin d'accéder à p
  friend const Polynome operator*(Polynome p, const Polynome& q);
  bool tronque();
};
// opérateurs externes
const Polynome operator*(Polynome p, const Polynome& q);
const Polynome operator*(Polynome p, double x);
const Polynome operator*(double x, const Polynome& p);
// ======================================================================
// définition des méthodes
// ----------------------------------------------------------------------
Polynome::Polynome(double coef, size_t deg)
  : p(deg+1, 0.0) // garantit que le degré de p est au moins deg
{
  p[deg] = coef;
}
// ----------------------------------------------------------------------
double Polynome::top() { return p[p.size()-1];}
Polynome& Polynome::operator*=(const Polynome& q) {
  /* On définit ici exceptionnellement l'opérateur interne avec
     l'opérateur externe (au lieu de faire le contraire) car on aurait
     de toutes façon besoin d'un polynôme supplémentaire pour
     effectuer ce calcul.                                               */
  return (*this = *this * q);
}
// ----------------------------------------------------------------------
Polynome& Polynome::operator*=(double x) {
  for (Degre i(0); i <= degre(); ++i)
    p[i] *= x;
  return *this;
} 
// manque le-=, flemme
  Polynome& Polynome::operator+=(const Polynome& q){
	  while (degre()<q.degre())
p.push_back(0);
	  for(size_t i(0); i<q.degre(); ++i)
	  p[i]+=q.p[i];
	  return this->simplifie();
 }
  Polynome& Polynome::operator+=(double c){
	  p[0]+=c;
	  return *this;
  }
   // /!\ == existe déjà pour les classes !!!!
    bool Polynome::operator==(Polynome const& q) {
	if (p.size()!=q.p.size()) return false;
	else for (size_t i(0); i<p.size(); i++)
	if (p[i]!=q.p[i]) return false;
	return true;
	}
	
  bool Polynome::operator!=(Polynome const& q) {
	  return not (*this==q);
  }
// ======================================================================
// fonctions intermédiaires et opérateurs externes
// ----------------------------------------------------------------------
const Polynome operator+(Polynome p, double x) {
  return p += x;
}
//----------------------------------------------------------------------
const Polynome operator+(double x, const Polynome& p) {
  return Polynome(p) += x;
}
//----------------------------------------------------------------------
const Polynome operator+(Polynome p, const Polynome& q) {
	return p+=q;
}
const Polynome operator-(Polynome p, const Polynome& q) {
	return p+=(-1*q);
}
//----------------------------------------------------------------------
const Polynome operator*(Polynome p, double x) {
  return p *= x;
}
// ----------------------------------------------------------------------
const Polynome operator*(double x, const Polynome& p) {
  return Polynome(p) *= x;
}
// ----------------------------------------------------------------------
const Polynome operator*(Polynome p, const Polynome& q) {
  const Degre dp(p.degre());
  const Degre dq(q.degre());
  // Prépare la place pour le polynome résultat (de degre p.degre()+q.degre()).
  Polynome r(0.0, dp + dq);
  // fait le calcul
  for (Degre i(0); i <= dp; ++i)
    for (Degre j(0); j <= dq; ++j)
      r.p[i+j] += p.p[i] * q.p[j];
  // retourne le resultat
  return r;
}
// ----------------------------------------------------------------------
void Polynome::affiche_coef(ostream& out, Degre puissance, bool signe) const
{
  double const c(p[puissance]);
  if (c != 0.0) {
    if (signe and (c > 0.0))  out << "+";
    out << c;
    if (puissance > 1)
      out << "*X^" << puissance;
    else if (puissance == 1) out << "*X";
  } else if (degre() == 0) {
    // degré 0 : afficher quand même le 0 si rien d'autre
    out << 0;
  }
}
// ----------------------------------------------------------------------
ostream& operator<<(ostream& sortie, const Polynome& polynome)
{
  // plus haut degré : pas de signe + devant
  Degre i(polynome.degre());
  polynome.affiche_coef(sortie, i, false);
  // degré de N à 0 : +a*X^i
  if (i > 0) { 
    for (--i; i > 0; --i) polynome.affiche_coef(sortie, i);
    polynome.affiche_coef(sortie, 0);
  }
  return sortie;
}

bool Polynome::tronque() {
	if (p.size()-1>0) { p.pop_back(); return true; }
	return false;
	}
	
Polynome& Polynome::simplifie(bool s) {
if ((p[p.size()-1]==0)and(s)) simplifie(tronque()); else return *this;
}
/*void Polynome::simplifie()
{
while((not p.empty())and (top()==0.0))p.pop_back();
if (p.empty())p.push_back(0.0);
} */
// ======================================================================
int main() {
  Polynome p(3.2, 4);
  cout << "p=" << p << endl;
  Polynome q(1.1, 2), r;
  r = p * q;
  cout << p << " * " << q << " = " << r << endl;
  r *= 2.0;
  cout << " * 2 = " << r << endl;
  
  Polynome P(0,4); Polynome Q;
 q.simplifie();
 cout<< q;
 // cout<<S.simplifie();
  
  return 0;
}
