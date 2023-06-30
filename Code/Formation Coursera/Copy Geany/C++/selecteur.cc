#include <iostream>
#include <vector>
#include <string>
#include <memory>


using namespace std;

int main() {
	
	double a(0), b(1), c(2);
	double* choix;
	unique_ptr<int> vide(new int);
	cout <<"Nombre entre 1 et 3"<<endl;
	cin >> *vide;
	if (*vide==1) choix=&a; else if(*vide==2) choix=&b; else choix=&c;
	cout<<"Vous avez choisi " << *choix;
}
