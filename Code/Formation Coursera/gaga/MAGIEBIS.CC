#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <math.h>

using namespace std;


	
class Papier {
	
	unsigned int age_ecrit;
	unsigned int argent_ecrit;
	
	public:vector<unsigned int> infos() const {
		return {age_ecrit, argent_ecrit};
	}
	void set(unsigned int age, unsigned int argent) {
		age_ecrit=age; argent_ecrit=argent;
	}
	};
	
	
class Spectateur {
	
    Papier feuille;
	unsigned int age;
	unsigned int argent; 
	
    public:
    void Presentation();
	
	Papier ecrireetmontrer();
		
	
	};


class Assistant {
	vector<unsigned int> infos;
	unsigned int mcalcul;
	
	void calcul();
	
	public: 
	void lire(Papier t);
	unsigned int crier() ;
	

};

class Magicien {
	
	//puisque le tour se déroule dans la class magicien, mettre tout le reste en provée ??
	unsigned int nbr;
	
	void annonce();
	void calcul(unsigned int nombre);
	//dans le doute on rajoute &
	public:void tour_deroulement(Assistant& A, Spectateur& S);
	};
	
	




int main() {
	Magicien M; Assistant A; Spectateur S;
	M.tour_deroulement(A,S);
 		
}
 void Spectateur::Presentation() {
		cout<<"Euh Bonjour... j'ai ";
		cin>> age; cout<<"ans.";
		while (age>=100) {
			cout <<" Je plaisante, j'ai "; cin >> age; cout<<"ans."<<endl;
			}
			cout<< "Sinon, dans ma poche j'ai "; cin >>argent; cout <<" francs. "<<endl;
			while (argent>=100) { argent-=100; } cout<<"Dans ma poche, j'ai "<<argent<<" francs."<<endl; 
		}
   
   Papier Spectateur::ecrireetmontrer() { 
	   feuille.set(age,argent);
	   cout<<"*Le spectateur inscrit quelque chose sur un papier*"<<endl;
	   cout<<"*Le spectateur montre le contenu du papier au public et à l'assistant*"<<endl;
	   return feuille;
	   }
	   
	   
	void Assistant::lire(Papier t){
		this->infos=t.infos();
		}
		
	unsigned int Assistant::crier() {
		calcul();
		cout<<"\" "<<mcalcul<<"!!!!\", hurle l'assistant."<<endl;
		return mcalcul;
		}
		
	void Assistant::calcul(){
		mcalcul=(infos[0]*2+5)*50+infos[1]-365;
		}
		
	void Magicien::calcul(unsigned int nombre) {
		nbr=nombre;
		nbr+=115;
	}
	
	void Magicien::annonce(){
		cout <<"Hmmm... je vois que vous avez "<< nbr/100<<" ans et que vous avez sur vous "<<nbr%100<<" francs !"<<endl;
	}
	
	void Magicien::tour_deroulement(Assistant& A, Spectateur& S) {
		S.Presentation(); A.lire(S.ecrireetmontrer()); calcul(A.crier());
		annonce();
	}
		
		

