#include <iostream>
#include <cmath>
using namespace std;

int main () {
	cout << "Donner les 3 coefficients dans leur ordre respectif: " << endl;
	 double a2, a1,a0;
	cin >> a2>> a1 >> a0;
	 double q((3*a1-a2*a2)/9);
	 double r((9*a2*a1-27*a0-2*a2*a2*a2)/54);
	 double d=q*q*q+r*r;
	//
	cout << d<< endl;
	
	if (d<0.){
	cout << "Les solutions sont: " << endl;
		double Delta=acos(r/sqrt(-q*-q*-q));
		double chiant=2*sqrt(-q);
		 cout << chiant*cos(Delta/3)-a2/3 << "; "<< chiant*cos((Delta+2*
		M_PI)/3)-a2/3 << " et " << chiant*cos((Delta+4*M_PI)/3) << endl;
} else {
       double s(pow(r+sqrt(d), 1./3.));
       if ((r+sqrt(d))>=0)
               s=pow(r+sqrt(d), 1./3.);
          else s=-pow(-sqrt(d)-r,1./3.);
       //
       cout << s << endl;
       double t(0.);
          if ((r-sqrt(d))>=0)
               t=pow(r-sqrt(d), 1./3.);
          else t=-pow(sqrt(d)-r,1./3.);
       cout << t << endl;
       double z1(s+t-a2/3);
     //
       cout <<z1<< endl <<endl;
       ;
			double z2((-s+t)/2-a2/3);
        if ((d==0.)and(s+t!=0.)) {
			cout << "on compte 2 racines: " << endl << z1 << " et "<< z2;
			}
			else cout <<"racine unique: " << endl << z1;
		}
}
