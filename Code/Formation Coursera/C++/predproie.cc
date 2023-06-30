#include <iostream>
#include <iomanip> // pour setprecision()
using namespace std;

int main()
{
  // Réduire le format d'affichage
  cout << setprecision(4);

  // Paramètres
  double taux_croissance_lapins(0.3);
  double taux_attaque(0.01);
  double taux_croissance_renards(0.008);
  double taux_mortalite(0.1);
  int duree(50);

  double renards_i(0.0);
  double lapins_i(0.0);

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/

  // ===== PARTIE 1 =====
  // Saisie des populations initiales
  
  //pas besoin de do car initialisés à 0.
   while (renards_i<2) {
	   cout << endl<< "Combien de renards au départ (>= 2) ? ";
  cin >> renards_i;
 };
 
 while (lapins_i<5) {
	 cout << endl <<"Combien de lapins au départ  (>= 5) ? ";
	cin >> lapins_i;
}
  // ===== PARTIE 2 =====
  // Première simulation
  cout <<  endl << "***** Le taux d'attaque vaut "<< taux_attaque * 100 << "%" <<  endl;
  double  nb_renards(renards_i); double nb_lapins(lapins_i);
  for (int i(1); i<=duree;++i) {
	double temp(nb_lapins);
	 nb_lapins=nb_lapins*(1. + taux_croissance_lapins - taux_attaque*nb_renards);
	 nb_renards=nb_renards*(1.+taux_attaque*temp*taux_croissance_renards-taux_mortalite);
	  if (nb_lapins<0) nb_lapins=0;
      if (nb_renards<0) nb_renards=0;
 
	  cout << "Après " <<i<< " mois, il y a "<<nb_lapins<<" lapins et "<<nb_renards<<" renards"<<endl;
  }


  // ===== PARTIE 3 =====
  // Variation du taux d'attaque
 
 cout<<endl;
 double taux_attaque_i(0.), taux_attaque_f(0.);
 do {
  cout << "taux d'attaque au départ en % (entre 0.5 et 6) ? ";
  cin >> taux_attaque_i;
  } while ((taux_attaque_i<0.5)or(taux_attaque_i>6));

  do {
	  cout << "taux d'attaque à la fin  en % (entre "<<taux_attaque_i<<
   " et 6) ? ";
   cin >> taux_attaque_f;
} while ((taux_attaque_f<taux_attaque_i) or(taux_attaque_f>6));

 cout << endl;
  
  // on a préféré faire une boucle for et ajouter j dans la formule que de faire un while avec un ++taux_attaque_i 
  //variation du t'aux dattaque
  int j(0);
  // remarque: j+taux_attaque_i < taux_attaque_f est équivalent (et j+taux_attaque_i est le taux testé).
  
  //passage d'un for à un do { } while pour le cas TAi = TAf;
  do {
	  //variable d'affichage du mois après simul
	  int prem(duree);
	  //déclaration de variable booleene et réinitilisation de la simulation
	  bool alerteR(false); bool alerteL(false);
      bool oufR(false); bool oufL(false);  
        nb_renards=renards_i;  nb_lapins=lapins_i;
         // simulation
   for (int i(1); i<=duree;++i) {
	    double temp(nb_lapins);
	         
	nb_lapins=nb_lapins*(1. + taux_croissance_lapins - (taux_attaque_i+j)/100*nb_renards);
	nb_renards=nb_renards*(1.+(taux_attaque_i+j)/100*temp*taux_croissance_renards-taux_mortalite);
	//cout << nb_lapins<< "      " <<nb_renards<<endl;
	
	 //code d'affichage extinction
	 if (nb_lapins<5) { alerteL=true; 
		 if (nb_lapins<2) nb_lapins=0;
   } else if (alerteL) oufL=true;
	 
	 if (nb_renards<5) { alerteR=true;
		 if (nb_renards<2) nb_renards=0; 
   } else if (alerteR) oufR=true;
   
   // arret de la simul à 0 et 0
   if (nb_lapins+nb_renards==0)  {
	    prem=i; i=duree;
	}
    
}
    cout << "***** Le taux d'attaque vaut "<< taux_attaque_i+j<<"%"<<endl;
	cout << "Après " <<prem<< " mois, il y a "<<nb_lapins<<" lapins et "<<nb_renards<<" renards"<<endl;


//essayer un switch pour simplifier la condition sur la ligne "pop stable ??"
 // else après 1er if pas obligatoire car ces booleens dependant déjà de alerteR/L
	  if (alerteR) cout<< "Les renards ont été en voie d'extinction"<<endl; 
	  if (oufR) cout << "mais la population est remontée ! Ouf !"<<endl;  
	  if (nb_renards==0) cout << "et les renards ont disparu :-(" << endl;
	    
	  if (alerteL) cout<< "Les lapins ont été en voie d'extinction"<<endl; 
	  if (oufL) cout << "mais la population est remontée ! Ouf !"<<endl;  
	  if (nb_lapins==0) cout << "et les lapins ont disparu :-(" << endl;

  //vérifier condition en dessous
 if (not((alerteR)or(alerteL))) cout << "Les lapins et les renards ont des populations stables." <<endl;
 cout <<endl;
 j++;
} while (j<taux_attaque_f-taux_attaque_i);
  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
