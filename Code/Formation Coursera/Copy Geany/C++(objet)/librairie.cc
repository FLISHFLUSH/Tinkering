#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <math.h>

using namespace std;
class Livre{
	protected:
	string titre;
	string auteur;
	int pages;
	bool best_seller;
	
	public:
	Livre(string t, string a, int p, bool b)
	:titre(t), auteur(a), pages(p), best_seller(b) {}
	virtual ~Livre() {cout<<"URGH";}
	
	virtual double calculer_prix() const;
	virtual void afficher() const; 
	//affiche est une fonction cree pour librairie. Noter que affiche() utilise le polymorphisme bien que se situant dans Livre.
	void affiche() const { 
		afficher(); cout<<"prix: "<<calculer_prix()<<"Frcs"<<endl<<endl;}

};

class Roman:public Livre{
	protected:
	bool biographie;
	
	public:
	Roman(string t, string a, int p, bool best, bool bio)
	: Livre(t,a,p,best), biographie(bio) {}
	virtual ~Roman () {}
	
	void afficher() const;
	};
	
class Policier:public Roman {
	public:
	Policier(string t, string a, int p, bool best, bool bio)
	:Roman(t,a,p,best,bio) {}
	
	double calculer_prix() const;
	};	
class BeauLivre:public Livre{
	public:
	BeauLivre(string t, string a, int p, bool b)
	:Livre(t,a,p,b) {}
	~BeauLivre() {}
	
	double calculer_prix() const;
	};	
//======================================================
	
double Livre::calculer_prix() const {
	double prix=pages*0.3;
	if (best_seller) prix+=50;
	return prix;
	}
	
void Livre::afficher() const {
		string s("non"); if (best_seller) s="oui";
	cout<<"titre: "<<titre<<endl<<"auteur: "<<auteur<<endl;
	cout<<"Nombre de pages: "<<pages<<endl;
	cout<<"best-seller: "<<s<<endl; 
	}
void Roman:: afficher() const {string s("non"); if (biographie) s="oui";
		Livre::afficher(); cout<<"biographie: "<<s<<endl;
}

double BeauLivre::calculer_prix() const {
	//besoin de resolution de portée,
return Livre::calculer_prix()+30.;
}
double Policier::calculer_prix() const { 
	//besoin d'un resolutionneur(XDDDDDDD) de portée 
	return max(Livre::calculer_prix()-10,1.);
}
//=====================================================================
class Librairie{
	vector<Livre*> livres;	

public: 
void ajouter_livre(Livre*) ;
void afficher() const;
void vider_stock();
	};
	
void Librairie::	ajouter_livre(Livre* l) {
	livres.push_back(l);
}

void Librairie::afficher() const {
	for(auto const& livre:livres)
	livre->affiche();
	}
void Librairie::vider_stock() {
	for(auto const& livre:livres)
	delete livre;
	livres.clear();
}	


int main()
{
  Librairie l;
  l.ajouter_livre(new Policier("Le chien des Baskerville", "A.C.Doyle",
                               221, false, false));
  l.ajouter_livre(new Policier("Le Parrain ", "A.Cuso", 367, true, false));
  l.ajouter_livre(new Roman("Le baron perché", "I. Calvino", 283, false, false));
  l.ajouter_livre(new Roman ("Mémoires de Géronimo", "S.M. Barrett", 173, false, true));
  l.ajouter_livre(new BeauLivre ("Fleuves d'Europe", "C. Osborne", 150, false));
  l.afficher();
  cout<<"tududu";
  l.vider_stock();
  return 0;
}
