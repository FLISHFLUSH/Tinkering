#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <math.h>

using namespace std;

//on aurait pu utiliser Point3D
struct Pcoord {
	double x0;
	double y0;
	double z0;
};

class Triangle {
	Pcoord x;
	Pcoord y;
	Pcoord z;
	//'v' pas obligatoire 'v'
	double xy;
	double xz;
	double yz;
	
	double longueur(Pcoord const& , Pcoord const& ) const ;
	
	void calculcote();
	
	public: 
	//flemme de faire méthode init
	void affiche_perimetre() ;
	bool isocele() ;
	/* Pcoord getx() { return x; } 
	void gety() { return y; } 
	void getz() { return z; } */
	void set(const Pcoord& a,const Pcoord& b,const Pcoord& c) {
		x=a; y=b; z=c;
}
void afficher() const {
	
	cout <<"("<<x.x0<<","<<x.y0<<","<<x.z0<<")"<<endl;
		cout <<"("<<y.x0<<","<<y.y0<<","<<y.z0<<")"<<endl;
			cout <<"("<<y.x0<<","<<y.y0<<","<<y.z0<<")"<<endl;
			cout<<xy<<"  "<<xz<<"   "<<yz<<endl;
}
};

int main () {
	Triangle T;
	Pcoord a={1,0,0},b={0,1,0},c={0,1,0};
	T.set(a,b,c);
	T.affiche_perimetre();
	if (T.isocele()) cout<< "le triangle est isocèle !";
	return 0;
	
}
//sans const, bug sur xz et yz mal calculé
double Triangle::longueur(const Pcoord& x1, const Pcoord& x2) const  {
	afficher();
	//cout <<sqrt(pow((x1.x0-x2.x0),2)+pow((x1.y0-x2.y0),2)+pow((x1.z0-x2.z0),2))<<"  ** "<<endl;
return sqrt(pow((x1.x0-x2.x0),2)+pow((x1.y0-x2.y0),2)+pow((x1.z0-x2.z0),2));

}
//Idee du cours: on calculcote en meme temps qu'on initialise
//PS: init triangle fait appel à init Point 3D
// MEILLEUR ! '^'
void Triangle::calculcote(){
xy=longueur(x,y); //cout <<xy;
xz=longueur(x,z); // cout <<xz;
yz=longueur(y,z);  //cout <<yz;
}

	void Triangle::affiche_perimetre()  {
		calculcote();
		afficher();
		cout <<".."<< xy+xz+yz<<endl;
	}
	
	bool Triangle::isocele()  {
		calculcote();
		if ((xy==xz)or(xy==yz)or(yz==xz)) return true;
		return false;
	}
