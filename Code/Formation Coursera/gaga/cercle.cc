#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <math.h>

using namespace std;

class Cercle {
	
	double rayon;
	double x;
	double y;
public:	
    void setRayon(double r) {
	rayon=r;	
	}
	
	void setcentre(double x, double y) {
		this->x=x;
		this->y=y;
	}

	
	 void getcentre(double& x, double& y) const {
		 x=this->x; y=this->y;
	 }
	
	
	
	double surface() const {
	
	return 2*M_PI*rayon;	
	}
	
	bool estInterieur(double x1, double y1) {
		if (sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1))<=rayon) {return true; }
		return false;
	}
	
	void   affiche(){
		cout << "abscisse: " << x<<";   ordonnée: "<<y<<endl;
	} 
};

int main () {
	Cercle c1, c2; 
	c1.setcentre(2,3); c2.setcentre(0,0); c1.setRayon(3); c2.setRayon(5);
	c1.affiche(); c2.affiche(); cout <<c1.estInterieur(2,3)<<"     "<<c2.estInterieur(4.9,0);
	return 0;
	
}
