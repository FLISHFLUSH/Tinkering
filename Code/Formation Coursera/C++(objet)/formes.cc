#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <math.h>

using namespace std;

class Forme {
	protected:
	
	public:
	virtual void description() const {cout<<"Ceci est une forme !"<<endl;}
	virtual double aire() const =0;
	};

class Cercle:public Forme {
	private:
	double rayon;
	
	public:
	Cercle(double r)
	:rayon(r) {}

	void description() const { cout<<"Ceci est un cercle d'aire "<<aire()<<"!"<<endl;}
		double aire() const { return M_PI*rayon*2; }
	};
	
class Triangle:public Forme {
	private:
	double base; double hauteur;
	
	public:
	Triangle(double b, double h)
	: base(b),hauteur(h) {}
	
	void description() const {cout<<"Ceci est un triangle d'aire "<<aire()<<"!"<<endl;}
	double aire() const {return base*hauteur;}
	};	
	void affichageDesc(Forme& f){	f.description(); }
	
int main() {                 
 Cercle c(5);                    
 Triangle t(10, 2);
 affichageDesc(t);
 affichageDesc(c);
 return 0;
}
