#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <math.h>

using namespace std;	
enum Couleur {rouge, jaune,vide};
//int jaune;
//Couleur jaune;
//enum mumu {rouge, tudu};

// /!\ Choses à NOTER:
//on pourrait inventerune sous classe de joueur pour chaque Jeu (joueurPoker, joueurDames etc)
//une partie regroupe les joueurs avec les jeux, ce qui rend l'utilisation des atributs plus simple ?
  /*                   i (colonnes)
   * ^
   * |
   * |
   * |
   * |
   * |
   * | j (lignes)
   * |
   * |
   * |
   * |
   * -----------------------------------> 
   *                   i (colonnes)
   * */
 class Jeu {
	vector<vector<Couleur>> jeu;
	bool pasplein(size_t col) { if (jeu[col][jeu[col].size()-1]!=vide) return false; return true;}
	 
	 //complication avec les size_t cependant c'est une fonction privée donc on e permet un unage particulier
	 unsigned int comptage_partiel(size_t col, size_t ligne, int dx, int dy,Couleur c){
		unsigned int chaine(0); size_t i(col); size_t j(ligne); 
		// sii!=0 ou i==0 and dx>0
		 while ((i!=0)and(i!=jeu.size())and(j!=0)and(j!=jeu.size())) {
			 i+=dx;j+=dy; if (jeu[i][j]==c) chaine++;
			 }
			 return chaine;
		 }
		unsigned int comptage(size_t col, size_t ligne, int dx, int dy,Couleur c) {
			return comptage_partiel(col, ligne,dx,dy, c)+comptage_partiel(ligne, col,-dx,-dy, c);
			}
		
	public:
	Jeu(unsigned int nb_cases=8)
	:jeu(vector<vector<Couleur>> (nb_cases,vector<Couleur> (nb_cases,vide))) {}
	
	
	size_t taille() {return jeu.size();}
	size_t jouer(size_t col, Couleur) ;
	Couleur gagnant(size_t, size_t , Couleur); // on pourrait faire une fonction qui prend en argument la couleur et la colonne jouées et teste aux alentours
	//si gagnant (mettre en attribut ?)
	//while(not jouer(...) {} ????

	};  
   
class Joueur{
	protected:
	Couleur couleur;
	string nom;
	public:
	string getN() {return nom;};
	Couleur getC() {return couleur;};
	virtual  vector<size_t> jouer(Jeu&) =0;
	};

class AI:public Joueur{
	vector<size_t> jouer(Jeu&);
	};
	
class Humain:public Joueur {
	 vector<size_t> jouer(Jeu&);
	};

class Partie{
	vector<Joueur> joueurs;
	Jeu jeu;
	//rajouter static pour initialiser une partie ?
	
	public:
	Partie(Joueur const& j1, Joueur const& j2, Jeu const& jeu)
	:joueurs({j1,j2}), jeu(jeu) {}
	
	static 
	bool partie();
	
	};
// ==================================	
size_t Jeu::jouer(size_t col, Couleur c) {
	if (pasplein(col)) 
	for(size_t i(0);i<jeu.size();i++) { //jeu.size()=jeu[col].size()
	 if (jeu[col][i]==vide) { jeu[col][i]=c; return i;} else; }
	
	 else return jeu.size();
	}hj
Couleur Jeu::gagnant(size_t col, size_t ligne, Couleur c){
	int chaine(1); 
	//on aurait pu faire une boucle for qui parcourt un double tableau de vector  (4,(2)) {0,1},{1,1}...
	chaine+=comptage(col, ligne, 1,0,c);
	if (chaine==4) return c;
	chaine+=comptage(col, ligne, 0,1,c);
	if (chaine==4) return c;
	chaine+=comptage(col, ligne, 1,1,c);
	if (chaine==4) return c;
	chaine+=comptage(col, ligne, 1,-1,c);
	if (chaine==4) return c;
	return vide;
/*	tant que on reste dans le tableau && couleur case=c chainer ++
	sinon la meme chose dans l'autre sens
	si chaine =4 (ou > mais inutile si code bien fait) return c;
	sinon on recommence dans une autre direction et chaine==1
	
	4 direction !!! NS OE NOSE NESO faire fonction avec en parametre dx dy  */
	}
//RJOUTER FONCTION MATCH NUL (ou mettre dans partie un COMPTEUR)=cotex;


vector<size_t> Humain::jouer(Jeu& jeu) {
bool non_place(false); size_t ligne; size_t col;
do { if (non_place) cout<<"Pion non placée !"<<endl;
	cout<<nom<<", dans quelle colonne placez-vous le pion ? (de 0 a "<<jeu.taille()-1<<"."<<endl;
cin >> col; ligne=jeu.jouer(col,couleur);
non_place=(ligne==jeu.taille());
}
while(non_place);
return {col, ligne};
}


vector<size_t> AI::jouer(Jeu& jeu) {
cout<<"L'IA stupide place son pion dans la colonne la plus à gauche"<<endl;
size_t col; size_t ligne;
	for( col=0; col<jeu.taille(); col++)
	if ((ligne=jeu.jouer(col, couleur))!=jeu.taille()) break;
	return {col, ligne};
	}
	


bool Partie::partie() {
	size_t compteur(0);
	size_t max=jeu.taille()*jeu.taille(); vector<size_t> position;
 do {
	 //mauvais code, c'est à la fonction partie de bien voir si les régles sont respectées.
	position=joueurs[compteur%2].jouer(jeu); ++compteur;
} while ((jeu.gagnant(position[0],position[1], joueurs[compteur%2].getC())==vide)or(compteur<max));	
if (compteur!=max) cout<<"Bravo a "<<joueurs[compteur%2].getN()<<" qui a gagné la partie !"<<endl;
else cout <<"match nul ! :'((("<<endl;
return false;
}

int main() {
	
	
	return 0;
	}
