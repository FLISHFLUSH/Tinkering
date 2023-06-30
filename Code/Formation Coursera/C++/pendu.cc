#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;
unsigned const int pendu(14);

//FAIT SANS LIRE LES INDICATIONS
struct Joueur {
	unsigned int score;
	unsigned int pendu;
	string nom="";
	string mot="";
	string progress="";
	//progress est inutile... aucun interet de le garder.
	
};
// on pourrait faire un tableau de pointeur, cependant n'ont uacune eistence à part dans le tableau
//pas utile;
typedef vector<Joueur> Groupe;
typedef vector<Joueur*> Joueurptr;

void affiche_pendu(Joueur const& j){
	unsigned int r(pendu-j.pendu); 
	switch (r) {
	case 14
	:; case 13:;case 12:; case 11:;	case 10:; case 9:;
   case 8: cout<<"  _____"; if (r>=8) cout <<"DEAD"; cout <<endl;
   case 7:  cout<<"  |   ";  cout <<"|"; cout <<endl; 
   case 6: cout<<"  | ";if (r>9)  cout<<"yyyyy"; cout <<endl;
   case 5: cout<<"  | "; if (r>10) cout<<"(X.X)";cout <<endl;
   case 4: cout<<"  | "; if (r>11) cout<<" \\o/"; cout <<endl;
   case 3: cout<<"  | ";if (r>12) cout<<" /|\\";cout <<endl;
   case 2: cout<<"  | ";if (r>13) cout<<" /'\\"; cout <<endl;
   case 1: cout<<"  |_______";cout <<endl;
   case 0: cout<<" /|       |";cout <<endl;
  


} cout<<endl;
} 


bool pendu_mot_trouve(Joueur j,string s) {
  	if (s==j.mot) return true;
  	return false; 
}


bool pendu_remplacer_lettre(char const& c, Joueur& j){	
bool trouve(false);

	for(size_t i(0); i<j.mot.size();i++)
	if ((j.mot[i]==c)and(j.progress[i]=='.')) { j.progress[i]=c; trouve=true; } 
	cout << j.progress<<endl;	if (not trouve) cout<<"Oups, mauvais choix de lettre !"<<endl;
return trouve;
}


void pendu_transfo(Joueur& j) {
	for (size_t i(0); i<j.mot.size(); i++) {
	//cout<<"zezezezeza";
	j.progress+='.';  }
}

void pendu_tous_transfo(Groupe& g){
	for(size_t i(0); i<g.size();i++)
	pendu_transfo(g[i]);
}




void pendu_demander_joueur(Groupe& g, unsigned int const& pendu) {
	g.clear();
	size_t nb;
	
	cout <<"Combien de joueurs ?  ";
    cin >> nb; 
    cout <<endl;
    
for (size_t i(0); i<nb; i++) {
	cout <<"nom du joueur "<< i+1 <<" ?  ";
	Joueur j={0,pendu,"","",""};
	//cout<<"eeeee";
	cin >> j.nom; 
	g.push_back(j); //cout<<"xxxxxxxxxx";
}	
}


void pendu_demander_mot(Groupe& g) {
for (size_t i(0); i<g.size(); i++) {
 cout<<"mot du joueur "<<i+1<<" ?  ";
 cin>> g[i].mot;
 for(size_t j(0);j<70;j++)
 cout<<"********************************************************"<<endl;
}

}
// /!\ const très important car sinon le paramètre g va etre copié donc mauvais pointage
Joueurptr pendu_constituer(Groupe& g){
	Joueurptr s;
	for(size_t i(0);i<g.size();i++)
	if ((g[i]).pendu!=0) s.push_back(&g[i]);
	//cout << s[0]<<"***"<<&g[0];
	return s;
}
// /!\ idem, const& important car sinon on fait une copie de j !!!
Joueurptr pendu_retirer_joueur(Joueurptr const& g, Joueur const& j) {
	Joueurptr c;
for (size_t i(0); i<g.size();i++)
//si adresse g[i]=adresse de j, ne pas pushback
if (g[i]!=&j) c.push_back(g[i]);
return c;
}
         // /!\ FONCTION TESTEE, SEMBLE BIEN FONCTIONNER. PAS DE SOUCI SUR POINTEUR, BONNES ADRESSES. ENREGISTRE BIEN --pendu, ARRETE BIEN SI PLUS DE JOUEUR DISPOS.
         //RESTE A TESTER LES                      INDICES !!!!
//renvoie l'indice
void pendu_joueurmot(Joueurptr& g, Joueur& j, size_t& i){
	 string s; char c;  
	 cout<<endl<<"                Mot du joueur "<<j.nom<<": "<<endl<<endl;
	 //on crée un vecteur de pointeurs qui points vers tous les joueurs qui doivnet deviner le mot. l'indice t est l'indice du joueur qui ne joue pas.
 bool trouve(false);
	 //si il n y a moins de 2 joueurs ou si qqn a trouvé le bon mot.
	 		while ((g.size()>0)and(not trouve)) { 
	//cout <<"(g[i]!=&j)   "<<(g[0]!=&j)<<(*g[i]).nom<<endl;			
	if (g[i]==&j) i++; else {

//cout<<i<<"   i" <<endl;
	 cout<<"Quelle lettre, "<<(*g[i]).nom<<" ?   ";
	 cin>>c;
	 if (not pendu_remplacer_lettre(c,j)) { 
		 --(*g[i]).pendu; //cout <<(*g[i]).pendu<<endl; 
		 affiche_pendu(*g[i]);}
	 //s'il ne trouve pas la lettre, on ne lui laisse pas deviner le mot
	  else {
 
 cout <<(*g[i]).nom<< ", avez-vous trouve le mot ? ";
		cin>>s;
		cout<<endl;
 	//si oui
if (s=="O") { cout <<"Donnez votre prédiction :"<<endl;
	cin>>s;
	trouve=pendu_mot_trouve(j,s);
	//s'il a trouvé
  if (trouve)  {
	 ++(*g[i]).score; cout<<"Bravo, "<< (*g[i]).nom<<" !!!"; } // break;  
	//sinon 
  else {
	 cout <<"Perdu !";
	 --(*g[i]).pendu; cout <<(*g[i]).pendu<<"  (*g[i]).pendu"<<endl<<endl;
}}}//sinon
//on retire un élément et l'indice était sur cet élément. Et j reçoit 1 point.
//cout<<"flush    "<<g.size();
 if ((*g[i]).pendu==0) { g=pendu_retirer_joueur(g,*g[i]); ++j.score; } 
 else	 ++i; 
} //comme if (g[i]==&j) i++; on doit vérifier si i ne dépasse pas notre tableau
 if (i>=g.size()) i=0; 
 
 // la condition pour sortir du while est (g.size()>0)and(not trouve) cependant si g.size pointe vers le joeuur, alors la boucle ne s'arretera jamais àcause if (g[i]==&j) i++;;
 // il faut break dans le cas ou ça arrive;
if ((g.size()==1)and(g[0]==&j)) break; }
} 


void pendu_deroulement( Joueurptr v, Groupe& g) {
	unsigned int t(0);
for (unsigned int i(0); i<g.size(); i++){
v=(pendu_constituer(g)); v.size();
		cout<<"Au tour du joueur du mot du joueur ("<<i+1<<"), "<<g[i].nom<<": ";
		pendu_joueurmot(v,g[i], t);
		cout<<endl<<endl;
	}
	 
	 
	/* //Les noms et mots ont été notés.
	 //On doit faire tous les mots, 1 par 1.// on parcout ainsi G pour récuperer les mots.
	 
	 // pour chaque mot, on peut éventuellement former un groupe temporaire (tableau de pointer) pour ceux qui doivent deviner.
	 // il faudra cependant garder et actualiser l'indice de ce tableau de faire en sorte d'interroger tout le monde
	
	 // si au cours de la phase de "devinage" quelqu'un est pendu, on le retire du groupe
	 //quand sous groupe ===1 ou qu'on a parcouru tous les mots, afficher resultats. */
}
void pendu_score_affiche(Groupe const& g) {
	for (size_t i(0); i<g.size(); i++){
		if (g[i].pendu==0) cout << g[i].nom<< " est pendu XDDDDDDDD"<<endl;
		else cout << g[i].nom <<" affiche un score de "<<g[i].score<< " avec son mot "<<g[i].mot<<". Pas mal !"<<endlw<;
	}
	
}
//rajouter fonction de classement

int main () {
	Groupe g; pendu_demander_joueur(g, 14); pendu_demander_mot(g); pendu_tous_transfo(g); 
	// g[1].pendu=0;
	Joueurptr v(pendu_constituer(g)); 
	pendu_deroulement(v,g);
	pendu_score_affiche(g);
	
	//(*s[0]).score=12; cout <<g[0].score;
	
	
}
