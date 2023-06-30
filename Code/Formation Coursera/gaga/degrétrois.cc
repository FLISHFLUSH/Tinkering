#include <iostream>
#include <cmath>
using namespace std;

int main () {
	cout << "Donner les 3 coefficients dans leur ordre respectif: " << endl;
	double a2, a1,a0;
	cin >> a0>> a1 >> a2;
	double q((3*a1-a2*a2)/9);
	double r((9*a2*a1-27*a0-2*a2*a2*a2)/54);
	double d=q*q*q+r*r;
	
	if (d<0){
	cout << "Les solutions sont: " << endl;
		double Delta=acos(r/sqrt(-q*-q*-q));
		double chiant=2*sqrt(-q);
		cout << chiant*cos(Delta/3)-a2/3 << "; "<< chiant*cos((Delta+2*
		M_PI)/3)-a2/3 << " et " << chiant*cos((Delta+4*M_PI)/3) << endl;
}
}
