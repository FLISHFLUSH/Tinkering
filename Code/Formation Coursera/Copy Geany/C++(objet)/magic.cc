#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <math.h>
using namespace std;
enum Couleur {BLANC,BLEU,NOIR,ROUGE,VERT};

class Carte {
	protected:
	int cout_;
	
	public:
	Carte (int i)
	:cout_(i) {}
	virtual ~Carte() {}
	
	virtual void afficher() const =0;
	};
	
class Terrain: public  virtual Carte{
Couleur couleur;
void affiche_coul() const { if (couleur==NOIR) cout<<"noir"; else if (couleur==BLEU) cout<<"bleu";
	else if (couleur==ROUGE) cout<<"rouge"; else if (couleur==VERT) cout<<"vert"; else cout<<"blanc";}

public:
Terrain(Couleur c, int i=0)
: Carte(i), couleur(c) {cout<<"un terrain a poussé"<<endl;}	
~Terrain() {cout<<"Le terrain est devenu plat"<<endl;}

void afficher() const {cout<<"Cette carte de coût "<<cout_<<" contient un terrain de couleur "; affiche_coul(); cout<<"."<<endl; }
	};
	
class Creature: public virtual Carte{
string nom;
int PdV;
int PdD;

public:
Creature(string nom, int pdv, int pdd,int i=0 )
:Carte(i) ,nom(nom), PdV(pdv), PdD(pdd) {cout<<"Une creature a ete cree !!!"<<endl;}
~Creature() {cout<<"la creature n'est plus"<<endl;}

void afficher() const {cout<<"Cette carte de coût "<<cout_<<" contient une créature, un(e) "<<nom<<" avec "<<PdV<<"points de vie";
	cout<<" et faisant "<< PdD<<" points de dégâts."<<endl; }
	};
	
class Sortilege: public virtual Carte{
	string nom;
	string description;
	
	public:
	Sortilege( string nom, string descript,int i=0)
	: Carte(i), nom(nom), description(descript) {cout<<"Un sortilège a été concocté"<<endl;}
	~Sortilege() {cout<<"le parchemin a été brulé"<<endl;}
	
	void afficher() const {cout<<"Cette carte de coût "<<cout_<<" contient un sortilège, un(e) "<<nom<<". "<<"Son effet est le suivant: "<<endl<<description<<endl; }
	};
	
class Createrrain: public Creature, public Terrain {
	public:
	Createrrain (int i, string nom, int pdv, int pdd, Couleur c)
	//on pouvait eventuellement definir le cout à 0 et mettre i à la fin pour éviter de trop recopier
	//vu qu'on sait que carte est hérité virutellement.
	: Carte(i), Creature (nom, pdv,pdd), Terrain(c) { cout<<"un créaterrain naît"<<endl; }
	~Createrrain() {cout<<"Un créaterrain n'est plus";}
	
	void afficher() const  {cout<<"Cette carte un créaterrain, combinaison d'un terrain et d'une creature."<<endl<<"Premièrement:"<<endl;
		Creature::afficher(); cout<<"Enfin:"<<endl; Terrain::afficher();}
	};
class Jeu {
	vector<Carte*> jeu;
	
	public:
	
	Jeu() {cout<<"On change de main"<<endl;}
	void ajoute(Carte* c) {
		jeu.push_back(c);}
	~Jeu() {for (auto carte:jeu) delete carte; jeu.clear(); cout<<"Je jette ma main";}	
	
	void afficher() const {
		for(auto carte: jeu)
		carte->afficher();
	}	
	};

int main() {
	  Jeu mamain;
  mamain.ajoute(new Terrain(BLEU));
  mamain.ajoute(new Creature("Golem",6, 4, 6));
  mamain.ajoute(new Sortilege( "Croissance Gigantesque",
             "La créature ciblée gagne +3/+3 jusqu'à la fin du tour",1));
  mamain.ajoute(new Createrrain(2, "Ondine", 1, 1, BLEU));
  mamain.afficher();
	return 0;}
