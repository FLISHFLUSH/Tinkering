#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<unsigned int> vect;
typedef vector<vect> mat;


unsigned int somme_consecutifs_max(vect t) {
unsigned int max(0);
unsigned int temp(0);
for(size_t i(0); i<t.size(); i++){
	temp+=t[i];
	if (max<temp)  max=temp; 
	if (t[i]==0) temp=0;
	//cout << max << "   ";
}
//cout <<endl;
return max;
}

vect lignes_max(mat m){
	vect t(0,0);
	unsigned int max(0);
	for (size_t i(0); i<m.size(); i++){
	 unsigned int max_i(somme_consecutifs_max(m[i]));	
/*	m[i].push_back(max_i); */
	if (max_i>max) { t.clear(); max=max_i;  }
    if (max_i==max) t.push_back(i);
	}
	//cout <<max<<"  ";

		//cout << max;
  /*  for (size_t i(0); i<m.size(); i++) {
    if (m[i][m[i].size()-1]==max) t.push_back(i);
    //cout <<i;
    //cout << "   "<<m[i][m[i].size()-1]; 
    }
    * */

    
    return t;
}

mat tranches_max(mat m){
	mat coquille(0);
 vect indice(lignes_max(m));
 for(auto a:indice)
 coquille.push_back(m[a]);
 
 return coquille;
}

int main () {
	 //cout << somme_consecutifs_max({1,2,0,2,2});
	//mat m={{1,2,0,5,4},{1,3,0,6,3},{1,3,3,2},{9},{1,3,3,2},{},{0},{1,2,3},{2,3}};
	//m.clear();
	/* vect v=lignes_max(m);
	for (auto a:v)
	cout << a<<"   "; */ /*
m=tranches_max(m);
	for(auto a:m){
	for(auto b:a)
	cout <<b <<" ";
	cout <<endl;
} */
}
