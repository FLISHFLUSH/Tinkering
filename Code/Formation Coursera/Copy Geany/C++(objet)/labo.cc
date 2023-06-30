#include <iostream>
#include <string>
using namespace std;

class Souris
{
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
	double poids;
	string couleur;
	unsigned int age;
	unsigned int esperance_vie;
	bool clonee;
	
	public:
	Souris(double poids, string couleur, unsigned int age=0,unsigned int esperance_vie=36, bool clonee=false)
	:poids(poids), couleur(couleur), age(age), esperance_vie(esperance_vie), clonee(clonee)
	{cout<<"Une nouvelle souris !"<<endl;}
	
	Souris(Souris const& S)
	: poids(S.poids), couleur(S.couleur), age(S.age), esperance_vie(S.esperance_vie*4/5) , clonee(true)
	{cout<<"Clonage d'une souris !"<<endl;}
	
	~Souris()
	{cout<<"Fin d'une souris..."<<endl;
	};
	
	void afficher()const  {
		cout <<"Une souris "<<couleur;
		if (clonee) cout<<", clonee,";
		cout<<" de "<<age<<" mois et pesant "<<poids<<" grammes"<<endl;

	}
	
	void vieillir() {
	++age;
	//+1 car si esp est pair, aucun changement avec la valeur original, si impair alors la valeur vaut et comme on
	//travaille sur des int, ça symbolise le +0.5 (flemme d'expliquer correctement) ?
	if ((clonee)and(age>((esperance_vie)/2))) couleur="verte";	
	}
	
	void evolue() {
		while (age<esperance_vie)  {
			vieillir();
			}
	}
  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

}; // fin de la classe Souris

int main()
{
  Souris s1(50.0, "blanche", 2);
  Souris s2(45.0, "grise");
  Souris s3(s2);
  // ... un tableau peut-être...
  s1.afficher();
  s2.afficher();
  s3.afficher();
  s1.evolue();
  s2.evolue();
  s3.evolue();
  s1.afficher();
  s2.afficher();
  s3.afficher();
  return 0;
}
