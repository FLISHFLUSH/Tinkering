
#include <iostream>
#include <cmath>
using namespace std;

int main () {
int i(0);
bool a(true);
cout << a<<endl;
// ici on ne peut pas redéclarer i avec int i(X) car déjà déclarée
do {
	//ça ne gêne pas de redéclarer à chaque fois
	//x se volatise à chaque boucle
double x(-1);
cout <<x<<endl;
++x;
cout << x;
++i;
}
while (i<10) ;
}
