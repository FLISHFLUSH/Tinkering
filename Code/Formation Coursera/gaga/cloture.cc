#include <iostream>
#include <vector>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/
// idée: incrementer de 1 tant qu'on ne change pas de direction mais si ça arrive, +1 - 1 et on recommence dans une autre direction.
//autre idée: partir des 0 dans les étangs et rajouter +1 pour chaque 1 à droite, ghauche, en haut en bas
typedef vector<vector<int>> Carte;

struct Position {
	int i;
	int j;
};


double longueur_cloture(Carte const& carte,
double echelle = 2.5) ;

bool binaire(Carte const& carte) {
	for(auto a: carte)
	for(auto b:a)
	if ((b!=1)and(b!=0)) return false;
	
	return true;
}

void affiche(Carte const& carte) {
	for(auto a: carte){
	for(auto b:a)
	cout << b;
    cout <<endl;
}
cout << endl <<"----"<<endl;
}

bool verifie_et_modifie(Carte& carte){
//reecrire avec un switch ? ou une fonction ??
if (binaire(carte)) {
	for(size_t i(0); i<carte.size();i++){
		//cout << i << "   ";
		bool Precedent(false), suivant(false);
		//si suivant est vrai, la ligne a déjà été transformé, on arrete la boucle j;
	for(size_t j(0); (j<carte[i].size())and(not(suivant));j++){
		//cout << j << "    ";
		// si on detecte un 1 en partant de la gauche, prec=true;
	if (carte[i][j]==1) Precedent=true; //cout << ((carte[i][j]==0)and(Precedent))<<"     " <<suivant<< "         "<< i<< "   " << j<<endl;
	// si on detecte un 0 en partant de la gauche et qu'on a un précedent
	if ((carte[i][j]==0)and(Precedent)) 
		 for (size_t z(carte[i].size()-1); z>j;--z){ //cout<< z << endl;
			// Si on detecte un 1 en partant de la droite, suivant=true en s'arretant à l'indice du 0 qui nous a fait rentré dans le for;
		if (carte[i][z]==1) { suivant=true; carte[i][j]=1; } // on travaille sur des size_t donc z>=j pour j=0 donneune boucle infine
		//si suivant et on trouve un 0 en partant de la droite, remplacer sa valuer par 1;
		if ((suivant)and(carte[i][z]!=1)) carte[i][z]=1;  
	} 
			
}
}
return true;
}
   else cout << "Votre carte du terrain ne contient pas que des 0 et des 1." << endl;
    return false;
}

double longueur_cloture(Carte const& carte,
double echelle){

int cloture(0);
for(size_t i(0); i<carte.size(); i++)
 for(size_t j(0); j<carte[i].size(); j++) {
    if (carte[i][j]==1) 	  
	//   if (i>0)and[carte[i-1][j]!=1)          
	switch(1) {
	//on peut écrire and(carte[i-1]) pour i=0 car l'ordi test i>0 avant pour résoudre le and.
	case 1: if ((i>0)and(carte[i-1][j]!=1)) ++cloture ; if ((i==0)and(carte[i][j]==1)) ++cloture;// cout <<"1: " << i << " et "<< j<< "     " <<cloture<< endl;
	case 2: if ((i<carte.size()-1)and(carte[i+1][j]!=1)) ++cloture ; if ((i==carte.size()-1)and(carte[i][j]==1)) ++cloture; // cout <<"1: " << i << " et "<< j<< "     " <<cloture<< endl;
	case 3: if ((j>0)and(carte[i][j-1]!=1)) ++cloture ; if ((j==0)and(carte[i][j]==1)) ++cloture; // cout <<"1: " << i << " et "<< j<< "     " <<cloture<< endl;
	case 4: if ((j<carte[i].size()-1)and(carte[i][j+1]!=1)) ++cloture ;  if ((j==carte[i].size()-1)and(carte[i][j]==1)) ++cloture; // cout <<"1: " << i << " et "<< j<< "     " <<cloture<< endl;

}
 // cout <<"***"<< i << "   " << j << "    " <<cloture<< "***"<<endl; 
 }
return cloture*echelle;
}


void marque_composantes(Carte& carte){
	 vector<Position> trait;
int composante(1);
for(size_t i(0); i<carte.size(); i++)
  for(size_t j(0); j<carte[i].size(); j++) {
   if (carte[i][j]==0)	{
     ++composante; 
     //cout << composante << "     **"<< endl; // si ne fonctionne pas, init position avec ({i,j}) 
     trait.push_back({i,j});
     while (trait.size()!=0) {
		// cout <<trait[trait.size()-1].i<< "    " << trait[trait.size()-1].j<<" tudu"<< endl;
	   Position p(trait[trait.size()-1]); trait.pop_back();
	   	//   cout <<p.i<< "    " << p.j<< endl;
	   if (carte[p.i][p.j]==0) { 
	   carte[p.i][p.j]=composante;
	   if (p.i>0)            {int carteN(carte[p.i-1][p.j]); if (carteN==0) trait.push_back({p.i-1,p.j}); }
	   if (p.i<carte.size()-1) {int carteS(carte[p.i+1][p.j]); if (carteS==0) trait.push_back({p.i+1,p.j}); }
	   if (p.j>0)            {int carteO(carte[p.i][p.j-1]); if (carteO==0) trait.push_back({p.i,p.j-1}); }
	   //1/2h perdue car j'ai écrit carte.size au lieu de carte[i].size...
	   if (p.j<carte[i].size()-1) { int carteE(carte[p.i][p.j+1]); if (carteE==0)  trait.push_back({p.i,p.j+1}); }
	// en gros, on parcourt les cases alentours et les enregistre si ==0. Tant qu'il y'a des nombres des diff de 0, on fait des push_back, quand ce n'est plus le cas, spam pop_back
	 }
	 }
}

}
	
}

void ajoute_unique(vector<int>& ensemble, int valeur) {
	bool t(true);
for(size_t i(0); i<ensemble.size(); i++)
if (ensemble[i]==valeur) t=false;
if (t) ensemble.push_back(valeur);
}

 void ajoute_sans_un(vector<int>& ensemble, int valeur) {
if (valeur!=1) ajoute_unique (ensemble, valeur);	 
 }
 
vector<int> valeur_rebord(Carte carte){
	/*   ***********
	     *         *
	     *         *
	     *         *
	     *         *
	     *********** */
	vector<int> ensemble(0);
	for(auto ligne:carte)
	ajoute_sans_un(ensemble, ligne[0]);
	for(auto ligne:carte)
	ajoute_sans_un(ensemble, ligne[ligne.size()-1]);
	for(auto colonne:carte[0])
	ajoute_sans_un(ensemble, colonne);
	for(auto colonne:carte[carte.size()-1])
	ajoute_sans_un(ensemble, colonne);
	
	return ensemble;
}

bool convexite_lignes(Carte& carte, vector<int> const& labels_bords) {
	for(size_t i(0); i<carte.size(); i++){
	bool prem(false); bool der(false); size_t a(carte[i].size());
	for(size_t j(0); j<a;j++){
     if (carte[i][j]==1)  {
		 //prem inutile ? car si der, alors prem--et si prem faux alors der faux
		 prem=true;
		 //z tourne dans j, cherche un der et change la borne de recherche pour j;
		 // on ne refait pas la recherche si der est vrai: (not(der));
       for(size_t z(carte[i].size()); (z>j)and(not(der));--z){
		   //z>j donc der!=prem
	    if (carte[i][z]==1) { der=true; a=z; }
	   }
	 }
	 // si on trouve un !=1, et qu'on a déjà un prem et donc que j>prem et qu'on a un dernier (=> que j<der, car recherche avec z par le sens ivnerse et on sait que der != prem)
	 if ((carte[i][j]!=1)and(prem)and(der))
	   for(auto n:labels_bords)
	   if (carte[i][j]==n) { cout << "Votre carte du terrain n'est pas convexe par lignes :" << endl;
	   cout << "bord extérieur entrant trouvé en position [";
          cout <<i<< "][";
          cout <<j<< "]" << endl; return false;
	  }
	 
	 
 }		
} return true;	
}

bool convexite_lignes(Carte& carte)  {
	marque_composantes(carte);
	vector<int> labels_bords(valeur_rebord(carte));
	return convexite_lignes(carte,labels_bords);
}


         


/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Carte carte =  {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} /* {  0,1,1,1,1,1,0},
{  0,1,1,1,1,1,0},
{  0,1,1,1,1,1,0} */
  };

 cout <<convexite_lignes(carte)<<endl;
 affiche(carte);
 cout << "Carte au départ :" << endl;
  affiche(carte);
  if (verifie_et_modifie(carte)) {
    cout << "Carte après modification :" << endl;
    affiche(carte);
    cout << "Il vous faut " << longueur_cloture(carte)
         << " mètres de clôture pour votre terrain."
         << endl;
  } 
// convexite_lignes(carte);
 //affiche(carte);
 // IL MANQUE LA FONCTION QUI CALCULE LA CLOTURE.
  return 0;
}
