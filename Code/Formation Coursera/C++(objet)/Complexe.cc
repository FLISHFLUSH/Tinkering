#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Complexe {
	double REEL;
	double IMAG;
	//Complexe& inverse();
	
	public:
	/* Complexe(Complexe const& z)
	:REEL(z.REEL), IMAG(z.IMAG)  {} */
	Complexe(double x=0, double y=0)
	:REEL(x), IMAG(y) {}
	
	//2 choix: faire directement avec friend, 
	//ou faire fonction qui affiche qui prend et retourne un ostream puis 2eme fonction qui l'utilise.
	friend ostream& operator<<(ostream& cout, Complexe const& z); 
	bool operator==(Complexe const&) ;
	Complexe& operator+=(Complexe const&) ;
	Complexe& operator-=(Complexe const&) ;
	Complexe& operator+=(double const&) ;
	/*il était possible de faire z+z1 en interne avec:
	Complexe Complexe::operator+(const Complexe& c)const{
	return Complexe(*this)+=c;
	} */
	Complexe& operator*=(Complexe const&);
	Complexe operator*(Complexe const&);
	Complexe& operator /=(Complexe const &);
    Complexe  operator/(Complexe const &);
    
	};
Complexe operator*(Complexe z, double const& c);
Complexe operator*(double const& c, Complexe z);	
Complexe operator+(Complexe z, double const& c);
const Complexe operator+(Complexe z, Complexe const& z1);
Complexe operator+(double const& c, Complexe z);
	
int main () {
	    Complexe defaut;
    Complexe zero(0.0, 0.0);
    Complexe un(1.0, 0.0);
    Complexe i(0.0, 1.0);
    Complexe j;
    
cout << zero << " ==? " << defaut;
if (zero == defaut) cout << " oui" << endl;
else cout << " non" << endl;
cout << zero << " ==? " << i;
if (zero == i) cout << " oui" << endl;
else cout << " non" << endl;

j = un + i;
cout << un << " + " << i << " = " << j << endl;
Complexe trois(un);
trois += un;
trois += 1.0;
cout << un << " + " << un << " + 1.0 = " << trois << endl;
Complexe deux(trois);
deux -= un;
cout << trois << " - " << un << " = " << deux << endl;
trois = 1.0 + deux;
cout << "1.0 + " << deux << " = " << trois << endl;

Complexe z(i*i);
cout << i << " * " << i << " = " << z << endl;
cout << z << " / " << i << " = " << z/i << " = ";
cout << (z/=i) << endl; 

Complexe k(2.0,-3.0);
z = k;
z *= 2.0;
z *= i;
cout << k << " * 2.0 * " << i << " = " << z << endl;
z = 2.0 * k * i / 1.0;
//testé
cout << " 2.0 * " << k << " * " << i << " / 1 = " << z << endl;
    
    return 0;
	}
		
		
 bool Complexe::operator==(Complexe const& z) {
	if ((REEL==z.REEL)and(IMAG==z.IMAG)) return true; return false;
	}
	
ostream& operator<<(ostream& cout, Complexe const& z){
	cout<<"("<<z.REEL<<","<<z.IMAG<<")";
	return cout;
	}
	
	
	Complexe& Complexe::operator+=(Complexe const& z) {
		REEL+=z.REEL; IMAG+=z.IMAG;
		return *this;
		}
		
	Complexe& Complexe::operator-=(Complexe const& z) {
	REEL-=z.REEL; IMAG-=z.IMAG;
		return *this;
	}
	//l'idée est que comme on doit faire une copie, autant faire une fonction plutot qu'une méthode (pas de changement d'attributs);
	const Complexe operator+(Complexe z, Complexe const& z1) {
		return z+=z1;
	}
	
		
	Complexe& Complexe::operator+=(double const& c) {
	REEL +=c;
	return *this;
}
Complexe operator+(Complexe z, double const& c) {
	return z+=c;
}

Complexe operator+(double const& c, Complexe z) {
	return z+=c;
}
/* ne marche pas car, on doit utiliser *this*z.inverse
//et * renvoie une copie donc un objet volatile, donc /= ne peut pas rendre une reférence (on veut une ref).
Complexe& Complexe::inverse() {
	double t=REEL*REEL+IMAG*IMAG;
	REEL=REEL/t;
	IMAG=-IMAG/t;
	return (*this);
	} */
	
Complexe& Complexe::operator /=(Complexe const& z){
	double t=z.REEL*z.REEL + z.IMAG*z.IMAG;
	*this*=z;
	REEL=REEL/t; IMAG=IMAG/t;
	return *this;
		}
Complexe Complexe::operator/(Complexe const& z) {
	return Complexe(*this)/=z;
	}
		
Complexe& Complexe::operator*=(Complexe const& z){
	double r(REEL), i(IMAG);
	REEL=r*z.REEL-i*z.IMAG;
	IMAG=r*z.IMAG +i*z.REEL;
	return *this;
	}
	
Complexe Complexe::operator*(Complexe const& z) {
return Complexe(*this)*=z;
}

Complexe operator*(Complexe z, double const& c) {
	return z*=c;
}

Complexe operator*(double const& c, Complexe z) {
	return z*=c;
}
