#include <iostream>
#include <cmath>
using namespace std;

int main () {
	int ligne(0);
	cin >> ligne;

	for (int i(0); i<ligne;i++){
	 for (int a(1);a<ligne-i;++a)
     cout <<" ";
     // ou j(0) ... j<i*2+1
     for (int j(1); j<=i*2+1;++j)
     cout << "*";

 
     cout << endl;
 }
 
}
