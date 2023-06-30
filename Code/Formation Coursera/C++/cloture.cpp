#include <iostream>
#include <vector>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/

typedef vector<vector<int>> Carte ;
struct Position {
	size_t i; 
	size_t j;
	};
void remplir(Carte& carte, size_t i, size_t j, size_t k) {
	while(j<=k) {
		carte[i][j]=1; j++;
		}
	}
bool binaire(Carte const& carte);
void affiche(Carte const& carte);
bool verifie_et_modifie(Carte& carte);
unsigned int cloture_pos(Carte const& c, Position pos);
double longueur_cloture(Carte const& carte, double echelle = 2.5);


bool binaire(Carte const& carte) {
	for (auto ligne: carte)
	for (auto ligne_colonne: ligne) { 
	if ((ligne_colonne!=1) and (ligne_colonne!=0)) return false; }
	return true;
	}
void affiche(Carte const& carte) {
    for (auto ligne: carte){
	for (auto ligne_colonne: ligne) 
	cout<<ligne_colonne; 
	cout<<endl; } 
	cout<<endl<<"----"<<endl;
}

bool verifie_et_modifie(Carte& carte){
	if (binaire(carte)) {
		for(size_t i(0); i<carte.size(); i++) {
		bool etang(false);
		for (size_t j(0); j<carte[i].size(); j++)
		 if (etang) break;
		 else if (carte[i][j]==1) {
		  for (size_t k(carte[i].size()-1);k>j;k--)
		  if (carte[i][k]==1) { remplir(carte, i,j,k); etang=true;}
	      }
	     } return true;
		}
    else { cout << "Votre carte du terrain ne contient pas que des 0 et des 1." << endl;  return false; }
}


unsigned int cloture_pos(Carte const& c, size_t i, size_t j){
	//on part du principe que i j ne débordent pas;
	unsigned int cloture(0);
	if (c[i][j]==1) {
	if (i>0) {if (c[i-1][j]==0) cloture++;} else cloture++;
	if (j>0) {if (c[i][j-1]==0) cloture++;} else cloture++;
	//cout<<i<<"---"<<c.size()<<"{}";
	if (i<c.size()-1) { if (c[i+1][j]==0) cloture++;} else cloture++;
	//cout<<j<<"**";
	if (j<c[i].size()-1) {if (c[i][j+1]==0) cloture++;} else cloture++;
    }
    return cloture;
	}
	
double longueur_cloture(Carte const& carte, double echelle){
	Carte c=carte;
	verifie_et_modifie(c);
	unsigned murs(0); 
	for (size_t i(0); i<c.size();i++) 
	for (size_t j(0); j<c[i].size(); j++) { 
		//cout<<j<<" ";
	murs+=cloture_pos(c,i,j); }
	return murs*echelle;
	}
//--------------------------
void marque_composantes(Carte& carte){
vector<Position> position;
int composante(1);
for(size_t i(0); i<carte.size(); i++)
for(size_t j(0); j<carte[i].size(); j++)
if (carte[i][j]==0) 
  {
   composante++; position.push_back({i,j});
   while (position.size()!=0)
   {
	Position p(position.back()); position.pop_back(); 
	size_t pi=p.i; size_t pj=p.j;
	if (carte[pi][pj]==0) 
	{
	 carte[pi][pj]=composante;
	 if (pi>0 and carte[pi-1][pj]==0) position.push_back({pi-1,pj});
	 if (pj>0 and carte[pi][pj-1]==0) position.push_back({pi,pj-1});
	 if (pi<carte.size()-1 and carte[pi+1][pj]==0) position.push_back({pi+1,pj});
	 if (pj<carte[i].size()-1 and carte[pi][pj+1]==0) position.push_back({pi,pj+1});
	 } 
    }
   }
}
void ajoute_unique(vector<int>& ensemble, int valeur)
{
bool unique(true);
for(auto val:ensemble)
if 	(val==valeur) { unique=false; break; }
if (unique) ensemble.push_back(valeur);
}
void ajoute_sans_un(vector<int>& ensemble, int valeur) {
if (valeur!=1) ajoute_unique (ensemble, valeur);	 
 }
void tour_carte(vector<int>& ensemble, Carte const& carte) {
	/*   ***********
	     *         *
	     *         *
	     *         *
	     *         *
	     *********** */
for (size_t j(0); j<carte[0].size(); j++)
ajoute_sans_un(ensemble, carte[0][j]);
for (size_t j(0); j<carte[carte.size()-1].size(); j++)
ajoute_sans_un(ensemble, carte[carte.size()-1][j]);
for (size_t i(0); i<carte.size(); i++)
ajoute_sans_un(ensemble, carte[i][0]);
for (size_t i(0); i<carte.size(); i++)
ajoute_sans_un(ensemble, carte[0][carte[i].size()-1]);
}
bool fait_partie(vector<int> const& ensemble, int valeur){
for (auto val:ensemble)
if (val==valeur) return true;
return false;
}
bool convexite_lignes(Carte& carte, vector<int> const& labels_bords)
{
for(size_t i(0); i<carte.size(); i++)
 { 
 bool prem_et_der(false);
 for(size_t j(0); j<carte[i].size();j++)
 if (prem_et_der) break;
 else if (carte[i][j]==1)  
   { 
	for(size_t k(carte[i].size()-1); k>j;k--) {
	 if (carte[i][k]==1)  prem_et_der=true;  
	// cout<<i<<"  "<<k<<"  "<<fait_partie(labels_bords, carte[i][k])<<" * ";
	else if (fait_partie(labels_bords, carte[i][k]) and prem_et_der)
	 { while(carte[i][j]==1) j++;
		 cout << "Votre carte du terrain n'est pas convexe par lignes :" << endl;
          cout << "bord extérieur entrant trouvé en position ["<<i;
          cout << "][";
          cout << j<<"]" << endl; return false;
		 }
	 
      } //cout<<endl;
	}

 }
return true;
}
bool convexite_lignes(Carte& carte)
{
	marque_composantes(carte);
	vector<int> ensemble;
	tour_carte(ensemble, carte);  //for (size_t i(0);i<ensemble.size();i++) cout<<ensemble[i]<<"t  "<<endl;
	return convexite_lignes(carte,ensemble);
}
/*         

    */

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Carte carte = {
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
    {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  };

  cout << "Carte au départ :" << endl;
  affiche(carte);
  if (verifie_et_modifie(carte)) {
    cout << "Carte après modification :" << endl;
    affiche(carte);
    cout << "Il vous faut " << longueur_cloture(carte)
         << " mètres de clôture pour votre terrain."
         << endl;
  }

  return 0;
}
