#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <math.h>
 using namespace std;
 
 class Animal {
	
protected:
	 string nom;
	 string continent;
	 
	 public:
	 Animal (string n, string c)
	 :nom(n), continent(c) {cout<<"Nouvel animal protégé"<<endl;}
	 ~Animal (){cout<<"Je ne suis plus un animal"<<endl;}
	 
	 //rappel: l'ostream& est pratique si on veut surcharger un opérateur<<;
	 ostream& affiche(ostream&) const;
	 };

class EnDanger {
	protected:
	int nombre;
	
	public:
	EnDanger(int n)
	:nombre(n) {cout<<"Nouvel animal en danger"<<endl;}
	~EnDanger (){cout<<"Je ne suis plus en danger"<<endl;}
	
	ostream& affiche(ostream&)const;
	};
class Gadget{
	protected:
	string nom;
	double prix;
	
	public:
	Gadget(string n, double p)
	:nom(n), prix(p) {cout <<"Nouveau gadget"<<endl;}
	~Gadget (){cout<<"Je ne suis plus un gadget"<<endl;}
	ostream& affiche(ostream&)const;
	ostream& affiche_prix(ostream&)const;
	};

class Peluche: public Animal, public EnDanger, public Gadget {
	public:
	Peluche(string nomA, string nom, string continent, int nombre,  double prix)
	: Animal (nomA, continent), EnDanger(nombre), Gadget(nom, prix) {cout<<"Je suis une peluche, hello everyone"<<endl;}
	~Peluche () {cout<<"Qui a encore laissé trainé la peluche sur la table !"<<endl;}
	
	void etiquette()  {
		cout<<"Hello,"<<endl;
		EnDanger::affiche(Animal::affiche(Gadget::affiche(cout)));
		}
	};
	
ostream& Animal::affiche(ostream& s) const {
	return s<<"Je suis un "<<nom<<" et je vis en "<<continent<<"."<<endl;

}	
ostream& EnDanger::affiche(ostream& s) const{
	return s<<"Il ne reste que "<<nombre<<" de mon espèce sur Terre !"<<endl;
	}

ostream& Gadget::affiche(ostream& s)const {
	return s<< "Mon nom est "<<nom<<endl;
 
	}
	ostream& Gadget::affiche_prix(ostream& s)const{
		return s<<"Achetez-moi pour "<<prix<<" francs et vous contribuerez à me sauver !"<<endl;
		}
	int main()
{ 
  Peluche panda("Panda","Ming","Asie", 200, 20.0);
  Peluche serpent("Cobra","Ssss","Asie", 500, 10.0);
  Peluche toucan("Toucan","Bello","Amérique", 1000, 15.0);
  panda.etiquette();
  serpent.etiquette();
  toucan.etiquette();
  return 0;
}
