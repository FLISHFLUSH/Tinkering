#include <iostream>
#include <cmath>
using namespace std;

int main (){
	double nbr;
	double eps;
	double h0;
	const double g(9.81);
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
	
	do { cout << "Pour combien de rebonds ? " << endl;
	cin >> nbr; 
	if (not(nbr>=0)) 
	cout << endl << "très drôle ! mais plus sérieusement..." << endl;
	} while (not (nbr>=0));
	
	double h(h0); double v;
	double v1;
	for (int i(0); i<nbr;++i){
		// v est inutile, autant remplacer par v1
		v=(sqrt(2*h*g)); v1=eps*v; h=v1*v1/2/g;
		
	}
	cout << "hauteur " << endl << h<< "mètres.";
}
