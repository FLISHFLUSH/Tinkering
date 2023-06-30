#include <iostream>
using namespace std;

int main()
{
  int debut(0);
  do {
    cout << "de (>= 1) ? ";
    cin >> debut;
  } while (debut < 1);

  int fin(0);
  do {
    cout << "a (>= " << debut << ") ? ";
    cin >> fin;
  } while (fin < debut);

  /*******************************************
   * Completez le programme a partir d'ici.
   *******************************************/
   
for (int i(debut); i<=fin;i++){
	int k(0), j(i);
	
	do {
		if (j%3==0) j+=4;
		else if (j%4==0)  j/=2;
		else --j;
		++k;
	} while (j!=0);
	cout <<i<<" -> "<<k<<endl;

 }

  /*******************************************
   * Ne rien modifier apres cette ligne.
   *******************************************/

  return 0;
}
