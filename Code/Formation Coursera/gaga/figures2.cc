#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <math.h>

using namespace std;	

class Figure{
public:
virtual void affiche() const =0;	
virtual Figure* copie() const =0;
virtual ~Figure() {}
	};
	
class Cercle:public Figure {
	double rayon;
	
	public:
	Cercle(double r=1)
	:rayon(r) {}
	Cercle(Cercle const& c)
	: rayon(c.rayon) {}
	~Cercle() {cout<<"Cercle dead";}
	
	
    void affiche() const {cout<<"Ceci est un cercle de rayon"<<rayon<<"!"<<endl;}
    //cree une méthode statique qui 
    	
	static Figure* init(){
		cout<<"Rayon du cercle ?"<<endl;
		double s; cin>>s;
		//renvoie un new (pointeur) sur un cercle (qui est une Figure) qu'on construit à l'aide du constructeur.
		// On renvoie un pointeur sur une figure  pointant evrs un cercle dynamiquement crée.
		return new Cercle(Cercle(s));
		// /!\ on ne peut aps faire new Figure car 1) ça créerait une figure et pas un cercle 2// figure est une class abstraite
		}
		//meme chose sauf que pas besoin de cin.
	Figure* copie() const {
		return new Cercle(rayon);
	}
	};

class Carre:public Figure {
	double cote;
	
	public:
	Carre(Carre const& c=1)
	:Figure(c), cote(c.cote) {cout<<"Un carre est copie";}
	Carre(double c)
	:cote(c) {} 
	~Carre() {cout<<"Carre dead";}
	
	
	void affiche() const {cout<<"Ceci est un carre de cote "<<cote<<"!"<<endl;
		}
	Figure* copie() const {
		return new Carre(*this);
	    }
	};
	
class Triangle:public Figure {
	double base; double hauteur;
	
	public:
	Triangle(Triangle const& t)
	:base(t.base), hauteur(t.hauteur) {}
	Triangle(double b=0, double h=0)
	:base(b), hauteur(h) {}
	~Triangle() {cout<<"Triangle dead";}
	
	void affiche() const {cout<<"Ceci est un triangle de base "<<base<<" et de hauteur"<<hauteur<<"!"<<endl;
		}
	Figure* copie() const {
		return new Triangle(base,hauteur);
	}
	};
	
class Dessin{
	private:
	vector<Figure*> dessins;
	void destroy() {
	for (auto fig:dessins)
	delete fig; dessins.clear();
	}
	
	public:
	Dessin() {}
	Dessin(Dessin const& d)
	:dessins(vector<Figure*> (d.dessins.size())) 
	 {for (size_t i(0);i<dessins.size(); i++)
		 //copie() renvoie déja un new, donc pas besoin d'enremettre un
		 // DEPLUS             IMPORTANT
		 //Impossible au niveau de dessin de  proposer un new car on ne peut qu'écrire
		 // new FIGURE (on ne connait pas les sous classes utilisées de chaque élément).
		 // c'est à l'instance de lma sous classe de FOURNIR un pointeur vers une copie d'elle meme pour avoir 
		 // une écriture de la forme Figure* sousclasse_Figure(...); (valide car sc_figure EST une figure)
		 //voir l'écriture de copie() pour s'en convaincre
		//Dessin au fond ne sait rien sur la réelle identité de ses élements (à part qu'ils sont des figures... trop vague)
		dessins[i]=d.dessins[i]->copie();}
	~Dessin() {cout<<"Dessin pas intéressant"<<endl; destroy(); cout<<"Dessin jeté à la poubelle"<<endl;}
	
	void ajouteFigure(Figure const& fig) {
		dessins.push_back(fig.copie()); cout<<"mumu";
		}
		
    void affiche() const {
		for(auto fig:dessins)
		fig->affiche();
		}
	};
	
void unCercleDePlus(Dessin const& img) {
	// si copie superficielle
	//tmp est détruit après appel de la fcontion
	//et donc delete les contenus pointés.
	//Il faut offrir à dessins un construct de copie profonde
   Dessin tmp(img);            
   tmp.ajouteFigure(Cercle(1));
   cout << "Affichage de 'tmp': " << endl;
   tmp.affiche();          
}
	
	int main() {
   Dessin dessin;    
   //l'affichage du destructeur au début a lieu car les figures passées en paramètres sont volatiles     
   dessin.ajouteFigure(Triangle (3,4));               
   dessin.ajouteFigure(Carre(2));
   dessin.ajouteFigure(Triangle(6,1));
   dessin.ajouteFigure(Cercle(12));
   unCercleDePlus(dessin);
   cout << endl << "Affichage du dessin : " << endl;
   dessin.affiche();  
	
// Dessin est la seule variable statique appelé dans le main.
//en fin de block seul le destructeur de Dessin est appelé
// s'il n'est pas virtuel, puisque la résolution est statique(absence de virtual)
// pas d'appel des autres destructeurs.	
		
		return 0;}	
	
