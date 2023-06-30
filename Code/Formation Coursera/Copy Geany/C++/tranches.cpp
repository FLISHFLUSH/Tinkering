#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <math.h>
using namespace std;

int somme_consecutifs_max (vector<int> v) {
	v.push_back(0);
	int somme(0), max(0);
	for (auto elem:v)
	if (elem>0) somme+=elem; else if (max<somme)  {max=somme; somme=0;}
	return max;
	}
vector<size_t> lignes_max(vector<vector<int>> v)	{
	int max(0); vector<size_t> tab;
	for(size_t i(0);i<v.size(); i++) {
	int max_l(somme_consecutifs_max(v[i]));
	if (max<max_l) { tab.clear(); max=max_l; }
	if (max==max_l) { tab.push_back(i);}
    } return tab;
}
vector<vector<int>> tranches_max(vector<vector<int>> v) {
vector<vector<int>> tab ; vector<size_t> selec(lignes_max(v));
for(auto elem: selec)
tab.push_back(v[elem]);
return tab;
}
int main() { 

vector<vector<int>> v(tranches_max({{ 0,0,0,0,0 },{1,2,3,0},{6},{0,1,2,0,0,5},{1,1,1,0,1,2,2,1}}));	
for (auto elem:v) { cout<<"(";
for (auto element:elem)
cout<<element<<",";
cout<<"\b"<<")"<<endl;}
	return 0;}
