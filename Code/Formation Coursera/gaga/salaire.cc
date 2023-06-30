#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <math.h>
using namespace std;
 

//----------------------------------------------------- 
 class Employe {
	 //idée: attribut en privéé, methode nomprneom en protected
	 protected:
	 string nom;
	 string prenom;
	 int age;
	 string arrivee;
	 string nomprenom() {return prenom+" "+nom;}
	 
	 public:
	 
	 Employe (string nom, string prenom, int age,string arrivee)
	 :nom(nom), prenom (prenom), age(age), arrivee(arrivee) {}
	 virtual ~Employe() {}
	 
	 virtual double calculer_salaire() const=0;
	virtual string get_nom() { return "L'employé "+nomprenom();}
	 };
	
class EmployeCA: public Employe {
	protected:
	double CA;
	
	public: EmployeCA(string nom, string prenom, int a, string ar,double ca)
	:Employe(nom, prenom,a,ar), CA(ca) {}
	};	 

class PrimeMensuelle{
	protected:
	double prime;
	
	public:
	PrimeMensuelle(double p=100)
	:prime(p) {}
	virtual ~PrimeMensuelle () {}
	};	
//-------------------------------------------------------------
class Vendeur	: public EmployeCA{
	public: 
	Vendeur(string nom, string prenom, int age, string ar,double ca)
	:EmployeCA(nom, prenom,age,ar,ca) {}
	
	double calculer_salaire() const{return CA/5+400;}
	 string get_nom() {return "Le vendeur "+nomprenom();}
	};

class Representant: public EmployeCA {
	public:
	Representant(string nom, string prenom, int age, string ar, double ca)
	:EmployeCA(nom, prenom,age,ar,ca) {}
	
	 string get_nom() {return "Le représentant "+nomprenom();}
	double calculer_salaire() const {return CA/5+800;}
	};

class Technicien: public Employe{
	int unites;
	
	public:
	Technicien(string nom, string prenom, int age, string ar,int nombre)
	: Employe(nom, prenom,age,ar), unites(nombre) {}
	
	 string get_nom() {return "Le producteur "+nomprenom();}
	double calculer_salaire() const{ return unites*5;}
	};
class Manutentionnaire :public Employe{
	int heures;
	
	public:
	Manutentionnaire(string nom, string prenom, int age, string ar, int nombre)
	: Employe(nom, prenom,age,ar), heures(nombre) {}
	~Manutentionnaire () {}
	
	 string get_nom() {return "Le manutentionneur "+nomprenom();}
	double calculer_salaire() const { return 65*heures;}
	};

//------------------------------------------------------------	
class ManutARisque :public Manutentionnaire, PrimeMensuelle{ 
		public:
	ManutARisque(string nom, string prenom, int age, string ar, int nombre, int prime)
	:Manutentionnaire(nom, prenom, age,ar,nombre), PrimeMensuelle(prime) {}
	double calculer_salaire() const {return Manutentionnaire::calculer_salaire()+prime;}
	};
class TechnARisque :public Technicien, PrimeMensuelle{
	public:
	TechnARisque(string nom, string prenom, int age, string ar,int nombre, int prime)
	:Technicien(nom, prenom, age,ar ,nombre), PrimeMensuelle(prime) {}
	double calculer_salaire() const {return Technicien::calculer_salaire()+prime;}
	
	};
//	--------------------------------------------------------------------------------------------
 class Personnel {
 vector<Employe*> personnel;
 
 public:
 void ajouter_employe(Employe* e) { personnel.push_back(e);}
 void afficher_salaires() const {
 for (auto const& employe:personnel)
 cout<<employe->get_nom()<<" gagne "<<employe->calculer_salaire()<<" Francs."<<endl;
 }
 double salaire_moyen() const {
	 size_t i; double salaire_moyen(0);
	 for (i=0; i<personnel.size(); i++) { cout<<personnel[i]->calculer_salaire()<<endl;
	 salaire_moyen+=personnel[i]->calculer_salaire(); }
	 return salaire_moyen/(i);
 }
 void licencie() {
	 for(auto const& employe:personnel)
	 delete employe;
	 personnel.clear();
	 }
 	 
	 };
	 
int main () {
  Personnel p;
  p.ajouter_employe(new Vendeur("Pierre", "Business", 45, "1995", 30000));
  p.ajouter_employe(new Representant("Léon", "Vendtout", 25, "2001", 20000));
  p.ajouter_employe(new Technicien("Yves", "Bosseur", 28, "1998", 1000));
  p.ajouter_employe(new Manutentionnaire("Jeanne", "Stocketout", 32, "1998", 45));
  p.ajouter_employe(new TechnARisque("Jean", "Flippe", 28, "2000", 1000, 200));
  p.ajouter_employe(new ManutARisque("Al", "Abordage", 30, "2001", 45, 120));
  p.afficher_salaires();
  cout << "Le salaire moyen dans l'entreprise est de "  
       << p.salaire_moyen() << " francs." << endl;
  // libération mémoire
  p.licencie();
}
	 
