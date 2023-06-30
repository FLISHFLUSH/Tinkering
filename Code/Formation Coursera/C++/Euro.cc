#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;
typedef unsigned int Score;	
// equip va stocker le score de chaque equipe.
//difference avec le corrig‚:
//ils demande les matchs puis demandent les buts; les matchs sont des struct … 2 int ou chaque int
//correspond … l'indice du pool
//le mien: on sauvegarde chaque match et chaque but dans structure et les equipes sont reperees par leur string
//puis par leur indice: l'utilisateur renvoie les equipes dans l'ordre squi lui plait 
// il metait possible de proc‚der comme le corrig‚ (sauv dindice plutot que ref);
struct Equip {
		string nom;
		Score points;
	    int but;
	    int butadv ;
		};
// les valeurs de Match vont etre initialis‚s par l'utilisateur et stock‚s dans un tableau.	

//remplacer struct match par une fonction sur des ‚quipes ?	Ok si on stocke pas de matchs
struct Match {
	 Equip& equip1;
	 Equip& equip2;
 	int but1;
	int but2;
};
// on est paresseux, on typedef presque tout
typedef vector<Equip> Pool;
typedef vector<Match> Competition;

void affiche_E(Equip const& E) {
	cout<<E.nom<<" - "<<"Score: " <<E.points<< " - "<< "Nombre de buts r‚alis‚s: "<< E.but<<
	" - "<<"Nombre de buts encaiss‚s: "<< E.butadv<<endl;
 }
void P_affiche(Pool const& euro) {
	cout<<"    R‚sultats"<<endl;
	for(size_t i(0); i<euro.size();i++) 
	affiche_E(euro[i]);
	

}

void resultat(Match& M){
	switch (1) { 
	case 1: if (M.but1==M.but2) { ++((M.equip1).points); ++((M.equip2).points);  break; }
	case 2: if (M.but1>M.but2)  { M.equip1.points+=3;  } else M.equip2.points+=3;  break;
	};
	cout <<"kkkkkk"<<endl; cout << (M.equip1).but;
	(M.equip1).but+=M.but1; (M.equip1).butadv+=M.but2; 
	(M.equip2).but+=M.but2; (M.equip2).butadv+=M.but1;
		cout <<"ggggggg"<<endl;

}

void deroulement_euro(Competition& M){
	for(size_t i(0); i<M.size(); i++)
	resultat(M[i]);
}


Competition Demander(Pool& P){
	Competition c;int num_match(0); string s; bool tss(true);
	do { 
		size_t E1(0); size_t E2(0);
		//comme Match contient un ref‚rence, on peut pas le reaffecter comme on veut.
		//c'est “ur cela qu'on doit en declarer un nouveau … chaque nouvelle prise de donn‚e.
		//NON TESTE !!!!!
	cout << "****Match " << num_match +1<<":"<<endl;
	//eventuellemnt ajouter boucle while pour le cas ou les r‚ponses ne sont pas correctes sur 
	//le modele de locationvelos.cc      while(not reponse correcte) { poser question; cin;  }
	// on pouvait faire avec for (i(0) i<2) mais ‡a implique de creer un Pool pour match;
	// ou alors faire en sorte que pool soit un tableau de pointeur sur equip!!!!
	
	cout << "*Equipe 1"<<endl;
	do { cout<<"Nom ?"<<endl;
		cin>>s; //cout <<s<<"cout s";
		//faire fonction ??
		for(E1=0; E1<P.size();E1++) { //cout<<"(P[E1].nom==s) "<<(P[E1].nom==s) ;
		if (P[E1].nom==s) { tss=false; break;} }
	//rappelle : on travail sur un tableau de Equip.
	} while (tss); 
	//meme chose pour equipe 2
	
			tss=true;
	cout <<endl<< "Equipe 2"<<endl;
	do { cout <<"Nom ?"<<endl;
		cin>>s; //cout <<(P[1].nom==s)<<"cout s";
		//faire fonction ??
		for(E2=0; E2<P.size();E2++) { //cout <<"(P[E2].nom==s)  "<<(P[E2].nom==s);
		if (P[E2].nom==s) { tss=false; break;} }
	//rappelle : on travail sur un tableau de Equip.
	} while (tss);
	//cout<< "erer"<<E1<<"   "<<E2;
	/* /!\ Ne pas renvoyer … match une copie de P[E1], P[E2], mais initialiser directement dessus ! erreur
	 sur ref‚rence sinon (p‚tage de cable, 1h30 deperdu); */
	Match match {P[E1],P[E2]}; 
	// on aurait pu choisir E1 E2 au lieu de P[E1] P[E2]
	cout <<endl<<"Nb de buts r‚alis‚s par l'‚quipe 1"<<endl;
	cin >> match.but1; 
	cout <<"Nb de buts r‚alis‚s par l'‚quipe 2"<<endl;
	cin >> match.but2;
	c.push_back(match);
	//cout<<match.equip1.points;
	//'v' bool fonction "string, string) 'v'
	// remplacer cette question par une demande de nombre de match
cout<<endl<<"un autre match ??"	<<endl<<endl;
cin >> s ;

	++num_match;
	
	//essayer de decomposer ce code en fonctions qui prennent en paramŠtres des fonctions ?
	//car meme proc‚d‚ pour cr‚ation d'un pool et d'un competition;
	} while (s=="oui");
	return c;
}
bool meilleure(Equip const& e1, Equip const& e2) {
//	switch ? flemme
//rajouter des accolades ? flemme
	if (e1.points==e2.points) 
	  if ((e1.but-e1.butadv)==(e2.but-e2.butadv)) 
	    { if (e1.but>=e2.but) return true; } 
	  else if ((e1.but-e1.butadv)>(e2.but-e2.butadv)) return true;
	if (e1.points>e2.points) return true;
	return false;
}

void classement(Pool& P) {
for(size_t i(0); i<=2;i++)
for (size_t j(3); j>=i+1; --j)	
if (meilleure(P[j-1], P[j-2])) swap(P[j-1], P[j-2]);
}

int main () {
	
	
	//fonction possible
	 string s; int i(0); Pool P(0); 
	cout<< "Entrez non pour terminer une commande" <<endl<<endl;
	/*do { 
		Equip E;
		cout <<"Donnez le nom de l'‚quipe " <<i+1<<": "<<endl;
		cin >> s;
		E={s,0,0,0};
		P.push_back(E);
		i++;
	} while (s!="non"); 
	
	if (P.size()>0) */
	   Equip E3={"F",0,0,0}, E2={"A",0,0,0}, E1={"C",0,0,0}, E4={"S",0,0,0};P={E1,E2,E3,E4};
		Competition euro(Demander(P));
		//(euro[0].equip1).points=10;
		
		/*cout<<E1.points<<"erer";
		cout <<(euro[0].equip1).points;
		cout<<endl<<(euro[0].equip1).points<<"ddd";
		* */
		//cout <<endl<<endl<<"****"<<P.size()<<"      "<<euro.size()<<"****"<<endl<<endl;
		deroulement_euro(euro);
		cout<<endl<<(euro[0].equip1).points<<"ddd";
		P_affiche(P);
		classement(P); P_affiche(P);
	//}
}


