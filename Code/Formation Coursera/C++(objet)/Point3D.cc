#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <math.h>

using namespace std;

struct Pcoord {
	double x;
	double y;
	double z;
};

class Point3D {
	protected:
	Pcoord p;
	
	public:
	Point3D(Point3D const& p)
	:p(p.p) {}
	Pcoord get() const { return p; }
	Point3D(double x=0, double y=0, double z=0)
	:p({x,y,z}) {}
	
	//ne marche pas sans friend, meme si metho de publiqque

	ostream& affiche(ostream&) const;
	bool compare  (const Point3D&)const;
	bool operator==(const Point3D& autre) const;
	
	};

class Vecteur : public Point3D {
	public:
	Vecteur(Vecteur const& v)
	: Point3D(v) {}
	Vecteur(): Point3D () {}
	Vecteur(double x, double y, double z):Point3D(x,y,z) {}
	
	Vecteur& operator+=(const Vecteur&);
	Vecteur& operator*=(double); 
	Vecteur operator-();
	const Vecteur operator-=(Vecteur const& v);
	double operator*(Vecteur const& v) {
 return p.x*v.p.x+p.y*v.p.y+p.z*v.p.z;
	}
	
	double norme() { return sqrt(*this**this);}
		
/* 	const Vecteur operator-(Vecteur u, const Vecteur& v){
	return u-=v; }*/
	
	}; 
		
const Vecteur operator+(Vecteur, const Vecteur&);
const Vecteur operator-(Vecteur, const Vecteur&);
ostream& operator<<(ostream& s, Point3D const&  p);

class Vecteur_Unitaire : public Vecteur{
	public:
	Vecteur_Unitaire(double x, double y, double z)
	:Vecteur(x, y, z) {cout<<"Vecteur crée";}
	~Vecteur_Unitaire() {cout<<"Vecteur détruit";}
		
	void testunit() {
	if (norme()!=1) { cout <<*this<<" n'est pas un vecteur unitaire."<<endl; }
	else cout<<"Le vecteur est unitaire !"<<endl;
	}
	};

//exo pas finit, flemme


int main() {
	Point3D p(2,3,4), g(1,1,1); cout<<p;
cout<<Vecteur(1, 2, -0.1)*Vecteur(2.6, 3.5, 4.1)<<endl<<Vecteur(1, 2, -0.1).norme()<<endl;
Vecteur_Unitaire s(3,3,3); s*=1/s.norme(); cout<<"    "<<s.norme();
	}
	
	
	
	
//NE PAS OUBLIER PROTOTYPE	
ostream& operator<<(ostream& s, Point3D const&  p) {
	//const& p a fonctionné car affiche() mis en const;
	return p.affiche(s);
	} 
	//mettre en void ?	
	ostream& Point3D::affiche(ostream& s) const {
	return	s<<endl<<"("<<p.x<<","<<p.y<<","<<p.z<<")";
	}	
	
	bool Point3D::operator==(const Point3D& autre) const { 
		// return (autre.x==x)and(autre.y==y)and(autre.z==z);
		// private => CLASSE et non INSTANCE
		if (autre.p.x==p.x) if (autre.p.y==p.y) if (autre.p.z==p.z) return true;
		return false;
	}
	
		Vecteur Vecteur::operator-() { 
			return Vecteur(p.x*=-1, p.y*=-1, p.z*=-1);
	
			}

Vecteur& Vecteur::operator+=(const Vecteur& v){
	p.x+= v.p.x; p.y+= v.p.y; p.z+= v.p.z;
	return *this;
	}
	
const Vecteur operator+(Vecteur u, const Vecteur& v){
		return u+=v;
		}
		
Vecteur& Vecteur::operator*=(double a)  {
		p.x*=a; p.y*=a; p.z*=a; 
		return *this;
		} 
		
const Vecteur operator*(Vecteur v, double a){
		return v*=a;
			} 
const Vecteur operator*(double a,Vecteur v){
		return v*=a;
			} 

const Vecteur Vecteur::operator-=(Vecteur const& v){
		return *this+=-Vecteur(v);
		}
				

const Vecteur operator-(Vecteur u, const Vecteur&v){
	return u-=v;
	}			
	//	Vecteur operator*(double a,Vecteur v); 


/*

int main () { 
	Point3D point1;
Point3D point2;
Point3D point3;
point1.init(1.0, 2.0, -0.1);
point2.init(2.6, 3.5,  4.1);
point3 = point1;
cout << "Point 1 :";
point1.affiche();
cout << "Point 2 :";
point2.affiche();
cout << "Le point 1 est ";
if (point1.compare(point2)) {
  cout << "identique au";
} else {
  cout << "différent du";
}
cout << " point 2." << endl;
cout << "Le point 1 est ";
if (point1.compare(point3)) {
  cout << "identique au";
} else {
  cout << "différent du";
}
cout << " point 3." << endl;
return 0; 
	
	} 
*/
