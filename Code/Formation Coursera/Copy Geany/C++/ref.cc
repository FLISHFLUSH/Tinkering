#include <iostream>
#include <vector>
#include <string>
#include <memory>


using namespace std;

struct Maison {
	string adresse;
};
 struct Personne {
	
string nom;
Maison*  maison;
};

void affiche(const Personne& p){
	//même si structure a 1 seul champ, il faut préciser ce champ 
	//pour identification;
	// (*(P.maison)).adresse  pensé mais non écrit, dommage
	cout << p.nom<<" habite au " << (*(p.maison)).adresse<<endl;
	//(p.maison)->adresse
}

int main() {
enum direction { N = 2, NE, E, SE, S, SO, O, NO };

for (int i(E); i < O ; ++i) {
  cout << i << " ";
}	
Maison maison1={"18, rue des lilas fleuris"}; Maison maison2={"00 rue du commencement"};
Personne p1={"Jean-Paul", &maison1}; Personne p2={"Cynnedy", &maison2}; p2.maison=&maison1;
affiche(p1); affiche(p2); 

delete p2.maison; delete p1.maison;
p1.maison=nullptr; p2.maison=nullptr;
//inutile, pas d'alllocation dynamique;
	
}
	
