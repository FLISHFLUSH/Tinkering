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
//supprimer et remplacer par adapter() plus bas?
	const Produit& getProd() const { return *this;}
	
	public:
	Produit (string n, string u="")
	:nom(n), unite(u) {}
	virtual ~Produit() {}
	
    string getNom() const {return nom;}
	string getUnite() const {return unite;}
	virtual string toString() const {return  nom;}
	//cette methode bien que "inutile" existe pour pouvoir utiliser le polymorphisme
	//pas d'erreur de compil si on utilise adapter(n) sur un Produit et bon résultat si sur un ProduitCuisiné
	virtual const Produit* adapter(double n) const {return this;}
	//ajouter virtual a qtotale fait bugger l'execution (FIXED: Buggait à cause de Ingrédient qui ne prenait pas un produit en référence
	//mais était une sous classe de produit et en faisait la copie dans le constructeur (copie => non polym)
   virtual  double quantiteTotale(const string& nomProduit) const {//cout<<"produit, qtotale"<<endl;
		 if (nom== nomProduit) return 1; else return 0;}
	};

class Ingredient  {
	const Produit& produit;
	double quantite;
	
	public: 
	Ingredient(Produit const& p,  double q)
	// ne pas oublier la référence, a causé beaucoup de soucis (2h de perdues)
	:produit(p), quantite(q) {}
	
	const Produit& getProduit() const { return produit;}
	double getQuantite() const { return quantite; }	
	
	void descriptionAdaptee() const {// passage intéressant... la récursivité (?) de << fait que 
		// cout<<produit.getUnite()<<" de "<<produit.toString();  || Produit.top string est résolu avant et vu l'allure du code(to string 
		//renvoie"" mais affiche pendant l'execution), affiche toString() avant getUnite. Un code en Ostream se serait bien déroulé
		//rappel: le probleme qu'on avait était que "portion(s) de" s'affichait à la fin recette.toString autnt de fois que
		// le glaçage était appelé (au lieu d'apparaitre après la quantité de glaçage)
		//résolution ? voir code
		 cout.precision(6);cout<<fixed; cout<<quantite<<" "<<produit.getUnite()<<" de "; cout<<produit.toString(); cout.precision(0);
		}
	
	double quantiteTotale(const string& nomProduit) const {
		//Semble faire appel au polymorphisme donc on suppose qu'il faut utiliser quantite totale...
	return quantite*produit.quantiteTotale(nomProduit); }
	};
class Recette {
	vector<Ingredient*> recette;
	string nom;
	double nbFois_; 
	
	public:
	int size() { return recette.size() ;}
	Recette(string nom, double nb=1)
	:nom(nom), nbFois_(nb) {}
	~Recette() {for (auto const& ingredient:recette) delete ingredient; recette.clear();}
	
	void ajouter(const Produit& p, double quantite){
		recette.push_back(new Ingredient(p,quantite*nbFois_)); }
		
	Recette adapter(double n) const	{ 
		Recette r(nom, nbFois_*n);
		for (auto const& ingredient:recette)
		r.ajouter(ingredient->getProduit(),ingredient->getQuantite()*n);
		return r;
	}
		//puisque toString doit rendre un argument pouretre lu par cout<<, on fait l'afichage à l'intéreiur et on revoie "" 
		//pour pas se fdaire chier
	string toString()	const {
		cout<<"  Recette \""<<nom<<"\" x "<<nbFois_<<":";
		for(size_t i(0); i<recette.size();i++) {
cout<<endl<<"  "<<i+1<<". "; recette[i]->descriptionAdaptee(); }
return "";
		}
		
		double quantiteTotale(const string& nomProduit) const {
		//	cout<<"quantitetotale **********";
		double somme(0);	
		for(auto const& ingredient: recette) {//cout <<ingredient->getProduit().getNom()<<endl; //cout <<"lulu"<<endl; cout<<ingredient->getQuantite();cout<<ingredient->getProduit().quantiteTotale(nomProduit); //cout<<&(ingredient->getProduit()); cout<< &(ingredient->getProduit());
		somme+=ingredient->getQuantite()*ingredient->getProduit().quantiteTotale(nomProduit); }
		return somme;
	//	cout <<"mumumumumumu";
		}
	};

class ProduitCuisine: public Produit {
	Recette recette;
	
	
	public:
	int size() { return recette.size() ;}
//	string getNom() { cout <<"Ta mere en string"<<endl;return ""; }
	ProduitCuisine(string nom, string unite="portions(s)", double nbFois_=1)
	//revoir !!!
	:Produit (nom,unite), recette(Recette(nom, nbFois_)) {}
	
	void ajouterARecette(const Produit& produit, double quantite) {
		recette.ajouter(produit, quantite); }
		
	const ProduitCuisine* adapter(double n) const{
		//verif que adapter est bien const (censé travailler sur copie)
		ProduitCuisine pc(*this);
		pc.recette=recette.adapter(n); 
		return new ProduitCuisine(pc);
	}
	
	virtual string toString () const { //cout <<" pppp";
		cout.precision(0);
		cout<<Produit::toString()<<endl; recette.toString();
		return "";
		}
	double quantiteTotale(const string& nomProduit) const { //cout<<"produitCUIStotale"<<endl;
		if (nom==nomProduit) return 1; else return recette.quantiteTotale(nomProduit);
		}
	
	};
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
  glacageParfume.ajouterARecette(glacage, 1); //cout <<glacageParfume.size();
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
