#include <iostream>
using namespace std;

int separer_chiffre_gauche(int& nombre)
{
  int dix(1);
  int temp(nombre);
  while (temp >= 10) {
    dix  *= 10;
    temp /= 10;
  }
  nombre %= dix;
  return temp;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

void ajouter_chiffre_droit(int& nombre, int chiffre)
{
	nombre=nombre*10+chiffre;
}

void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre)
{
	ajouter_chiffre_droit(nombre,repetitions_chiffre);
	ajouter_chiffre_droit(nombre,chiffre);
}

int lire_et_dire(int nombre)
{
	int temp;
	int bis=(nombre);
	bool nouveau(true);
	int chiffre;
	//cout << nombre << endl ; cout << chiffre<< endl;
	int i(1);
	// on sort chiffre car on ne veut pas le répeter à cause du passage d'argument apr ref
	chiffre=separer_chiffre_gauche(nombre);
	do{
		 temp=separer_chiffre_gauche(nombre);
		 // on répète le i++ par la boucle while
			if ((chiffre==temp)) 
		
				i++;
				// si chiffre==temp, i++ puis redémarrage de la boucle.
				// on a crée bool nouveau car on ne sait pas former le début du nouveau nombre sans.
		    else { if (nouveau) { ajouter_chiffre_droit(i,chiffre); 
					                  bis=i;nouveau=false;
			           } 
			       else  dire_chiffre(bis,i,chiffre); 
		/* on pose chiffre = temp pour éviter un nouveau passage d'argument par référence
			 la variable chiffre ne sert qu'à sauver le dernier chiffre étudié. */
			 //crucial, long blocage dessus (également avec temp!=0)
		chiffre=temp; i=1;
			}
		//si temp !=0 le nombre n'a pas été complètement parcouru, c'est une forme de do {} while inversé
		// nombre>0 inutile ?
		// le temp!=0 permet à la boucle while d'opérer encore une fois pour réaliser le dernier collage. 
		//autrement elle s'arreterait sur le dernier chiffre en calculant la répétition sans calculer dire_chiffre.
		} while ((nombre>0)or(temp!=0));
		// une autre façon de faire consistait à rajouter l'étape de transformation 1 fois après la boucle.
				
				

return bis;
}
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void repeter_lire_et_dire(int& nombre, int fois)
{
  while (fois-- > 0) {
    nombre = lire_et_dire(nombre);
  }
}

int main()
{
  int nombre(1);
  int fois(1);
  cin >> nombre >> fois;
  repeter_lire_et_dire(nombre, fois);
  cout << nombre << endl;
  return 0;
}
