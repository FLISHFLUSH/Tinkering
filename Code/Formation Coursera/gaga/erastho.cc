#include <iostream>
#include <vector>
using namespace std;
// essayer sans bool
// fonction inutile si on utilise une fonction bool

//on pouvait écrire vector<bool> b(n, true);
void deux_a_n(vector<bool>& v, size_t n) {
	v.clear();
	for(size_t i(0); i<=n;i++)
	v.push_back(true);
}


void lire_matrice(vector<bool> v){
for(size_t i(2); i<v.size();i++)
if (v[i]) cout << i << "  ";
}

// idee: tableau bool init en false.
// tous les multiples de 2 passent en true [T2*i] =true pour 2*i<=n;
// pareil pour 3
// ensuite la fonction detect le prochain false et teste sur la valeur i+2 (ex 2 correpond à l'élément 0, 5 =>3 etc).
// on peut aussi faire un tableau de 0 à n et ne pas afficher 1 et 0
void retirer_elem(vector<bool>& v){
for	(size_t i(2); i<v.size(); i++){
	if (v[i]) 
	for (size_t j(2); j*i<v.size();j++){
	v[j*i]=false;
 //cout << i*j<< endl;
}
//cout << v[i]<< "  " <<i<<endl;
}
}


int main() {
	size_t n(100);
	vector<bool> w (n, true);
	
	retirer_elem(w);
	lire_matrice(w);
}	
