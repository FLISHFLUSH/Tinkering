#include <iostream>
#include <vector>
using namespace std;
// apparemment un tableau de taille 5 peut avoir un élément à l'indice 10 ?
vector<int> elements_en_indice(vector<int>& v, size_t n) {
	size_t i(0); vector<int> w(n/2);;
	while (i<n) {
		w[v[2*i+1]]=v[2*i];
		i+=2;
	
		
	}
	return w;
}
int main() {
	vector<int> v({1,2,3,4,5,6,7,8});
	vector<int> w=elements_en_indice(v, v.size());
	for(auto a:w)
	cout << a<< "  ";
	
}

//EXO DE MERDE
