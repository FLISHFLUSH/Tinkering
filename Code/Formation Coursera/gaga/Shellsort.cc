#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;
typedef vector<int> Tableau;
// idee derrière le tri de shell: (?)
//plutot que de trier chaque elem du tableau 1par1, on trie des sous ensemble de taille k, jusqu'à ce que k=1.
// à k=1 le tri de shell ressemble à un tri par insertion normal 
bool test_croissant(Tableau t){
	for (size_t i(0); i<t.size()-2; i++)
	if  (t[i]>t[i+1]) return false;
	return true;
}

void echanger_element(Tableau& t, size_t k, size_t j){
 int temp(t[j]);
 t[j]=t[j+k];
 t[j+k]=temp;
}

void tri_shell(Tableau& t){
	for (size_t k(t.size()/2) ; k>0; k/=2)
	for (size_t i(k+1); i<=t.size(); i++){
		int j(i-k);
		while (j>0){
		if (t[j-1]>t[j-1+k]) {  cout <<t[j-1]<<"    " << t[j-1+k]<< "**** ";
			//travail sur unsigned int donc on test j>k
			   echanger_element(t,k,j-1);
			   // ou swap; 
			   cout <<t[j-1]<<"    " << t[j-1+k]<< endl;
		 j=j-k; } else j=0;
		}
		
			
	 //swap(t[j-1],t[j+k-1]);
	}
}

int main () {
	Tableau p={3, 5, 12, -1, 215, -2, 17, 8, 3, 5, 13, 18, 23, 5, 4, 3, 2, 1 };
	tri_shell(p);
	for(auto a:p)
	cout <<"*"<< a <<" ";
}
