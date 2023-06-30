#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/*****************************************************
  * Compléter le code à partir d'ici
 *****************************************************/
 	string retirer_les_zero(string m, size_t taille_max) { //int i(0);
		while (m.back()=='0' and m.size()>taille_max) {//cout<<i;i++;
			 m.pop_back();}
		if (m.back()=='.') m.pop_back();
		return m;
	}	
/* 	string couper_string(double s, size_t taille_max)
	{
	 int a(s); double t(s); t-=a; cout <<t<<" --- c t   "; string m=to_string(t)+"000000";// cout<<m.size();
	while(m.front()=='0' and m.size()>taille_max+2) {m.pop_back();}
	return to_string(a) + m.substr (1,7);
	} */

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
	virtual string toString() const { return nom;}
	//cette methode bien que "inutile" existe pour pouvoir utiliser le polymorphisme
	//pas d'erreur de compil si on utilise adapter(n) sur un Produit et bon résultat si sur un ProduitCuisiné
	virtual const Produit* adapter(double n) const {return this;}
	//ajouter virtual a qtotale fait bugger l'execution (FIXED: Buggait à cause de Ingrédient qui ne prenait pas un produit en référence
	//mais était une sous classe de produit et en faisait la copie dans le constructeur (copie => non polym)
   virtual  double quantiteTotale(const string& nomProduit) const {//cout<<"produit, qtotale"<<endl;
		 if (nom== nomProduit) return 1; else return 0;}
	};
/*	string rajouter_zero(double a) {
		double n(0); double t(0.1);
		for(size_t i(0); i<6;i++) {
		double x=a/t;
		if ((x%t)>0) { n++; t/=10;} else break; }
		string s;
		for(size i(0);i<n;i++)
		s+="0";
		return s;
		} */

class Ingredient  {
	const Produit& produit;
	double quantite;
	
	public: 
	Ingredient(Produit const& p,  double q)
	// ne pas oublier la référence, a causé beaucoup de soucis (2h de perdues)
	:produit(p), quantite(q) {}
	
	const Produit& getProduit() const { return produit;}
	double getQuantite() const { return quantite; }	
	
	//Hall fucking lujah... gros soucis, d'écriture amis aussi conceptuel. Le code affichait la bonne recette finale mais
	// n'adaptait pas l'affichage pour les produits cuisinés:
	// 2 portions de glacage    - puis 
	// recette glaçage x1
	//En gros, pour afficher un produit cuisiné, il suffit d'avoir la recette de base 
	//du produitC et de multiplier par la quantité. La quantité est initialisé avec la méthode Recette::ajouter.
	//Il suffisait donc d'adapter l'affichage d'un Produit (en se servant du polymorphisme) de tel sorte qu'il  renvoie
	//l'affichage d'un produitcuisiné dont la recette a été modifié. Risque de memory leak ? corrigé plus bas
	
	stringstream descriptionAdaptee() const {cout<<"DescriptionAdaptee"<<endl;
		// passage intéressant... la récursivité (?) de << fait que 
		// cout<<produit.getUnite()<<" de "<<produit.toString();  || Produit.top string est résolu avant et vu l'allure du code(to string 
		//renvoie"" mais affiche pendant l'execution), affiche toString() avant getUnite. Un code en Ostream se serait bien déroulé
		//rappel: le probleme qu'on avait était que "portion(s) de" s'affichait à la fin recette.toString autnt de fois que
		// le glaçage était appelé (au lieu d'apparaitre après la quantité de glaçage)
		//résolution ? voir code
		//cout.precision(6);cout<<fixed; 
		//cout<<quantite<<" "<<produit.getUnite()<<" de ";cout<<produit.adapter(quantite)->toString(); cout.precision();

	stringstream s; s<< to_string(quantite)<<" "<<produit.getUnite(); cout<<"getUnite passe"<<endl;s<<" de "<<produit.adapter(quantite)->toString();
	cout<<"mumu";
	return s;
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
	Recette(string nom, double nb=1.)
	:nom(nom), nbFois_(nb) {}
	~Recette() {for (auto const& ingredient:recette) {
		//cout<<"Je détruis une recette, "<<ingredient->getProduit().getNom()<<endl;
		 delete ingredient;} recette.clear();}
	
	//normalement, un produit et sa recette ne change pas. La quantite d'un produit cuisine dans une recette est determiné par
	// l'attribut quantité.
	// ainsi l'affichage d'un ProduitCuisiné doit utiliser un produit utilisé en référence et multiplier la quantité
	//des ingrédients de sa recette par la quantité du produitcuisiné.  Le produit a une valeur qualitative, non quantitative.
	void ajouter(const Produit& p, double quantite){
		recette.push_back(new Ingredient(p,quantite*nbFois_)); }
		
	Recette adapter(double n) const	{ 
		Recette r(nom, nbFois_*n);
		for (auto const& ingredient:recette) { 
			//perdu un temps fou, avait écrit :
			// r.ajouter(ingredient->getProduit(),ingredient->getQuantite()); }
		r.ajouter(ingredient->getProduit(),ingredient->getQuantite()/nbFois_); }
		return r;
	}
		//puisque toString doit rendre un argument pouretre lu par cout<<, on fait l'afichage à l'intéreiur et on revoie "" 
		//pour pas se fdaire chier
	string toString()	const { cout<<"ToString. Recette"<<endl; stringstream s;
		s<<"  Recette \""<<nom<<"\" x "<<retirer_les_zero(to_string(nbFois_),0)<<":";
		for(size_t i(0); i<recette.size();i++) { cout<<"Boucle recette   "; cout<<  recette[i]->getProduit().getNom();
s<<endl<<"  "<<to_string(i+1)<<". "; s<<recette[i]->descriptionAdaptee().str(); }
return s.str();
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
	int size() { return recette.size() ;}
	
	public:
//	string getNom() { cout <<"Ta mere en string"<<endl;return ""; }
	ProduitCuisine(string nom, string unite="portion(s)", double nbFois_=1)
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
	
	 string toString () const { cout <<"toString ProdC"<<endl;
		//correction:
		stringstream s; s<<Produit::toString()<<endl<<recette.toString();
		
		/* cout.precision();
		cout<<Produit::toString()<<endl; recette.toString(); */
		return s.str();
		}
	double quantiteTotale(const string& nomProduit) const { //cout<<"produitCUIStotale"<<endl;
		if (nom==nomProduit) return 1; else return recette.quantiteTotale(nomProduit);
		}
	
	};
	//idee: on rajoute 6 0 puis on retire des 0 jusqu'à arriver à taille max=6

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
  glacageParfume.ajouterARecette(glacage, 1);cout<<"tttt";

  cout << glacageParfume.toString() << endl;
cout<<"tttt";

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
