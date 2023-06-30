#include <iostream>
#include <cmath>
using namespace std;

int main () {
cout << "entrez un nombre reel" << endl;
double x;
cin >> x;
//idée on fait tous les ensemble exclus puis on rajoute les valeurs inclsues
//construire d'abord () or () pour égalités et ensembles exclus
if ( ( ( ( (x<3)and(2<x) )or( (x<1)and(0<x) ))or( (x<-2)and(-10<x) ))or
(( (x==2)or(x==1) )or( (x==-10)or(x==-2) )))
// /!\ on peut noter (cond)or(cond)or(cond) au lieu de 
// ((cond)or(cond))or(cond)
cout <<"x appartient à I" << endl;
else cout <<"x n'appartient pas à I" << endl;
}


