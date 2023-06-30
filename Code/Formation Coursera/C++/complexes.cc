#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Complexe {
	double reel;
	double imag;
};
Complexe addition (Complexe z, Complexe y){
	return {z.reel+y.reel, z.imag+y.imag};
	
}

Complexe soustraction (Complexe z, Complexe y){
	return {z.reel-y.reel, z.imag-y.imag};
	
}

Complexe multiplication (Complexe z, Complexe y){
	return {z.reel*y.reel-z.imag*y.imag,z.reel*y.imag+z.imag*y.reel};
	
}

Complexe division (Complexe z, Complexe y){
	double acarrebcarre(y.reel*y.reel+ y.imag*y.imag);
	return {(z.reel*y.reel+ z.imag*y.imag)/acarrebcarre, (z.imag*y.reel-z.reel*y.imag)/acarrebcarre};
	
}

void affiche(Complexe z){
	cout <<"z="<<z.reel<<"+"<<z.imag<<"i"<<endl <<"("<<z.reel<<","<<z.imag<<")"<<endl;
}

int main() {
	Complexe z={2,-3};
	Complexe y={1,1};
	affiche(addition(z,y));
	affiche(soustraction(z,y));
	affiche(multiplication(z,y));
	affiche(division(z,y));
	
}
