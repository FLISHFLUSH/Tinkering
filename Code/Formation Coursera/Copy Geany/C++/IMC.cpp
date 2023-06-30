#include <iostream>
using namespace std;

int main  ()
{
	double poids;
	double taille;
	
	cout << "Donnez votre poids" <<endl;
	cin >> poids;
	cout << "maintenant votre taille"<<endl;
	cin >> taille; 
	
	double imc(poids / (taille*taille)) ;
	
	cout << "votre imc est de " << imc << " tavu." << endl ;
	
	return imc;
}
