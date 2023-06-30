#include <iostream>
#include <vector>
using namespace std;

vector<vector<double>> saisie_matrice() {
	unsigned int ligne; unsigned int colonne;
	cout<<endl<<"nombre de ligne ? ";
	cin >> ligne;
	cout <<endl<<"nombre de colonnes ? ";
	cin >> colonne;
	// si on voulait du w[i][j]:
	// il faut initialiser les tableaux de tableaux.
	//vector>vector<double>> w(ligne, vector<double> (colonne));
	double(temp);
	vector<vector<double>> w(ligne);
	for (size_t i(0); i<ligne;i++) {
		for (size_t j(0); j<colonne;j++){
		cout<<"M["<<i+1<<"]["<<j+1<<"]=";
		cin >> temp; w[i].push_back(temp);
	    }
    } cout << endl;
return w;
}

//po mal, fait tout seul
void lire_matrice(vector<vector<double>> v){
for(auto ligne:	v) {
for(auto colonne: ligne)
cout << colonne<< "  ";
cout <<endl;
}
cout << endl;
}

vector<vector<double>> multip(vector<vector<double>> M1, vector<vector<double>> M2){
	vector<vector<double>> M(M1.size(), vector<double>(M2[0].size()));
	// /!\ à ne pas inversre M1.size et M2[0] size;
	for(size_t i(0);i<M1.size();i++)
	for(size_t j(0); j<M2[0].size();j++)
	//rappel: M2.size== M1[0].size
	for(size_t k(0); k<M2.size();++k)
	M[i][j]+= M1[i][k]*M2[k][j];
	
	return M;
	
}
bool compatibilite(vector<vector<double>> M1,vector<vector<double>> M2) {
	if (M1[0].size()==M2.size()) {
		cout <<"Les matrices sont compatibles !"<<endl;
		return true; }
    else { cout <<"les matrices ne sont pas compatibles !" <<endl; return false;
}
}

// on pourra rajouter une fonction qui vérife que 2 fonctions sont comaptibles.

int main () {
	bool comp;
	do {
	vector<vector<double>> M1(saisie_matrice());
	vector<vector<double>> M2(saisie_matrice());
	comp=compatibilite(M1,M2);
	if (comp) {
	lire_matrice(M1); lire_matrice(M2);
	vector<vector<double>> M(multip(M1,M2));
	lire_matrice(M);
} 
} while (not comp);
	return 0;
}
