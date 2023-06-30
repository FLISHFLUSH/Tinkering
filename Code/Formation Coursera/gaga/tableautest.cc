#include <iostream>
#include <vector>
#include <array>
#include <string>
using namespace std;

//w[10] sur un tableau de taille <=10 n'est po accessible.

// apparemment 
	// array<array<string, 1>, 3> s= { {"a"}, {"a"}, {"c"}}; pas possible, 2eme accolades inutiles (car taille déjà spécifiées ?) "a" => tableau 1, "a" -> tableau 2, "c" tableau ->3
	//vector<vector<string, 1>, 3> s= { {"a"}, {"a"}, {"c"}}; fonctionne par contre

int main () {
	/* string w("0123456789");
	w.insert(w.size(),"mzzzzz");
	for (auto a :w)
	cout << a<< "   "; 
	array<double,3> c ({1,2,3});
	cout << c[0]; */array<array<string, 1>, 3> s = { "a", "a", "c"};
s[2][0] = "d";
//tester le code avec array<array<string, 3>, 1> s = { "a", "a", "c"}; et array<array<string, 1>, 3> s = { "a", "a", "c"}; (remplacer s[2][0] par s[0][2] si besoin
for(auto a:s){
cout <<endl;
for(auto b:a)
cout << b<< "   ";
}
	
	
return 0;
}
