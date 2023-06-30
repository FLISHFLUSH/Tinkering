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
Brique(Forme forme, Couleur couleur)
:forme(forme), couleur(couleur) {}

ostream& afficher(ostream& sortie) const ;
friend ostream& operator<<(ostream& sortie, Brique const& B) ;

};
//==========================================================
ostream& Brique::afficher(ostream& sortie) const {
	string s(couleur);
	if (couleur.empty()) ; else s=","+s;
	return sortie<<"("<<forme<<s<<")";
	}	
//==========================================================
ostream& operator<<(ostream& sortie, Brique const& B) {
return B.afficher(sortie);
}

//==========================================================
//==========================================================
class Construction
{
  friend class Grader;
  vector<vector<vector<Brique>>> contenu;
  
  public:
  Construction(Brique const& B)
  //(1,vector<vector<Brique>> (1, vector<Brique> ( etc)) 
  :contenu(vector<vector<vector<Brique>>> {{{B}}}) {}
  
//==========================================================  
 ostream& afficher(ostream& sortie) const;
 friend ostream& afficher(ostream& sortie);
 Construction& operator^=(Construction const& b);
 Construction& operator-=(Construction const& b);
 Construction& operator+=(Construction const& b);
};
//==========================================================
ostream& Construction::afficher(ostream& sortie) const {
	    for (size_t i(contenu.size()-1); i>=0; i--){
			sortie<<"Couche "<<i<<":"<<endl;
	   // for (size_t i(contenu[i].size()-1); j>=0; j--)
	    for (size_t k(contenu[i][0].size()-1); k>=0 ;k--)
	  contenu[i][0][k].afficher(sortie);
	  sortie<<endl;
	  }
	  return sortie;
  }
//==========================================================	  
ostream& operator<<(ostream& sortie, Construction const& c) {
	return c.afficher(sortie);
}

 Construction& Construction::operator^=(Construction const& b){
 for(size_t i(0); i<b.contenu.size();i++)
 contenu.push_back(b.contenu[i]);
 return *this;
 }
 
 Construction operator^(Construction a, Construction const b) {
 return a^=b;
 }
 
Construction& Construction::operator-=(Construction const& b){
	  if (b.contenu.size()>=contenu.size()) {
		for(size_t i(0); i<contenu.size();i++)
		//on parcout le j de la construction b à la ligne i et on colle à a son k à cette meme ligne.
		for(size_t j(0); j<b.contenu[i].size();j++)
		contenu[i].push_back(b.contenu[i][j]); 
	   }
	   return *this; 
	  }

Construction& Construction::operator+=(Construction const& b){
	//on suppose que les constructions n'ont pas de trous
	if ((b.contenu.size()>=contenu.size())and(b.contenu[0].size()>=contenu[0].size())) {
	for(size_t i(0); i<contenu.size();i++)
		for(size_t j(0); j<contenu[i].size();j++)
		for(size_t k(0); k<b.contenu[i][j].size();k++)
		contenu[i][j].push_back(b.contenu[i][j][k]);
		
		}
		return *this;
	}

Construction& operator+(Construction a, Construction const b){
	return a+=b;
}

Construction operator-(Construction a, Construction const b) {
	return a-=b;
	}	  

const Construction operator*(unsigned int n, Construction const& a)
{ Construction b(a);
	for(size_t i(0); i<n;i++)
	b=b+a;
	return b;
}

const Construction operator/(unsigned int n, Construction const& a)
{Construction b(a);
	for(size_t i(0); i<n;i++)
	b=b^a;
	return b;
}

const Construction operator%(unsigned int n, Construction const& a)
{Construction b(a);
	for(size_t i(0); i<n;i++)
	b=b-a;
	return b;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  // Modèles de briques
  Brique toitD("obliqueD", "rouge");
  Brique toitG("obliqueG", "rouge");
  Brique toitM(" pleine ", "rouge");
  Brique mur  (" pleine ", "blanc");
  Brique vide ("                 ", "");

  unsigned int largeur(4);
  unsigned int profondeur(3);
  unsigned int hauteur(3); // sans le toit

  // on construit les murs
  Construction maison( hauteur / ( profondeur % (largeur * mur) ) );

  // on construit le toit
  Construction toit(profondeur % ( toitG + 2*toitM + toitD ));
  toit ^= profondeur % (vide + toitG + toitD);

  // on pose le toit sur les murs
  maison ^= toit;
  
  // on admire notre construction
  cout << maison << endl;

  return 0;
}
