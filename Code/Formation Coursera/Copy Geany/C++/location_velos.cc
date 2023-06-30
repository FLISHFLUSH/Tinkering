#include <iostream>
using namespace std;

int main()
{
  cout << "Donnez l'heure de début de la location (un entier) : ";
  int debut;
  cin >> debut;

  cout << "Donnez l'heure de fin de la location (un entier) : ";
  int fin;
  cin >> fin;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
 if (   (debut<0)or(debut>24) or (fin<0)or(fin>24)  ) 
    cout << "Les heures doivent être comprises entre 0 et 24 !" << endl;
  else if (debut==fin)
    cout << "Bizarre, vous n'avez pas loué votre vélo bien longtemps !" << endl;
   else if (debut > fin) 
    cout << "Bizarre, le début de la location est après la fin ..." << endl;
else {

//refaire avec comme idée:
// si début est dans l'horaire 2franc, vérifier fin.
// si début n'est pas dans l'horaire 2 franc,
	
	
	//comment on calcule: on s'intéresse au cas ou le temps passé en horaire à 2 franc est maximal (début<=7 et fin <=17)
	//puis on s'intéresse au cas contraire (le cas oppose)
/*int duree(fin-debut); int hor1(0); int hor2(0);
if ((debut<=7)and(fin>=17)){ // contraire: non(début<7)ou non(fin>=17)
   hor2=10; //17heures-7heures
   hor1=duree-10; 
   } else if (debut>7) 
             if (fin<17)
             hor2=duree;
             else {
				 hor2=17-debut;
				 hor1=fin-17;
			 }
	      else  if (fin>7) {
	              hor2=fin-7;
	              hor1=7-debut;
			  }
			  else hor1=fin-debut;
		  
   

   */       
int hor1(0); int hor2(0);
int i(0);
if (debut<7) i=0;
else { if (debut<17) i =1;
       else i=2;
   }
     
     
     switch(i) {
     case 0: if (fin>7) 
              hor1=7-debut;
              else { hor1=fin-debut; break; 
			  }
				//réflechir à formule générale en fin/17*17 et fin/17*fin
				     
              case 1: if (fin>17)
              // si i>=1 alors hor 1=0, sinon -debut-hor1 =debut-debut-7= 7 donc ok (car hor2=min(fin,17) - 7)
              
                       hor2=17-debut-hor1;
                       else { hor2=fin-debut-hor1; break ; 
					   }
					
					   case 2: hor1=fin-hor2-debut; break;
					      //formule fonctionne pour case 0 case 1... case 2?
					   // si i=2, alors hor2=0   ok
					   //si antérieur, alors hor2=17-debut-hor1 
					   //donc hor1=fin-17+debut+hor1-début=fin-17+hor1
					   //cas 1, hor1 = 0 donc   ok
					   //cas 0, ok (hor1+=fin-17)
				   }
               
 cout << "Vous avez loué votre vélo pendant" << endl;

if (hor1!=0)
      cout << hor1 <<" heure(s) au tarif horaire de "
      << "1 franc(s)" << endl;
if (hor2!=0)     
      cout << hor2  <<" heure(s) au tarif horaire de "
      << "2 franc(s)" << endl;
	  
    cout << "Le montant total à payer est de "
         << hor1+2*hor2 <<" franc(s)." << endl; 
	  }
        
	

  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
