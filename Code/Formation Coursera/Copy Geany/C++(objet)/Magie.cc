#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <math.h>

using namespace std;

class Spectateur {
	// Inscrire ses infos sur un bout de papier

	 
	 public:
     string nom(){
		 return mnom;
	 }
	 //ecrire setbillet set age 
	 unsigned int argent()  {
		 setargent();
		  return  margent; }
		 
	 unsigned int age() {
		 setage();
			  return mage; };
			  
	private:
	string mnom="Jamila";
	unsigned int mage;
	unsigned int margent;
	

	
	void setargent()  {
		cout << "sur moi, j'ai ";
		cin >> margent; cout <<" euros."<<endl;
		while (margent>100) {
				margent-=100;
	    cout << "Sur moi, j'ai "<<margent<<" francs."<<endl;
	
	}
	 }
	void setage ()  {
		cout <<"J'ai ";
		cin >>mage;
		cout <<" ans."<<endl;
		while (mage>=100) {
			cout <<"Je plaisante, j'ai ";
			cin>>mage; cout <<" ans."<<endl;
		
		}
	}
	
};

class Magicien {
	//role: faire le tour de magie en se servant seulement des infos données par l'assistant.
	//il commence et coordoone aussi le tour de magie.
	//on ne veut pas que le magicien accède aux infos. Il ne faut pas qu'il possède de varaible où les enregister.
	
	/* void tourdemagie (Assistant A, spectateur S)  {
	 * 
	 * }
	 * */
	 
	 
    public: vector<unsigned int > tour(Spectateur S) {
		return fonction(S);
	}
	
     void reveler(unsigned int t){
		calcul(t);
	}
	
	private: void calcul(unsigned int l){
		unsigned int t(l); t+=115;
		cout <<"Je vois... vous avez: "<<	t/100<<" ans et vous avez "<<t%100<<" francs en poche";
	}
	//j'ai choisi de mettre return du papier chez le magicien, flemme. Sinon faire void.
	 vector<unsigned int> fonction(Spectateur s) {
		//demande au spectateur d'utiliser setage setbillet.
		cout <<" Spectateur "<<s.nom()<<", quel âge avez-vous? et combien d'argent ? Inscrivez le sur un papier"<<endl;
	
		return {s.age(),s.argent()};
	
	}
};


class Papier {
//role: retenir les infos écrites par le spect	
//empecher au magicien de lire son contenu (comment faire sans creer une 3eme classe ???)

	private :vector<unsigned int> mpapier;
	

	
	public: void set(vector<unsigned int> m){
		mpapier=m;
	}
	
	/* vector<unsigned int> set(Assistant A) {
		return mpapier;
	} */
	
	public :vector<unsigned int> get()const{
		
		return mpapier;
		};
};	
	  

class Assistant {
	
	//role recupérer le papier et renvoyer un nombre.
	
	
	public: unsigned int calcul(Papier P)  {
		set(P); cout <<mcalcul<<" !!"<<endl;
		return mcalcul;
	}
	
	
	private: void set(Papier P){
		mcalcul=(P.get()[0]*2+5)*50+P.get()[1]-365;
	}

	unsigned int mcalcul;
};

int main () {
	Magicien M;
	Spectateur S; Papier P; Assistant A;
P.set((M.tour(S)));
M.reveler(A.calcul(P));
}
