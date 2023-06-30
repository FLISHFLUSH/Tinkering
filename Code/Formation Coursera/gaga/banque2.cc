#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Personne {
	string nom;
	string ville;
	 
	 public:
	 Personne()
	 :nom("Johndoe"){}
	 Personne(string nom, string ville) 
	 : nom(nom), ville(ville) {}
	 
	 
	 Personne(Personne const& P)
	 :nom(P.nom), ville (P.ville) {}
	
	string getn() { return nom;}
	string getv() {return ville;}
	};

class Compte {
	string identifiant;
	double taux;
	int solde;
	
	public:
	Compte()
	:solde(0), taux (0) {}
	
	Compte(string id, double t, int s=0)
	:identifiant(id), taux(t), solde(s) {}
	
	void produit_taux() {
		solde=solde*(1+taux); 
	}
	//c'est … la banque de faire cette v‚rif, pas … cette fonction
	//on se prend pas la tete, on ne s'int‚resse qu'… des montants positifs
    void deposer(int depot) {
		if (depot>=0) solde+=depot; else cout<<"Veuillez d‚poser une somme positive"<<endl;
		}
 
    int retirer(int retrait) { if (retrait>=0) {
		int i(abs(solde-retrait)); solde=min(0,solde-retrait); return i;} 
		else cout <<"Entrez une somme d'argent >0."<<endl; }
		
	int getsolde() { return solde; }
	
	string getID() { return identifiant; }
	}; 
	
class FClient {
	//cette description embete, car 2 comptes seulement.
	//vector<compte> ??
	private:
	vector<Compte> comptes;
	Personne personne;
	
	public:
    void depot(size_t j, int depot){
		
	comptes[j].deposer(depot);	
	}
	
	FClient(Personne p) 	
	:personne(p) {}

	void ajouter_compte(double taux, string identifiant) {
		//identifiant+=comptes.size()-1;
		cout <<"Vous souhaitez un nouveau compte ?"<<endl;
		comptes.push_back(Compte(identifiant,taux));
		cout <<"Compte "<<identifiant<< " au taux "<<taux<<" cr‚e !"<<endl;
	}
	void Fboucler_compte() { for(auto& a:comptes) a.produit_taux(); }
	
	
	vector<Compte> getC() { return comptes; }
	Personne getP() { return personne; }
	};

class Banque {
	
	//NOTE: on ne peut aps travailler sur les methodes client directement, car seule la banque possŠde un 
	// ficheirs clients. Banque B(Personne P) => creation client. On poeut init Client tout seul mais une banque ne sait pas 
	// recup‚rer de client en passant par cette classe, seulement par Personne.
	
	//preferer ^pointeur de client ? (utile pour utilsier methodes client)
	vector<FClient> fichiers;
	
	/* void boucler_compte(FClient& c) {
		for(auto& a:c.getC())
		a.produit_taux();
		 } */
		 
		/*  void boucler_Comptes(vector<FClient> f) {
			 for (auto a:f)
			 boucler_compte(a);
			 } */
		 
	void affiche_compte(FClient  client){
	  cout<<"Client "<<client.getP().getn()<<" de "<<client.getP().getv()<<endl;
      for (auto c:client.getC()) 
      cout<<"Compte "<<c.getID()<<" : "<<c.getsolde() <<" francs"<<endl;
  }
	
	public:
	vector<FClient> getF() const { return fichiers ; }
	
	Banque()
	 {cout<<" Ouverture d'une nouvelle banque. Champagne !"<<endl;}
	
	//ne fonctionne pas, car la banque contient plusieurs clients, peut etre mettre dans la classe client.
	//eventuellement se servir de destruc et construc pour affiche
/*	Banque(Banque const& b)
	:compte(b.compte.produit_taux), personne (b.personne) 
	{boucle=false;} */
	
	void nouveau_client(Personne const& p) {
		fichiers.push_back(FClient(p));
	}
	
	void ajouter_compte(size_t i, string ID, double taux) {
	fichiers[i].ajouter_compte(taux, ID);
	
	}
	
	void depot(size_t i, size_t j, int depot) {
		fichiers[i].depot(j, depot);
	}
	
	//void bouclercompte parcours fichiers, affiche, copie banque, affiche


		
	void boucler_comptes() {	
		string s;bool boucle=true;
		for (size_t i(0);i<2;i++){
		if (boucle) s="avant"; else s="aprŠs";
		cout <<"Donn‚es "<<s<<" le bouclement des comptes :"<<endl; 
for (auto client: fichiers) {	
	if (not boucle) client.Fboucler_compte(); affiche_compte(client); boucle=false;
		
/* cout<<"Client "<<client.getP().getn()<<" de "<<client.getP().getv()<<endl;
for (auto c:client.getC()) {
   cout<<"Compte "<<c.getID()<<" : "<<c.getsolde() <<" francs"<<endl; */
   }
   
}
	}
	

	};

int main (){ 
	Banque B; Personne R("Ricardo", "Lille"); Personne M("Maria", "Madrid");
	B.nouveau_client(R); B.nouveau_client(M);//cout <<B.getF().size();//
	B.ajouter_compte(0, "epargne", 0.02); B.ajouter_compte(0, "courant", 0.01);
	B.depot(0,0,2000); B.depot(0,1,3000);
	B.ajouter_compte(1, "epargne", 0.02); B.ajouter_compte(1, "courant", 0.01);
	B.depot(1,0,2000); B.depot(1,1,4000);
	B.boucler_comptes();
	
	return 0;}
