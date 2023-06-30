#include <iostream>
#include <ctime>

// pour les nombres aléatoires
#include <random>
#include <cstring> // strlen

using namespace std;

// ======================================================================
// Couleur au hasard
std::uniform_int_distribution<int> distribution;
std::default_random_engine generateur(time(NULL)); /* NOT using std::random_device since not
                                                    * all compilers seems to support it :-( */

char tirer_couleur()
{
  static const char* const couleurs = ".RGBCYM";
  static const int nb = strlen(couleurs) - 1;

  return couleurs[distribution(generateur,
                               std::uniform_int_distribution<int>::param_type {0, nb})];
}

// ======================================================================
char poser_question()
{
  char lu(' ');
  cout << "Entrez une couleur : ";
  cin >> lu;
  return lu;
}

// ---- prototype -------------------------------------------------------
bool couleur_valide(char c);

// ======================================================================
char lire_couleur()
{
  char lu(poser_question());
  while (not couleur_valide(lu)) {
    cout << "'" << lu << "' n'est pas une couleur valide." << endl;
    cout << "Les couleurs possibles sont : ., R, G, B, C, Y ou M." << endl;
    lu = poser_question();
  }
  return lu;
}

// ======================================================================
void afficher_couleurs(char c1, char c2, char c3, char c4)
{
  cout << ' ' << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4;
}

// ======================================================================
void afficher(int nb, char c)
{
  while (nb-- > 0) {
    cout << c;
  }
}

// ---- prototype -------------------------------------------------------
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4);

// ======================================================================
void afficher_coup(char c1, char c2, char c3, char c4,
                   char r1, char r2, char r3, char r4)
{
  afficher_couleurs(c1, c2, c3, c4);
  cout << " : ";
  afficher_reponses(c1, c2, c3, c4,
                    r1, r2, r3, r4);
  cout << endl;
}

// ======================================================================
void message_gagne(int nb_coups)
{
  cout << "Bravo ! Vous avez trouvé en " << nb_coups << " coups." << endl;
}

// ======================================================================
void message_perdu(char c1, char c2, char c3, char c4)
{
  cout << "Perdu :-(" << endl;
  cout << "La bonne combinaison était : ";
  afficher_couleurs(c1, c2, c3, c4);
  cout << endl;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/
void jouer(int a=8);
// ======================================================================
bool couleur_valide(char c)
{
	if ((c=='R')or(c=='G')or(c=='B')or(c=='C')or(c=='Y')or(c=='M')or(c=='.')) 
	    return true;
	else return false;
}

// ======================================================================
//NE PAS OUBLIER LE & POUR INT& N
bool verifier(char un, char& deux, int& n) 
             { 
	if (un==deux) { ++n; deux='x';return true;
  } else return false;
}

// ======================================================================
void apparier(char test, char& un, char& deux, char& trois, int& i)
             {
				 //besoin de return? REMPLACER par else?
			if (verifier(test, un, i)) return ;  if (verifier(test,deux,i)) return ;
			else verifier(test,trois,i) ;
}

// ======================================================================
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4)
{   char a(r1),b(r2),c(r3),d(r4);
	int i(0);
	int j(0);
	//AUTRE METHODE: ENREGISTRER LES BOOLENS ET if(vrai) aaparier
	if (verifier(c1,a,i)) c1='t';if (verifier(c2,b,i)) c2='t' ;if (verifier(c3,c,i)) c3='t'; if (verifier(c4,d,i)) c4='t';
	// cout << a<<"  "<<b<<"   "<<c<<"   "<<d<<endl; 
	 // il est important e vérifier les # avant les + avant les -
	//if (c1==r1) ++i; if (c2==r2) ++i;if (c3==r3) ++i; if (c4==r4) ++i;  
	 apparier(c1, b, c, d, j);  //cout << a<<"  "<<b<<"   "<<c<<"   "<<d<<endl;
	 apparier(c2, a, c, d, j);  //cout << a<<"  "<<b<<"   "<<c<<"   "<<d<<endl;
	 apparier(c3, a, b, d, j); //cout << a<<"  "<<b<<"   "<<c<<"   "<<d<<endl;
	 apparier(c4, a, b, c, j); //cout << a<<"  "<<b<<"   "<<c<<"   "<<d<<endl;
	afficher(i,'#'); afficher(j,'+'); afficher(4-i-j,'-');
}

// ======================================================================
bool gagne(char c1, char c2, char c3, char c4,
           char r1, char r2, char r3, char r4)
{
	if ((c1==r1)and(c2==r2)and(c3==r3)and(c4==r4)) return true;
	else return false;
}

// ======================================================================
void jouer(int n)
{
    int i(0);
    //char r1='.'; char r2='.'; char r3='M'; char r4='.';
	char r1(tirer_couleur()); char r2(tirer_couleur()); char r3(tirer_couleur()); char r4(tirer_couleur());
	//afficher_couleurs(r1,r2,r3,r4);
	bool gagner;
	do {i++; 
		char c1=(lire_couleur()), c2=(lire_couleur()),
		c3=(lire_couleur()), c4=(lire_couleur());
		gagner=gagne(c1,c2,c3,c4,r1,r2,r3,r4);
		afficher_coup(c1,c2, c3, c4,
                   r1, r2, r3, r4);
			   } while (not(gagner)and(i<n)) ;
			   if (gagner) message_gagne(i);
			   else message_perdu(r1,r2,r3,r4);
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  jouer();
  return 0;
}
