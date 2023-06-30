#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/*****************************************************
  * Compléter le code à partir d'ici
 *****************************************************/
class Produit {
	protected:
	string nom;
	string unite;
	
	public:
	Produit (string nom, string unite="")
	:nom(nom), unite(unite) {}
	virtual ~Produit() {}
	
	string getNom() const{return nom;}
	string getUnite()const {return unite;}
	virtual string toString() const {return nom;}
	virtual const Produit* adapter(double n) const {return this;}
	virtual double quantiteTotale(const string& nomProduit) const
	{ if (nomProduit==nom) return 1; else return 0;}
	};
	
class Ingredient {
	//le seul produit qu'on va modifier est un produicuisine qui SERA UNE COPIE d'une Reference d'un produit
	//	dans un ingredient (fonction adapter(n);
	//donc normalement pas de soucis avec const ref
	const Produit& produit;
	double quantite;
	string representation_produit() const;
	
	public:
	Ingredient(Produit const& p, double quantite)  //on n'arrive as à imaginer autre chose pour 
	//Ingredient::produit que produit 
	:produit(p), quantite(quantite) {}
	
	const Produit& getProduit() const {return produit;}
    double getQuantite() const {return quantite;}
    //void ? sstream ??? sait pas
    string descriptionAdaptee() const ;
    double quantiteTotale(const string& nomProduit) const ;
	};
class Recette {
	string nom;
	double nbFois_;
	vector<Ingredient> recette;
	
	public:
	Recette(string nom, double nb=1.)
	:nom(nom), nbFois_(nb) {}
	
	void ajouter(const Produit& p, double quantite);
	Recette adapter(double n) const ;
	string toString() const ;
	double quantiteTotale(const string& nomProduit) const;
	};
class ProduitCuisine: public Produit{
	Recette recette;
	
	public:
	ProduitCuisine(string nom, string unite="portion(s)")
	:Produit(nom,unite), recette(Recette(nom)) {}
	
	void ajouterARecette(const Produit& produit, double quantite);
	const ProduitCuisine* adapter(double n) const ;
	string toString() const;
	double quantiteTotale(const string& nomProduit) const ;
	};
//--------------------------------------------------------------
string Ingredient::representation_produit() const{ cout<<"Repres. produit";
	const Produit* ptr=produit.adapter(quantite);
	stringstream s; s<<ptr->toString(); delete ptr;
	return s.str();
	}
 string Ingredient::descriptionAdaptee() const{
stringstream s; s<<quantite<<" "<<produit.getUnite()<<" de "<<representation_produit();
return s.str();
  }
double Ingredient::quantiteTotale(const string& nomProduit) const {
return quantite*produit.quantiteTotale(nomProduit); 
}
//--------------------------------------------------------------
void Recette::ajouter(const Produit& p, double quantite){
	recette.push_back(Ingredient(p,quantite*nbFois_));
	}
	
	//quand on ajoute, on multiplie par le nbFois_. Quand on adapte, on veut multiplier par n la quantité de
	// chaque ingrédient
	//si on adapte en utilisante ajouter, alors la quantité déjà multiplier par *this.nbFois va 
	//etre re multiplier par new.nbFois=*thisnbFois_*n... il faut donc diviser cette quantite par *this.nbFois_
Recette Recette::adapter(double n) const {
	Recette r(nom,nbFois_*n);
	for (auto& ingredient: recette)
	r.ajouter(ingredient.getProduit(), ingredient.getQuantite()/nbFois_);
	return r;
	}
string Recette::toString() const {
	stringstream s;
	s<<"  Recette "<<nom<<" x "<<nbFois_<<":";
	for(size_t i(0);i<recette.size();i++)
s<<endl<<"  "<<i+1<<". "<<recette[i].descriptionAdaptee();
return s.str();
    }
double Recette::quantiteTotale(const string& nomProduit) const{
	double somme(0);
	for(auto const& ingredient:recette)
	somme+=ingredient.quantiteTotale(nomProduit);
	return somme;
	}
  //-- - - - - - - - - - - - - - - -  - - - - - - 
void ProduitCuisine::ajouterARecette(const Produit& produit, double quantite){
	 //rappel: normalement, recette.nbFois_=1;
	  recette.ajouter(produit, quantite);
	  }
const ProduitCuisine* ProduitCuisine::adapter(double n) const {
	//raccourcir en creant le pointeur tout de suite ?
	ProduitCuisine* ptr= new ProduitCuisine(nom);
	ptr->recette=this->recette.adapter(n);
	return ptr;
	
	}
string ProduitCuisine::toString() const {
stringstream s;
s<<Produit::toString()<<endl<<recette.toString();
return s.str();
}
double ProduitCuisine::quantiteTotale(const string& nomProduit) const {
	if (Produit::quantiteTotale(nomProduit)==1) return 1;
	else return recette.quantiteTotale(nomProduit) ;
	}
	
	//VERIFIER QUANTIE TOTALE(semblue juste)
//------------------------------------------------------------------------
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
void afficherQuantiteTotale(const Recette& recette, const Produit& produit)
{
  string nom = produit.getNom();
  cout << "Cette recette contient " << recette.quantiteTotale(nom)
       << " " << produit.getUnite() << " de " << nom << endl;
}

int main()
{
  // quelques produits de base
  Produit oeufs("oeufs");
  Produit farine("farine", "grammes");
  Produit beurre("beurre", "grammes");
  Produit sucreGlace("sucre glace", "grammes");
  Produit chocolatNoir("chocolat noir", "grammes");
  Produit amandesMoulues("amandes moulues", "grammes");
  Produit extraitAmandes("extrait d'amandes", "gouttes");

  ProduitCuisine glacage("glaçage au chocolat");
  // recette pour une portion de glaçage:
  glacage.ajouterARecette(chocolatNoir, 200);
  glacage.ajouterARecette(beurre, 25);
  glacage.ajouterARecette(sucreGlace, 100);
  cout << glacage.toString() << endl;

  ProduitCuisine glacageParfume("glaçage au chocolat parfumé");
  // besoin de 1 portions de glaçage au chocolat et de 2 gouttes
  // d'extrait d'amandes pour 1 portion de glaçage parfumé

  glacageParfume.ajouterARecette(extraitAmandes, 2);
  glacageParfume.ajouterARecette(glacage, 1);
  cout << glacageParfume.toString() << endl;

  Recette recette("tourte glacée au chocolat");
  recette.ajouter(oeufs, 5);
  recette.ajouter(farine, 150);
  recette.ajouter(beurre, 100);
  recette.ajouter(amandesMoulues, 50);
  recette.ajouter(glacageParfume, 2);

  cout << "===  Recette finale  =====" << endl;
  cout << recette.toString() << endl;
  afficherQuantiteTotale(recette, beurre);
  cout << endl;

  // double recette
  Recette doubleRecette = recette.adapter(2);
  cout << "===  Recette finale x 2 ===" << endl;
  cout << doubleRecette.toString() << endl;

  afficherQuantiteTotale(doubleRecette, beurre);
  afficherQuantiteTotale(doubleRecette, oeufs);
  afficherQuantiteTotale(doubleRecette, extraitAmandes);
  afficherQuantiteTotale(doubleRecette, glacage);
  cout << endl;

  cout << "===========================\n" << endl;
  cout << "Vérification que le glaçage n'a pas été modifié :\n";
  cout << glacage.toString() << endl;

  return 0;
}
