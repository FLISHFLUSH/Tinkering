
#include <iostream>
#include <cmath>
using namespace std;

int main (){
	double eps;
	double h0;
	const double g(9.81);
	// on peut traduire et se débarasser des not(), pas envie.
	do { cout << " A quelle hauteur lachez-vous la balle ? " << endl;
	cin >> h0; 
	if (not(h0>0)) 
	cout << endl <<"Ne vous moquez pas du monde ! Je vous repose la question: " << endl;
	} while (not (h0>0));
	 
	 do { cout << " Quel est le coefficient de rebond de la balle ?" << endl;
	cin >> eps; 
	
	// si eps ne respecte pas l'une des 2 conditions, alors il y'a un faux ce qui rend donc vrai
	// grace au "and" et au "not".
	if (not((eps>=0)and(eps<1)))
	cout << endl <<"Entre 0 et 1, SVP!!! " << endl;
	} while (not((eps>=0)and(eps<1)));
	
	
	// hmin >0 aussi
	// je n'ai pas mis do { } car j'ai mis hmin <= h au lieu de hmin < h 
	double h(h0); double v; double hmin; int i(0);
	cout << "Hauteur minimale ?" << endl;
	cin >> hmin;
	while (not hmin<=h) {
		// v est inutile, autant remplacer par v1
		v=(sqrt(2*h*g)); v=eps*v; h=v*v/2/g;
		++i;
	}
	
	cout << "Nombre de rebonds : " << endl << i;
}
