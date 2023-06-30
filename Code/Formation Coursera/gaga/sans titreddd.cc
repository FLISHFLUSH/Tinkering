#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Pour simplifier
typedef string Forme   ;
typedef string Couleur ;

class Brique
{
private:
  Forme   forme   ;
  Couleur couleur ;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
Brique(Forme forme, Couleur couleur="blanc")
:forme(forme), couleur(couleur) {}

ostream& afficher(ostream& sortie) const {
	
	if (couleur.empty()) return sortie<<forme;
	else return sortie<<"("<<forme<<","<<couleur<<")";
	}
	void afficher() {cout <<forme;};

};

class Construction
{
  friend class Grader;
  vector<vector<vector<Brique>>> contenu;
  
  public:
  Construction(Brique const& B) 
  :contenu(vector<vector<vector<Brique>>> {{{B}}}) {}
  
  void afficher() { contenu[1][0][0].afficher();}

};

int main () {
	Brique b("obliqueG");
	Construction c(b); c.afficher();
	vector<vector<string>> s= { {"a"}, {"a"}, {"c"}};
	
	}
