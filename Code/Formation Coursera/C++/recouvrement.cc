#include <iostream>
#include <vector>
#include <array>
using namespace std;

const unsigned int DIM(10);
bool remplitgrille(array<array<bool,DIM>, DIM>& grille, unsigned int ligne, unsigned int colonne, char direction, unsigned int longueur){
// idee du cours: plutot que de réecrire du code à coup de si N, alors va en haut, si E (etc) on donne une valeur pour N S E et O et on applique une formule générale
 int x; int y; bool test(true);
 if (direction=='N') { x=-1; y=0; } 
 if (direction=='S') { x=1;  y=0; }
 if (direction=='E') {x=0;  y=1;  }
 if (direction=='O') {x=0; y=-1;  }	
 
 // on décide que ligne contient des colonnes.
 //ligne = 2; colonne = 3;
 // cout << ligne-colonne;
 unsigned int a(ligne), b(colonne), l(longueur);
 while ((l!=0)and(a!=0)and(b!=0)and(a!=DIM-1)and(b!=DIM-1)and(not(grille[a][b]))){
 a+=x; b+=y; l-=1; 
}
	 
 
 if ((grille[a][b])or(l!=0)) { test=false; cout <<l<<"    " <<grille[a][b]<<endl;}
else { grille[ligne][colonne]=true;
while (longueur!=0){
 ligne+=x; colonne+=y; grille[ligne][colonne]=true; longueur-=1; 
}
}
return test;
}

void ajouter_element(array<array<bool, DIM>, DIM>& grille) {
unsigned int ligne, colonne, longueur; 
do {	cout << "Indiquez la ligne par un nombre entier positif (0 pour arrêter le programme) : " ;
	cin  >> ligne;
	if (ligne >0) {
	cout <<endl <<endl<< "Indiquez la colonne par un nombre entier positif (0 pour arrêter le programme) : " ;
	cin>> colonne;
	   if (colonne >0)  {
		cout <<endl <<endl<< "Indiquez une longueur par un nombre entier positif (0 pour arrêter le programme) : " ;
		cin >> longueur;
		   if (longueur >0) {
			   char dir;
			   do { cout <<endl <<endl<< "Indiquez une direction (N, O, E ou S) : " ;
				   cin>> dir;
				   } while ((dir!='N')and(dir!='S')and(dir!='E')and(dir!='O'));
				if (remplitgrille(grille, ligne, colonne, dir, longueur))  cout << "L'élément a été décalé de "<<longueur<< "vers la direction "<<dir<<'.'<<endl;
				else cout <<"La longueur était trop grande pour placer l'élément dans la direction "<< dir<<"."<<endl; 
			   }
	}

}
} while ((ligne!=0)and(colonne!=0));
}

void lire_matrice(array<array<bool,DIM>,DIM> v){
for(auto ligne:	v) {
for(auto colonne: ligne) {
	if (colonne==false) cout << "-";
	else cout<<"*";
}
cout << endl;
}
}
void init_array(array<array<bool,DIM>,DIM>& v){
for(auto& l:v)
for(auto& c:l)
c=false;
}

int main() {
	array<array<bool,DIM>, DIM> grille;
	init_array(grille);
	lire_matrice(grille);
	ajouter_element(grille);
	lire_matrice(grille);


}
