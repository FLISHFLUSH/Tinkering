#include <iostream>
#include <vector>
using namespace std;

// idee: faire fonction qui multiplie V[i] et u[i] et s'en servivr pour produit scalaire
vector<double> produitscalaire(vector<double> v, vector<double> u) {
	vector<double> w;
for (size_t i(0); i<v.size(); i++) {
      w.push_back(v[i]*u[i]);
	
 }
	return w;
}

void saisie(string a, vector<double>& v){
	
	for (size_t i(0); i<v.size();i++){
    cout << "saisie du " << a<< " vecteur" <<endl<< "coordonnées "<< i+1<<": ";
    cin >> v[i];
    cout << endl;
}
}
	
int main (){
	vector<double> v(3);	vector<double> u(3);
	saisie("premier",v); saisie ("deuxieme", u);
	vector<double> w(produitscalaire(u,v));
	for(auto a: w)
	cout << a<<endl;
	return 0;
}
