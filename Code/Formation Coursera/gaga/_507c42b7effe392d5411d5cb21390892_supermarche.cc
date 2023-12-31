#include <iostream>
#include <vector>
using namespace std;

// /!\ contient test ostream&

//rappel: le const& est inutile dans les constructeurs qui n'utilisent pas la meme classe,
// car le changement n'est pas possible si attribut en private et sans methode set();
//utile pour constr de copie car on peut modifier les attributs d'instance diff si meme classe;
class Article {
	string nom;
	double prix_U;
	bool solde;
	
	public:
	Article(string nom, double prix, bool solde=false)
	:nom(nom), prix_U(prix), solde(solde) {}
	
	double getP()const {return prix_U; }
	string getN()const { return nom;}
	bool getS()const {return solde;}
	};
	
	
class Achat {
	Article article;
	unsigned int quantite;
	
	public:
	friend ostream& operator<<(ostream& cout, Achat const&);
	double prix_tot();
	Achat(Article article, unsigned int i=1)
	: article(article), quantite(i) {}
	
	
	void afficher();

	
	};
		
class Caddie {
	vector<Achat> courses;
	
	public:
	
	//ne f onctionne pas sans friend (car Achat requiert friend ?)
    friend ostream& operator<<(ostream& cout,Caddie const& c);
	vector<Achat> getc() { return courses;}
	void afficher();
	void remplir(Article const& A, unsigned int const& i=1) ;

	
	};
	
class Caisse {
	string ID;
	double montantT;
	
	public:
	Caisse()=default,
	Caisse(string ID, double montant=0)
	: ID(ID), montantT(montant) {}
	void scanner(Caddie);
	void afficher() const;	
		
		};
		
		

// ======================================================================
int main()
{
  // Les articles vendus dans le supermarch�
  Article choufleur ("Chou-fleur extra"      ,  3.50 );
  Article roman     ("Les malheurs de Sophie", 16.50, true );
  Article camembert ("Cremeux 100%MG"        ,  5.80 );
  Article cdrom     ("C++ en trois jours"    , 48.50 );
  Article boisson   ("Petit-lait"            ,  2.50, true);
  Article petitspois("Pois surgeles"         ,  4.35 );
  Article poisson   ("Sardines"              ,  6.50 );
  Article biscuits  ("Cookies de grand-mere" ,  3.20 );
  Article poires    ("Poires Williams"       ,  4.80 );
  Article cafe      ("100% Arabica"          ,  6.90, true);
  Article pain      ("Pain d'epautre"        ,  6.90 );

  // Les caddies du supermarch�, disons 3 ici
  vector<Caddie> caddies(3);

  // Les caisses du supermarch�, disons 2
  vector<Caisse> caisses(2);

  // Les clients font leurs achats :
  // le second argument de la m�thode remplir correspond � une quantit�

  // remplissage du 1er caddie
  caddies[0].remplir(choufleur, 2);
  caddies[0].remplir(cdrom       );
  caddies[0].remplir(biscuits , 4);
  caddies[0].remplir(boisson  , 6);
  caddies[0].remplir(poisson  , 2);
 // caddies[0].afficher();
 
  // remplissage du 2eme caddie
  caddies[1].remplir(roman        );
  caddies[1].remplir(camembert    );
  caddies[1].remplir(petitspois, 2);
  caddies[1].remplir(poires    , 2);

  // remplissage du 3eme caddie
  caddies[2].remplir(cafe     , 2);
  caddies[2].remplir(pain        );
  caddies[2].remplir(camembert, 2);

  // Les clients passent � la caisse :
  caisses[0].scanner(caddies[0]);
  cout << "=========================================" << endl;
  caisses[0].scanner(caddies[1]);
  cout << "=========================================" << endl;
  caisses[1].scanner(caddies[2]);
  cout << "=========================================" << endl;

  // Affichage du r�sultat des caisses
  cout << "R�sultats du jour :" << endl;
  for (size_t i(0); i < caisses.size(); ++i) {
    cout << "Caisse " << i+1 << " : " ;
    caisses[i].afficher();
    cout << endl;
    for (auto cad:caddies) {
		cout<< "=========================================" << endl;
	cout <<cad;
}
  }

  return 0;
}  

void Achat::afficher() {
	// /!\ if () double t(x) else double t(y) n'est pas possible
	double t;
	if (article.getS())  t=(0.5); 
	else  t=(1);
	cout <<article.getN()<<" : "<<article.getP()<<" x "<<quantite<<" = "<<article.getP()*quantite*t<<" Frs ";
	if (article.getS()) cout<<" (en action)";
	cout <<endl;
	
}

double Achat::prix_tot() {
	double tot=article.getP()*quantite;
if (not article.getS()) return article.getP()*quantite; else return tot*0.5;
}
void Caddie::remplir(Article const& A, unsigned int const& i) { 
		
courses.push_back(Achat(A,i));
		}
		
void Caddie::afficher(){
			for (auto a:courses)
			a.afficher();
		}
void Caisse::scanner(Caddie C){
	double c(0);
	for(auto achat:C.getc()){
		double l(achat.prix_tot());
		montantT+=l;
		c+=l;
		achat.afficher();
		}
		cout <<"Total � payer: "<<c<<" Frcs."<<endl;
		cout <<endl;
}

void Caisse::afficher() const {
	cout <<"La caisse "<<ID<<" a encaisse "<<montantT<<" Frs aujourd'hui."<<endl;
}

ostream& operator<<(ostream& cout, Achat const& a){
	double t;
	if (a.article.getS())  t=(0.5); 
	else  t=(1);
	cout <<a.article.getN()<<" : "<<a.article.getP()<<" x "<<a.quantite<<" = "<<a.article.getP()*a.quantite*t<<" Frs ";
	if (a.article.getS()) cout<<" (en action)";
	cout <<endl;
	return cout;
	}

ostream& operator<<(ostream& cout,Caddie const& c) {

Caddie L(c);
for(auto achat:L.getc())
cout<<achat;
return cout;

}

