 #include <iostream>
#include <cmath>
using namespace std;

int main () {
 
 
  cout << "Pensez à un champignon : amanite tue-mouches, pied bleu, girolle," << endl
       << "cèpe de Bordeaux, coprin chevelu ou agaric jaunissant." << endl << endl;
  int lame(2), anneau(2), chapeau(2), foret(2), i(0);
  
  //forcément anneau => foret => lame
  
   cout << "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
  cin >> anneau;

  
  cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
  cin >> chapeau;

  if (chapeau==1) {
	  if (anneau==1) i=1; 
	  }
	  else if (anneau==0) i=2;
  

	  
 if (i==1) {
	 cout << "Est-ce que votre champignon vit en forêt (1 : oui, 0 : non) ? ";
  cin >> foret;  
}
  
   if (i==2) {
	   cout << "Est-ce que votre champignon a des lamelles (1 : oui, 0 : non) ? ";
  cin >> lame;
}



  
  // pour trouver la bonne réponse, on comparera les champignons possibles en se servant des réponses
  // mais aussi en prenant soin de ne pas compter les champignons déjà éliminés.
  cout << "==> Le champignon auquel vous pensez est ";

    
 if ((anneau==0)and(chapeau==1))   cout << "le pied bleu";
 if ((anneau==1)and(chapeau==0))   cout << "le coprin chevelu";
	  
	  
	  if (i==1) if (foret==1)   cout << "l'amanite tue-mouches";
      else  cout << "l'agaric jaunissant";

if (i==2) if (lame==1)    cout << "la girolle";
             else cout << "le cèpe de Bordeaux";
return 0;
}
